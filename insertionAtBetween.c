#include <stdio.h>
#include <stdlib.h>

struct node {
    int data ;
    struct node * next;
};

void traversalList(struct node *ptr){
    while(ptr!=NULL){
        printf("Element Found :%d\n" , ptr->data);
        ptr=ptr->next;
    }
}

struct node * insertAtMid(struct node * head , int data , int index){
    struct node *ptr = (struct node *) malloc (sizeof(struct node));
    struct node * p = head ;
    int i = 0 ;

    while(i!=index-1){
        p=p->next;
        i++;

    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head ;

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
    traversalList(head);
    insertAtMid(head , 99 , 2);
    printf("\n LinkedList after Insertion \n");
    traversalList(head);
    return 0;



}