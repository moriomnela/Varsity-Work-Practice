/*Task 2
Extend your linked list operations. Implement functions to insert a node after a specific value or at a given position and to
delete nodes with a given value or at a given position.*/


#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void display(struct node* head){
    if(head==NULL){
        printf("Linked list is empty.");
    }else{
        struct node* ptr = head;
        printf("\nLinked list:");
        while(ptr!=NULL){
            printf(" %d", ptr->data);
            ptr = ptr->next;
        }
    }
}
 struct node* insert_beg(struct node* head, int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    temp->next = head;
    head = temp;
    return head;
}

void insert_pos(struct node *head, int data, int position){
    struct node* ptr = head;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    position--;
    while(position!=1){
        ptr=ptr->next;
        position--;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}

void del_pos(struct node** head, int position){
    struct node* current = *head;
    struct node* previous = *head;
    if(*head==NULL){
        printf("Linked list is empty");
    }else if(position==1){
        *head = current->next;
        free(current);
        current=NULL;
    }else{
        while(position!=1){
            previous=current;
            current=current->next;
            position--;
        }
        previous->next=current->next;
        free(current);
        current=NULL;
    }
}
int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = 5;
    head->next = NULL;

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = 10;
    newnode->next = NULL;
    head->next = newnode;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = 15;
    newnode->next = NULL;
    head->next->next = newnode;

    display(head);

    printf("\n\nInserting 25 after 10");
    insert_pos(head, 25, 3);
    display(head);

    printf("\n\nDeleting the node with value 10");
    del_pos(&head,2);
    display(head);

    printf("\n\nInserting 20 at position 2");
    insert_pos(head, 20, 3);
    display(head);

    printf("\n\nDeleting the node at position 3");
    del_pos(&head,4);
    display(head);
    return 0;
}
