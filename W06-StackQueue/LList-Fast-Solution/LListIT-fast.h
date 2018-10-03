#ifndef LLIST_IT_FAST_H
#define LLIST_IT_FAST_H
/* Name: Paul Talaga
   Date: Sept 20, 2018
   Desc: Definition of a class to store and manipulate a list of integers.
         Internally uses a linked list
         Iterative solution (loops).
         Stores size speed: 2ms
*/
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cassert>
#include <cmath>

#include "List.h"

using namespace std;

struct List_Node_t{
  int data;
  List_Node_t* next;
  List_Node_t* prev;
};

// By subclassing of List, we verify we follow the required List interface.
class LListIT : public List{
    private:
      List_Node_t* head;
      List_Node_t* tail;
      unsigned my_size;
      
      unsigned last_at_loc;
      List_Node_t* last_at_ptr;
  
    public:
      LListIT(){
        head = NULL;
        tail = NULL;
        my_size = 0;
        // Somewhat pointless to set last_at when nothing is in the list
        // Need to make sure it isn't used until there is something in the list
        last_at_loc = 0;
        last_at_ptr = NULL; // Signifies this is not valid
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
          temp->prev = last;
          if(last)last->next = temp;
          if(!head)head = temp;
          last = temp;
          cur_other = cur_other->next;
        }   
        tail = last;
        my_size = other.my_size;
        last_at_loc = 0;
        last_at_ptr = NULL;
      }
      
      ~LListIT(){
        clear();
      }
      
      LListIT& operator=(const LListIT &other){
        // Verify I'm not other
        if(this == &other) return *this;
        // Wipe the current data
        clear();
        List_Node_t* cur_other = other.head;
        // Pointer to keep track of the last node, to tack them on.
        List_Node_t* last = NULL;
        head = NULL;
        while(cur_other){
          List_Node_t* temp = new List_Node_t;
          temp->data = cur_other->data;
          temp->next = NULL;
          temp->prev = last;
          if(last)last->next = temp;
          if(!head)head = temp;
          last = temp;
          cur_other = cur_other->next;
        }   
        tail = last;
        my_size = other.my_size;
        last_at_loc = 0;
        last_at_ptr = NULL;
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
        my_size = 0;
        last_at_loc = 0;
        last_at_ptr = NULL;
      }
      
      unsigned size() const{ // Returns the length of the list.
        // Used the saved variable rather than walking the list.
        return my_size;
      }
      
      int& at(int loc){// Returns the element at position loc
                // 0-based, with negatives, -1 is last element
                // Throw exception if index is not correct
        List_Node_t* node = getNodeFromNdx(loc);
        return node->data;
      }
                
      void push_back(int value){// Inserts value on the end of the list
        my_size++;
        // Create the node
        List_Node_t* temp = new List_Node_t;
        temp->data = value;
        temp->next = NULL;
        temp->prev = NULL;
        // Verify head isn't null
        if(!head){ // Note NULL is 0, which is false!
          head = temp;
          tail = temp;
          return;
        }
        
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
        // Last_at is OK if set
      }
      
      void push_front(int value){// Inserts value at the beginning of the list
        
        my_size++;
        // Create the node
        List_Node_t* temp = new List_Node_t;
        temp->data = value;
        temp->next = head; // Have it point to the current head (ok if null)
        temp->prev = NULL;
        if(head)head->prev = temp;
        // fix head
        head = temp;
        if(!tail)tail = temp;
        // All indexes will change, so disable last_at
        last_at_loc =0;
        last_at_ptr = NULL;
      }
      
      void remove(int loc){ // Removes the element at position loc
          // if loc is invalid, throw an error.  Allow negative indexes.
        // Since this is bi-directional, we can find the exact node
        // and go left and right to fix the pointers.
        List_Node_t* node = getNodeFromNdx(loc);
        
        if(!node->prev){ // removing the first node!
          head = node->next;
          if(head)head->prev = NULL; // Just in case only 1 node
        }
        if(!node->next){ // removing the last node!
          tail = node->prev;
          if(tail)tail->next = NULL;  // Just in case only 1 node
        }
        if(node->next && node->prev){// in the middle
          node->prev->next = node->next;
          node->next->prev = node->prev;
        }
        delete node;
        my_size--;
        last_at_loc = 0;
        last_at_ptr = NULL; // Disable last_at.  May be OK based on position?.
        return;
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
      
      
    private:
    
      List_Node_t* getNodeFromNdx(int loc){
        // Convenience function to get to a node as fast as possible
        if(loc >= (int)my_size || loc < -(int)my_size){
          throw logic_error("Index not valid");
        }
        if(loc < 0){
          loc = my_size + loc;
        }
        assert(loc >= 0);
        // Which side to start from?
        // 4 options: 
        //   1. go up from head
        //   2. go down from tail
        //   3. go up from last_at (if valid pointer)
        //   4. go down from last_at (if valid pointer)
        int one = loc;
        int two = (int)my_size - loc - 1;
        int middle = last_at_loc - loc;
        int three = last_at_ptr? abs(middle): one + 10;
        // The one + 10 will garuntee one will win over three or four, or
        // last_at_pointer is NULL (false)
        //cout << "loc:" << loc << " last_at_loc:" << last_at_loc << " end:" << my_size << endl;
        //cout << one << "  " << two << "  " << three << " " << middle << endl;
        last_at_loc = loc;
        if(0 || (one <= two && one < three)){
          //cout << "Up From start" << endl;
          // Now walk and count
          List_Node_t* cur = head;
          while(cur && loc > 0){ // When cur becomes NULL (0, false) stop counting
            cur = cur->next;
            loc--;
          }
          if(!cur)throw logic_error("Unknown error - up from start");
          last_at_ptr = cur;
          return cur;
        }else if(two <= one && two <= three){
          //cout << "Down from tail" << endl;
          // Now walk and count
          List_Node_t* cur = tail;
          loc = two;
          while(cur && loc > 0){ // When cur becomes NULL (0, false) stop counting
            cur = cur->prev;
            loc--;
          }
          if(!cur)throw logic_error("Unknown error - down from tail");
          last_at_ptr = cur;
          return cur;
        }else if(three < one && three <= two && middle > 0){
          //cout << "Down from last" << endl;
          List_Node_t* cur = last_at_ptr;
          loc = three;
          while(cur && loc > 0){ // When cur becomes NULL (0, false) stop counting
            cur = cur->prev;
            loc--;
          }
          if(!cur)throw logic_error("Unknown error - down from last");
          last_at_ptr = cur;
          return cur;
        }else{
          //cout << "Up from last" << endl;
          List_Node_t* cur = last_at_ptr;
          loc = three;
          while(cur && loc > 0){ // When cur becomes NULL (0, false) stop counting
            cur = cur->next;
            loc--;
          }
          if(!cur)throw logic_error("Unknown error - up from last");
          last_at_ptr = cur;
          return cur;
        }
        
      }
};

#endif