/*Task 3: Implement a Min Stack Modify your stack to support retrieving the minimum element in constant time without removing it.
 This will likely require additional storage within your stack structure to keep track of the minimum elements.*/

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

int top(Stack* stack) {
    if (stack->top == -1) {
        return EMPTY_STACK;
    }
    return stack->data[stack->top];
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

typedef struct MinStack {
    Stack mainStack;
    Stack minStack;
} MinStack;

void initMinStack(MinStack* minStack) {
    initStack(&minStack->mainStack);
    initStack(&minStack->minStack);
}

void pushMinStack(MinStack* minStack, int value) {
    push(&minStack->mainStack, value);
    if (isEmpty(&minStack->minStack) || value <= top(&minStack->minStack)) {
        push(&minStack->minStack, value);
    }
}
int popMinStack(MinStack* minStack) {
    int value = pop(&minStack->mainStack);
    if (value != EMPTY_STACK && value == top(&minStack->minStack)) {
        pop(&minStack->minStack);
    }
    return value;
}

int getMin(MinStack* minStack) {
    return top(&minStack->minStack);
}

int main() {
    MinStack minStack;
    initMinStack(&minStack);
    pushMinStack(&minStack, 9);
    pushMinStack(&minStack, 8);
    pushMinStack(&minStack, 19);

    printf("Minimum element after pushes: %d\n", getMin(&minStack));
    popMinStack(&minStack);
    printf("Minimum element after one pop: %d\n", getMin(&minStack));

    return 0;
}
