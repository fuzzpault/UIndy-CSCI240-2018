#ifndef BST_H
#define BST_H
/* Name: Paul Talaga
   Date: Oct 16, 2018
   Desc: Binary search tree - with balancing
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

// Give this a node and a level of 0 and it will print
// a sideways tree with the root at the far left.
// Useful for checking BST shape.
void myprint(Node_t* node, unsigned level, const string &prefix){
    if(!node)return;
    myprint(node->right, level + 1, prefix);
    // print the value, but indent
    cout << prefix << " :";
    for(unsigned i = 0; i < level * 2; i++){
        cout << "  ";
    }
    cout << node->data << endl;
    myprint(node->left, level + 1, prefix);
}

class BST{
    private:
      Node_t* root;
  
    public:
    
    BST(){
      root = NULL;
    }
  
    ~BST(){
        clear(root);
        root = NULL;
    }
  
    BST(const BST &other){
      root = duplicate(other.root);
    }
    
    BST& operator=(const BST &other){
        if(this == &other)return *this;
        clear(root);
        root = duplicate(other.root);
        return *this;
    }
  
    // Insert word into the BST
    void insert(const string &word){
        if(!root){
            root = new Node_t;
            root->data = word;
            root->left = NULL;
            root->right = NULL;
        }else{
            insert(word, root);
        }
    }
  
    // Number of nodes in the BST
    unsigned size()const{
        return size(root);
    }
    
    // The height of the tree (number of edges on longest path)
    unsigned height()const{
        if(!root)return 0;
        return height(root) - 1;
    }
    
    // Preorder traversal of the tree
    string preOrderTraversal()const{
        return preOrderTraversal(root);
    }
    
    // Postorder traversal of the tree
    string inOrderTraversal()const{
        return inOrderTraversal(root);
    }
    
    // Returns true if that value is stored, false otherwise
    bool find(const string &value)const{
        return find(root, value);
    }
    
    // Returns true if the tree is balanced, false otherwise
    // For all nodes, the number of nodes to the right and to the left
    // differ by at most 1.
    bool isBalanced()const{
        return isBalanced(root);
    }
    
    void rotateRootRight(){
        rotateRight(root);
    }
    
    void rotateRootLeft(){
        rotateLeft(root);
    }
    
    void balance(){
        balance(root);
    }
    
    void print(){
        cout << endl;
        myprint(root, 0, "");
        cout << endl;
    }
    
    private:
    
    // Recursive functions
    unsigned size(Node_t* n)const{
        if(!n)return 0;
        return size(n->left) + size(n->right) + 1;
    }
    
    void insert(const string &value, Node_t* node){
        assert(node);
        if(value <= node->data){
            if(node->left){
                insert(value, node->left);
            }else{
                node->left = new Node_t;
                node->left->data = value;
                node->left->left = NULL;
                node->left->right = NULL;
            }
        }else{
            if(node->right){
                insert(value, node->right);
            }else{
                node->right = new Node_t;
                node->right->data = value;
                node->right->left = NULL;
                node->right->right = NULL;
            }
        }
        return;
    }
    
    void clear(Node_t* n){
        if(!n)return;
        clear(n->left);
        clear(n->right);
        delete n;
    }
    
    bool find(Node_t* node,const string &value)const{
        if(!node){
            return false;
        }
        if(node->data == value){
            return true;
        }
        if(value < node->data){
            return find(node->left, value);
        }else{
            return find(node->right, value);
        }
    }
    
    unsigned height(Node_t* n)const{
        if(!n)return 0;
        // Return the max of the two branches
        unsigned left = height(n->left);
        unsigned right = height(n->right);
        return max(left,right) + 1;
    }
    
    bool isBalanced(Node_t* node)const{
        if(!node)return true;
        if(!isBalanced(node->left))return false;
        if(!isBalanced(node->right))return false;
        unsigned left = height(node->left);
        unsigned right = height(node->right);
        if(left < right){
            return right - left <= 1;
        }else{
            return left - right <= 1;
        }
    }
    
    string preOrderTraversal(Node_t* node)const{
        if(!node) return "";
        stringstream s;
        s << node->data;
        return s.str() + " " + preOrderTraversal(node->left) + preOrderTraversal(node->right);
    }
    
     string inOrderTraversal(Node_t* node)const{
        if(!node) return "";
        stringstream s;
        s << node->data;
        return inOrderTraversal(node->left) + " " + s.str() + " " + inOrderTraversal(node->right);
    }
    
    // Walk the 'other' tree and duplicate as you go.
    Node_t* duplicate(Node_t* other){
        if(!other)return NULL;
        Node_t* ret = new Node_t;
        ret->data = other->data;
        ret->right = duplicate(other->right);
        ret->left = duplicate(other->left);
        return ret;
    }
    
    // HW 09
    
    // For a rotation, we'll move pointers and data.  To fix the problem 
    // of changing the parent's pointer, we'll just copy the data and change
    // the pointers rather than move the given node.
    void rotateRight(Node_t* node){
        if(!node || !node->left)return; // Can't rotate
        // Get the subtrees
        Node_t* lower_node = node->left;
        Node_t* a = node->left->left;
        Node_t* b = node->left->right;
        Node_t* c = node->right;
        // switch the data in node and left;
        string temp = node->data;
        node->data = node->left->data;
        lower_node->data = temp;
        node->right = lower_node;
        lower_node->right = c;
        lower_node->left = b;
        node->left = a;
    }
    
    void rotateLeft(Node_t* node){
        if(!node || !node->right)return; // Can't rotate
        // Get the subtrees
        Node_t* lower_node = node->right;
        Node_t* c = node->right->right;
        Node_t* b = node->right->left;
        Node_t* a = node->left;
        // switch the data in node and left;
        string temp = node->data;
        node->data = lower_node->data;
        lower_node->data = temp;
        node->left = lower_node;
        lower_node->left = a;
        lower_node->right = b;
        node->right = c;
    }
    
    void balance(Node_t* node){
        if(!node)return;
        // Find which side has more and rotate until they have about the same
        unsigned left_size = size(node->left);
        unsigned right_size = size(node->right);
        for(unsigned i = left_size; i < right_size; i += 2){
            // only move half the difference
            rotateLeft(node);
        }
        for(unsigned i = right_size; i < left_size; i += 2){
            // only move half the difference
            rotateRight(node);
        }
        // Now go down each size
        balance(node->left);
        balance(node->right);
    }
    
};

#endif

