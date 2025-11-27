#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
int stack[SIZE], top = -1, i;
void push(int ele)
{
    if (SIZE - 1 == top)
    {
        printf("Stack Overflow");
    }
    else
    {
        stack[top++] = ele;
    }
}
void pop()
{
    if (top == -1)
    {

        printf("Stack Underflow");
    }
    else
    {
        printf("Deleted element : %d", stack[top]);
        top--;
    }
}
void display()
{
    if (top == -1)
    {
        printf("Stack overflow");
    }
    else
    {
        for (i = top; i >= 0; i--)
        {
            printf("%d ->", stack[i]);
        }
    }
}

int main()
{
    int choice, ele;
    while (1)
    {
        printf("\n Stack Operations \n");
        printf("1. Push \n");
        printf("2. Pop \n");
        printf("3. Display Stack \n");
        printf("4. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to push :");
            scanf("%d", &ele);
            push(ele);
            break;
        case 2:
            pop();
            break;
        case 3:
            displayStack();
            break;
        case 4:
        default:
            return 0;
        }
    }
}