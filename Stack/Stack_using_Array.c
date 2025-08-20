#include <stdio.h>
#include <stdbool.h>  // Include this for bool type


#define N 5   //Macros

int stack[N];
int top = -1;

bool isfull()
{
    if(top == N - 1)
      return 1;
    else
      return 0;
}


void push(int x)         //here we can also do print enter value and scanf("%d";&stack[top]) inside the push function
{
    if(isfull())          //top == N-1 in place isfull
    {
        printf("Overflow Stack");

    }
    else
    {
        top++;
        stack [top] = x;

    }
}

bool isempty()
{
    if(top == -1)
     return 1;
    else
     return 0;
}

int pop()
{
    if(isempty())                  //top == -1 in place isempty
    {
        printf("Underflow Stack\n");
        return -1;  // Return -1 or an appropriate value
    }
    else
    {
        int y;   //local variable
        y = stack[top];
        top --;
        return y;
    }
}

int peak()
{
    if(top == -1)
    {
        printf("the stack is empty!");
        return -1;  // Return -1 or an appropriate value
    }
    else
    {
        printf("Top element: %d\n", stack[top]); //we can also print the value
        return stack[top];
    }
}

void display()
{
    if(top == -1)
    {
        printf("The stack is empty!");
    }
    else
    {
        for(int i = top; i >= 0; i--)
        {
            printf("%d ",stack[i]);   //after %d\n can also do for newline here i just given a space 

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
