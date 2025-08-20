#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node* next;
};

struct node *head = NULL,*last = NULL, *temp;
int pos;

// Function to get the count of nodes
int getcount() {
    int count = 0;
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return count;
    }
    
    temp = head;

    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// Insert at the beginning of the list
void insertAtBeginning(struct node* newnode) 
{
    if (head == NULL) 
    {
        head = last = newnode;    // If the list is empty, both head and last point to the new node
        newnode->next = head;     // Point the new node to itself, forming a circular link
        return;
    }
    newnode->next = head;
    head = newnode;
    last->next = head;

}

// Insert at the end of the list
void insertAtEnd(struct node* newnode) 
{
    if (head == NULL) 
    {
        head = last = newnode;
        newnode->next = head; 
        return;
    }
    last->next = newnode;  // Link the last node to the new node
    last = newnode;        // Update last to the new node
    last->next = head;     // The new last node points to the head, maintaining the circular link
}

// Insert at a specific position
void insertAtPosition(struct node* newnode, int pos) {
    int count = getcount();
    
    if (pos < 1 || pos > count + 1) {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(newnode);
        return;
    }

    if (pos == count + 1) {
        insertAtEnd(newnode);
        return;
    }

    temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

// Function to print the list
void printList() 
{
    if (head == NULL) 
    {
        printf("The list is empty.\n");
        return;
    }
    
    temp = head;
    printf("The linked list values are:\n");
    do 
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != head);  // Traverse the list until we loop back to the head
    printf("\n");
}

int main() {
    int choice = 1, insertChoice, insertionAgain = 1;
    int pos;

    // Build initial list
    while (choice == 1) 
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) 
        {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter the value for newnode: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) 
        {
            head = last = newnode;
            newnode->next = head;  // Point the first node to itself to create the circular structure   
        } 
        else 
        {
            last->next = newnode;  // Update the last node to point to the new node
            last = newnode;        // Set last to the new node
            last->next = head;     // Point the new last node back to head
        }

        printf("Do you want to continue? If yes enter 1, else 0: ");
        scanf("%d", &choice);
    }
    
    printList();

    // Insertion loop
    while (insertionAgain == 1) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter the value for newnode: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        printf("Where do you want to insert the node? Enter 1 for beginning, 2 for end, 3 for position: ");
        scanf("%d", &insertChoice);

        if (insertChoice == 1) {
            insertAtBeginning(newnode);
        } else if (insertChoice == 2) {
            insertAtEnd(newnode);
        } else if (insertChoice == 3) {
            printf("Enter the position to insert: ");
            scanf("%d", &pos);
            insertAtPosition(newnode, pos);
        } else {
            printf("Invalid choice! Please try again.\n");
            free(newnode);
        }

        printList();

        printf("Do you want to continue? If yes enter 1, else 0: ");
        scanf("%d", &insertionAgain);
    }

    // Final linked list output
    printList();

    // Print number of nodes
    int count = getcount();
    printf("The number of nodes in the linked list is: %d\n", count);

    return 0;
}
