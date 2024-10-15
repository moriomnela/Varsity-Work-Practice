/*Task 4: Reverse a Queue Using a Stack
Implement a function that uses a stack to reverse a given
queue.*/

#include <stdio.h>
#include <stdlib.h>
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
return ((q1->rear + 1) % MAX_SIZE == q1->front);
}
int isEmpty(struct Queue* q1) {
return (q1->front == -1);
}
void enqueue(struct Queue* q1, int data) {
if (isFull(q1)) {
printf("Queue is full\n");
return;
}

if (isEmpty(q1)) {
q1->front = 0;
}
q1->rear = (q1->rear + 1) % MAX_SIZE;
q1->items[q1->rear] = data;
}
int dequeue(struct Queue* q1) {
if (isEmpty(q1)) {
printf("Queue is empty\n");
return -1;
}
int data = q1->items[q1->front];
if (q1->front == q1->rear) {
q1->front = q1->rear = -1;
} else {
q1->front = (q1->front + 1) % MAX_SIZE;
}
return data;
}
void display(struct Queue* q1) {
if (isEmpty(q1)) {
printf("Queue is empty\n");
return;
}
printf("Queue: ");
int i = q1->front;
while (1) {
printf("%d ", q1->items[i]);
if (i == q1->rear) {
break;
}

i = (i + 1) % MAX_SIZE;
}
printf("\n");
}
void reverseQueue(struct Queue* q1) {
if (isEmpty(q1)) {
return;
}
// Stack to hold queue elements
int stack[MAX_SIZE];
int top = -1;
// Dequeue all elements and push onto stack
while (!isEmpty(q1)) {
stack[++top] = dequeue(q1);
}
// Pop all elements from stack and enqueue back into the queue
while (top != -1) {
enqueue(q1, stack[top--]);
}
}
int main() {
struct Queue* q1 = createQueue();
// Sample input
enqueue(q1, 1);
enqueue(q1, 2);
enqueue(q1, 3);
enqueue(q1, 4);
printf("Original ");

display(q1);
reverseQueue(q1);
printf("Reversed ");
display(q1);
return 0;
}
