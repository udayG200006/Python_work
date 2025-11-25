#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next, *prev;
};
struct Node *start = NULL, *end = NULL, *temp;
void insertend(int ele)
{
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = ele;
    temp->next = NULL;
    temp->prev = NULL;
    if (start == NULL)
    {
        start = end = temp;
    }
    else
    {
        temp->prev = end;
        end->next = temp;
        end = temp;
    }
}
void delend()
{
    if (start == NULL)
    {
        printf("List is empty");
    }
    else if (start == end)
    {
        start = end = NULL;
    }
    else
    {
        temp = end;
        end = end->prev;
        end->next = NULL;
        free(temp);
    }
}
void insertbeg(int ele)
{
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = ele;
    temp->next = NULL;
    temp->prev = NULL;
    if (start == NULL)
    {
        start = end = temp;
    }
    else
    {
        temp->next = start;
        start->prev = temp;
        start = temp;
    }
}
void delbeg()
{
    if (start == NULL)
    {
        printf("List is empty");
    }
    else if (start == end)
    {
        start = end = NULL;
    }
    else
    {
        temp = start;
        start = start->next;
        start->prev = NULL;
        free(temp);
    }
}
void insertatpos(int ele, int pos)
{
    struct Node *curr;
    int i;
    if (pos == 1)
    {
        insertbeg(ele);
    }
    else
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = ele;
        temp->next = NULL;
        temp->prev = NULL;

        curr = start;
        for (i = 1; i < pos - 1; i++)
        {
            curr = curr->next;
        }
        if (curr == NULL)
        {
            printf("Cant insert at this position");
        }
        else
        {
            curr->next->prev = temp;
            temp->next = curr->next;
            curr->next = temp;
            temp->prev = curr;
            if (curr == end)
            {
                end = temp;
            }
        }
    }
}
void delatpos(int pos)
{
    int i;
    struct Node *curr;
    if (pos == 1)
    {
        delbeg();
    }
    else
    {
        curr = start;
        for (i = 1; i < pos - 1; i++)
        {
            curr = curr->next;
        }
        if (curr == NULL)
        {
            printf("Position out of range");
        }
        if (curr->next == end)
        {
            curr->next = NULL;
            end = curr;
        }
        else
        {
            curr->next = curr->next->next;
            curr->next->prev = curr;
        }
    }
}
void displayList()
{
    if (start == NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp = start;
        while (temp != end)
        {
            printf("%d<->", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}
void searchKey(int key)
{
    if (start == NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp = start;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                printf("\n Key node found in the list. ");
                break;
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("\n Key element not found in the list.");
        }
    }
}

int main()
{
    int choice, ele, pos, key;

    while (1)
    {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf(" 1. Insert End\n");
        printf(" 2. Delete End\n");
        printf(" 3. Insert Beginning\n");
        printf(" 4. Delete Beginning\n");
        printf(" 5. Insert At Position\n");
        printf(" 6. Delete At Position\n");
        printf(" 7. Display List\n");
        printf(" 8. Search Key\n");
        printf(" 9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &ele);
            insertend(ele);
            break;

        case 2:
            delend();
            break;

        case 3:
            printf("Enter the element: ");
            scanf("%d", &ele);
            insertbeg(ele);
            break;

        case 4:
            delbeg();
            break;

        case 5:
            printf("Enter the element: ");
            scanf("%d", &ele);
            printf("Enter the position: ");
            scanf("%d", &pos);
            insertatpos(ele, pos);
            break;

        case 6:
            printf("Enter the position: ");
            scanf("%d", &pos);
            delatpos(pos);
            break;

        case 7:
            displayList();
            break;

        case 8:
            printf("Enter the key element to find: ");
            scanf("%d", &key);
            searchKey(key);
            break;

        case 9:
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
