/*
    Name:
    Date:
    Desc: 
    
    Class to measure and time an algorithm's performance
    and save the results to a csv file.
    
    setN should be called with a value, and the subsequent
    tic/toc and increment calls will be logged until another setN
    is called, or a saveResults.
    
    saveResults saves a csv file in the current directory provided
    by a string.  The columns should be n, time, A count, B count, C count.
    The file is overwritten if one already exists.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sys/time.h>


#include "timer.h"

using namespace std;

double getTimeAsDoubleSeconds(){
  struct timeval now;
  gettimeofday(&now, NULL);
  return (double)now.tv_sec + (double)now.tv_usec / 1000000.0;
}

/*  Example code to save a CSV file 
    ofstream myfile;
    myfile.open (file_name.c_str());
    myfile << "n,time,a,b,c\n";
    ...
    myfile.close();
*/
