/*Task 7: Sort a Stack Implement a function to sort a stack such that the smallest items are on the top. You may use an additional temporary stack,
 but you should not copy the elements into any other data structure (e.g., array).*/

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
int peek(Node* top) {
    if (isEmpty(top)) {
        return -1;
    }
    return top->data;
}

void sortStack(Node** stack) {
    Node* tempStack = NULL;

    while (!isEmpty(*stack)) {
        int temp = pop(stack);
        while (!isEmpty(tempStack) && peek(tempStack) > temp) {
            push(stack, pop(&tempStack));
        }
        push(&tempStack, temp);
    }
    while (!isEmpty(tempStack)) {
        push(stack, pop(&tempStack));
    }
}
void printStack(Node* top) {
    printf("Sorted Stack: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}
int main() {
    Node* stack = NULL;

    push(&stack, 3);
    push(&stack, 1);
    push(&stack, 4);
    push(&stack, 2);

    sortStack(&stack);
    printStack(stack);
    return 0;
}

