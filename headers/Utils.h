// Contains utility function viz input menus etc

#ifndef Util
#define Util

#include <stdio.h>
#include <stdlib.h>

/// @brief Display prompt and take int input.
/// @param prompt Message to display.
/// @return Int Input.
int input(char *prompt)
{
    int inp;
    printf("%s", prompt);
    scanf("%d", &inp);
    return inp;
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

#endif