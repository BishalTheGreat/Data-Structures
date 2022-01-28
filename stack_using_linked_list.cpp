// Stack implementation using singly linear linked list, also called Dynamin Stack

#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

// Singly linear linked list; Linked list is the connection of Nodes.
class SLLL{

    // Create node for the linked list
    class Node{
        public:
        string data;
        Node *next;
        Node(){
            next = NULL;
        }
    };
    
    Node *start;

    public:
    void display();

    void push(string data);
    void pop();
};

// Insert New Node at Last
void SLLL::push(string data){
    Node *temp = new Node();
    temp->data = data;
    
    Node *p = start;

    // If stack is empty new node will be first else qdd to last
    if(start==NULL){
        start = temp;
    }
    else{
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    cout<<data<<" is Pushed!!"<<endl;
}

// Remove last node
void SLLL::pop(){
    Node *temp = new Node();
    Node *p = new Node();
    p = start;
    
    // If stack is empty
    if (p==NULL){
        cout<<"stack is empty!"<<endl;
    }

    // If only one data item in stack
    else if(start->next == NULL){
        temp = start;
        cout<<temp->data<<" is Popped!!"<<endl;
        start = NULL;
        delete temp;
    }
   
    // More than one data
    else{
        while(p->next->next != NULL){
            p = p->next;
        }
        temp = p->next;
        p->next = NULL;
        cout<<temp->data<<" is Popped!!"<<endl;
        delete temp;
    }
}

// Display Stack
void SLLL::display(){
    Node *p = start;

    // If empty stack display it is empty
    if (p==NULL){
        cout<<"stack is empty!"<<endl;
    }
    else{
        cout<<"Stack: "<<endl;
        cout<<"-------------------"<<endl;
        while(p->next != NULL){
            cout<<p->data<<"\t";
            p = p->next;
        }
        cout<<p->data<<endl;
    }
}

int main(){
    SLLL *stack = new SLLL();
    while(1){
    int choice;
    cout<<"\n1. Push\n2. Pop\n3. Display\n4. Exit\n"<<endl;
    string data;
    cin>>choice;
        switch(choice){
            case 1: cout<<"Enter Data to Push:  ";
                    cin>>data;
                    stack->push(data);
                    break;

            case 2: stack->pop();
                    break;

            case 3:
                    stack->display(); 
                    break;   

            case 4:
                    cout<<"Exiting..."<<endl;
                    exit(0);
            default:
                    cout<<"Enter valid input !!"<<endl;
        }
    }
    delete stack;
    return 0;
}