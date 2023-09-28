#ifndef LL
#define LL

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

void traverse(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        printf("[%d]->", temp->data);
        temp = temp->link;
    }
    printf("null\n");
}

void insertAtStart(Node **head, int data)
{
    Node *newNode = createNode(data);

    if (!*head)
    {
        *head = newNode;
        return;
    }

    newNode->link = *head;
    *head = newNode;
}

void insertAtEnd(Node **head, int data)
{
    Node *newNode = createNode(data);

    if (!*head)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;

    while (temp->link)
        temp = temp->link;

    temp->link = newNode;
}

void insertAfter(Node **head, int data, int after)
{
    Node *newNode = createNode(data);

    if (!*head)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;

    while (temp->link)
    {
        if (temp->data == after)
            break;

        temp = temp->link;
    }

    newNode->link = temp->link;
    temp->link = newNode;
}

void removeFromStart(Node **head)
{
    if (!*head)
        return;

    Node *temp = *head;
    *head = (*head)->link;

    free(temp);
}

void removeAfter(Node **head, int after)
{
    if (!*head)
        return;

    Node *temp = *head;

    while (temp->link)
    {
        if (temp->data == after)
        {
            Node *toRemove = temp->link;
            temp->link = toRemove->link;
            free(toRemove);
            return;
        }

        temp = temp->link;
    }

    if (temp->data != after)
        printf("\nNode with value [%d] not found.\n", after);
}

void removeFromEnd(Node **head)
{
    if (!*head)
        return;

    Node *temp = *head;

    if (!temp->link)
    {
        *head = NULL;
        free(temp);
        return;
    }

    Node *prev = NULL;

    while (temp->link)
    {
        prev = temp;
        temp = temp->link;
    }

    prev->link = NULL;
    free(temp);
}

#endif