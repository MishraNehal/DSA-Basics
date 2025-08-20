#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *head = NULL, *temp;
int pos;

// Function to get the count of nodes
int getcount() {
    int count = 0;
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Insert at the beginning of the list
void insertAtBeginning(struct node* newnode) {
    if (head == NULL) {
        head = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}

// Insert at the end of the list
void insertAtEnd(struct node* newnode) {
    if (head == NULL) {
        head = newnode;
        return;
    }
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
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
void printList() {
    temp = head;
    printf("The linked list values are:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice = 1, insertChoice, insertionAgain = 1;
    int pos;

    // Build initial list
    while (choice == 1) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter the value for newnode: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = temp->next;
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
