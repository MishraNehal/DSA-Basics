#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *head = NULL, *tail = NULL, *temp;
int pos;

// Function to count the number of nodes in the circular linked list
int getcount() {
    int count = 0;
    if (head == NULL) {
        return count;
    }
    temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);  // Continue until we loop back to the head
    return count;
}

// Function to print the circular linked list
void printList() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    temp = head;
    printf("The circular linked list values are:\n");
    do {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != head);  // Stop when we reach the head again
    printf("\n");
}

// Deletion from the beginning of the circular list
void DeletionFromBeginning() {
    if (head == NULL) {
        printf("There is no node to delete from the circular linked list.\n");
        return;
    }

    temp = head; // Temporary pointer to hold the node to be deleted
    if (head == tail) 
    {  // Only one node in the list
        head = tail = NULL; // Update head and last to NULL
    } 
    else 
    {
        head = head->next; // Move head to the next node
        tail->next = head; // Update last to point to new head
    }
    free(temp); // Free the memory of the deleted node
    printList();
}

// Deletion from the end of the circular list
void DeletionFromEnd() {
    if (head == NULL) {
        printf("There is no node to delete from the circular linked list.\n");
        return;
    } else if (head == tail) {  // If only one node exists
        head = tail = temp;
        head = tail = NULL;
        free(temp);
        return;
    } else 
    {
        temp = head;
        struct node *previous = NULL;

        // Traverse to the second-last node
        while (temp->next != head) {
            previous = temp;
            temp = temp->next;
        }

        previous->next = head;  // Link second-last node to head
        tail = previous;        // Update tail to second-last node
        free(temp);
    }
    printList();
}

// Deletion from a specific position
void DeletionFromSpecificPosition() {
    int count = getcount();

    if (pos < 1 || pos > count) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        DeletionFromBeginning();
    } else if (pos == count) {
        DeletionFromEnd();
    } else {
        temp = head;
        struct node *previous = NULL;
        int i = 1;

        // Traverse to the node just before the position
        while (i < pos) {
            previous = temp;
            temp = temp->next;
            i++;
        }

        // Adjust the links and free the node
        previous->next = temp->next;
        free(temp);
        printList();
    }
}

int main() {
    int choice = 1, delete = 1, deleteChoice;

    // Create the initial circular linked list
    while (choice == 1) {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

                printf("Enter the value for newnode: ");
        scanf("%d", &newnode->data);
        newnode->next = head; // Point new node to head

        if (head == NULL) {
            head = newnode; // If the list is empty, set head to newnode
            tail = newnode; // Also set tail to newnode
            tail->next = head; // Point tail's next to head (circular)
        } else {
            tail->next = newnode; // Link the old tail to the new node
            tail = newnode; // Update tail to the new node
            tail->next = head; // Maintain the circular link
        }

        printf("Do you want to continue adding nodes? Enter 1 for yes, 0 for no: ");
        scanf("%d", &choice);
    }

    printList();

    // Deletion choices
    while (delete == 1) {
        printf("Where do you want to delete the node? Enter 1 for beginning, 2 for end, 3 for specific position: ");
        scanf("%d", &deleteChoice);

        if (deleteChoice == 1) {
            DeletionFromBeginning();
        } else if (deleteChoice == 2) {
            DeletionFromEnd();
        } else if (deleteChoice == 3) {
            printf("Enter the position (1-based index) for deletion: ");
            scanf("%d", &pos);
            DeletionFromSpecificPosition();
        } else {
            printf("Invalid choice! Please try again.\n");
        }

        printf("Do you want to continue deleting nodes? Enter 1 for yes, 0 for no: ");
        scanf("%d", &delete);
    }

    // Final output and node count
    int count = getcount();
    printf("The number of nodes in the circular linked list is: %d\n", count);

    return 0;
}
