#ifndef LLISTIT_H
#define LLISTIT_H
/* Name: Paul Talaga
   Date: Sept 20, 2018
   Desc: Definition of a class to store and manipulate a list of integers.
         Internally uses a linked list
         Iterative solution (loops).
*/
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>

#include "List.h"

using namespace std;

struct List_Node_t{
  int data;
  List_Node_t* next;
};

// By subclassing of List, we verify we follow the required List interface.
class LListIT : public List{
    private:
      List_Node_t* head;
  
    public:
      LListIT(){
        head = NULL;
      };
      // Since dynamic memory is used (new), the copy constructor, assignment
      // operator, and destructor must all be implemented
      LListIT(const LListIT &other){ // Copy constructor
        // Pointer to to walk down other
        List_Node_t* cur_other = other.head;
        // Pointer to keep track of the last node, to tack them on.
        List_Node_t* last = NULL;
        head = NULL;
        while(cur_other){
          List_Node_t* temp = new List_Node_t;
          temp->data = cur_other->data;
          temp->next = NULL;
          if(last)last->next = temp;
          if(!head)head = temp;
          last = temp;
          cur_other = cur_other->next;
        }   
      }
      
      ~LListIT(){
        clear();
      }
      
      LListIT& operator=(const LListIT &other){
        // Verify I'm not other
        if(this == &other) return *this;
        // Wipe the current data
        clear();
        // Copy everything from other
        List_Node_t* cur_other = other.head;
        List_Node_t* last = NULL;
        head = NULL;
        while(cur_other){
          List_Node_t* temp = new List_Node_t;
          temp->data = cur_other->data;
          temp->next = NULL;
          if(last)last->next = temp;
          if(!head)head = temp;
          last = temp;
          cur_other = cur_other->next;
        }
        return *this;
      }
      
      void clear(){// Removes all elements from the list.
        // Return all nodes & sets head to NULL
        List_Node_t* cur = head;
        head = NULL;
        while(cur){
          List_Node_t* temp = cur;
          cur = cur->next;
          delete temp;
        }
      }
      
      unsigned size() const{ // Returns the length of the list.
        // Walk the list!
        List_Node_t* cur = head;
        unsigned count = 0;
        while(cur){ // When cur becomes NULL (0, false) stop counting
          cur = cur->next;
          count++;
        }
        return count;
      }
      
      int& at(int loc){// Returns the element at position loc
                // 0-based, with negatives, -1 is last element
                // Throw exception if index is not correct
        unsigned my_size = size();
        if(loc >= (int)my_size || loc < -(int)my_size){
          throw logic_error("Index not valid");
        }
        if(loc < 0){
          loc = my_size + loc;
        }
        // Now walk and count
        List_Node_t* cur = head;
        unsigned count = 0;
        while(cur && loc > 0){ // When cur becomes NULL (0, false) stop counting
          cur = cur->next;
          loc--;
        }
        if(!cur)throw logic_error("Unknown error");
        return cur->data;   
      }
                
      void push_back(int value){// Inserts value on the end of the list
        // Create the node
        List_Node_t* temp = new List_Node_t;
        temp->data = value;
        temp->next = NULL;
        // Verify head isn't null
        if(!head){ // Note NULL is 0, which is false!
          head = temp;
          return;
        }
        // Walk to the end
        List_Node_t* cur = head;
        // We need to stop ONE EARLY
        while(cur->next){
          cur = cur->next;
        }
        // So cur->next should be null, so cur must be the last element
        // Tack on temp onto it!
        cur->next = temp;
      }
      
      void push_front(int value){// Inserts value at the beginning of the list
        // Create the node
        List_Node_t* temp = new List_Node_t;
        temp->data = value;
        temp->next = head; // Have it point to the current head (ok if null)
        // fix head
        head = temp;
      }
      
      void remove(int loc){ // Removes the element at position loc
          // if loc is invalid, throw an error.  Allow negative indexes.
        unsigned my_size = size();
        if(loc >= (int)my_size || loc < -(int)my_size){
          throw logic_error("Index not valid");
        }
        if(loc < 0){
          loc = my_size + loc;
        }
        assert(loc >= 0);
        if(loc == 0 && my_size == 1){
          clear();
          return;
        }
        // Special case where we remove loc=0 as head needs fixing
        if(loc == 0){
          List_Node_t* temp = head;
          head = head->next;
          delete temp;
          return;
        }
        // The trick is we need to stop ONE early to fix the pointers
        // Walk and count
        List_Node_t* cur = head;
        unsigned count = 0;
        while(cur && loc > 1){ // When cur becomes NULL (0, false) stop counting
          // or we are 1 away
          cur = cur->next;
          loc--;
        }
        assert(cur);
        assert(cur->next);
        // Cur is a node BEFORE the one to remove, save the node to remove
        List_Node_t* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
      }
      
      unsigned count(int value) const{ // Returns the number of times value
                // is in the list
        unsigned c = 0;
        // Walk to the end
        List_Node_t* cur = head;
        while(cur){
          if( cur->data == value)c++;
          cur = cur->next;
        }
        return c;
      }
                
      int location(int value) const{// Returns the index of the first occurance of value.
                // throw an exception if value does not exist in the list
        unsigned c = 0;
        // Walk to the end
        List_Node_t* cur = head;
        while(cur){
          if( cur->data == value)return c;
          cur = cur->next;
          c++;
        }
        throw logic_error("Value not foundd");
      }
      
      string getAsString() const{ // Returns a string of the list
        stringstream s;
        s << "[";
        List_Node_t* cur = head;
        while(cur){
          if( cur->next ){ // Not last
            s << cur->data << ",";
          }else{ // Last element
            s << cur->data;
          }
          cur = cur->next;
        }
        s << "]";
        return s.str();
      }
};

#endif