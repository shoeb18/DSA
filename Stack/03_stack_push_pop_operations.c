#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

// push operation
void push(struct stack *ptr, int element)
{
    if (isFull(ptr)){
        printf("Stack overflow! you can't add %d element\n", element);
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top] = element;
}

// pop operation
int pop(struct stack *ptr)
{
    if (isEmpty(ptr)){
        printf("Stack underflow! you can't pop\n");
        return -1;
    }
    int value = ptr->arr[ptr->top];
    ptr->top--;
    return value;
}


int main()
{

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 54);
    push(s, 65);
    push(s, 43);


    printf("The popped element is : %d\n", pop(s));
    printf("The popped element is : %d\n", pop(s));
    printf("The popped element is : %d\n", pop(s));

    return 0;
}