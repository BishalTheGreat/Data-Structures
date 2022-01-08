# include <iostream>
# include <stdlib.h>
using std::cin;
using std::cout;
using std::endl;
# define max 5

bool isFull(int * tos, int *stack){
	if(*tos >= max-1)
		return true;
	else
		return false;
}

bool isEmpty(int *tos, int *stack){
	if(*tos <= -1)
		return true;
	else
		return false;
}

void push(int * tos, int* stack){
    if(isFull(tos, stack)){
        cout<<"Stack is full"<<endl;
    }
    else{
        int el;
        cout<<"Enter element for push: ";
        cin>>el;
        stack[++(*tos)] = el;
        cout<<"Push completed !!"<<endl;
    }
}

void pop(int* tos, int* stack){
    if(isEmpty(tos, stack)){
        cout<<"Stack is empty"<<endl;
    }
    else{
        int el;
        el = (stack[*tos]);
        --(*tos);
        cout<<"Poped element: "<<el<<endl;
    }
}

void display(int* tos, int* stack){
	if(isEmpty(tos, stack))
		cout<<"Sorry, Stack is empty."<<endl;
	else{
		cout<<"Elements in stack:"<<endl;
    	if((*tos)>=0){
        	for(int i=0; i<=(*tos); i++){
            	cout<<stack[i]<<"  ";
       	 	}
        	cout<<endl;
    	}
	} 
}

int main(){
    int tos = -1;

    int stack[max];

    while(1){
    int choice;
    cout<<"\n1. Push\n2. Pop\n3. Display\n4. Exit\n"<<endl;
    cin>>choice;
        switch(choice){
            case 1: push(&tos, &stack[0]);
                    break;

            case 2: pop(&tos, &stack[0]);
                    break;

            case 3:
                    display(&tos, &stack[0]); 
                    break;   

            case 4:
                    cout<<"Exiting...";
                    exit(0);
            default:
                    cout<<"Enter valid input !!"<<endl;
        }
    }
    return 0;
}
