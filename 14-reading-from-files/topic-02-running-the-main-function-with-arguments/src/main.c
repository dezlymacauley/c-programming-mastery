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


    // TIP: To supply additional arguments (arv[1], argv[2] and so on),
    // do this, use `ARGS=` for EACH additional argument.

    // make run ARGS="argument_one, argument_two"
    // E.g.
    // make run ARGS="kamen" ARGS="rider"

    // Its three arguments in total
    // argv[0] + two arguments from the user
    if (argc != 3) {
        printf("You need to supply two arguments\n");
    }

    return 0;
}
