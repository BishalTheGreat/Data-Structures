#include<iostream>
#include<stdlib.h>
#define max 10
using std::cin;
using std::cout;
using std::endl;
class Queue{
    int rear;
    int front;
    int content[max], data;
    public:
        Queue(){
            rear = front = -1;
        }
        void Enqueue();
        void Dequeue();
        bool isFull();
        bool isEmpty();
        void Display();
};

bool Queue::isFull(){
    if((rear+1)%max == front)
        return true;
    else
        return false;
}

bool Queue::isEmpty(){
    if(front == -1 and rear == -1)
        return true;
    else
        return false;
}

void Queue::Enqueue(){
    if(isFull()){
        cout<<"Queue is Full"<<endl;
    }
    else{
        cout<<"Enter element to insert: ";
        cin>>data;
        if(isEmpty()){
            ++front;
            ++rear;
            content[rear] = data;
        }
        else{
            rear = (rear+1)%max;
            content[rear] = data;
        }
    }
}

void Queue::Dequeue(){
    if(isEmpty()){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        if(front == rear){
            data = content[front];
            rear = front = -1;
        }
        else{
            data = content[front];
            front = (front+1)%max;
        }
        cout<<"Dequeued element: "<<data<<endl;
    }
}

void Queue::Display(){
    if(isEmpty()){
        cout<<"Nothing to Display."<<endl;
    }
    else{
    cout<<"Elements in Queue..."<<endl;
    if(rear >= front){
        for(int i=front; i<=rear; i++){
            cout<<content[i]<<"  ";
        }
    }
    else{
        for(int i=front; i<max; i++)
            cout<<content[i]<<"  ";
        for(int j=0; j<=rear; j++)
            cout<<content[j]<<"  ";
    }
    cout<<endl;
    }
}

int main(){
    int choice;
    class Queue q;
    while(1){
        cout<<"\n***** Operations *****\n\
            1. Enqueue\n\
            2. Dequeue\n\
            3. Display\n\
            4. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1: q.Enqueue();
                    break;
            case 2: q.Dequeue();
                    break;
            case 3: q.Display();
                    break;
            case 4: cout<<"Exiting..."<<endl;
                    exit(1);
            default: cout<<"Enter valid option!!!"<<endl;
        }
    }
    return 0;
}
