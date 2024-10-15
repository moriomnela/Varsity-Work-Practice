/*Task 2: Checking for Balanced Parentheses Extend your stack operations to include a function that checks if a given string of parentheses is balanced.
A string is balanced if each open parenthesis is matched with a closing parenthesis in the correct order.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define EMPTY_STACK -1

typedef struct Stack {
    int data[MAX];
    int top;
} Stack;


void initStack(Stack* stack) {
    stack->top = -1;
}

void push(Stack* stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return EMPTY_STACK;
    }
    return stack->data[stack->top--];
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isBalanced(char* expression) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < strlen(expression); i++) {
        if (expression[i] == '(') {
            push(&stack, '(');
        } else if (expression[i] == ')') {
            if (isEmpty(&stack)) {
                return 0;
            }
            pop(&stack);
        }
    }
    return isEmpty(&stack);
}

int main() {
    char expression[MAX];

    printf("Enter a string of parentheses to check if it is balanced: ");
    scanf("%s", expression);

    if (isBalanced(expression)) {
        printf("Is balanced: Yes\n");
    } else {
        printf("Is balanced: No\n");
    }

    return 0;
}
