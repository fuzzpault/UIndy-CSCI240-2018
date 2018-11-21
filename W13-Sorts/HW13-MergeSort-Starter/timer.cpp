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

Timer::Timer(){
    n = 0;
    a = 0;
    b = 0;
    c = 0;
    stored_time = 0.0;
    last_tic = -1.0;
}

void Timer::setN(unsigned n){
    if(this->n == n)return; // Do nothing if no change
    // Save all values to the log
    log_row_t temp;
    temp.n = this->n;
    temp.a = this->a;
    temp.b = this->b;
    temp.c = this->c;
    toc(); // just to be sure!
    temp.time = stored_time;
    log.push_back(temp);
    // Set n
    this->n = n;
    // Reset all
    stored_time = 0.0;
    last_tic = -1.0;
}

void Timer::tic(){
    if(last_tic != -1.0)return; // if running, don't reset
    last_tic = getTimeAsDoubleSeconds();
}

void Timer::toc(){
    if(last_tic == -1.0)return; // Timer wasn't going
    stored_time += getTimeAsDoubleSeconds() - last_tic;
    last_tic = -1.0; // turn off the timer
}

void Timer::incrementA(){
    a++;
}

void Timer::incrementB(){
    b++;
}

void Timer::incrementC(){
    c++;
}

void Timer::saveResults(string file_name){
    setN(99999); // To save current data
    // Sort?
    ofstream myfile;
    myfile.open (file_name.c_str());
    myfile << "n,time,a,b,c\n";
    for(int i = 0; i < log.size(); i++){
        myfile << log[i].n << ",";
        myfile << log[i].time << ",";
        myfile << log[i].a << ",";
        myfile << log[i].b << ",";
        myfile << log[i].c << "\n";
    }
    myfile.close();
}
