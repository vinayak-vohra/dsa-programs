// P2: Wap to implement LL and CLL ops: [insert, delete] at start, end, index

// Headers
#include <string.h>
#include "LL.h"

// Declarations
int opsMenu(char *);
int posMenu(char *);
void mainMenu(bool);

// Main
int main()
{
    int choice;
    do
    {
        system("cls");
        printf(
            "Select List Type:\n"
            "1. Linear Single Linked List.\n"
            "2. Circular Single Linked List.\n"
            "3. Exit.\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        case 2:
            mainMenu(choice == 2);
            break;

        case 3:
            exit(0);

        default:
            break;
        }
    } while (1);
}

/// @brief Main Menu Driver Code
/// @param isCircular whether linked list is circular or linear
void mainMenu(bool isCircular)
{
    Node *list = NULL;
    int op, pos, data, after;
    do
    {
        system("cls");
        op = opsMenu(isCircular ? "Circular" : "Linear");

        switch (op)
        {
        case 1:
            pos = posMenu("Insert");

            if (pos < 0 || pos > 3)
                continue;

            printf("\nEnter Data: ");
            scanf("%d", &data);

            switch (pos)
            {
            case 1:
                insertAtStart(&list, data, isCircular);
                break;

            case 2:
                traverse(list);
                printf("\nInsert Node After (value): ");
                scanf("%d", &after);
                insertAfter(&list, data, after, isCircular);
                break;

            case 3:
                insertAtEnd(&list, data, isCircular);
                break;

            default:
                break;
            }
            traverse(list);
            break;

        case 2:
            pos = posMenu("Remove");

            if (pos < 0 || pos > 3)
                continue;

            switch (pos)
            {
            case 1:
                removeFromStart(&list, isCircular);
                break;

            case 2:
                printf("\nRemove Node After (value): ");
                scanf("%d", &after);
                removeAfter(&list, after, isCircular);
                break;

            case 3:
                removeFromEnd(&list, isCircular);
                break;

            default:
                break;
            }
            traverse(list);

            break;

        case 3:
            traverse(list);
            break;

        case 4:
            return;

        case 5:
            exit(0);

        default:
            continue;
        }
        printf("\n");
        system("pause");
    } while (1);
}

/// @brief Operations Menu Driver Code
/// @param listType Linked List type: Linear | Circular
/// @return Operation choice[1-3]: Insert | Remove | Traverse etc.
int opsMenu(char *listType)
{
    int choice;
    printf("%s Single Linked List Menu:\n", listType);
    printf(
        "1. Insert\n"
        "2. Remove\n"
        "3. Traverse\n"
        "4. Back\n"
        "5. Exit\n");
    scanf("%d", &choice);
    return choice;
}

/// @brief Insert/Remove Position Menu
/// @param operation Operation Type: Insert | Remove
/// @return Position choice[1-3]: start | index | end
int posMenu(char *operation)
{
    int choice;
    system("cls");
    printf("%s:\n", operation);
    printf(
        "1. At the start\n"
        "2. At given index\n"
        "3. At the end\n"
        "4. Back\n");
    scanf("%d", &choice);
    return choice;
}
