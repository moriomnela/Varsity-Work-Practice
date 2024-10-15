/*Task 3: Implement a Circular Queue
Modify your queue to support circular behavior, where
elements can be dequeued from the front and enqueued
at the back, and vice versa, without shifting all elements.
*/
#define MAX_SIZE 100
struct CircularQueue {
int items[MAX_SIZE];
int front;
int rear;
};
struct CircularQueue* createCircularQueue() {
struct CircularQueue* q = (struct CircularQueue*)malloc(sizeof(struct
CircularQueue));
q->front = -1;
q->rear = -1;
return q;
}
int isCircularFull(struct CircularQueue* q) {
return ((q->rear + 1) % MAX_SIZE == q->front);
}
int isCircularEmpty(struct CircularQueue* q) {
return (q->front == -1);
}
void circularEnqueue(struct CircularQueue* q, int data) {
if (isCircularFull(q)) {
printf("Circular Queue is full\n");
return;
} else if (isCircularEmpty(q)) {
q->front = q->rear = 0;
} else {

q->rear = (q->rear + 1) % MAX_SIZE;
}
q->items[q->rear] = data;
}
int circularDequeue(struct CircularQueue* q) {
if (isCircularEmpty(q)) {
printf("Circular Queue is empty\n");
return -1;
}
int data = q->items[q->front];
if (q->front == q->rear) {
q->front = q->rear = -1;
} else {
q->front = (q->front + 1) % MAX_SIZE;
}
return data;
}
int main() {
struct CircularQueue* q = createCircularQueue();
circularEnqueue(q, 1);
circularEnqueue(q, 2);
circularDequeue(q);
circularEnqueue(q, 3);
circularDequeue(q);
circularEnqueue(q, 4);
printf("Current Circular Queue: ");
while (!isCircularEmpty(q)) {
printf("%d ", circularDequeue(q));
}
return 0;
}
