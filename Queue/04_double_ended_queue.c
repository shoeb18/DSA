#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct Queue *q){
    if (q->rear == q->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue *q){
    if (q->front == q->rear){
        return 1;
    }
    return 0;
}

void QueueTraverse(struct Queue *q){
    for (int i = 0; i <= q->rear; i++)
    {
        printf("element : %d\n", q->arr[i]);
    }
}

void enqueue_Front(struct Queue *q, int val){
    if (isFull(q)){
        printf("Queue overflow\n");
        return;
    }
    q->front++;
    q->arr[q->front] = val;
}
void enqueue_Rear(struct Queue *q, int val){
    if (isFull(q)){
        printf("Queue overflow\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = val;
}

int dequeue_Front(struct Queue *q){
    if (isEmpty(q)){
        printf("Queue underflow\n");
        return -1;
    }
    int val =  q->arr[q->front];
    q->front--;
    return val;
}
int dequeue_Rear(struct Queue *q){
    if (isEmpty(q)){
        printf("Queue underflow\n");
        return -1;
    }
    q->rear--;
    return q->arr[q->rear];
}

int main(){

    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->size = 10;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue_Rear(q, 2);
    enqueue_Rear(q, 43);
    enqueue_Rear(q, 54);

    QueueTraverse(q);

    dequeue_Front(q);
    QueueTraverse(q);

    return 0;
}