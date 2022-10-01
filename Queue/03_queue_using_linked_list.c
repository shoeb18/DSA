#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void Traverse(struct Node *ptr)
{
    printf("Printing the elements of linked list\n");
    while (ptr != NULL)
    {
        printf("element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

void enqueue(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        ptr->data = data;
        ptr->next = NULL;

        if (f == NULL)
        {
            f = r = ptr;
        }
        else
        {
            r->next = ptr;
            r = ptr;
        }
    }
}

int dequeue()
{
    int val = -1;

    struct Node *ptr = f;

    if (isEmpty(ptr))
    {
        printf("Queue is empty\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{

    Traverse(f);

    enqueue(54);
    enqueue(2);
    enqueue(43);

    Traverse(f);

    printf("The dequeued element is : %d\n", dequeue());
    printf("The dequeued element is : %d\n", dequeue());
    printf("The dequeued element is : %d\n", dequeue());

    return 0;
}