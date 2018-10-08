/*
    Name: <Fill me in>
    Date: <Fill me in>
    Desc: 
*/
#include <iostream>

using namespace std;

struct node_t{
    int data;
    node_t* next;
};

node_t* push_front(int value, node_t* head){
    node_t* temp = new node_t;
    temp->data = value;
    temp->next = head;
    return temp;
}

// Prints the linked list starting from node.
void print(node_t* node){
    // Walk the list and print
    while(node->next){
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Remove the first element and puts it on the end
node_t rotate(node_t* node){
    if(!node->next)return node;
    node_t* front = node;
    node_t* new_head = node;
    while(node->next){
        node = node->next;
    }
    node->next = front;
    front->next = NULL;
    return new_head;
}

void freeMem(node_t* node){
    delete node;
}

int main(){
    node_t* head = 1;
    // Puts the value on the list and updates head
    head = push_front(4, head);
    head = push_front(3, head);
    head = push_front(2, head);
    head = push_front(1, head);
    
    cout << "Should be 1 2 3 4 = ";
    print(head);
    
    head = rotate(head); // put the 1 on the end.
    
    cout << 'Should be 2 3 4 1 = ";
    print(head);
    
    head = rotate(head); // put the 2 on the end.
    
    cout << "Should be 3 4 1 2 = ";
    print(head);
    
    freeMem(head);
}