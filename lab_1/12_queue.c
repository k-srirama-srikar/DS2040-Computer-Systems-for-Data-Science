#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

typedef struct {
    int front, rear;
    int arr[MAX_SIZE];
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    return;
    }
    if (q->front == -1)
    q->front = 0;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->arr[q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
    printf("Queue is empty!\n");
    return -1;
    }
    int result = q->arr[q->front];
    if (q->front == q->rear) {
    // Only one element
    q->front = -1;
    q->rear = -1;
    } else {
    q->front = (q->front + 1) % MAX_SIZE;
    }
    return result;
}

int main(void) {
    Queue myQueue;
    initQueue(&myQueue);

    enqueue(&myQueue, 1);
    enqueue(&myQueue, 2);
    enqueue(&myQueue, 3);
    printf("Dequeued: %d\n", dequeue(&myQueue));
    printf("Dequeued: %d\n", dequeue(&myQueue));
    return 0;
}
