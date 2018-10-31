/* Name: // Fill me in
   Date: Oct 28, 2018
   Desc: Demo code to run a simple HTTP webserver.
   
   Compile with: g++ trie-auto-complete.cpp
*/

#include "http-server.cpp"

#include <iostream>

using namespace std;

// Convert a vector of strings into a JSON list
string listify(const vector<string> &list){
    stringstream s;
    s << "[";
    for(unsigned i = 0; i < list.size(); i++){
        s << "\"" << list[i] << "\"";
        if(i != list.size() -1){
            s << ",";
        }
    }
    s << "]";
    return s.str();
}

string doStuff(string query){
    vector<string> a;
    if(rand() % 2 == 0)a.push_back("honey");
    if(rand() % 2 == 0)a.push_back("grapes");
    if(rand() % 2 == 0)a.push_back("apples");
    if(rand() % 2 == 0)a.push_back("pears");
    return listify(a);
}

int main(){
    srand(time(0));
    
    // Start the webserver on port 8080
    HTTPServer server(8080);
    // Whenever /cgi-bin/doStuff? is accessed, call the given function with
    // everything after the ? as a paramter.
    server.addCallback("query", doStuff);
    
    // Run the server (will loop forever)
    server.run();
}