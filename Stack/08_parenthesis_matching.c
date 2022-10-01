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

// push operation
void push(struct stack *ptr, char bracket)
{
    ptr->top++;
    ptr->arr[ptr->top] = bracket;
}

// pop operation
void pop(struct stack *ptr)
{
    char val = ptr->arr[ptr->top];
    ptr->top--;
}

// parenthesis matching problem
int ParenthesisMatching(char *exp)
{

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = strlen(exp);
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    for (int i = 0; (exp[i] != '\0'); i++)
    {
        if (exp[i] == '(')
        {
            push(s, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            pop(s);
        }
    }

    if (isEmpty(s)){
        return 1;
    }
    else{
        return 0;
    }
}



int main()
{
    char *exp = "(4+3*(2+1))";

    if (ParenthesisMatching(exp)){
        printf("Parenthesis are balanced\n");
    }
    else{
        printf("Parenthesis are not balanced\n");
    }

    return 0;
}