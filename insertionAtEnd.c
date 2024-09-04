#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * next ;
};

void transversalList(struct node* ptr){
    while(ptr!=NULL){
        printf("Element found :%d\n", ptr->data);
        ptr=ptr->next;
    }
}

struct node * insertAtLast(struct node * head , int data ){
    struct node * ptr = (struct node *) malloc (sizeof(struct node));
     ptr->data= data;
    struct node * p = head ;
   


    while(p->next!=NULL){
        p= p->next;
      }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}


int main(){
    struct node * head; 
    struct node * second;
    struct node * third ;
    struct node * fourth ;

    head = (struct node *) malloc (sizeof(struct node));
    second = (struct node*)malloc (sizeof(struct node));
    third = (struct node*)malloc (sizeof(struct node));
    fourth = (struct node* )malloc(sizeof(struct node));

    head->data = 10;
    head->next=second;

    second->data = 20;
    second->next=third ;

    third->data = 30;
    third->next = fourth ;

    fourth->data = 40;
    fourth ->next = NULL;

    printf("LinkedList before Insertion \n");
    transversalList(head);
    head = insertAtLast(head,99);
    printf("\nLinkedList after insertion \n");
    transversalList(head);

    return 0 ;


}