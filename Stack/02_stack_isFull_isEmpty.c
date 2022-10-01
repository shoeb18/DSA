#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

// isfull method
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

// isEmpty method
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int main()
{

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));

    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // pushing elements manually in stack
    s->arr[0] = 45;
    s->top++;
    s->arr[1] = 89;
    s->top++;

    if (isFull(s)){
        printf("Stack is full\n");
    }
    else{
        printf("Stack is not full\n");
    }

    if (isEmpty(s)){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack is not empty\n");
    }



    return 0;
}