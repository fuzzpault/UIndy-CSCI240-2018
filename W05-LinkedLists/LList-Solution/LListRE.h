#ifndef LLISTRE_H
#define LLISTRE_H
/* Name: Paul Talaga
   Date: Sept 26, 2018
   Desc: Definition of a class to store and manipulate a list of integers.
         Internally uses a linked list
         Recursive solution.
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
class LListRE : public List{
    private:
      List_Node_t* head;
  
    public:
      LListRE(){
        head = NULL;
      };
      // Since dynamic memory is used (new), the copy constructor, assignment
      // operator, and destructor must all be implemented
      LListRE(const LListRE &other){ // Copy constructor
        head = duplicate(other.head);
      }
      
      ~LListRE(){ // Destructor
        clear();
        head = NULL;
      }
      
      LListRE& operator=(const LListRE &other){
        if(this == &other)return *this; // Don't clear if self assign.
        clear();
        head = duplicate(other.head);
        return *this;
      }
      
      void clear(){// Removes all elements from the list.
        // Return all nodes & sets head to NULL
        clear(head);
        head = NULL;
      }
      
      unsigned size() const{ // Returns the length of the list.
        return size(head); // Recursive version
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
        assert(loc >= 0);
        return at(loc, head);
      }
                
      void push_back(int value){// Inserts value on the end of the list
        // Create the node
        // If head is null, we have a problem, catch it here
        if(!head){
          head = new List_Node_t;
          head->data = value;
          head->next = NULL;
          return;
        }else{
          push_back(value, head);  // Recursive version
        }
      }
      
      void push_front(int value){// Inserts value at the beginning of the list
        // Create the node
        List_Node_t* temp = new List_Node_t; 
        temp->data = value;
        temp->next = head;
        head = temp;
      }
      
      void remove(int loc){ // Removes the element at position loc
        // if loc is invalid, throw an error.  Allow negative indexes.
        unsigned my_size = size();  // Valid index?
        if(loc >= (int)my_size || loc < -(int)my_size){
          throw logic_error("Index not valid");
        }
        if(loc < 0){
          loc = my_size + loc;
        }
        // If they want to remove location 0, we need to change head,
        // which is a special case, handle it here.
        if(loc == 0){
          List_Node_t* to_die = head;
          head = head->next;
          delete to_die;
          return;
        }
        remove(loc, head);
      }
      
      unsigned count(int value) const{ // Returns the number of times value
                // is in the list
        return count(value, head);
      }
                
      int location(int value) const{// Returns the index of the first occurance of value.
                // throw an exception if value does not exist in the list
        return location(value, 0, head);
      }
      
      string getAsString() const{ // Returns a string of the list
        return "[" + getAsString(head) + "]";
        stringstream s;
        s << "[";
        List_Node_t* curr = head;
        while(curr){
          if(!curr->next){
            s << curr->data; 
          }else{
            s << curr->data << ",";
          }
          curr = curr->next;
        }
        s << "]";
        return s.str();
      }
      
  private:
    unsigned size(List_Node_t* cur) const{ // Returns the length of the list.
        if(!cur)return 0;
        return 1 + size(cur->next);
    }
    
    unsigned count(int value, List_Node_t* cur) const{ 
        if(!cur)return 0;
        if(cur->data == value){
          return 1 + count(value, cur->next);
        }else{
          return count(value, cur->next);
        }
    }
    
    void push_back(int value, List_Node_t* cur){// Inserts value on the end of the list
        // Create the node
        assert(cur);
        if(! cur->next){// cur is last node
          cur->next = new List_Node_t;
          cur->next->data = value;
          cur->next->next = NULL;
        }else{
          push_back(value, cur->next);
        }
    }
    
    List_Node_t* duplicate(List_Node_t* cur){
      if(!cur)return NULL;
      List_Node_t* temp = new List_Node_t;
      temp->data = cur->data;
      temp->next = duplicate( cur->next );
      return temp;
    }
    
    int& at(int loc, List_Node_t* cur){
      if(loc == 0){
        return cur->data;
      }else{
        return at( loc - 1 , cur->next);
      }
    }
    
    int location(int value, int ndx, List_Node_t* cur) const{
      if(!cur){ // Detect if current pointer is null
        throw logic_error("Value not found");
      }
      if(value == cur->data){
        return ndx;
      }else{
        return location(value, ndx + 1, cur->next);
      }
    }
    
    void clear(List_Node_t* cur){
      if(!cur)return;
      clear(cur->next);
      delete cur;
    }
    
    void remove(int loc, List_Node_t* cur){
      if(!cur)return; //just in case, catch if we go off the end
      assert(loc > 0);
      if(loc <=1){ // stop one early to hop over the node we want to delete.
        List_Node_t* to_die = cur->next;
        cur->next = cur->next->next;
        delete to_die;
      }else{
        remove(loc - 1, cur->next);
      }
    }
    
    string getAsString(List_Node_t* cur) const{ // Returns a string of the list
      if(!cur)return "";
      stringstream s;
      s << cur->data;
      if(!cur->next){
        return s.str();
      }else{
        return s.str() + "," + getAsString(cur->next);
      }
    }
};

#endif