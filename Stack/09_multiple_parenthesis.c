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
char pop(struct stack *ptr)
{
    char bracket = ptr->arr[ptr->top];
    ptr->top--;
    return bracket;
}

int chech_Bracket(char openBracket, char closeBracket)
{
    if (openBracket == '(' && closeBracket == ')')
    {
        return 1;
    }
    if (openBracket == '{' && closeBracket == '}')
    {
        return 1;
    }
    if (openBracket == '[' && closeBracket == ']')
    {
        return 1;
    }
    return 0;
}

int MultiParenthesisMatching(char *exp)
{

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = strlen(exp);
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    for (int i = 0; (exp[i] != '\0'); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            char popped_bracket = pop(s);

            if (!chech_Bracket(popped_bracket, exp[i]))
            {
                return 0;
            }
        }
    }
    if (isEmpty(s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    char *exp = "{ [ 3 + 4 * ( 2 + 1 ) ] }";

    if (MultiParenthesisMatching(exp))
    {
        printf("Parenthesis are balanced\n");
    }
    else
    {
        printf("Parenthesis are not balanced\n");
    }

    return 0;
}