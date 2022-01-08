#! /bin/python3i
import sys

# Program that ask user to input infix expression and convert it into postfix.
# This can be implemented using stack data structure.
# Here built-in list data structure is useses for implementing stack

# Checking whether it is operator or not
def isOperator(op):
    if op =="-" or op =="+" or op =="*" or op =="/" or op =="^" or op =="$":
        return True
    else:
        return False

# Checking for operator precedence
def prec(op):
    if (op=="-" or op=="+"):
        return 1
    elif (op=="*" or op=="/"):
        return 2
    elif (op=="^" or op=="$"):
        return 3
    elif (op=="("):
        return 5
    elif (op==")"):
        return 6
    else:
        return 10

# Function for conversion
def toPostfix(infix):
    postfix = list()
    stack = list()

    # Looking for each elements
    for item in infix:
        # If operands direct push into postfix
        if (item.isalpha() or item.isnumeric()):
            postfix.append(item)
            print("{} is added into postfix".format(item))
        
        # If open bracket "(" then push into stack
        if (prec(item) == 5):
            stack.append(item)
            print(item, " pushed into stack")

        # If closed bracket ")" then pop all element from stack untill "(" appear
        if (prec(item) == 6):
            while (len(stack)>0 and prec(stack[-1]) != 5) :
                pp = stack[-1]
                stack.pop()
                print(pp + " is poped from stack")
                postfix.append(pp)
                print("{} is added into postfix".format( pp))
            stack.pop()

        """ If operators are present, check tos
        If prec of item is greater than push into stack,
        else if prec of stack[-1] is greater or equal than item,
        pop-tos, and push it into postfix, and repeat this command """
        
        if (isOperator(item)):
            if len(stack) == 0:
                stack.append(item)
                print("{} is pushed into stack".format(item))

            elif len(stack) >0:
                if prec(item) > prec(stack[-1]):
                    stack.append(item)
                    print(item, " is push into stack")

                elif prec(stack[-1]) >= prec(item):
                    while (len(stack) > 0 and prec(stack[-1]) != 5 and prec(stack[-1]) >= prec(item)) :
                        pp = stack[-1]
                        stack.pop()
                        print(pp + " is poped from stack")
                        postfix.append(pp)
                        print("{} is added into postfix".format( pp))

    # Empty stack and all push into postfix
    while stack:
        pp = stack[-1]
        stack.pop()
        print(pp + " is poped from stack")
        postfix.append(pp)
        print("{} is added into postfix".format( pp))

    return postfix

# Use main function to track the execution of code.
# But it is not necessary
if __name__== "__main__":
    # Exception Handeling
    try:
        infix = input("Enter infix Expression:\n")
    except KeyboardInterrupt:
        print("Exiting program...")
        sys.exit()
    postfix = toPostfix(infix)    #calling to function
   
    print("Infix Expression:")
    print(infix)
    print("Postfix Expression:")
    for i in postfix:
        print(i,end="")
    print("\n=== Operation Completed ===")
