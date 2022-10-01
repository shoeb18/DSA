#include <stdio.h>
#include <stdlib.h>

// stack structure
struct stack{
    int size;
    int top;
    int *arr;
};

int main(){

    // creating the stack in heap memory
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));



    return 0;
}