/*Task 2: Checking for Palindrome
Extend your queue operations to include a function that
checks if a given string is a palindrome. A string is a
palindrome if it reads the same backward as forward.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
struct Queue {
int items[MAX_SIZE];
int front;
int rear;
};
struct Queue* createQueue() {
struct Queue* q1 = (struct Queue*)malloc(sizeof(struct Queue));
q1->front = -1;
q1->rear = -1;
return q1;
}
int isFull(struct Queue* q1) {
return (q1->rear == MAX_SIZE - 1);
}
int isEmpty(struct Queue* q1) {

return (q1->front == -1);
}
void enqueue(struct Queue* q1, int data) {
if (isFull(q1)) {
printf("Queue is full\n");
return;
} else if (isEmpty(q1)) {
q1->front = q1->rear = 0;
} else {
q1->rear++;
}
q1->items[q1->rear] = data;
}
int dequeue(struct Queue* q1) {
if (isEmpty(q1)) {
printf("Queue is empty\n");
return -1;
} else {
int data = q1->items[q1->front];
if (q1->front == q1->rear) {
q1->front = q1->rear = -1;
} else {
q1->front++;
}
return data;
}
}
int isPalindrome(char* str) {
int length = strlen(str);
struct Queue* q1 = createQueue();
char stack[MAX_SIZE];
int top = -1;

// Enqueue all characters to queue and push to stack
for (int i = 0; i < length; i++) {
enqueue(q1, str[i]);
stack[++top] = str[i];
}
// Compare elements from queue and stack
while (!isEmpty(q1)) {
char queueChar = dequeue(q1);
char stackChar = stack[top--];
if (queueChar != stackChar) {
return 0;
}
}
return 1;
}
int main() {
char str[] = "radar";
if (isPalindrome(str)) {
printf("Is palindrome: Yes\n");
} else {
printf("Is palindrome: No\n");
}
return 0;
}
