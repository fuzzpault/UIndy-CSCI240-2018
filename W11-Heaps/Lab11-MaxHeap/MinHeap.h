#ifndef MinHEAP_H
#define MinHEAP_H
/* Name: // Fill me in
   Date: NOV 4, 2018
   Desc: Min heap/priority queue
*/
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cassert>
#include <vector>

using namespace std;


class MinHeap{
    private:
      // Fill me in
  
    public:
    
    MinHeap(){
        // Fill me in
    }
  
    ~MinHeap(){
        // Fill me in
    }
  
    MinHeap(const MinHeap &other){
       // Fill me in
    }
    
    MinHeap& operator=(const MinHeap &other){
       // Fill me in
       return *this;
    }
  
    // Insert word into the Heap
    void push(const string &word){
        // Fill me in
    }
  
    // Number of values stored
    unsigned size()const{
        // Fill me in
        return 0;
    }
    
    // Returns the Minimum string - Does not change the heap!
    // Throw exception if heap is empty.
    string top()const{
        // Fill me in
        return "I will not work";
    }
    
    // Remove the Minimum value from the heap
    void pop(){
        // Fill me in
    }
    
    
    private:
    
    // Fill me in
    
};

#endif

