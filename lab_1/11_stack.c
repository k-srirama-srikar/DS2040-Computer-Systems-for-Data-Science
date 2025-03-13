#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
typedef struct {
    int top;
    int arr[MAX_SIZE];
} Stack;
void initStack(Stack *s) {s->top = -1;}

int isFull(Stack *s) {return s->top == MAX_SIZE - 1;}

int isEmpty(Stack *s) {return s->top == -1;}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
    printf("Stack underflow!\n");
    return -1;
    }
    return s->arr[(s->top)--];
}

int main(void) {
    Stack myStack;
    initStack(&myStack);
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    printf("Popped: %d\n", pop(&myStack));
    printf("Popped: %d\n", pop(&myStack));
    return 0;
}