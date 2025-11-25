#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *list1, *list2, *start, *end, *temp;
struct Node *createlist()
{
    int i;
    int ele;
    start = end = NULL;
    while (1)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter the ele:");
        scanf("%d", &ele);
        temp->data = ele;
        temp->next = NULL;
        if (start == NULL)
        {
            start = end = temp;
        }
        else
        {
            end->next = temp;
            end = temp;
        }
        printf("\nDo you want to continue (yes==1/no==0)\n");

        scanf("%d", &i);

        if (i == 1)
        {
            continue;
        }
        else if (i == 0)
        {
            break;
        }
    }
    return start;
}
void display(struct Node *list)
{
    temp = list;
    if (temp == NULL)
    {
        printf("\nLIST IS EMPTY");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
}
void concatinete()
{
    if (list1 != NULL && list2 != NULL)
    {
        temp = list1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = list2;
        display(list1);
    }
    else
    {
        printf("\nLIST IS EMPTY");
    }
}
int main()
{

    printf("\ncreat li1");
    list1 = createlist();
    printf("\ncreat li2");
    list2 = createlist();
    printf("\nLIST-1");
    display(list1);
    printf("\nLIST-2");
    display(list2);
    printf("\nL1+L2:");
    concatinete();
}
