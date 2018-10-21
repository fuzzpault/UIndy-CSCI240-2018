#ifndef BST_H
#define BST_H
/* Name: // Fill me in
   Date: Oct 16, 2018
   Desc: Binary search tree class to store strings
*/
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cassert>

using namespace std;

// Definition of a node 
struct Node_t{
  string data;
  Node_t* left;
  Node_t* right;
};

class BST{
    private:
      // Fill me in
  
    public:
    
    BST(){
      // Fill me in
    }
  
    ~BST(){
        // Fill me in
    }
  
    BST(const BST &other){
       // fill me in
    }
    
    BST& operator=(const BST &other){
        // Fill me in
        return *this;
    }
  
    // Insert word into the BST
    void insert(const string &word){
        // Fill me in
    }
  
    // Number of nodes in the BST
    unsigned size()const{
        // Fill me in
        return 0;
    }
    
    // The height of the tree (number of edges on longest path)
    unsigned height()const{
        // Fill me in
        return 0;
    }
    
    // Preorder traversal of the tree
    // Just separate elements with a space, no []
    string preOrderTraversal()const{
        // Fill me in
    }
    
    // Postorder traversal of the tree
    // Just separate elements with a space, no []
    string inOrderTraversal()const{
        // Fill me in
    }
    
    // Returns true if that value is stored, false otherwise
    bool find(const string &value)const{
        // Fill me in
        return false;
    }
    
    // Returns true if the tree is balanced, false otherwise
    // For all nodes, the number of nodes to the right and to the left
    // differ by at most 1.
    bool isBalanced()const{
        // Fill me in
        return false;
    }
    
    private:
    
    // Fill me in
    
};

#endif

