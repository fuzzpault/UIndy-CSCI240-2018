#ifndef ALIST_STATIC_H
#define ALIST_STATIC_H
/* Name: Paul Talaga
   Date: Sept 20, 2018
   Desc: Definition of a class
         to store and manipulate a list of integers.
         Internally uses a static array of length 100
*/
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <stdexcept>

#include "List.h"

#define SIZE 100

using namespace std;

// By subclassing of List, we verify we follow the required List interface.
class AListStatic : public List{
    private:
      //vector<int> stuff;
      int stuff[SIZE];
      unsigned my_size;
  
    public:
      AListStatic(){
        my_size = 0;
      };
      //List(const List&){}; // Copy constructor not needed, no new
      //virtual ~List(){};  // Not needed, no new
      
      void clear(){// Removes all elements from the list.
        my_size = 0;
      }
      
      unsigned size() const{ // Returns the length of the list.
        return my_size;
      }
      
      int& at(int loc){// Returns the element at position loc
                // 0-based, with negatives, -1 is last element
                // Throw exception if index is not correct
        if(loc >= (int)my_size || loc < -(int)my_size){
          throw logic_error("Index not valid");
        }
        if(loc < 0){
          return stuff[my_size + loc];
        }
        return stuff[loc];    
      }
                
      void push_back(int value){// Inserts value on the end of the list
        if(my_size >= SIZE){
          throw logic_error("List too large");
        }
        stuff[my_size] = value;
        my_size++;
      }
      
      void push_front(int value){// Inserts value at the beginning of the list
        if(my_size == 0){ // Empty list, just add it to the beginning
          push_back(value);
          return;
        }
        // Otherwise add an element to the end, shift all up
        push_back(stuff[my_size - 1]);
        // Shift everything up by 1
        for(unsigned i = my_size - 2; i >= 1; i--){
          stuff[i] = stuff[i-1];
        }
        // put on the beginning
        stuff[0] = value;
      }
      
      void remove(int loc){ // Removes the element at position loc
          // if loc is invalid, throw an error.  Allow negative indexes.
        if(loc >= (int)my_size || loc < -(int)my_size){
          throw logic_error("Index not valid");
        }
        if(loc < 0){
          loc = my_size + loc;
        }
        if(loc == 0 && my_size == 1){
          clear();
          return;
        }
        for(int i = loc; i < my_size - 1; i++){ // shift everything down 1
          stuff[i] = stuff[i + 1];
        }
        // remove the last element
        my_size--;
      }
      
      unsigned count(int value) const{ // Returns the number of times value
                // is in the list
        unsigned c = 0;
        for(unsigned i = 0; i < my_size; i++){
          if( stuff[i] == value) c++;
        }
        return c;
      }
                
      int location(int value) const{// Returns the index of the first occurance of value.
                // throw an exception if value does not exist in the list
        for(unsigned i = 0; i < my_size; i++){
          if(stuff[i] == value)return i;
        }
        throw logic_error("Value not foundd");
      }
      
      string getAsString() const{ // Returns a string of the list
        stringstream s;
        s << "[";
        for(unsigned i = 0; i < my_size; i++){
          if(i == my_size -1){
            s << stuff[i]; 
          }else{
            s << stuff[i] << ",";
          }
        }
        s << "]";
        return s.str();
      }
};

#endif