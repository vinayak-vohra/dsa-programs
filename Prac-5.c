// P5: Wap to implement stack ops: [push, pop] using arrays

// Headers
#include <stdio.h>
#include <stdlib.h>

int N;      // Size of Stack
int top;    // Top of Stack
int *stack; // Stack Pointer [dynamic array]

/// @brief View Top of Stack
int getTop()
{
    if (top == -1)
    {
        printf("\nStack Empty.");
        return top;
    }
    return stack[top];
}

/// @brief Push New Value in Stack.
/// @param val Value to be pushed.
void push(int val)
{
    // Overflow
    if (top == N - 1)
    {
        printf("Stack Overflow.\n");
        return;
    }

    stack[++top] = val;
}

/// @brief Pop Top from the Stack
void pop()
{
    // Underflow
    if (top == -1)
    {
        printf("Stack Underflow.\n");
        return;
    }

    printf("Popped: %d\n", stack[top--]);
}

int main()
{
    printf("Enter Size of Stack: ");
    scanf("%d", &N);

    top = -1;                               // initialise top
    stack = (int *)malloc(N * sizeof(int)); // dynamic array

    int choice;

    do
    {
        system("cls");
        printf("Stack Operations[top: %d, size: %d]:\n"
               "1. Push\n"
               "2. Pop\n"
               "3. Top\n"
               "4. Exit\n"
               "Select> ",
               top, N);
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int val;
            printf("Enter Value to add: ");
            scanf("%d", &val);
            push(val);
        }
        break;

        case 2:
            pop();
            break;

        case 3:
            printf("%d", getTop());
            break;

        case 4:
            return 0;

        default:
            printf("Please enter a valid choice.\n");
        }
        printf("\n");
        system("pause");
    } while (choice != 4);
}