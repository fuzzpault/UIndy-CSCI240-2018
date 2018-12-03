#ifndef HASHTABLE_H
#define HASHTABLE_H
/* Name: // Fill me in
   Date: Dec 3, 2018
   Desc: Hash table implementation
*/
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cassert>
#include <vector>

using namespace std;

struct TableEntry_t{
    string thing;
    bool stored;
};


class HashTable{
    private:
      // Fill me in
    vector<TableEntry_t> table;
    unsigned my_size;
  
    public:
    
    HashTable(){
        my_size = 0;
        table = vector<TableEntry_t>(20);
        for(unsigned i = 0; i < 20; i++){
            table[i].stored = false;
            table[i].thing = "";
        }
    }
    
    unsigned size() const{
        return my_size;
    }
    
    float loadFactor() const{
        unsigned count = 0;
        for(unsigned i = 0; i < table.size(); i++){
            if(table[i].stored)count++;
        }
        return (float)count / (float)table.size();
    }
    
    void insert(const string &thing){
        unsigned loc = myHash(thing) % table.size();
        if(table[loc].stored && table[loc].thing == thing)return; // Already there!
        unsigned loop_start = loc;
        while(table[loc].stored){
            loc++;
            loc = loc % table.size();
            if(loc == loop_start){
                cout << "Table is full!" << endl;
                return;  // Can't be stored, table full!
            }
        }
        table[loc].stored = true;
        table[loc].thing = thing;
        my_size++;
    }
    
    bool contains(const string &thing) const{
        unsigned loc = myHash(thing) % table.size();
        unsigned loop_start = loc;
        while(table[loc].stored){
            if(table[loc].thing == thing)return true;
            loc++;
            loc = loc % table.size();
            if(loc == loop_start)return false;  // Can't be found, table full!
        }
        return false;
    }
    
    void remove(const string &thing){
        // Fill me in.
    }
    
    private:
    
    unsigned myHash(const string &thing) const{
        unsigned c = 0;
        for(unsigned i = 0; i < thing.length(); i++){
            c = c + thing[i];
        }
        return c;
    }
    
};

#endif

