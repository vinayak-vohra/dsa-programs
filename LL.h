// To prevent multiple include in sub files
#ifndef LL
#define LL

// Headers
#include <stdio.h>
#include <stdlib.h>

// Node Structure
typedef struct node
{
    int data;
    struct node *link;
} Node;

/// @brief Create a new node.
/// @param data Node data.
/// @return Pointer to the newly created node.
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // allocate mem
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

/// @brief Print the Linked List.
/// @param head Pointer to List Head.
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

/// @brief Insert new node at start of Linked List.
/// @param head Reference to Head Pointer.
/// @param data Node Data.
void insertAtStart(Node **head, int data)
{
    Node *newNode = createNode(data);

    // If First Node
    if (!*head)
    {
        *head = newNode;
        return;
    }

    newNode->link = *head; // link to head
    *head = newNode;       // update head
}

/// @brief Insert new node at end of Linked List.
/// @param head Reference to Head Pointer.
/// @param data Node Data.
void insertAtEnd(Node **head, int data)
{
    Node *newNode = createNode(data);

    // If First Node
    if (!*head)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;

    // go to the last node
    while (temp->link)
        temp = temp->link;

    temp->link = newNode; // add new node
}

/// @brief Insert new node after provided value.
/// @param head Reference to Head Pointer.
/// @param data Node Data.
/// @param after Value after which new node is to be inserted. If not found, inserts at end.
void insertAfter(Node **head, int data, int after)
{
    Node *newNode = createNode(data);

    // If First Node
    if (!*head)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;

    // Find Node with value [after]
    while (temp->link)
    {
        if (temp->data == after)
            break; // found, exit loop

        temp = temp->link;
    }

    // connect new node link to after link
    newNode->link = temp->link;
    //
    //  [temp]
    //    |
    // [after]->[some-node]->[other-node]
    //              |
    //          [new-node]

    // connect after link to new node
    temp->link = newNode;
    //
    //  [temp]
    //    |
    // [after]  [some-node]->[other-node]
    //     |        |
    //     |--->[new-node]
}

/// @brief Remove the node at start of Linked List.
/// @param head Reference to Head Pointer.
void removeFromStart(Node **head)
{
    // Already Empty
    if (!*head)
        return;

    Node *temp = *head;    // save head
    *head = (*head)->link; // update head
    free(temp);            // free memory
}

/// @brief Remove the node after provided value.
/// @param head Reference to Head Pointer.
/// @param after Value after which the node is to be removed.
void removeAfter(Node **head, int after)
{
    // Already Empty
    if (!*head)
        return;

    Node *temp = *head; // save head

    while (temp->link)
    {
        if (temp->data == after) // node found
        {
            Node *toRemove = temp->link; // node to be removed
            temp->link = toRemove->link; // connect previous to next. toRemove is free of linked list.
            free(toRemove);              // free the memory associated with toRemove. (resource management)
            return;
        }

        temp = temp->link;
    }

    // If last node value also not match, show message.
    if (temp->data != after)
        printf("\nNode with value [%d] not found.\n", after);
}

/// @brief Remove the node at the end of Linked List.
/// @param head Reference to Head Pointer.
void removeFromEnd(Node **head)
{
    // Already Empty
    if (!*head)
        return;

    Node *temp = *head; // save head

    // Only 1 node
    if (!temp->link)
    {
        *head = NULL; // update head
        free(temp);   // free memory
        return;
    }

    Node *prev = NULL;

    // go to end
    while (temp->link)
    {
        prev = temp; // update previous node
        temp = temp->link;
    }

    prev->link = NULL; // end of list. last node no longer part of linked list
    free(temp);        // free memory associated with last node.
}

#endif