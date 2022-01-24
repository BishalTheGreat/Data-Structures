#include<iostream>
using std::cin;
using std::cout;
using std::endl;

// Doubly linear linked list; Linked list is the connection of Nodes.
class SLLL{

    // Create node for the linked list
    class Node{
        public:
        int data;
        Node *next;
        Node *prev;
        Node(){
            next = NULL;
            prev = NULL;
        }
    };
    
    Node *start;

    public:
    void display();

    void push(int data=0);
    void insert(int data);
    void insert(int data, int postion);

    void pop();
    void remove();
    void remove(int position);
};

// Remove specific node between first and last
void SLLL::remove(int position){
    Node *temp = new Node();
    Node *p = new Node();
    p = start;
    while(position > 2){
        p = p->next;
        position--;
    }
    temp = p->next;
    temp->next->prev = p;
    p->next = temp->next;
    delete temp;
    cout<<"Removed!!"<<endl;
}

// Remove first node
void SLLL::remove(){
    Node *temp = new Node();
    temp = start;
    start = start->next;
    start->prev = NULL;
    delete temp;
    cout<<"Rmoved!!"<<endl;
}

// Remove last node
void SLLL::pop(){
    Node *temp = new Node();
    Node *p = new Node();
    p = start;
    while(p->next->next != NULL){
        p = p->next;
    }
    temp = p->next;
    p->next = NULL;
    delete temp;
    cout<<"Popped!!"<<endl;
}

// Insert new node at given position
void SLLL::insert(int data, int position){
    Node *temp = new Node();
    temp->data = data;
    Node *p = start;

    while(position > 2){
        p = p->next;
        position--;
    }
    p->next->prev = temp;
    temp->next = p->next;
    temp->prev = p;
    p->next = temp;
    cout<<"Inserted!!"<<endl;
}

// Insert new node at first
void SLLL::insert(int data){
    Node *temp = new Node();
    temp->data = data;
   
    if(start == NULL){
        start = temp;
    }
    else{
        temp->next = start;
        start->prev = temp;
        start = temp;

    }
    cout<<"Inserted!!"<<endl;
}

// Insert New Node at Last
void SLLL::push(int data){
    Node *temp = new Node();
    temp->data = data;
    
    Node *p = start;
    while(p->next != NULL){
        p = p->next;
    }
    temp->prev = p;
    p->next = temp;
    cout<<"Pushed!!"<<endl;
}

// Display Linked List
void SLLL::display(){
    Node *p = start;
    while(p->next != NULL){
        cout<<p->data<<" ----> ";
        p = p->next;
    }
    cout<<p->data<<endl;

    cout<<"Reverse:"<<endl;
    while(p->prev != NULL){
        cout<<p->data<<" <---- ";
        p = p->prev;
    }
    cout<<p->data<<endl;
}


int main(){

    SLLL *linked_list = new SLLL();
    linked_list->insert(50);
    linked_list->insert(6);
    linked_list->push(18);
    linked_list->insert(10, 3);
    linked_list->insert(11, 2);
    linked_list->push();

    cout<<"After Insertion:"<<endl;
    linked_list->display();

    linked_list->remove(3);
    linked_list->pop();
    linked_list->remove();
    cout<<"After Removed:"<<endl;
    linked_list->display();

    delete linked_list;
    return 0;
}