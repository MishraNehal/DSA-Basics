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
        // Insert in the middle of the list
        temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }

        newnode->next = temp->next; // New node's next points to the next node
        newnode->pre = temp;        // New node's previous points to the current node

        if (temp->next != NULL) {
            temp->next->pre = newnode;   // The next node's previous points to the new node
        } 
        temp->next = newnode;       // Current node's next points to the new node
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

int main() {
    int choice = 1, insertChoice, insertionAgain = 1;

    while (choice == 1) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
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
            end->next = newnode;  // Update end's next
            newnode->pre = end;    // New node's previous points to current end
            newnode->next = head;  // New node's next points to head
            head->pre = newnode;   // Head's previous points to new node
            end = newnode;         // Update end to new node
        }

        printf("Do you want to continue adding nodes? If yes, enter 1, else 0: ");
        scanf("%d", &choice);
    }

    printList();

    while (insertionAgain == 1) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter the value for newnode: ");
        scanf("%d", &newnode->data);
        newnode->next = newnode->pre = NULL;

        printf("Where do you want to insert the node? Enter 1 for beginning, 2 for end, 3 for position: ");
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
            printf("Invalid choice! Please try again.\n");
            free(newnode);
            continue;
        }

        printList();

        printf("Do you want to continue inserting nodes? If yes, enter 1, else 0: ");
        scanf("%d", &insertionAgain);
    }

    int count = getcount();
    printf("The number of nodes in the linked list is: %d\n", count);

    return 0;
}
