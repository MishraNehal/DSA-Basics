#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* pre;
    int data;
    struct node* next;
};

struct node *head = NULL, *temp = NULL, *end = NULL;
int pos;

// Function to count the nodes in the linked list
int getcount() {
    int count = 0;
    temp = head;
    while (temp != NULL) {
        count++;  
        temp = temp->next;
    }
    return count;
}

// Insert node at the beginning of the list
void insertAtBeginning(struct node* newnode) { 
    if (head == NULL) {
        head = end = newnode;
    } else {
        newnode->next = head;
        head->pre = newnode;
        head = newnode;
    }
}

// Insert node at the end of the list
void insertAtEnd(struct node* newnode) {
    if (head == NULL) {
        head = end = newnode;
    } else {
        end->next = newnode;
        newnode->pre = end;
        end = newnode;
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
        int i = 1;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }

        newnode->next = temp->next;
        newnode->pre = temp;

        if (temp->next != NULL) {
            temp->next->pre = newnode;
        }

        temp->next = newnode;
    }
}


// Function to print the linked list
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
            head = end = temp = newnode;
        } else {
            temp->next = newnode;
            newnode->pre = temp;
            temp = temp->next;
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

