#include <stdio.h>
#include <stdlib.h>
char stack[50];
int top = -1;
void push(char val)
{
    stack[top++] = val;
}
void pop()
{
    if (top >= 0)
    {
        stack[top--];
    }
}
int priority(char opr)
{
    if (opr == '+' || opr == '-')
    {
        return 1;
    }
    else if (opr == '*' || opr == '/' || opr == '%')
    {
        return 2;
    }
    else if (opr == '^')
    {
        return 3;
    }
}
int main()
{
    char infix[100], postfix[100];
    int i, j;
#include <stdio.h>
#include <stdlib.h>
    char stack[50];
    int top = -1;
    void push(char val)
    {
        stack[top++] = val;
    }
    void pop()
    {
        if (top >= 0)
        {
            stack[top--];
        }
    }
    int priority(char opr)
    {
        if (opr == '+' || opr == '-')
        {
            return 1;
        }
        else if (opr == '*' || opr == '/' || opr == '%')
        {
            return 2;
        }
        else if (opr == '^')
        {
            return 3;
        }
    }
    int main()
    {
        char infix[100], postfix[100];
        int i, j;
        printf("Enter the expression :");
        scanf("%s", &infix);
    }