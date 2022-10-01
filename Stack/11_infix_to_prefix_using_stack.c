#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
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

void push(struct stack *ptr,char op)
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

char *InfixToPrefix(char *infix)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = strlen(infix);
    s->arr = (char *)malloc(s->size + 1 * sizeof(char));

    char *prefix = (char *)malloc(s->size + 1 * sizeof(char));

    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        // TODO
    }
    
}


int main(){

    
    return 0;
}