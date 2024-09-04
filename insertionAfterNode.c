#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node * next;
};

void transversalList(struct node* ptr){
    while(ptr!=NULL){
        printf("Element found :%d\n", ptr->data);
        ptr=ptr->next;
    }
}

struct node * insertAfterNode(struct node * head , struct node *prevNode , int data){
    struct node * ptr = (struct node*) malloc (sizeof(struct node));
    ptr->data=data;


    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;
}

int main(){
    struct node * head;
    struct node * second ;
    struct node * third ;
    struct node * fourth ;

    head = (struct node * )malloc (sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc (sizeof(struct node));
    fourth = (struct node*)malloc (sizeof(struct node));

    head->data=7;
    head->next=second;

    second->data=13;
    second->next=third;

    third->data=16;
    third->next=fourth;

    fourth->data=20;
    fourth->next=NULL;

    printf("LinkedList before Insertion \n");
    transversalList(head);
    head =insertAfterNode(head , second , 111);
    printf("\n LinkedList insertion after Node\n");
    transversalList(head);
    return 0;


}