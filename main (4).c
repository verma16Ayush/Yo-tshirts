#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * deleteFirst(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}


struct Node * deleteAtLast(struct Node * head){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = NULL;
    free(q);
    return head;
}

struct Node * deleteAtIndex(struct Node * head, int index){
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    free(q);
    return head;
}

int main()
{
   struct Node * head=NULL;
   struct Node * current;
   struct Node *last;
   int num=0;
   
    printf("Enter number of elements of linked list: \n");
    scanf("%d",&num);
    printf("\nEnter the elemets of the linked list:\n");
    for(int i =0; i < num; i++)
    {
        struct Node* current = (struct Node *)malloc(sizeof(struct Node)); 
        scanf( "%d", &current->data);      
       // current->next = head; 
       if(i==0)
        {head = current;  
        last=current;}
        else{
            last->next=current;
            last=current;
        }
    }
    printf("Linked list before created successfully:\n");
    linkedListTraversal(head);
    
    head = deleteFirst(head);
    printf("Linked list after deletion at beginning\n");
    linkedListTraversal(head);
    
    head = deleteAtLast(head);
    printf("Linked list after deletion at beginning\n");
    linkedListTraversal(head);

    head = deleteAtIndex(head, 2);
    printf("Linked list after deletion at given index\n");
    linkedListTraversal(head);
    
return 0;
}


