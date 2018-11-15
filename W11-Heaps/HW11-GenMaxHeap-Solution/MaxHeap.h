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

template <class myType>
bool defaultLessThan(myType a, myType b){
        if( a < b ) return true;
        return false;
}

template <class myType>
class MaxHeap{
    private:
      vector<myType> data;
      unsigned heap_size;
      // cmp operator - https://www.learncpp.com/cpp-tutorial/78-function-pointers/
      bool (*lessThanPtr)(myType,myType);
      
  
    public:
    
    
    MaxHeap(){
        heap_size = 0;
        lessThanPtr = defaultLessThan;
    }
    
    MaxHeap(bool (*lessThanPtr2)(myType,myType)){
        heap_size = 0;
        this->lessThanPtr = lessThanPtr2;
    }
  
    // Insert word into the Heap
    void push(const myType &word){
        if(data.size() == heap_size){
            // vector is at capacity, need to add more
            data.push_back(word);
            heap_size++;
        }else{
            data[heap_size] = word;
            heap_size++;
        }
        bubbleUp();
    }
  
    // Number of values stored
    unsigned size()const{
        // Fill me in
        return heap_size;
    }
    
    // Returns the Minimum string - Does not change the heap!
    // Throw exception if heap is empty.
    myType top()const{
        if(size() == 0)throw logic_error("no enteries in heap");
        return data[0];
    }
    
    // Remove the Minimum value from the heap
    void pop(){
        // Removes the minimum value from the heap by putting the last element
        // on top, then bubbling down.
        if(heap_size == 0)return;
        //print();
        data[0] = data[heap_size-1];
        heap_size--;
        //print();
        bubbleDown();
        //print();
        //cout << "------\n";
    }
    
    
    private:
    
    unsigned getParent(unsigned n){
        return (n - 1) / 2;
    }
    
    unsigned getLeftChild(unsigned n){
        return n * 2 + 1;
    }
    
    unsigned getRightChild(unsigned n){
        return n * 2 + 2;
    }
    
    void bubbleUp(){
        //print();
        // This will be called after push, so heap_size will be one past, 
        unsigned cur = heap_size-1;
        // Bubble up!
        while(cur != 0 && lessThanPtr(data[getParent(cur)], data[cur]) ){ // Wrong order!
            myType temp  = data[cur];
            data[cur] = data[getParent(cur)];
            data[getParent(cur)] = temp;
            cur = getParent(cur);
        }
        //print();
    }
    
    void bubbleDown(){
        if(heap_size <= 1)return;
        unsigned cur = 0;
        while(1){
            // See if the right child exists
            if(getLeftChild(cur) >= heap_size){
                return;  // Must be only 1 element!
            }
            if(getRightChild(cur) >= heap_size){  // Nope!
                // Maybe just flip with left
                if(lessThanPtr(data[cur] , data[getLeftChild(cur)])){
                    myType left = data[getLeftChild(cur)];
                    data[getLeftChild(cur)] = data[cur];
                    data[cur] = left;
                    return; // We must be at the bottom level, so are done!
                    //cur = getLeftChild(cur);
                }else{
                    return;
                }
            }else{
                // See if we need to flip
                if(lessThanPtr(data[cur] , data[getLeftChild(cur)]) || lessThanPtr(data[cur] , data[getRightChild(cur)])){
                    myType left = data[getLeftChild(cur)];
                    myType right = data[getRightChild(cur)];
                    if( lessThanPtr(right, left) ){
                        data[getLeftChild(cur)] = data[cur];
                        data[cur] = left;
                        cur = getLeftChild(cur);
                    }else{
                        data[getRightChild(cur)] = data[cur];
                        data[cur] = right;
                        cur = getRightChild(cur);
                    }
                }else{
                    return;
                }
            }
        }
    }
    
    void print()const{
        cout << "heap_size: " << heap_size << endl;
        for(unsigned i = 0; i < heap_size; i++){
            cout << i << ":" << data.at(i) << endl;
        }
        cout << endl;
    }
    
};

#endif

