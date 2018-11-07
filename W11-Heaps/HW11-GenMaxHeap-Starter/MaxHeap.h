#ifndef MAXHEAP_H
#define MAXHEAP_H
/* Name: // Fill me in
   Date: Nov 5, 2018
   Desc: Max heap/priority queue, templated.
*/
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cassert>
#include <vector>

using namespace std;


//template <class myType>  // uncomment this line when you are ready!
class MaxHeap{
    private:
        // Fill me in.
      
    public:
    
    
    MaxHeap(){
        // Fill me in.
    }
    
    // For a templated class to work on any type, a less-than operator function
    // may be required.  For extra credit only.
    /*
    MaxHeap(bool (*lessThanPtr2)(myType,myType)){
        // Fill me in.
    }
    */
  
    // Insert word into the Heap
    void push(const string &word){
        // Fill me in.
    }
  
    // Number of values stored
    unsigned size()const{
        // Fill me in
        return heap_size;
    }
    
    // Returns the Minimum string - Does not change the heap!
    // Throw exception if heap is empty.
    string top()const{
        // Fill me in.
    }
    
    // Remove the Minimum value from the heap
    void pop(){
        // Fill me in.
    }
    
    
    private:
    
   // Fill me in.
};

#endif

