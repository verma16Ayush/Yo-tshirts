#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node *ptr,struct node *head)
{
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
}

struct Node * InsertBeg(struct Node* head, int data)
{
    struct Node * new, *temp;
    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        new = (struct Node *)malloc(sizeof(struct Node));
        new->data = data;
        new->next = head;
        
        temp = head;
        
        
        while(temp->next!=head)
        {
            temp = temp->next;
        }
        temp->next = new;
        
        head = new;
        
    }
    return head;
}

struct Node * InsertEnd(struct Node * head, int data)
{
    struct Node *new, *temp;
    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        new = (struct Node *)malloc(sizeof(struct Node));
        new->data = data;
        
        temp=head;
        do
        {
            temp = temp->next;
            
            
        }while(temp->next!=head);
        temp->next = new;
        new->next = head;
    }
    return head;
}

int main()
{
   struct Node * head=NULL;
   struct Node * current;
   struct Node *temp;
   int num=0;
   
    printf("Enter number of elements of linked list: \n");
    scanf("%d",&num);
    printf("Enter  elements of linked list: \n");

    for(int i =0; i < num; i++)
    {
        struct Node* current = (struct Node *)malloc(sizeof(struct Node)); 
        scanf( "%d", &current->data);      
       // current->next = head; 
       if(i==0)
        {
            head = current;  
            temp=current;}
        else
        {
            temp->next=current;
            temp=current;
        }
    }
     temp->next = head;
    
    
    
    printf("Linked list before insertion\n");
    linkedListTraversal(head,head);
    printf("Linked list After Insertion\n");
    head = InsertBeg(head, 10);
    linkedListTraversal(head,head);
    printf("Linked list After Insertion\n");
    head = InsertEnd(head, 10);
    linkedListTraversal(head,head);
    
return 0;
    
    
}








