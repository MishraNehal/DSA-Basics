#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node* pre;
    int data;
    struct node* next;     
};


int getcount(struct node* head)
{
    int count = 0;
    if (head == NULL) return count;  // Return 0 if the list is empty

    struct node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head); // Loop until we reach the head again
    return count;
    
}

int main()
{
    
    int choice = 1;
    struct node *head = NULL, *newnode, *end = NULL, *temp;
   
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

            newnode->next = newnode->pre = NULL;
            if(head == NULL)
            {
                head = end = newnode ;
                head ->pre = end;// head points to itself
                end->next = head;// end points to head
            }
            else
            {
                newnode->pre = end;
                end->next = newnode;
                end = newnode;
                head ->pre = end;
                end->next = head;
            }
            
        }
        printf("Do you want to continue, if yes enter(1) else (0):");
        scanf("%d", &choice);

    }
   

    // Printing the linked list
    if (head != NULL) {
        temp = head;
        printf("The linked list values are:\n");
        do {
            printf("%d\n", temp->data);
            temp = temp->next;
        } while (temp != head); // Loop until we reach the head again
        printf("\n");
    } else {
        printf("The linked list is empty.\n");
    }
    

    int count = getcount(head);
    printf("The number of nodes in the linked list is: %d\n", count);

    
    return 0;
}