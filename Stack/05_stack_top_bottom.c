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

// peek operation
int peek(struct stack *ptr, int i)
{
    if (ptr->top-i+1 < 0){
        printf("Invalid position\n");
        return -1;
    }
    return ptr->arr[ptr->top - i + 1];
}

// stack top
int stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}
// stack bottom
int stackBottom(struct stack *ptr)
{
    return ptr->arr[0];
}


int main()
{

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 65);
    push(s, 87);
    push(s, 34);
    push(s, 55);

    printf("The bottom element in stack is : %d\n", stackBottom(s));
    printf("The top element in stack is : %d\n", stackTop(s));

    return 0;
}