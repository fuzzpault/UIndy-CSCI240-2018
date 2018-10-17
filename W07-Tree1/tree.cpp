#include <iostream>
#include <cstdlib>

using namespace std;

struct node_t{
    int data;
    node_t* left;
    node_t* right;
};

void insert(int value, node_t* node){
    if(!node){
        cout << "I got a null node!" << endl;
    }
    if(value <= node->data){
        if(node->left){
            insert(value, node->left);
        }else{
            node->left = new node_t;
            node->left->data = value;
            node->left->left = NULL;
            node->left->right = NULL;
        }
    }else{
        if(node->right){
            insert(value, node->right);
        }else{
            node->right = new node_t;
            node->right->data = value;
            node->right->left = NULL;
            node->right->right = NULL;
        }
    }
    return;
}

void pre(node_t* node){
    if(!node)return;
    cout << node->data << " ";
    pre(node->left);
    pre(node->right);
}

void inorder(node_t* node){
    if(!node)return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main(){
    node_t* root = new node_t;
    root->data = 5;
    root->left = NULL;
    root->right = NULL;
    
    insert(3, root);
    insert(10, root);
    for(int i = 0; i < 10; i++){
        insert(rand() % 100, root);
    }
    
    pre(root);
    cout << endl;
    inorder(root);
}