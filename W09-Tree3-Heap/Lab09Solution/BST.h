#ifndef BST_H
#define BST_H
/* Name: Paul Talaga
   Date: Oct 16, 2018
   Desc: Binary search tree
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

// Convenience print function
void myprint(Node_t* node, unsigned level, const string &prefix);

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
    
    // Lab/HW 09
    
    string getMin()const{
        if(!root)throw logic_error("Empty tree");
        return getMin(root);
    }
    
    string getMax()const{
        if(!root)throw logic_error("Empty tree");
        return getMax(root);
    }
    
    bool remove(const string &value){
        if( !find(value) )return false;
        // Special case where removing the root node because root will need
        // to change.
        if(root->data == value){  // removing root
            if(!root->left && !root->right){ // single node
                delete root;
                root = NULL;
                return true;
            }else if(!root->left && root->right){ // No left child, bring right up
                Node_t* to_die = root;
                root = root->right;
                delete to_die;
                return true;
            }else if(!root->right && root->left){ // No right child, bring left up.
                Node_t* to_die = root;
                root = root->left;
                delete to_die;
                return true;
            }else{ // Two children, UG!
                // Find the smallest on the right and delete it.
                // Then change this node's value with that min
                string min = getMin(root->right);
                remove(root, min);
                root->data = min;
                return true;
            }
        }else{ // Not the root, let remove handle it!
            return remove(root, value);
        }
    }
    
    void print(const string &s){
        cout << endl;
        myprint(root, 0, s);
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
    
    // Lab/HW 09
    
    string getMin(Node_t* node)const{
        assert(node); // Should never have gotten this far!
        if(!node->left){
            return node->data;
        }
        return getMin(node->left);
    }
    
    string getMax(Node_t* node)const{
        assert(node); // Should never have gotten this far!
        if(!node->right){
            return node->data;
        }
        return getMax(node->right);
    }
    
    bool remove(Node_t* node,const string &value){
        assert(node);  // Bad pointer
        assert(!(node->data == value)); // No way of fixing what points to me!
        if(node->left && node->left->data == value){ // remove my left child!
            if(!node->left->left && !node->left->right){ // single node
                delete node->left;
                node->left = NULL;
                return true;
            }else if(!node->left->left && node->left->right){ // No left child, bring right up
                Node_t* to_die = node->left;
                node->left = node->left->right;
                delete to_die;
                return true;
            }else if(!node->left->right && node->left->left){ // No right child, bring left up.
                Node_t* to_die = node->left;
                node->left = node->left->left;
                delete to_die;
                return true;
            }else{ // Two children, UG!
                // Find the smallest on the right and delete it.
                // Then change this node's value with that min
                string min = getMin(node->left->right);
                remove(node->left, min);
                node->left->data = min;
                return true;
            }
        }else if(node->right && node->right->data == value){ // remove my right child!
            if(!node->right->left && !node->right->right){ // single node
                delete node->right;
                node->right = NULL;
                return true;
            }else if(!node->right->left && node->right->right){ // No left child, bring right up
                Node_t* to_die = node->right;
                node->right = node->right->right;
                delete to_die;
                return true;
            }else if(!node->right->right && node->right->left){ // No right child, bring left up.
                Node_t* to_die = node->right;
                node->right = node->right->left;
                delete to_die;
                return true;
            }else{ // Two children, UG!
                // Find the smallest on the right and delete it.
                // Then change this node's value with that min
                string min = getMin(node->right->right);
                remove(node->right, min);
                node->right->data = min;
                return true;
            }
        }else if(value <= node->data){ // Go left
            return remove(node->left, value);
        }else{ // Go right
            return remove(node->right, value);
        }
    }
    
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

#endif

