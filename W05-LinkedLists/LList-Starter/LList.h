#ifndef LLIST_H
#define LLIST_H
/* Name: Paul Talaga
   Date: Sept 20, 2018
   Desc: Definition of a class
         to store and manipulate a list of integers.
         Internally uses a linked list
*/
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>

#include "List.h"

using namespace std;

// Definition of a node in the linked list.
struct List_Node_t{
  int data;
  List_Node_t* next;
};

// By subclassing of List, we verify we follow the required List interface.
class LList : public List{
    private:
      List_Node_t* head;
  
    public:
      LList(){
        head = NULL;
      };
      // Since dynamic memory is used (new), the copy constructor, assignment
      // operator, and destructor must all be implemented
      LList(const LList &other){ // Copy constructor
      
      }
      
      ~LList(){
        
      }
      
      LList& operator=(const LList &other){
        return *this;
      }
      
      void clear(){// Removes all elements from the list.
        // Return all nodes & sets head to NULL
      }
      
      unsigned size() const{ // Returns the length of the list.
        return 0;
      }
      
      int& at(int loc){// Returns the element at position loc
                // 0-based, with negatives, -1 is last element
                // Throw exception if index is not correct
      }
                
      void push_back(int value){// Inserts value on the end of the list
        // Create the node
      }
      
      void push_front(int value){// Inserts value at the beginning of the list
        // Create the node
      }
      
      void remove(int loc){ // Removes the element at position loc
          // if loc is invalid, throw an error.  Allow negative indexes.
      }
      
      unsigned count(int value) const{ // Returns the number of times value
                // is in the list
        return 0;
      }
                
      int location(int value) const{// Returns the index of the first occurance of value.
                // throw an exception if value does not exist in the list
        return 0;
      }
      
      string getAsString() const{ // Returns a string of the list
        return "Nothing here";
      }
};

#endif