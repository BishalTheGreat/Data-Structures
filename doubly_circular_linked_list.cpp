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
    Node *p = start;
    while(p->next != start)
        p = p->next;
    temp = start;
    start = start->next;
    p->next = start;
    start->prev = p;
    delete temp;
    cout<<"Rmoved!!"<<endl;
}

// Remove last node
void SLLL::pop(){
    Node *temp = new Node();
    Node *p = new Node();
    p = start;
    while(p->next->next != start){
        p = p->next;
    }
    temp = p->next;
    p->next = start;
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
        start->next = start;
    }
    else{
        Node *p = start;
        while(p->next != start)
            p = p->next;
        p->next = temp;
        temp->prev = p;
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
    while(p->next != start){
        p = p->next;
    }
    temp->prev = p;
    p->next = temp;
    temp->next = start;
    start->prev = temp;
    cout<<"Pushed!!"<<endl;
}

// Display Linked List
void SLLL::display(){
    Node *p = start;
    // To check circular works or not, display twice
    for(int i=0; i<2; i++){
        while(p->next != start){
            cout<<p->data<<" ----> ";
            p = p->next;
        }
        cout<<p->data<<endl;

        // To check doubly works or not, display reversly
        cout<<"Reverse:"<<endl;
        while(p != start){
            cout<<p->data<<" <---- ";
            p = p->prev;
        }
        cout<<p->data<<endl;
    }
}


int main(){

    SLLL *linked_list = new SLLL();
    linked_list->insert(50);
    linked_list->insert(26);
    linked_list->push(18);
    linked_list->insert(101, 2);
    linked_list->insert(111, 3);
    linked_list->push();

    cout<<"\nAfter Insertion:"<<endl;
    linked_list->display();

    linked_list->remove(3);
    linked_list->pop();
    linked_list->remove();
    cout<<"\nAfter Removed:"<<endl;
    linked_list->display();

    delete linked_list;
    return 0;
}