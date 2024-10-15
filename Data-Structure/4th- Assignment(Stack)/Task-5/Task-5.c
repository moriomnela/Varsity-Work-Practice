/*Task 5: Implement a Stack Using a Linked List Instead of using an array, implement your stack using a linked list.
This implementation should include the same push and pop operations.*/
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

    push(&stack, 12);
    push(&stack, 9);
    int popped = pop(&stack);
    if (popped != -1) {
        printf("Top element popped: %d\n", popped);
    }
    printStack(stack);

    return 0;
}

