/*Task 4
Implement a function to check if a linked list contains a cycle.*/

#include<stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Node* new_Node(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* mergeTwoLists(struct Node* head1, struct Node* head2) {

    if (!head1) return head2;
    if (!head2) return head1;

    struct Node dummy;
    struct Node* tail = &dummy;

    while (head1 && head2) {
        if (head1->data < head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    tail->next = head1 ? head1 : head2;

    return dummy.next;
}

void displayList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {

    struct Node* list1 = new_Node(5);
    list1->next = new_Node(10);

    struct Node* list2 = new_Node(7);
    list2->next = new_Node(12);


    printf("Two sorted singly linked lists:\n");
    displayList(list1);
    displayList(list2);

	struct Node* result = mergeTwoLists(list1, list2);
	printf("\nAfter merging the said two sorted lists:\n");
    displayList(result);

    return 0;
}

