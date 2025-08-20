#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // Include this for bool type


#define N 5   //Macros

struct node
{
        int data;
        struct node* next;     
};



struct node *top = NULL, *newnode, *temp ;


void push(int x)         //here we can also do print enter value and scanf("%d";&stack[top]) inside the push function
{
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) 
        {
            printf("Memory allocation failed\n");
            return;
        }
        
        newnode->data = x;
        newnode->next = top;
        top = newnode;
}

bool isempty()
{
    return top == NULL;
}

int pop()
{
    if(isempty())                  //top == Null in place isempty
    {
        printf("The stack is empty or Underflow Stack\n");
        return -1;  // Return -1 or an appropriate value
    }
    else
    {
       temp = top;
       int value = temp->data;  // Store the value to return
       top = top->next;
       free(temp);
       return value;
    }
}

int peak()
{
    if(top == NULL)
    {
        printf("the stack is empty!");
        return -1;  // Return -1 or an appropriate value
    }
    else
    {
        printf("Top element: %d\n", top->data); //we can also print the value
        return top->data;
    }
}

void display()
{
    if(top == NULL)
    {
        printf("The stack is empty!");
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            printf("%d ",temp->data);   //after %d\n can also do for newline here i just given a space 
            temp = temp->next;

        }
        printf("\n");

    }
}

int main()
{
    push(1);
    push(2);
    push(3);
    display();
    peak();
    pop();
    pop();
    push(4);
    display();
    peak();


    return 0;

}
