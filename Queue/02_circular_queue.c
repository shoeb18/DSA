#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size;
    int front;
    int back;
    int *arr;
};

int isEmpty(struct circularQueue *q)
{
    if (q->front == q->back)
    {
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *q)
{
    if ((q->back + 1) % q->size == q->front)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is overflow\n");
        return;
    }
    q->back = (q->back + 1) % q->size;
    q->arr[q->back] = val;
}

int dequeue(struct circularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    q->front = (q->front + 1) % q->size;
    return q->arr[q->front];
}


int main()
{
    struct circularQueue *q = (struct circularQueue *)malloc(sizeof(struct circularQueue));
    q->size = 5;
    q->front = q->back = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 12);
    enqueue(q, 43);
    enqueue(q, 67);
    enqueue(q, 87);

    for (int i = 0; i < 4; i++)
    {
        printf("Dequeuing element : %d\n", dequeue(q));
    }

    enqueue(q, 1);
    enqueue(q, 3);
    enqueue(q, 5);
    enqueue(q, 7);

    for (int i = 0; i < 4; i++)
    {
        printf("Dequeuing element : %d\n", dequeue(q));
    }
    return 0;
}