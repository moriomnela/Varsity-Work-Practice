/*Task 4: Reverse a String Using a Stack Implement a function that uses a stack to reverse a given string.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int top;
    char items[MAX];
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char item) {
    if (isFull(s)) {
        printf("Stack is full!\n");
        return;
    }
    s->items[++s->top] = item;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return '\0';
    }
    return s->items[s->top--];
}

void reverseString(char *str) {
    Stack s;
    initialize(&s);

    for (int i = 0; str[i] != '\0'; i++) {
        push(&s, str[i]);
    }
    for (int i = 0; !isEmpty(&s); i++) {
        str[i] = pop(&s);
    }
}

int main() {
    char str[] = "Bangladesh";
    printf("Original string: %s\n", str);

    reverseString(str);
    printf("Reversed string: %s\n", str);

    return 0;
}

