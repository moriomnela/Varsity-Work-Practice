/*Task 1: Basic Stack Operations Define a stack structure that can hold integer values.Implement functions to perform basic operations:*/



#include <stdio.h>
#include <stdlib.h>

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


void printStack(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Current Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 15);
    push(&stack, 20);
    printStack(&stack);

    int topElement = pop(&stack);
    if (topElement != EMPTY_STACK) {
        printf("Top element popped: %d\n", topElement);
    }
    printStack(&stack);

    return 0;
}
