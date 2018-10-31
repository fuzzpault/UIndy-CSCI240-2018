/*
 * tiny.c - a minimal HTTP server that serves static and
 *          dynamic content with the GET method. Neither
 *          robust, secure, nor modular. Use for instructional
 *          purposes only.
 *          Dave O'Hallaron, Carnegie Mellon  https://gist.github.com/bdahlia/7826649
 *
 *          usage: tiny <port>
 *          
 *          Converted to a class & added callback functionality by Paul Talaga
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#define BUFSIZE 1024
#define MAXERRS 16

using namespace std;

struct callback_t{
    string url_name;
    string (*fnPtr)(string);
};

class HTTPServer{
    private:
    int portno;
    vector<callback_t> callbacks;
    
    HTTPServer(); // Disallow default constructor
    
    public:
    
    HTTPServer(int port){
        this->portno = port;   
    }
    
    // Allow this server to call a proved function, which accepts
    // a string and returns a string, when a given cgi name is given.
    // In /cgi-bin/query?5  The 'query' url_name will be searched and
    // "5" will be given to the provded function.  Whatever that function
    // returns will be provided to the requestor over HTTP
    void addCallback(string url_name, string (*fnPtr)(string)){
        callback_t thing;
        thing.url_name = url_name;
        thing.fnPtr = fnPtr;
        callbacks.push_back(thing);
    }
/*
 * error - wrapper for perror used for bad syscalls
 */
void error(string msg) {
    cerr << msg;
    //perror(msg);
    exit(1);
}

/*
 * cerror - returns an error message to the client
 */
void cerror(FILE *stream,const char *cause,const char *errno,
            const char *shortmsg,const char *longmsg) {
    fprintf(stream, "HTTP/1.1 %s %s\n", errno, shortmsg);
    fprintf(stream, "Content-type: text/html\n");
    fprintf(stream, "\n");
    fprintf(stream, "<html><title>Tiny Error</title>");
    fprintf(stream, "<body bgcolor=""ffffff"">\n");
    fprintf(stream, "%s: %s\n", errno, shortmsg);
    fprintf(stream, "<p>%s: %s\n", longmsg, cause);
    fprintf(stream, "<hr><em>The Tiny Web server</em>\n");
}

