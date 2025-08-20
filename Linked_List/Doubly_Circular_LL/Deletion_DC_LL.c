#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* pre;
    int data;
    struct node* next;
};

struct node *head = NULL, *temp, *end = NULL;
int pos;

// Function to count the number of nodes
int getcount() {
    if (head == NULL) return 0; // If the list is empty
    int count = 0;
    temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// Function to print the circular linked list
void printList() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    temp = head;
    printf("The linked list values are:\n");
    do {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Deletion from the beginning of the list
void DeletionFromBeginning() {
    if (head == NULL) {
        printf("There is no node to delete from the linked list.\n");
        return;
    } else if (head == end) {
        temp = head;
        head = end = NULL;
        free(temp);
    } else {
        temp = head;
        head = head->next;
        head->pre = end; // Update the new head's previous to point to the old end
        end->next = head; // Update the end's next to point to the new head
        free(temp);
    }
    printList();
}

// Deletion from the end of the list
void DeletionFromEnd() {
    if (head == NULL) {
        printf("There is no node to delete from the linked list.\n");
        return;
    } else if (head->next == head) {
        // If only one node exists
        temp = head;
        head = end = NULL;
        free(temp);
    } else {
        temp = end;
        end = end->pre;
        end->next = head; // Update the new end's next to point to head
        head->pre = end; // Update the head's previous to point to the new end
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
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }

        // Adjust the links and free the node
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;
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
        newnode->next = newnode->pre = NULL;

        if (head == NULL) {
            head = end = newnode;
            head->next = head; // Point to itself
            head->pre = head;  // Point to itself
        } else {
            newnode->pre = end;
            end->next = newnode;
            newnode->next = head; // New node's next points to head
            head->pre = newnode;   // Head's previous points to new node
            end = newnode;         // Update end to new node
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
