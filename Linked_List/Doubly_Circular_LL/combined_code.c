#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* pre;
    int data;
    struct node* next;
};

struct node *head = NULL, *temp = NULL, *end = NULL;
int pos;

// Function to count the nodes in the circular linked list
int getcount() {
    if (head == NULL) return 0; // If the list is empty, return 0

    int count = 0;
    temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// Insert node at the beginning of the list
void insertAtBeginning(struct node* newnode) {
    if (head == NULL) {
        head = end = newnode;
        head->next = head; // Point to itself
        head->pre = head;  // Point to itself
    } else {
        newnode->next = head;
        newnode->pre = end; // New node's previous points to the current end
        head->pre = newnode; // Current head's previous points to the new node
        end->next = newnode; // Current end's next points to the new node
        head = newnode;      // Update head to new node
    }
}

// Insert node at the end of the list
void insertAtEnd(struct node* newnode) {
    if (head == NULL) {
        head = end = newnode;
        head->next = head; // Point to itself
        head->pre = head;  // Point to itself
    } else {
        newnode->next = head; // New node's next points to head
        newnode->pre = end;   // New node's previous points to the current end
        end->next = newnode;  // Current end's next points to the new node
        head->pre = newnode;  // Head's previous points to the new node
        end = newnode;        // Update end to new node
    }
}

// Insert node at a specific position
void insertAtPosition(struct node* newnode) {
    int count = getcount();

    if (pos > count + 1 || pos <= 0) {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1) {  // Insert at the beginning
        insertAtBeginning(newnode);
    } else if (pos == count + 1) {  // Insert at the end
        insertAtEnd(newnode);
    } else {
        temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }

        newnode->next = temp->next; // New node's next points to the next node
        newnode->pre = temp;      // New node's previous points to the current node
        temp->next->pre = newnode; // The next node's previous points to the new node
        temp->next = newnode;      // Current node's next points to the new node
    }
}

// Deletion from the beginning of the list
void DeletionFromBeginning() {
    if (head == NULL) {
        printf("The list is empty.\n");
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
}

// Deletion from the end of the list
void DeletionFromEnd() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    } else if (head == end) {
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

        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;
        free(temp);
    }
}

// Function to print the circular linked list
void printList() {
    if (head == NULL) {
        printf("The linked list is empty.\n");
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

int main() 
{
    int choice = 1, operationChoice, continueOperation = 1;

    // Initial list creation
    while (choice == 1) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter the value for newnode: ");
        scanf("%d", &newnode->data);
        newnode->next = newnode->pre = NULL;

        insertAtEnd(newnode);

        printf("Do you want to continue adding nodes? Enter 1 for yes, 0 for no: ");
        scanf("%d", &choice);
    }

    printList();

    // Menu-driven operations
    while (continueOperation == 1) {
        printf("\nChoose an operation:\n");
        printf("1. Insert Node\n2. Delete Node\n3. Display List\n4. Exit\n");
        scanf("%d", &operationChoice);

        switch (operationChoice) {
            case 1: 
            {
                struct node* newnode = (struct node*)malloc(sizeof(struct node));
                if (newnode == NULL) {
                    printf("Memory allocation failed!\n");
                    return 1;
                }

                printf("Enter the value for newnode: ");
                scanf("%d", &newnode->data);
                newnode->next = newnode->pre = NULL;

                printf("Where do you want to insert the node? Enter 1 for beginning, 2 for end, 3 for specific position: ");
                int insertChoice;
                scanf("%d", &insertChoice);

                if (insertChoice == 1) {
                    insertAtBeginning(newnode);
                } else if (insertChoice == 2) {
                    insertAtEnd(newnode);
                } else if (insertChoice == 3) {
                    printf("Enter the position to insert: ");
                    scanf("%d", &pos);
                    insertAtPosition(newnode);
                } else {
                    printf("Invalid choice!\n");
                    free(newnode);
                }
                break;
            }
            case 2: 
            {
                printf("Where do you want to delete the node? Enter 1 for beginning, 2 for end, 3 for specific position: ");
                int deleteChoice;
                scanf("%d", &deleteChoice);

                if (deleteChoice == 1) {
                    DeletionFromBeginning();
                } else if (deleteChoice == 2) {
                    DeletionFromEnd();
                } else if (deleteChoice == 3) {
                    printf("Enter the position to delete: ");
                    scanf("%d", &pos);
                    DeletionFromSpecificPosition();
                } else {
                    printf("Invalid choice!\n");
                }
                break;
            }
            case 3:
                printList();
                break;
            case 4:
                printf("Exiting...\n"); 
                continueOperation = 0; 
                break; 
            default: 
            printf("Invalid choice!\n"); 
            break; 
        } 
    } 
    return 0;
}
