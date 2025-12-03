
#include <stdio.h>
#include <stdlib.h>
char stack[50];
int top = -1;
void push(char val)
{
    stack[++top] = val;
}
char pop()
{
    if (top >= 0)
    {
        return stack[top--];
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

    char ch, x;

    for (i = 0, j = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];
        if (ch >= 97 && ch <= 122)
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while ((x = pop()) != '(')
            {
                postfix[j++] = x;
            }
        }
        else
        {
            while (priority(stack[top]) >= priority(ch) & top != -1)
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    while (top >= 0)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    printf("\n Postfix expression: %s", postfix);
    return 0;
}