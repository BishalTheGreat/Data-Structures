# include <stdio.h>
# include <stdlib.h>

# define max 5

void push(int * tos, int* stack){
    if(*tos >= max-1){
        printf("Stack is full\n");
    }
    else{
        int el;
        printf("Enter element for push: ");
        scanf("%d", &el);
        stack[++(*tos)] = el;
        printf("Push completed !!\n");
    }
}

void pop(int* tos, int* stack){
    if(*tos <= -1){
        printf("Stack is empty\n");
    }
    else{
        int el;
        el = (stack[*tos]);
        --(*tos);
        printf("Poped element: %d\n", el);
    }
}

void display(int* tos, int* stack){
    printf("Elements in stack:\n");
    if(tos>=0){
        for(int i=0; i<=(*tos); i++){
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main(){
    int tos = -1;

    int stack[max];

    while(1){
    int choice;
    printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
    scanf("%d", &choice);
        switch(choice){
            case 1: push(&tos, &stack[0]);
                    break;

            case 2: pop(&tos, &stack[0]);
                    break;

            case 3:
                    display(&tos, &stack[0]); 
                    break;   

            case 4:
                    printf("Exiting...");
                    exit(0);
            default:
                    printf("Enter valid input !!\n");
        }
    }
    return 0;
}
