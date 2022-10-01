#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Traversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("element : %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

// Case 1 : Insert at first
struct Node *InsertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *q = head->next;

    while (q->next != head)
    {
        q = q->next;
    }
    q->next = ptr;
    ptr->next = head;
    return ptr;
}

// Case 2 : Insert at index
struct Node * InsertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *q = head;

    int i = 0;
    while (i!=index-1)
    {
        q = q->next;
        i++;
    }
    ptr->next = q->next;
    q->next = ptr;
    return head;
}

// Case 3 : Insert at the end
struct Node * InsertAtEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *q = head->next;

    while (q->next!=head)
    {
        q = q->next;
    }
    ptr->next = q->next;
    q->next = ptr;
    return head;
}

// Case 4 : Insert after the given node
struct Node * InsertAfterNode(struct Node *head, struct Node *prevNode,int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

int main()
{

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *forth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = forth;

    forth->data = 4;
    forth->next = head;

    printf("Circular linked list before insertion :\n");
    Traversal(head);

    // head = InsertAtFirst(head, 34);
    // head = InsertAtIndex(head, 98, 2);
    // head = InsertAtEnd(head, 777);
    head = InsertAfterNode(head, third, 88);

    printf("Circular linked list after insertion :\n");
    Traversal(head);

    return 0;
}