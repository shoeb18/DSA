#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int back;
    int *arr;
};

int isEmpty(struct Queue *q)
{
    if (q->front == q->back)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Queue *q)
{
    if (q->back == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is overflow\n");
        return;
    }
    q->back++;
    q->arr[q->back] = val;
}

int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    q->front++;
    return q->arr[q->front];
}

int main()
{

    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->size = 10;
    q->front = q->back = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 1);
    enqueue(q, 23);
    enqueue(q, 43);
    enqueue(q, 65);

    for (int i = 0; i < 4; i++)
    {
        printf("The %d dequeued element is : %d\n",i+1, dequeue(q));
    }

    return 0;
}