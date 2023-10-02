// P2: Wap to implement LL and CLL ops: [insert, delete] at start, end, index

// Headers
#include <string.h>
#include "headers/LL.h" // required
#include "headers/Utils.h"

// Declarations
int opsMenu(char *);
void mainMenu(bool);

// Main
int main()
{
    int choice;
    do
    {
        system("cls");
        choice = input(
            "Select List Type:\n"
            "1. Linear Single Linked List.\n"
            "2. Circular Single Linked List.\n"
            "3. Exit.\n");

        switch (choice)
        {
        case 1: // same menu for both
        case 2: // linear & circular
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
        case 1: // Insert
            pos = posMenu("Insert");

            if (pos < 0 || pos > 3)
                continue;

            data = input("\nEnter Data: ");

            switch (pos)
            {
            case 1: // Insert at Start
                insertAtStart(&list, data, isCircular);
                break;

            case 2: // Insert After ?
                traverse(list);
                after = input("\nInsert Node After (value): ");
                insertAfter(&list, data, after, isCircular);
                break;

            case 3: // Insert at End
                insertAtEnd(&list, data, isCircular);
                break;

            default:
                break;
            }
            traverse(list);
            break;

        case 2: // Remove
            pos = posMenu("Remove");

            if (pos < 0 || pos > 3)
                continue;

            switch (pos)
            {
            case 1: // Remove from Start
                removeFromStart(&list, isCircular);
                break;

            case 2: // Remove After ?
                after = input("\nRemove Node After (value): ");
                removeAfter(&list, after, isCircular);
                break;

            case 3: // Remove from End
                removeFromEnd(&list, isCircular);
                break;

            default:
                break;
            }
            traverse(list);

            break;

        case 3: // Traverse
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
    printf("%s Single Linked List Menu:\n", listType);
    return input(
        "1. Insert\n"
        "2. Remove\n"
        "3. Traverse\n"
        "4. Back\n"
        "5. Exit\n");
}
