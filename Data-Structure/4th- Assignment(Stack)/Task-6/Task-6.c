/*Task 6: Design a Stack that Supports Increment Operations Design a stack that supports the following operations:*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(Node* top) {
    return top == NULL;
}

void push(Node** top, int data) {
    Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d onto the stack\n", data);
}

int pop(Node** top) {
    if (isEmpty(*top)) {
        printf("Stack is empty!\n");
        return -1;
    }
    Node* temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedData;
}

void increment(Node* top, int k, int val) {
    Node* current = top;
    int count = 0;

    while (current != NULL) {
        count++;
        current = current->next;
    }
    if (k > count) {
        k = count;
    }

    current = top;
    for (int i = 0; i < count - k; i++) {
        current = current->next;
    }

    while (current != NULL) {
        current->data += val;
        current = current->next;
    }
}
void printStack(Node* top) {
    printf("Current Stack: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    Node* stack = NULL;

    push(&stack, 10);
    push(&stack, 5);
    push(&stack, 7);

    increment(stack, 2, 1);
    printf("Current Stack after incrementing bottom 2 elements: ");
    printStack(stack);

    int popped = pop(&stack);
    if (popped != -1) {
        printf("Top element popped: %d\n", popped);
    }
    printStack(stack);

    return 0;
}


