#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void ListTraversal(struct Node *head)
{
    while (head != NULL)
    {
        printf("element : %d\n", head->data);
        head = head->next;
    }
}

// Case 1 : Delete first node
struct Node *DeleteAtFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case 2 : Delete at index
struct Node *DeleteAtIndex(struct Node *head, int index)
{
    struct Node *ptr = head;
    struct Node *q = head->next;

    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        q = q->next;
        i++;
    }
    ptr->next = q->next;
    free(q);
    return head;
}

// Case 3 : Delete the last node
struct Node *DeleteAtEnd(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *q = head->next;

    while (q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = NULL;
    free(q);
    return head;
}

// Case 4 : Delete a node with given value
struct Node *DeleteAtValue(struct Node *head, int value)
{
    struct Node *ptr = head;
    struct Node *q = head->next;

    while (q->data != value && q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }

    if (q->data == value)
    {
        ptr->next = q->next;
        free(q);
        return head;
    }
}

int main()
{

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *forth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 5;
    third->next = forth;

    forth->data = 7;
    forth->next = NULL;

    printf("Linked list before deletion :\n");
    ListTraversal(head);

    // head = DeleteAtFirst(head);
    // head = DeleteAtIndex(head, 1);
    // head = DeleteAtEnd(head);
    head = DeleteAtValue(head, 5);

    printf("Linked list after deletion :\n");
    ListTraversal(head);

    return 0;
}