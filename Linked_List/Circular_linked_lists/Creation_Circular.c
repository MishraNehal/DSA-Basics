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
    if (head == NULL) 
    {
        return count;
    }
    // Traverse the list until we reach the head again
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);

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

    // Complete the circular link (last node points to head)
    if (temp != NULL)
    {
        temp->next = head;
    }

    // Print the circular linked list
    if (head != NULL)
    {
        temp = head;
        printf("The linked list values are:\n");
        do
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        } while (temp != head);  // Stop when we reach the head again
    }
    printf("\n");

    int count = getcount(head);
    printf("The number of nodes in the linked list is: %d\n", count);

    
    return 0;
}