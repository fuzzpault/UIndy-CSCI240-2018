#ifndef VLIST_H
#define VLIST_H
/* Name: Paul Talaga
   Date: Sept 19, 2018
   Desc: Definition of a class
         to store and manipulate a list of integers.
         Internally uses a vector.
*/
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <stdexcept>

#include "List.h"

using namespace std;

// By subclassing of List, we verify we follow the required List interface.
class VList : public List{
    private:
      vector<int> stuff;
  
    public:
      VList(){};
      //List(const List&){}; // Copy constructor not needed, no new
      //virtual ~List(){};  // Not needed, no new
      
      void clear(){// Removes all elements from the list.
        stuff.clear();
      }
      
      unsigned size() const{ // Returns the length of the list.
        return stuff.size();
      }
      
      int& at(int loc){// Returns the element at position loc
                // 0-based, with negatives, -1 is last element
                // Throw exception if index is not correct
        if(loc >= (int)stuff.size() || loc < -(int)(stuff.size())){
          throw logic_error("Index not valid");
        }
        if(loc < 0){
          return stuff[stuff.size() + loc];
        }
        return stuff[loc];    
      }
                
      void push_back(int value){// Inserts value on the end of the list
        stuff.push_back(value);
      }
      
      void push_front(int value){// Inserts value at the beginning of the list
        if(stuff.size() == 0){ // Empty list, just add it to the beginning
          stuff.push_back(value);
          return;
        }
        // Otherwise add an element to the end, shift all up
        stuff.push_back(stuff[stuff.size() - 1]);
        // Shift everything up by 1
        for(unsigned i = stuff.size() - 2; i >= 1; i--){
          stuff[i] = stuff[i-1];
        }
        // put on the beginning
        stuff[0] = value;
      }
      
      void remove(int loc){ // Removes the element at position loc
          // if loc is invalid, throw an error.  Allow negative indexes.
        if(loc >= (int)stuff.size() || loc < -(int)(stuff.size())){
          throw logic_error("Index not valid");
        }
        if(loc < 0){
          loc = stuff.size() + loc;
        }
        if(loc == 0 && stuff.size() == 1){
          stuff.clear();
          return;
        }
        for(int i = loc; i < stuff.size() - 1; i++){ // shift everything down 1
          stuff[i] = stuff[i + 1];
        }
        // remove the last element
        stuff.erase(stuff.begin() + stuff.size() - 1);
      }
      
      unsigned count(int value) const{ // Returns the number of times value
                // is in the list
        unsigned c = 0;
        for(unsigned i = 0; i < stuff.size(); i++){
          if( stuff[i] == value) c++;
        }
        return c;
      }
                
      int location(int value) const{// Returns the index of the first occurance of value.
                // throw an exception if value does not exist in the list
        for(unsigned i = 0; i < stuff.size(); i++){
          if(stuff[i] == value)return i;
        }
        throw logic_error("Value not foundd");
      }
      
      string getAsString() const{ // Returns a string of the list
        stringstream s;
        s << "[";
        for(unsigned i = 0; i < stuff.size(); i++){
          if(i == stuff.size() -1){
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