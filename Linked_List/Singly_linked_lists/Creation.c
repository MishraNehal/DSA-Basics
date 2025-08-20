#include <stdio.h>
#include <stdlib.h>

struct node
{
        int data;
        struct node* next;     
};


int getcount(struct node* head)
{
    int count = 0;
    struct node* temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
 
int main()
{
    
    int choice = 1;
    struct node *head, *newnode, *temp ;
    head = NULL;
    while(choice == 1)
    {
        
        
        newnode = (struct node*)malloc(sizeof(struct node));
        if(newnode == NULL)
        {
            printf("Memory is not Available");
            break;
        }
        else
        {
            printf("Enter the value for newnode :");
            scanf("%d",&newnode->data);

            newnode->next = NULL;
            if(head == NULL)
            {
                head = temp = newnode ;
            }
            else
            {
                temp->next = newnode;
                temp = temp->next;
            }
            
        }
        printf("Do you want to continue, if yes enter(1) else (0):");
        scanf("%d", &choice);

    }
   

    temp = head;
    printf("The linked list value are :\n");
    while (temp != NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->next;

    }
    printf("\n");

    int count = getcount(head);
    printf("The number of nodes in the linked list is: %d\n", count);

    
    return 0;
}