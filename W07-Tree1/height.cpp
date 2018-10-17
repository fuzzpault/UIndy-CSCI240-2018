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

bool find(node_t* node, int value, int depth_so_far){
    if(!node){
        cout << "Element " << value << " not found, depth " << depth_so_far << endl;
        return false;
    }
    if(node->data == value){
        cout << "Found " << value << " at depth " << depth_so_far << endl;
        return true;
    }
    if(value < node->data){
        return find(node->left, value, depth_so_far + 1);
    }else{
        return find(node->right, value, depth_so_far + 1);
    }
}

int depth(node_t* node, int value, int depth_so_far){
    if(!node){
        //cout << "Element " << value << " not found, depth " << depth_so_far << endl;
        return depth_so_far;
    }
    if(node->data == value){
        //cout << "Found " << value << " at depth " << depth_so_far << endl;
        return depth_so_far;
    }
    if(value < node->data){
        return depth(node->left, value, depth_so_far + 1);
    }else{
        return depth(node->right, value, depth_so_far + 1);
    }
}

int height(node_t* node){
    if(!node)return 0;
    int left = height(node->left);
    int right = height(node->right);
    if(left > right){
        return left + 1;
    }else{
        return right + 1;
    }
}

int count(node_t* node){
    if(!node)return 0;
    return count(node->left) + count(node->right) + 1;
}

int main(){
    node_t* root = new node_t;
    root->data = 50;
    root->left = NULL;
    root->right = NULL;
    
    insert(45, root);
    insert(30, root);
    insert(46, root);
    
    cout << "height: " << height(root) - 1 << endl;
    cout << "count: " << count(root) << endl;
    return 0;
    
    for(int i = 0; i < 100; i++){
        insert(rand() % 100, root);
        //insert(i, root);
    }
    
    int total_depth = 0;
    for(int i = 0; i < 1000; i++){
        total_depth += depth(root, rand() % 1000, 0);
    }
    cout << "Avg depth: " << total_depth / 1000.0 << endl;
}