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
      vector<string> data;
      unsigned heap_size;
  
    public:
    
    MinHeap(){
        heap_size = 0;
    }
  
    // Insert word into the Heap
    void push(const string &word){
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
    string top()const{
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
        while(cur != 0 && data[cur] < data[getParent(cur)]){ // Wrong order!
            string temp  = data[cur];
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
                if(data[cur] > data[getLeftChild(cur)]){
                    string left = data[getLeftChild(cur)];
                    data[getLeftChild(cur)] = data[cur];
                    data[cur] = left;
                    return; // We must be at the bottom level, so are done!
                    //cur = getLeftChild(cur);
                }else{
                    return;
                }
            }else{
                // See if we need to flip
                if(data[cur] > data[getLeftChild(cur)] || data[cur] > data[getRightChild(cur)]){
                    string left = data[getLeftChild(cur)];
                    string right = data[getRightChild(cur)];
                    if( left < right){
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

