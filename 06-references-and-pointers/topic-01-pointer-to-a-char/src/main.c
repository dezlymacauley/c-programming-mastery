/*
    ABOUT: char*

    The data type `char` is 1 byte (8 bits)

*/

#include <stdio.h>
// Required for using:
// `printf()`

int main() {

    //_________________________________________________________________________

    // SECTION: Recap on char

    char my_letter = 'D';

    // How to print the char
    printf("my_letter: %c\n", my_letter);
    // my_letter: D

    // How to print the inter encoding value of of char,
    // also known as its ASCII code.
    printf("my_letter: %d\n", my_letter);
    // my_letter: 68

    //_________________________________________________________________________

    // SECTION: char*

    // In C a string is just a sequence of char elements,
    // that ends with null byte (also called an null terminator),
    // that looks like this '\0'

    // The null terminator tells C where the string ends.

    char* user_name = "Jin Lee";

    // This is stored in memory as:
    // 'J', 'i', 'n', ' ', 'L', 'e', 'e', '\0'

    // To print a char* in C, you use the format specifier %s,
    // this tells C to continue printing each character,
    // excluding the the null terminator '\0'
    // The `s` in `%s` stands for string

    printf("user_name: %s\n", user_name);
    // user_name: Jin Lee

    //_________________________________________________________________________

    // SECTION: How to print the memory address where the string is stored,
    // or to be more specific, 
    // the memory address of the first char in the string.

    printf(
        "The contents of user_name are stored at the memory address: %p\n",
        (void*)user_name
    );

    // What's `(void*)`?
    // The format specifier `%p` in `printf()` is used to print pointers,
    // aka memory addresses. This format specifier needs the data type of
    // the variable that it is printing to be of the type `void*`

    // void

    //_________________________________________________________________________

    return 0;
}
