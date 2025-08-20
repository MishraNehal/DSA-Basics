#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* prev;
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

void Reverse(struct node** head)
{
    struct node *C_node, *temp = NULL;
    C_node = *head;

    // Swap prev and next for all nodes
    while (C_node != NULL)
    {
        temp = C_node->prev;
        C_node->prev = C_node->next;
        C_node->next = temp;
        C_node = C_node->prev;  // move to next (was prev)
    }

    // Before setting new head, check if list was not empty
    if (temp != NULL)
    {
        *head = temp->prev;
    }
}

int main()
{
    int choice = 1;
    struct node *head, *newnode, *temp;
    head = NULL;

    while (choice == 1)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("Memory is not available\n");
            break;
        }
        else
        {
            printf("Enter the value for newnode: ");
            scanf("%d", &newnode->data);

            newnode->prev = NULL;
            newnode->next = NULL;

            if (head == NULL)
            {
                head = temp = newnode;
            }
            else
            {
                temp->next = newnode;
                newnode->prev = temp;
                temp = temp->next;
            }
        }
        printf("Do you want to continue, if yes enter (1) else (0): ");
        scanf("%d", &choice);
    }

    // Print original list
    printf("\nThe doubly linked list values are:\n");
    temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("The number of nodes: %d\n", getcount(head));

    // Reverse the list
    Reverse(&head);

    // Print reversed list
    printf("\nThe reversed doubly linked list values are:\n");
    temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("The number of nodes after reverse: %d\n", getcount(head));

    return 0;
}
