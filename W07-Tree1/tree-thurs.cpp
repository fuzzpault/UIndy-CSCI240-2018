#include <iostream>

using namespace std;

struct tree_t{
  int value;
  tree_t* left;
  tree_t* right;
};

void insert(tree_t* node, int value){
    if(!node){
        cout << "Bad news" << endl;
        return;
    }
    if(value <= node->value){
        // go left!
        if(node->left){
            insert(node->left, value);
        }else{  // tack on a new node!
            node->left = new tree_t;
            node->left->value = value;
            node->left->left = NULL;
            node->left->right = NULL;
        }
    }else{
        // go right!
        if(node->right){
            insert(node->right, value);
        }else{  // tack on a new node!
            node->right = new tree_t;
            node->right->value = value;
            node->right->left = NULL;
            node->right->right = NULL;
        }
    }
}

bool find(tree_t* node, int value){
    if(!node){
        return false;
    }
    if(value == node->value){
        return true;
    }else if(value < node->value){
        // go left!
        return find(node->left, value);
    }else{
        // go right!
        return find(node->right, value);
    }
}

int size(tree_t* node){
    if(!node)return 0;
    return size(node->left) + size(node->right) + 1;
}

void preOrder(tree_t* node){
    if(!node)return;
    cout << node->value << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(tree_t* node){
    if(!node)return;
    inOrder(node->left);
    cout << node->value << " ";
    inOrder(node->right);
}


int main(){
    tree_t* root = new tree_t;
    root->value = 56;
    root->left = NULL;
    root->right = NULL;
    
    insert(root, 5);
    insert(root, 15);
    insert(root, 57);
    
    cout << "Preorder: ";
    preOrder(root);
    
    cout << endl << "Inorder: ";
    inOrder(root);
    
    cout << endl << "5 is in there: " << find(root, 5) << endl;
    
    cout << "There are " << size(root) << " nodes in the tree." << endl;
}