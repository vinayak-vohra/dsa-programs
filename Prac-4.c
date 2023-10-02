// P4: Wap to count no. of nodes & reverse LL.

#include "headers/LL.h"

/// @brief Count no. of nodes in the Linked List
/// @param head Ptr to head of Linked List
/// @return No. of nodes in Linked List.
int count(Node *head)
{
    int count = 0;
    Node *temp = head;

    while (temp)
        count++, temp = temp->link;

    return count;
}

/// @brief Reverse the Linked List.
/// @param head Address of head ptr of Linked List.
void reverse(Node **head)
{
    // If 0 or 1 node
    if (!*head || !(*head)->link)
        return;

    Node *prev, *cur, *next;
    prev = next = NULL;
    cur = *head;

    while (cur)
    {
        // save next node
        //  NULL   [Node A]->[Node B]->NULL
        // (prev)   (cur)     (next)
        next = cur->link;

        // reverse current node link
        //  NULL <-[Node A]  [Node B]->NULL
        // (prev)   (cur)     (next)
        cur->link = prev;

        // update previous node
        //  NULL <-[Node A]  [Node B]->NULL
        //       (prev, cur)  (next)
        prev = cur;

        // update current node
        // [Node A]<-[Node A]  [Node B]->NULL
        //            (prev)  (cur, next)
        cur = next;
    }
    *head = prev;
}

int main()
{
    Node *head = NULL;

    for (int i = 0; i < 10; i++)
        insertAtStart(&head, i * 15, 0);

    traverse(head);
    printf("No. of Nodes: %d\n", count(head));

    printf("Reversing the list.\n");
    reverse(&head);
    printf("Reversed list:\t");
    traverse(head);
}
