#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, char op)
{
    ptr->top++;
    ptr->arr[ptr->top] = op;
}

char pop(struct stack *ptr)
{
    char op = ptr->arr[ptr->top];
    ptr->top--;
    return op;
}

char stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    return 0;
}

int precedence(char op)
{
    if (op == '*' || op == '/')
        return 3;
    if (op == '+' || op == '-')
        return 2;
    else
        return 0;
}

char *InfixToPostfix(char *infix)
{

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = strlen(infix);
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    char *postfix = (char *)malloc(s->size + 1 * sizeof(char));

    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(s)))
            {
                push(s, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(s);
                j++;
            }
        }
    }

    while (!isEmpty(s))
    {
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{

    char *infix = "x-y*z";

    printf("Infix to Postfix is : %s\n", InfixToPostfix(infix));

    return 0;
}