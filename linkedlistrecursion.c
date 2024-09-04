#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head_ref, int data) 
{
    struct Node* newNode = createNode(data);
    struct Node* last = *head_ref;
    
    if (*head_ref == NULL) 
    {
        *head_ref = newNode;
        return;
    }
    
    while (last->next != NULL) 
    {
        last = last->next;
    }
    
    last->next = newNode;
}

void reverseUtil(struct Node* current, struct Node* prev, struct Node** head_ref) 
{
    if (current == NULL) 
    {
        *head_ref = prev;
        return;
    }
    
    struct Node* next = current->next;
    current->next = prev;
    
    reverseUtil(next, current, head_ref);
}

void reverse(struct Node** head_ref) 
{
    reverseUtil(*head_ref, NULL, head_ref);
}

void printList(struct Node* head) 
{
    struct Node* temp = head;
    
    printf("Linked List: ");
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    struct Node* head = NULL;
    
    append(&head, 11);
    append(&head, 22);
    append(&head, 33);
    append(&head, 44);
    append(&head, 55);
    
    printf("Original ");
    printList(head);
    
    reverse(&head);
    
    printf("Reversed ");
    printList(head);
    
    return 0;
}