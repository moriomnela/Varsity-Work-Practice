/*Task 2: Extended Doubly Linked List Operations*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void display(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.");
    } else {
        struct Node* ptr = head;
        printf("\nLinked list:");
        while (ptr != NULL) {
            printf(" %d", ptr->data);
            ptr = ptr->next;
        }
    }
}

struct Node* insert_beg(struct Node* head, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    temp->prev = NULL;

    if (head != NULL) {
        head->prev = temp;
    }
    head = temp;
    return head;
}

void insert_pos(struct Node* head, int data, int position) {
    struct Node* ptr = head;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;

    if (position == 1) {
        temp->next = head;
        temp->prev = NULL;
        if (head != NULL) {
            head->prev = temp;
        }
        head = temp;
        return;
    }

    position--;
    while (position != 1 && ptr != NULL) {
        ptr = ptr->next;
        position--;
    }

    if (ptr == NULL) {
        printf("Position exceeds the length of the list.\n");
        free(temp);
        return;
    }

    temp->next = ptr->next;
    temp->prev = ptr;
    if (ptr->next != NULL) {
        ptr->next->prev = temp;
    }
    ptr->next = temp;
}

void del_pos(struct Node** head, int position) {
    if (*head == NULL) {
        printf("Linked list is empty");
        return;
    }

    struct Node* current = *head;

    if (position == 1) {
        *head = current->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(current);
        return;
    }

    while (position != 1 && current != NULL) {
        current = current->next;
        position--;
    }

    if (current == NULL) {
        printf("Position exceeds the length of the list.\n");
        return;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }

    free(current);
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 5;
    head->prev = NULL;
    head->next = NULL;

    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = 10;
    newnode->prev = head;
    newnode->next = NULL;
    head->next = newnode;

    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = 15;
    newnode->prev = head->next;
    newnode->next = NULL;
    head->next->next = newnode;

    display(head);

    printf("\n\nInserting 25 after 10");
    insert_pos(head, 25, 3);
    display(head);

    printf("\n\nDeleting the node with value 10");
    del_pos(&head, 2);
    display(head);

    printf("\n\nInserting 20 at position 2");
    insert_pos(head, 20, 3);
    display(head);

    printf("\n\nDeleting the node at position 3");
    del_pos(&head, 4);
    display(head);

    // Free allocated memory to avoid memory leak
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
