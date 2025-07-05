#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "int.h"

int get_int(const char *prompt)
{
    // Stores up to 100 characters
    char input[100];
    int integer;

    // Loop until a valid positive integer greater than 0 is entered
    while (1)
    {
        // Prints prompt passed to the function
        printf("%s", prompt);

        // Read input from user and store it in input
        fgets(input, sizeof(input), stdin);
         
        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Assume input has no spaces (true)
        int is_clean_number = 1;
        for (int i = 0; input[i] != '\0'; i++) 
        {
            if (input[i] == ' ' || isalpha(input[i]) == 1 || ispunct(input[i]) == 1)
            {
                // Input has space so it is not a clean number (false)
                is_clean_number = 0;
                break;
            }
        }

        /* Convert input string to integer
        IF string is not a number, return 0*/
        integer = atoi(input);

        // Check if number is valid
        // check if is_clean_number is true (= 1)
        if ((integer != 0 || input[0] == '0') && is_clean_number)
        {
            return integer;
        }
    }
}