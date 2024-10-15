/*Task 5: Implement a Priority Queue
Extend your queue to support priority enqueueing, where
each element has a priority
associated with it, and elements are dequeued based on
their priority.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct Element {
int data;
int priority;
};
struct Queue {
struct Element items[MAX_SIZE];
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
return (q1->front == -1 && q1->rear == -1);
}
void enqueue(struct Queue* q1, int data, int priority) {
if (isFull(q1)) {
printf("Queue is full\n");
return;
}
struct Element newElement;
newElement.data = data;
newElement.priority = priority;
if (isEmpty(q1)) {
q1->front = q1->rear = 0;
q1->items[q1->rear] = newElement;
} else {
// Insert the element according to its priority
int i;
for (i = q1->rear; i >= q1->front; i--) {
if (q1->items[i].priority >= priority) {
q1->items[i + 1] = q1->items[i];

} else {
break;
}
}
q1->items[i + 1] = newElement;
q1->rear++;
}
}
struct Element dequeue(struct Queue* q1) {
struct Element data;
if (isEmpty(q1)) {
printf("Queue is empty\n");
data.data = -1;
data.priority = -1;
return data;
} else if (q1->front == q1->rear) {
data = q1->items[q1->front];
q1->front = q1->rear = -1;
} else {
data = q1->items[q1->front];
q1->front++;
}
return data;
}
int main() {
struct Queue* q1 = createQueue();
// Sample Input: Enqueue (3, High Priority), Enqueue (5, Low Priority),
//Enqueue (2, Medium Priority)
enqueue(q1, 3, 3); // High Priority
enqueue(q1, 5, 1); // Low Priority
enqueue(q1, 2, 2); // Medium Priority

// Dequeue and print
struct Element deqElement = dequeue(q1);
printf("Dequeued Element: (%d, Priority %d)\n", deqElement.data,
deqElement.priority);
return 0;
}
