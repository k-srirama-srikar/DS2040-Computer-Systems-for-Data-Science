#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertAtHead(struct Node **head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
    }
    printf("NULL\n");
}

int main(void) {
    struct Node *head = NULL;

    insertAtHead(&head, 30);
    insertAtHead(&head, 20);
    insertAtHead(&head, 10);

    printList(head);
    return 0;
}