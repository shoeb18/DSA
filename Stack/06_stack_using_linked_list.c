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

int main(){

    struct Node *top = NULL;

    top = push(top, 34);
    top = push(top, 89);
    top = push(top, 15);
    top = push(top, 23);

    printf("Stack after pushing elements: \n");
    Traversal(top);

    printf("Stack after poping elements: \n");
    top = pop(top);
    top = pop(top);

    Traversal(top);

    return 0;
}