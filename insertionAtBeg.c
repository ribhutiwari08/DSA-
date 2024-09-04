#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next ;
};

struct node * insertAtBeg(struct node * head , int data ){
    struct node *ptr = (struct node *) malloc (sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr ; 
}

void linklistTraversal(struct node* ptr){
    while(ptr!=NULL){
        printf("Element Found %d\n" , ptr->data);
        ptr=ptr->next;

    }
}

int main(){
    struct node * head;
    struct node * second;
    struct node * third ;
    struct node * fourth ;


    head = (struct node *)malloc (sizeof(struct node));
    second = (struct node *)malloc (sizeof(struct node));
    third = (struct node *)malloc (sizeof(struct node));
    fourth= (struct node *)malloc (sizeof(struct node));


    head->data=7;
    head->next =second;

    second->data = 11;
    second->next = third ;

    third->data = 15;
    third->next = fourth;

    fourth->data = 20;
    fourth->next=NULL;
    printf("LinkedList before insertion \n");
    linklistTraversal(head);
    head = insertAtBeg(head , 111);
    printf("\nLinkedList after insertion \n");
    linklistTraversal(head);
    return 0;


}