/*
    ABOUT: Running the `main()` function with command line arguments

*/

#include <stdio.h>
// This is required to use:
// `printf()`

// `argc` which stands for argument count,
// is the number of command line arguments passed to the `main` function

//  `argv` which stands for argument vector,
//  is just an array of strings (the actual command line arguments)
int main(int argc, char* argv[]) {

    printf("argv[0] is: %s\n", argv[0]);
    // The first arguement at index 0 of argv is this:
    // argv[0] is: ./bin/main

    //_________________________________________________________________________

    // SECTION: How to supply additional arguments (arv[1],
    // argv[2] and so on), from the Makefile

    // make run ARGS="argument_one, argument_two"
    // E.g.
    // make run ARGS="kamen rider"

    // See the Makefile in this project

    //_________________________________________________________________________

    // SECTION: How to supply additional arguments (arv[1],
    // argv[2] and so on),
    // from the command line (Using the binary executable)

    // Do this:
    // ./bin/main kamen rider

    //_________________________________________________________________________

    // Its three arguments in total
    // argv[0] + two arguments from the user
    if (argc != 3) {
        fprintf(stderr, "You need to supply two arguments\n");
        fprintf(stderr, "Usage:\n");
        fprintf(stderr, "program_name argument_one argument_two\n");
        return 1;
    }

    printf("argv[1] is: %s\n", argv[1]);
    // argv[1] is: kamen

    printf("argv[2] is: %s\n", argv[2]);
    // argv[2] is: rider

    return 0;
}
