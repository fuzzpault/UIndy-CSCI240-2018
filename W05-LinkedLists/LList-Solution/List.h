#ifndef LIST_H
#define LIST_H
/*
    Pure virtual List class.
*/

#include <string>

using namespace std;

class List{
    public:
      List(){};
      List(const List&){}; // Copy constructor
      
      virtual ~List(){};
      
      virtual void clear() = 0; // Removes all elements from the list.
      
      virtual unsigned size() const = 0; // Returns the length of the list.
      
      virtual int& at(int loc) = 0; // Returns the element at position loc
                // 0-based, with negatives, -1 is last element
                
      virtual void push_back(int value) = 0; // Inserts value on the end of the list
      
      virtual void push_front(int value) = 0; // Inserts value at the beginning of the list
      
      virtual void remove(int loc) = 0; // Removes the element at position loc
      
      virtual unsigned count(int value) const = 0; // Returns the number of times value
                // is in the list
                
      virtual int location(int value) const = 0; // Returns the index of the first occurance of value.
                // Throw an exception if value does not exist in the list
      
      virtual string getAsString() const = 0; // Returns a string of the list
};

#endif