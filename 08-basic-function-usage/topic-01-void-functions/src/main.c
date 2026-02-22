/*
    ABOUT: Void Functions

    A function is a block of resuable code that can be used to perform
    a specific task. 

    Functions are used to make the code of a program modular.
    I.e. Splitting in the logic of the program into smaller sections.

    The syntax of a function in C

    return_type function_name(function_parameters) {

        // This is the body of the function.
        // The body contains the instruction that 
        // the function should execute when it is called.

    }

    What is a void function?

    A void function is a function that does not return a value back 
    to the caller.  The simplest way to confirm if a function is a void
    function is to ask this question:

    Can the function be used to initialize or update the value of a variable?

    If the answer is no, then its a void function.

*/

//_____________________________________________________________________________

#include <stdio.h>

void greet_user(char* user_name) {
    printf("Hello %s\n", user_name);
}

void say_goodbye() {
    printf("Goodbye\n");
}

//_____________________________________________________________________________

// `main` is a function that tells the C compiler where it should start
// executing the the program.

// The function `main` returns an integer to the `caller`,
// the operating system.
//
// `0` will be returned if `main` reaches the last line.

int main() {

    greet_user("Dezly");

    say_goodbye();

    return 0;
}
