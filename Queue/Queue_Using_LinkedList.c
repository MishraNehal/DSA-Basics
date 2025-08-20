#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

// Insertion at end : Deletion from beginning
// front = head : rear = tail

struct node *front = NULL ;
struct node *rear = NULL;

void enqueue(int x)
{
    struct node *newnode,*temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode ->data = x;
    newnode ->next = newnode ->prev = NULL;

    if (rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        temp = front;
        while(temp->next !=NULL)
        {
            temp = temp -> next;
        }
        newnode -> prev = temp;
        temp -> next = newnode;
    }
}

int dequeue()
{
    struct node *temp;
    if(front == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        temp = front;
        front = front -> next;
        front->prev = NULL;
        free(temp);
    }
}

int peek()
{
    if(front == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        //return front->data;
        printf("Front element: %d\n",front->data);
    }
}

int display()
{
    struct node *temp;
    temp = front;
    printf("The queue after operations is : \n");
    while(temp != NULL)
    {
        printf("%d\n",temp->data);
        temp = temp -> next;
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    peek();
    dequeue();
    display();
    peek();
    enqueue(4);
    enqueue(5);
    enqueue(6); 
    display();


    return 0;
}