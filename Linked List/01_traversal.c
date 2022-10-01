#include <stdio.h>
#include <stdlib.h>

// self referencing structure
struct Node {
    int data;
    struct Node *next;
};

// list traversal
void ListTraversal(struct Node *head){
    while (head!=NULL)
    {
        printf("element : %d\n", head->data);
        head = head->next;
    }
}


int main(){

    // Allocating dynamic memory for structure pointers
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *forth = (struct Node *)malloc(sizeof(struct Node));

    // linking the nodes
    head->data = 12;
    head->next = second;

    second->data = 34;
    second->next = third;

    third->data = 45;
    third->next = forth;

    forth->data = 78;
    forth->next = NULL;

    ListTraversal(head);

    return 0;
}