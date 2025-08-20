#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *head = NULL, *temp;
int pos;

// Function to count the number of nodes
int getcount() {
    int count = 0;
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to print the linked list
void printList() {
    temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("The linked list values are:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Deletion from the beginning of the list
void DeletionFromBeginning() {
    if (head == NULL) {
        printf("There is no node to delete from the linked list.\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
    printList();
}

// Deletion from the end of the list
void DeletionFromEnd() {
    if (head == NULL) {
        printf("There is no node to delete from the linked list.\n");
        return;
    } else if (head->next == NULL) {
        // If only one node exists
        temp = head;
        head = NULL;
        free(temp);
    } else {
        struct node *previous = NULL;
        temp = head;

        // Traverse to the end of the list
        while (temp->next != NULL) {
            previous = temp;
            temp = temp->next;
        }

        previous->next = NULL;
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

    if (pos == 1) 
    {
        DeletionFromBeginning();
    } 
    else if (pos == count) 
    {
        DeletionFromEnd();
    } 
    else 
    {
        struct node *nextnode;
        temp = head;
        int i = 1;

        // Traverse to the node just before the position
        while (i < pos - 1) 
        {
            temp = temp->next;
            i++;
        }

        // Adjust the links and free the node
        nextnode = temp->next;
        temp->next = nextnode->next;
        free(nextnode);
        printList();
    }
}

int main() {
    int choice = 1, delete = 1, deleteChoice;

    // Create the initial linked list
    while (choice == 1) {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter the value for newnode: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
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
    printf("The number of nodes in the linked list is: %d\n", count);

    return 0;
}
