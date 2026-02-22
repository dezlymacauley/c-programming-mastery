/*
    ABOUT: fixed-size array of char

    This is how to create a string in C

*/

#include <stdio.h>

// Use the `define` preprocessor macro to define the maximum number
// of elements that the array should have
#define CURRENCY_CODE_COUNT 3

int main() {

    //_________________________________________________________________________

    // SECTION: How to declare the array

    // This is how to create a fixed-size string of 4 characters
    // 3 characters for the currency code,
    // and 1 character for the `\0` null terminator.

    // The null terminator is not visible when you print the array.

    // The null terminator `\0` is what tells the program that this is
    // the end of the string.

    // TIP: Don't forget the null terminator `\0`

    // Indexes:                                     0,   1,   2,    3
    char currency_code[CURRENCY_CODE_COUNT + 1] = {'e', 'u', 'r', '\0'};

    //_________________________________________________________________________

    // SECTION: How to print each letter of the array on a new line

    for (int i = 0; i < CURRENCY_CODE_COUNT; i++) {
        printf("%c\n", currency_code[i]);
    }
    // e
    // u
    // r

    // Just adding a space before printing out the results 
    // of the next section.
    printf("\n");

    //_________________________________________________________________________

    // SECTION: How to print each letter of the array on a single line
    
    for (int i = 0; i < CURRENCY_CODE_COUNT; i++) {

        // I want a comma and a space to be added after each character,
        // except for the second last character in the array.

        // In simple terms:
        // Add a comma and a space, after index 0, and index 1
        if (i < CURRENCY_CODE_COUNT - 1) {
            printf("%c, ", currency_code[i]);
        } else {
            // Don't add a comma and a space after index 2,
            // because that is the currency_code
            printf("%c\n", currency_code[i]);
        }
    }
    // e, u, r

    //_________________________________________________________________________
}
