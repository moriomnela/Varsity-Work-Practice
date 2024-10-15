/*Task 1: Basic Queue Operations
Define a queue structure that can hold integer values.
Implement functions to perform basic operation*/

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
int main() {
struct Queue* q1 = createQueue();
enqueue(q1, 5);
enqueue(q1, 10);
printf("Front element dequeued: %d\n", dequeue(q1));
printf("Current Queue: ");
while (!isEmpty(q1)) {
printf("%d ", dequeue(q1));
}

return 0;
}
