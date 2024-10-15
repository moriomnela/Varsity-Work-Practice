/*Task 1: Basic Doubly Linked List Structure.*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;


typedef struct DoublyLinkedList {
    Node* head;
    Node* tail;
} DoublyLinkedList;


Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}


void add_to_beginning(DoublyLinkedList* list, int value) {
    Node* new_node = create_node(value);
    if (list->head == NULL) {
        list->head = list->tail = new_node;
    } else {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }
}

void add_to_end(DoublyLinkedList* list, int value) {
    Node* new_node = create_node(value);
    if (list->tail == NULL) {
        list->head = list->tail = new_node;
    } else {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void print_list(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d", current->value);
        if (current->next != NULL) {
            printf(" <-> ");
        }
        current = current->next;
    }
    printf("\n");
}


int main() {
    DoublyLinkedList list;
    list.head = NULL;
    list.tail = NULL;

    add_to_beginning(&list, 5);
    add_to_end(&list, 10);
    add_to_end(&list, 15);

    printf("Linked List: ");
    print_list(&list);

    return 0;
}
