// #include <stdio.h>
// #include <stdbool.h>  // Include this for bool type


// #define  N  5
 
// int queue[N];
// int front = -1;
// int rear = -1;

// void enqueue(int x)
// {
//     if(rear == N-1)
//     {
//         printf("Overflow or Queue is full");
//     }
//     else if (front == -1 && rear == -1)
//     {
//         front = rear = 0;
//         queue[rear] = x;

//     }
//     else
//     {
//         rear ++;
//         queue[rear] = x;

//     }
// }

// void dequeue()
// {
//     if(front == -1 && rear == -1)
//     {
//         printf("Queue is underflow or empty");
//     }
//     else if(rear == front)
//     {
//         front = rear = -1;
//     }
//     else
//     {
//         printf("The element you are dequeing is %d",queue[front]);
//         front ++;
//     }
// }

// void display()
// {
//     if(front == -1 && rear == -1)
//     {
//         printf("Queue is empty");
//     }
//     else
//     {
//         for(int i = front; i < rear + 1; i++)
//         {
//             printf("%d", queue[i]);
//         }
//     }
// }

// void peak()
// {
//     if(front == -1 && rear == -1)
//     {
//         printf("Queue is empty");
//     }
//     else
//     {
//        printf("%d",queue[front]); 

//     }
// }

#include <stdio.h>
#include <stdbool.h>  // Include this for bool type

#define N 5

int queue[N];
int front = -1;
int rear = -1;

bool isfull() {
    return rear == N - 1;
}

bool isempty() {
    return (front == -1 && rear == -1)|| (front == rear + 1);
}

void enqueue(int x) {
    if (isfull()) {
        printf("Overflow or Queue is full\n");
    } else if (isempty()) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear++;
        queue[rear] = x;
    }
}

void dequeue() {
    if (isempty()) {
        printf("Queue is underflow or empty\n");
    } else if (rear == front) {
        printf("The element you are dequeuing is %d\n", queue[front]);
        front = rear = -1;
    } else {
        printf("The element you are dequeuing is %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (isempty()) {
        printf("Queue is empty\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void peak() {
    if (isempty()) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    peak();
    dequeue();
    display();
    peak();
    enqueue(4);
    enqueue(5);
    enqueue(6);  //  an overflow Condition
    display();

    return 0;
}
