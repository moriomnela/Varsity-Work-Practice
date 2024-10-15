/*Task 7: Reverse the First K Elements of a Queue
Implement a function to reverse the first K elements of a
queue, leaving the other elements in their original order.*/
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
return (q1->front == -1 && q1->rear == -1);
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
int data;
if (isEmpty(q1)) {
printf("Queue is empty\n");
return -1;
} else if (q1->front == q1->rear) {
data = q1->items[q1->front];
q1->front = q1->rear = -1;
} else {
data = q1->items[q1->front];
q1->front++;
}
return data;
}
// Function to reverse the first K elements of the queue
void reverseFirstK(struct Queue* q1, int k) {

if (isEmpty(q1) || k > (q1->rear - q1->front + 1) || k <= 0) {
printf("Invalid input\n");
return;
}
int stack[k];
int i, temp;
// Step 1: Dequeue first K elements and push them onto the stack
for (i = 0; i < k; i++) {
stack[i] = dequeue(q1);
}
// Step 2: Pop from stack and enqueue back to the queue
for (i = k - 1; i >= 0; i--) {
enqueue(q1, stack[i]);
}
// Step 3: Move the rest of the elements to the back of the queue
int remaining = q1->rear - q1->front + 1 - k;
for (i = 0; i < remaining; i++) {
temp = dequeue(q1);
enqueue(q1, temp);
}
}
int main() {
struct Queue* q1 = createQueue();
// Sample Input: [1, 2, 3, 4, 5]
enqueue(q1, 1);
enqueue(q1, 2);
enqueue(q1, 3);
enqueue(q1, 4);
enqueue(q1, 5);

int k = 3;
reverseFirstK(q1, k);
// Output the modified queue
printf("Modified Queue: ");
while (!isEmpty(q1)) {
printf("%d ", dequeue(q1));
}
return 0;
}
