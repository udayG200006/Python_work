#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
int cqueue[SIZE], rear = -1, front = -1, i;
void enqueue(int ele)
{
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue Overflow");
    }
    else
    {
        if ((front) == -1)
        {
            front++;
        }
        rear = (rear + 1) % SIZE;
        cqueue[rear] = ele;
        printf("Element inserted");
    }
}
void dqueue()
{
    if (front == -1)
    {
        printf("queue Underflow");
    }
    else
    {
        printf("delete Element: %d", cqueue[front]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = ((front + 1) % SIZE);
        }
    }
}
void display()
{
    if (front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("\n Queue Elements: \n");
        for (i = front; i != rear; i = (i + 1) % SIZE)
        {
            printf("%d\n", cqueue[i]);
        }
        printf("%d", cqueue[i]);
    }
}

int main()
{
    int choice, ele;
    while (1)
    {
        printf("\ncqueue :");
        printf("1. EnQueue \n");
        printf("2. DQueue \n");
        printf("3. Display Queue \n");
        printf("4. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to push :");
            scanf("%d", &ele);
            enqueue(ele);
            break;
        case 2:
            dqueue();
            break;
        case 3:
            display();
            break;
        case 4:
        default:
            return 0;
        }
    }
}