void run() {
    cout << "Access this site at http://" << getenv("C9_HOSTNAME") << endl;
    /* variables for connection management */
    int parentfd;          /* parent socket */
    int childfd;           /* child socket */
    unsigned clientlen;         /* byte size of client's address */
    //struct hostent *hostp; /* client host info */
    char *hostaddrp;       /* dotted decimal host addr string */
    int optval;            /* flag value for setsockopt */
    struct sockaddr_in serveraddr; /* server's addr */
    struct sockaddr_in clientaddr; /* client addr */
    
    /* variables for connection I/O */
    FILE *stream;          /* stream version of childfd */
    char buf[BUFSIZE];     /* message buffer */
    char method[BUFSIZE];  /* request method */
    char uri[BUFSIZE];     /* request uri */
    char version[BUFSIZE]; /* request method */
    char filename[BUFSIZE];/* path derived from uri */
    char filetype[BUFSIZE];/* path derived from uri */
    char cgiargs[BUFSIZE]; /* cgi argument list */
    char *p;               /* temporary pointer */
    int is_static;         /* static request? */
    struct stat sbuf;      /* file status */
    int fd;                /* static content filedes */
    
    /* open socket descriptor */
    parentfd = socket(AF_INET, SOCK_STREAM, 0);
    if (parentfd < 0)
        error("ERROR opening socket");
    
    /* allows us to restart server immediately */
    optval = 1;
    setsockopt(parentfd, SOL_SOCKET, SO_REUSEADDR,
               (const void *)&optval , sizeof(int));
    
    /* bind port to socket */
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons((unsigned short)portno);
    if (bind(parentfd, (struct sockaddr *) &serveraddr,
             sizeof(serveraddr)) < 0)
        error("ERROR on binding");
    
    /* get us ready to accept connection requests */
    if (listen(parentfd, 5) < 0) /* allow 5 requests to queue up */
        error("ERROR on listen");
    
    /*
     * main loop: wait for a connection request, parse HTTP,
     * serve requested content, close connection.
     */
    clientlen = sizeof(clientaddr);
    while (1) {
        
        /* wait for a connection request */
        childfd = accept(parentfd, (struct sockaddr *) &clientaddr, &clientlen);
        if (childfd < 0)
            error("ERROR on accept");
        
        /* determine who sent the message */
        /*hostp = gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr,
                              sizeof(clientaddr.sin_addr.s_addr), AF_INET);
        if (hostp == NULL)
            error("ERROR on gethostbyaddr");
            */
        hostaddrp = inet_ntoa(clientaddr.sin_addr);
        if (hostaddrp == NULL)
            error("ERROR on inet_ntoa\n");
        
        /* open the child socket descriptor as a stream */
        if ((stream = fdopen(childfd, "r+")) == NULL)
            error("ERROR on fdopen");
        
        /* get the HTTP request line */
        fgets(buf, BUFSIZE, stream);
        printf("%s", buf);
        sscanf(buf, "%s %s %s\n", method, uri, version);
        
        /* tiny only supports the GET method */
        if (strcasecmp(method, "GET")) {
            cerror(stream, method, "501", "Not Implemented",
                   "Tiny does not implement this method");
            fclose(stream);
            close(childfd);
            continue;
        }
        
        /* read (and ignore) the HTTP headers */
        fgets(buf, BUFSIZE, stream);
        printf("%s", buf);
        while(strcmp(buf, "\r\n")) {
            fgets(buf, BUFSIZE, stream);
            printf("%s", buf);
        }
        
        /* parse the uri [crufty] */
        if (!strstr(uri, "cgi-bin")) { /* static content */
            is_static = 1;
            strcpy(cgiargs, "");
            strcpy(filename, ".");
            strcat(filename, uri);
            if (uri[strlen(uri)-1] == '/')
                strcat(filename, "index.html");
        }
        else { /* dynamic content */
            is_static = 0;
            p = index(uri, '?');
            if (p) {
                strcpy(cgiargs, p+1);
                *p = '\0';
            }
            else {
                strcpy(cgiargs, "");
            }
            strcpy(filename, "");
            strcat(filename, uri + 9);
        }
        
        /* make sure the file exists */
        if (is_static && stat(filename, &sbuf) < 0) {
            cerror(stream, filename, "404", "Not found",
                   "Tiny couldn't find this file");
            fclose(stream);
            close(childfd);
            continue;
        }
        
        /* serve static content */
        if (is_static) {
            if (strstr(filename, ".html"))
                strcpy(filetype, "text/html");
            else if (strstr(filename, ".gif"))
                strcpy(filetype, "image/gif");
            else if (strstr(filename, ".jpg"))
                strcpy(filetype, "image/jpg");
            else
                strcpy(filetype, "text/plain");
            
            /* print response header */
            fprintf(stream, "HTTP/1.1 200 OK\n");
            fprintf(stream, "Server: Tiny Web Server\n");
            fprintf(stream, "Content-length: %d\n", (int)sbuf.st_size);
            fprintf(stream, "Content-type: %s\n", filetype);
            fprintf(stream, "\r\n");
            fflush(stream);
            
            /* Use mmap to return arbitrary-sized response body */
            fd = open(filename, O_RDONLY);
            p = (char*)mmap(0, sbuf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
            fwrite(p, 1, sbuf.st_size, stream);
            munmap(p, sbuf.st_size);
        }
        
        /* serve dynamic content */
        else {
            cout << "CGIargs: " << cgiargs << endl;
            cout << "action: " << filename << endl;
            
            // Find filename in callback vector
            string ret = "";
            for(unsigned i = 0; i < callbacks.size(); i++){
                if(filename == callbacks[i].url_name){
                    ret = (*callbacks[i].fnPtr)(cgiargs);
                    break;
                }
            }
            
            /* print response header */
            fprintf(stream, "HTTP/1.1 200 OK\n");
            fprintf(stream, "Server: Tiny Web Server\n");
            fprintf(stream, "Content-length: %d\n", (int)ret.length());
            fprintf(stream, "Content-type: %s\n", "text/plain");
            fprintf(stream, "\r\n");
            fflush(stream);
            
            fwrite(ret.c_str(), 1, ret.length(), stream);
        }
        
        /* clean up */
        fclose(stream);
        close(childfd);
        
    }
}

};
