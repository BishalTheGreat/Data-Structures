#include<iostream>
using std::cin;
using std::cout;
using std::endl;

// Singly linear linked list; Linked list is the connection of Nodes.
class SLLL{

    // Create node for the linked list
    class Node{
        public:
        int data;
        Node *next;
        Node(){
            next = NULL;
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
    p->next = temp->next;
    delete temp;
    cout<<"Removed!!"<<endl;
}

// Remove first node
void SLLL::remove(){
    Node *temp = new Node();
    temp = start;
    start = start->next;
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
    temp->next = p->next;
    p->next = temp;
    cout<<"Inserted!!"<<endl;
}

// Insert new node at first
void SLLL::insert(int data){
    Node *temp = new Node();
    temp->data = data;
    temp->next = start;
    start = temp;
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
    p->next = temp;
    cout<<"Pushed!!"<<endl;
}

// Display Linked List
void SLLL::display(){
    Node *p = start;
    while(p->next != NULL){
        cout<<p->data<<endl;
        p = p->next;
    }
    cout<<p->data<<endl;
}


int main(){

    SLLL *linked_list = new SLLL();
    linked_list->insert(5);
    linked_list->insert(6);
    linked_list->push(8);
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