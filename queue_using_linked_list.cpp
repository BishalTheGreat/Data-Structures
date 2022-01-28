// Dynamic queue using linked list

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

    void Enqueue(string data);
    void Dequeue();
};

// Insert New Node at Last
void SLLL::Enqueue(string data){
    Node *temp = new Node();
    temp->data = data;
    
    Node *p = start;

    // If queue is empty new node will be first else add to last
    if(start==NULL){
        start = temp;
    }
    else{
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    cout<<data<<" is Enqueued!!"<<endl;
}

// Remove first node to dequeue
void SLLL::Dequeue(){
    Node *temp = new Node();
    Node *p = new Node();
    p = start;
    
    // If queue is empty
    if (p==NULL){
        cout<<"Queue is empty!"<<endl;
    }
   
    // More than one data
    else{
        temp = start;
        start = start->next;
        cout<<temp->data<<" is Dequeued!!"<<endl;
        delete temp;
    }
}

// Display Queue
void SLLL::display(){
    Node *p = start;

    // If empty queue display it is empty
    if (p==NULL){
        cout<<"Queue is empty!"<<endl;
    }
    else{
        cout<<"Queue: "<<endl;
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
    string data;
    cout<<"\n***** Operations *****\n\
            1. Enqueue\n\
            2. Dequeue\n\
            3. Display\n\
            4. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1: cout<<"Enter Data to Enqueue:  ";
                    cin>>data;
                    stack->Enqueue(data);
                    break;

            case 2: stack->Dequeue();
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