// To prevent multiple include in sub files
#ifndef LL
#define LL

// Headers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    if (!head)
        return;

    Node *temp = head;
    do
    {
        printf("[%d]->", temp->data);
        temp = temp->link;
    } while (temp && temp != head); // handles both linear & circular

    printf("\n");
}

/// @brief Insert new node at start of Linked List.
/// @param head Reference to Head Pointer.
/// @param data Node Data.
/// @param isCircular Flag for circular linked list.
void insertAtStart(Node **head, int data, bool isCircular)
{
    Node *newNode = createNode(data);

    // If First Node
    if (!*head)
    {
        *head = newNode;
        if (isCircular)
            newNode->link = newNode;
        return;
    }

    // Link last node to new node in circular list
    if (isCircular)
    {
        Node *temp = *head;

        do
        {
            temp = temp->link;
        } while (temp->link != *head); // reach last node

        temp->link = newNode; // link
    }

    newNode->link = *head; // link to head
    *head = newNode;       // update head
}

/// @brief Insert new node at end of Linked List.
/// @param head Reference to Head Pointer.
/// @param data Node Data.
/// @param isCircular Flag for circular linked list.
void insertAtEnd(Node **head, int data, bool isCircular)
{
    Node *newNode = createNode(data);

    // If First Node
    if (!*head)
    {
        *head = newNode;
        if (isCircular)
            newNode->link = newNode;
        return;
    }

    Node *temp = *head;

    // exit-control loop for circular list
    if (isCircular)
        do
        {
            temp = temp->link;
        } while (temp->link != *head);

    // entry-control loop for linear list
    else
        while (temp->link)
            temp = temp->link;

    // temp is the last node

    Node *save = temp->link; // NULL for linear list & Head for circular list
    temp->link = newNode;    // add new node at end
    newNode->link = save;    // mainly for circular
}

/// @brief Insert new node after provided value.
/// @param head Reference to Head Pointer.
/// @param data Node Data.
/// @param after Value after which new node is to be inserted. If not found, inserts at end.
/// @param isCircular Flag for circular linked list.
void insertAfter(Node **head, int data, int after, bool isCircular)
{
    Node *newNode = createNode(data);

    // If First Node
    if (!*head)
    {
        *head = newNode;
        if (isCircular)
            newNode->link = newNode;
        return;
    }

    Node *temp = *head;

    // Find Node with value [after]
    do
    {
        if (temp->data == after)
            break; // found, exit loop

        temp = temp->link;
    } while (
        temp->link &&         // linear LL
        temp->link != *head); // circular LL

    // Will add new node at the end
    // if no matching value found for [after]

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
/// @param isCircular Flag for circular linked list.
void removeFromStart(Node **head, bool isCircular)
{
    // Already Empty
    if (!*head)
        return;

    Node *toRemove = *head; // save head

    // only 1 node
    if (!toRemove->link || toRemove->link == toRemove)
    {
        free(toRemove);
        *head = NULL;
        return;
    }

    // In case of circular list,
    // link last node to head->next
    if (isCircular)
    {
        Node *save = toRemove;
        do
        {
            save = save->link;
        } while (save->link != *head);

        save->link = toRemove->link;
    }

    *head = (*head)->link; // update head
    free(toRemove);        // free memory
}

/// @brief Remove the node after provided value.
/// @param head Reference to Head Pointer.
/// @param after Value after which the node is to be removed.
/// @param isCircular Flag for circular linked list.
void removeAfter(Node **head, int after, bool isCircular)
{
    // Already Empty
    if (!*head)
        return;

    Node *temp = *head; // save head
    do
    {
        if (temp->data != after)
        {
            temp = temp->link;
            continue;
        }

        // only 1 node in circular list
        if (temp->link == temp)
        {
            free(temp);
            *head = NULL;
            return;
        }

        Node *toRemove = temp->link; // node to be removed
        temp->link = toRemove->link; // connect previous to next. toRemove is free of linked list.
        free(toRemove);              // free the memory associated with toRemove. (resource management)
        return;
    } while (temp->link && temp->link != *head);
}

/// @brief Remove the node at the end of Linked List.
/// @param head Reference to Head Pointer.
/// @param isCircular Flag for circular linked list.
void removeFromEnd(Node **head, bool isCircular)
{
    // Already Empty
    if (!*head)
        return;

    Node *temp = *head; // save head

    // Only 1 node
    if (!temp->link || temp->link == temp)
    {
        free(temp);   // free memory
        *head = NULL; // update head
        return;
    }

    Node *prev = NULL;

    // go to end
    do
    {
        prev = temp; // update previous node
        temp = temp->link;
    } while (temp->link && temp->link != *head);

    // end of list. last node(temp) no longer part of linked list
    if (isCircular)
        prev->link = *head;
    else
        prev->link = NULL;

    free(temp); // free memory associated with last node.
}

#endif