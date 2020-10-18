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
        {
            head = current;  
            last=current;}
        else
        {
            last->next=current;
            last=current;
        }
        
    }
    
    
    
    printf("Linked list before insertion\n");
    linkedListTraversal(head);
    
    
return 0;
    
    
}



