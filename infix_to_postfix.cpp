// Geting infix expression input from user and convert it into postfix expression using stack.

# include<iostream>
using std::cin;
using std::cout;
using std::endl;
# define max 20
int size;

char infix[max], pstfix[max], stak[max];
int tos = -1, p = -1;

// Inserting characters into stak

void push_stak(char ch){
    if(tos >= max-1){
        cout<<"Stack is full."<<endl;
    }
    else{
        ++tos;
        stak[tos] = ch;
        cout<<ch <<" pushed into stack completely."<<endl;
        cout<<"tos = "<<tos<<endl;
    }
}

// Returning or pop character from stak

char pop_stak(){
    char el;
    el = stak[tos];
    --tos;
    cout<<el <<" is poped from stack"<<endl;
    return(el);
}

// Inserting poerands and operators into postfix

void push_pstfix(char ch){
    if(p >= max-1){
        cout<<"Postfix stack is full."<<endl;
    }
    else{
        ++p;
        pstfix[p] = ch;
        cout<<ch <<" is added into postfix."<<endl;
        cout<<"p = "<<p<<endl;
    }
}

// Returning numbers for corresponding precedence of operators

int prec(char ch){
    if(ch == '-' || ch == '+'){
        return(1);
    }

    else if(ch == '*' || ch == '/'){
        return(2); 
    }

    else if(ch == '^' || ch == '$'){
        return(3);
    }

    else if(ch == '('){
        return(5);
    }

    else if(ch == ')'){
        return(6);
    }
    else
        return(11);
}

// Check either alphabet or not

bool ItemIsAlpha(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
        return true;
    }
    else{
        return false;
    }
}

// Check either number or not

bool ItemIsNum(char ch){
    if(ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9'){
        return true;
    }
    else{
        return false;
    }
}

// Check either operator or not

bool ItemIsOperator(char ch){
    if(ch == '-' || ch == '+' || ch == '*' || ch == '/' || ch == '^' || ch == '$'){
        return true;
    }
    else{
        return false;
    }
}

// Infix to postfix conversion

void InfixToPostfix(){
    int i=0;
    // Check for each character of infix expression
    while(infix[i] != '\0'){
        char item = infix[i];

        // If operands are present, push into postfix expression
        if(ItemIsAlpha(item) || ItemIsNum(item)){
            push_pstfix(item);
        }

        // If '(' is present, push into stack
        if(prec(item) == 5){
            push_stak(item);
        }

        // If ')' is present, pop upto '(' from stak and push into pstfix
        if(prec(item) == 6){
            char ppi;
            while(prec(stak[tos]) != 5){
                ppi = pop_stak();
                push_pstfix(ppi);
            }
            ppi = pop_stak();
            cout<<ppi<<" Discarded."<<endl;
        }

        // If opreators are present, Check tos of stak
        // If precedence of stack[tos] < precedence of item, push into stak
        // If precedence of stak[tos] >= precedence of item, 
            // pop[tos] and push into pstfix and repeat these operation, while(tos>-1 && prec(item) < prec(stak[tos]))
        if(ItemIsOperator(item)){
            if(prec(stak[tos]) == 5){
                push_stak(item);
            }
            else{
                char ppi;
                if(prec(item) > prec(stak[tos])){
                    push_stak(item);
                }
                else if(prec(stak[tos]) >= prec(item)){
                    while(tos > -1 && prec(stak[tos]) >= prec(item) && prec(stak[tos]) != 5){
                        ppi = pop_stak();
                        push_pstfix(ppi);
                    }
                    push_stak(item);
                }
            }
        }
        i++;
    }

    // Check if something store into stack and empty it.
    while(tos > -1){
        char ppi;
        ppi = pop_stak();
        push_pstfix(ppi);
    }
}

// Main function

int main(){
    cout<<"Enter infix expression:"<<endl;
    cin.getline(infix, 20);
    

    InfixToPostfix();

    cout<<"Operation completed!!"<<endl;
    cout<<"Your Infix Expression:"<<endl;
    for(int i=0; infix[i] !='\0'; i++){
        cout<<infix[i];
    }
    cout<<endl;

    cout<<"Converted Postfix Expression:"<<endl;
    for(int i=0; pstfix[i] != '\0'; i++){
        cout<<pstfix[i];
    }
    cout<<endl;
    return(0);
}