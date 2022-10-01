#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void Traversal(struct Node *top){
    while(top!=NULL){
        printf("element : %d\n", top->data);
        top = top->next;
    }
}

// isempty method
int isEmpty(struct Node *top)
{
    if (top==NULL){
        return 1;
    }
    return 0;
}

// push method
struct Node * push(struct Node *top , int data)
{
    
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    if (ptr==NULL)
    {
        printf("Stack overflow! you can't push %d element\n", data);
    }
    ptr->next = top;
    return ptr;
}

// pop method
struct Node * pop(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty! you can't pop\n");
    }
    struct Node *ptr = top;
    top = top->next;
    free(ptr);
    return top;
}

// peek operation
int peek(struct Node *top, int pos)
{
    struct Node *ptr = top;
    int i = 0;
    while (i<pos-1 && ptr!=NULL)
    {
        ptr = ptr->next;
        i++;
    }
    if (ptr!=NULL){
        return ptr->data;
    }
}

// stack top
int stackTop(struct Node *top){
    return top->data;
}

// stack bottom
int stackBottom(struct Node *top){
    struct Node *ptr = top;
    while (ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

int main(){

    struct Node *top = NULL;

    top = push(top, 34);
    top = push(top, 89);
    top = push(top, 15);
    top = push(top, 23);
    top = push(top, 76);

    Traversal(top);
    
    for (int i = 1; i <= 5; i++)
    {
        printf("The value at position %d is : %d\n", i, peek(top, i));
    }

    printf("The top most element in stack is : %d\n", stackTop(top));
    printf("The bottom most element in stack is : %d\n", stackBottom(top));

    return 0;
}