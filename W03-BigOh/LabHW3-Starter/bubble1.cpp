/*  Name: Paul Talaga
    Date: Sept 9, 2018
    Desc: Algorithm analysis test code
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "operations.cpp"
#include "timer.h"

const unsigned MAX_LENGTH = 1000;

using namespace std;

int main(){
    Timer t;
    
    srand(time(0));
    
    vector<int> a;
    
    // Evaluate different vector lengths
    for(unsigned length = 1; length < MAX_LENGTH; length++){
        // Always start with empty vectors
        a.clear();
    
        // Fill in the vectors with random numbers
        for(unsigned i = 0; i < length; i++){
            a.push_back(rand() % 10000);
        }
        
        // Sort
        t.setN(length);
        t.tic();
        bubbleSort3(a);
        t.toc();
        
        // Verify the operation worked
        for(unsigned i = 0; i < length-1; i++){
            if(a.at(i) > a.at(i+1)){
                cout << "Error!" << endl;
            }
        }
    }
    t.saveResults("times.csv");
}