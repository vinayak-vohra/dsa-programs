// Wap to perform array operations: [traverse, insert, remove, search, sort]

#include <stdio.h>   // for printf
#include <stdlib.h>  // for malloc
#include <stdbool.h> // for boolean

int N;      // Max Size
int end;    // Current end
int *array; // Dynamic Allocation

/**
 * end : [-1, N - 1]
 * -1    : when array is empty.
 * N - 1 : when array is full.
 */

// ---------- Declarations ----------
void rShift(int);
void lShift(int);

void traverse();
int linearSearch(int);
void selectionSort();

void insertElemAt(int, int);
void removeElemFrom(int);

void mainMenu();
int posMenu(char *);
int input(char *);
// End - Declarations

// ---------- Main ----------
int main()
{
    N = input("Enter Max Array Size: ");

    // size can't be 0 or -ve
    if (N < 1)
    {
        printf("Error: Invalid Array Size(%d).", N);
        exit(-1); // exit program
    }

    // init end & array
    end = -1;
    array = (int *)malloc(N * sizeof(int));

    mainMenu(); // Menu Driven Code
}
// End - Main

// ---------- Definitions ----------

/// @brief Shift Array elements to the right.
/// @param from Shift from this index.
void rShift(int from)
{
    for (int i = end; i >= from; i--)
        array[i + 1] = array[i];
}

/// @brief Shift Array elements to the left.
/// @param till Shift till this index.
void lShift(int till)
{
    for (int i = till; i <= end; i++)
        array[i] = array[i + 1];
}

/// @brief Prints the array
void traverse()
{
    for (int i = 0; i <= end; i++)
        printf("%d ", array[i]);
    printf("\n");
}

/// @brief Search for item linearly.
/// @param item Item to be search.
/// @return Index of item, if found. Else -1.
int linearSearch(int item)
{
    for (int i = 0; i <= end; i++)
        if (array[i] == item)
            return i;

    return -1;
}

void selectionSort()
{
    int min;
    for (int i = 0; i <= end; i++)
    {
        min = i; // assume as minimum

        for (int j = i + 1; j <= end; j++)
            if (array[j] < array[min]) // smaller element found,
                min = j;               // update min.

        // swap minimum element
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

/// @brief Insert new element in the array.
/// @param elem Element to be inserted.
/// @param index Insert at this index.
void insertElemAt(int elem, int index)
{
    // Array is Full
    if (end == N - 1)
    {
        printf("Error: Max Size Reached.\n");
        return;
    }

    // Insert at End (no shift required)
    if (index > end)
        array[++end] = elem;

    // Insert at Index (shift required)
    else
    {
        rShift(index);       // make space for new element
        array[index] = elem; // insert at index
        end++;               // update end
    }
}

/// @brief Remove Element from the array.
/// @param index Remove from this index.
void removeElemFrom(int index)
{
    // Array Empty
    if (end == -1)
    {
        printf("Error: Already Empty.\n");
        return;
    }

    // Invalid index
    else if (index < 0 || index > end)
    {
        printf("Error: Invalid Index(%d).\n", index);
        return;
    }

    // Shift left if index is not end
    if (index != end)
        lShift(index);

    end--;
}

/// @brief Menu Driven Code
void mainMenu()
{
    int choice;
    do
    {
        system("cls");
        choice = input(
            "Array Operations:\n"
            "1. Insert.\n"
            "2. Remove.\n"
            "3. Traverse.\n"
            "4. Search\n"
            "5. Sort.\n"
            "0. Exit.\n");
        int index, option, elem;

        switch (choice)
        {

        case 1: // Insert
            option = posMenu("Insert");

            if (option < 1 || option > 3)
                continue;

            elem = input("Enter element to insert: ");

            // Insert Sub-Menu
            switch (option)
            {
            case 5:
                exit(0);

            case 1: // Insert at Start
                insertElemAt(elem, 0);
                break;

            case 2: // Insert at Index
                index = input("Enter index to insert at: ");
                insertElemAt(elem, index);
                break;

            case 3: // Insert at End
                insertElemAt(elem, end + 1);
                break;

            default:
                break;
            }
            break;

        case 2: // Remove
            option = posMenu("Remove");

            if (option < 1 || option > 3)
                continue;

            // Remove Sub-Menu
            switch (option)
            {
            case 5:
                exit(0);

            case 1: // Remove from Start
                removeElemFrom(0);
                break;

            case 2: // Remove from Index
                index = input("Enter index to insert at: ");
                removeElemFrom(index);
                break;

            case 3: // Remove from End
                removeElemFrom(end);
                break;

            default:
                break;
            }
            break;

        case 3: // Traverse
            traverse();
            break;

        case 4: // Search
            index = linearSearch(input("Enter element to search: "));

            if (index == -1) // not found
                printf("%d not found.\n");

            else // found
                printf("%d found at: %d.\n",
                       elem, index);
            break;

        case 5: // Sort
            selectionSort();
            traverse();
            break;

        case 0: // Exit
            exit(0);

        default:
            break;
        }
        system("pause");
    } while (choice);
}

/// @brief Insert/Remove Options.
/// @param operation Operation Name: Insert or Remove.
/// @return Selected choice.
int posMenu(char *operation)
{
    system("cls");
    printf("%s:\n", operation);

    return input("1. at the start.\n"
                 "2. at given index.\n"
                 "3. at the end.\n"
                 "4. Back\n"
                 "5. Exit\n"
                 "Select: ");
}

/// @brief Display prompt and take int input.
/// @param message Message to display.
/// @return Int Input.
int input(char *message)
{
    int inp;
    printf("%s", message);
    scanf("%d", &inp);
    return inp;
}
// End - Definitions