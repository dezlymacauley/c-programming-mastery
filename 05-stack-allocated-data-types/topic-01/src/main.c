/*
    ABOUT: int

    This is the syntax for declaring variables in C:
    data_type variable_name = initial value;

*/

/*
  ABOUT: The compilation process

  The 4 Steps to compile human-readable C code into machine code.
  1. Preprocessor
  2. Compilation
  3. Assembling
  4. Linking

  SUB_SECTION: Step 1 - Preprocessor

  `#` is called the pound symbol or the `#` symbol.
  In C, any line that starts with `#` is called a preprocessor directives.

  This tells C that the line does not contain regular C code,
  but instructions that should be peformed BEFORE the code is compiled.

  The preprocessor replaces text in your code, or inserts text into your code.

  _____________________________________________________________________________
  `#include`

  An example of a preprocessor directive would be `#include`

  E.g. `#include <stdio.h>` tells the preprocessor to include the contents
  of the file stdio.h into your code.

  stdio.h is a header file from the C standard library.
  The C standard library is a collection of useful functions and data
  structures that make things more convinient when writing C code.

  The `stdio` in stdio.h stands for `standard input, standard output`.
  stdio.h includes functions like `printf()`
  for displaying the output of some code to the terminal.

  A header file, is a file that has a `.h` file extension.
  stdio.h would contain the function signature of functions like `printf()`.

  The function signature is simply a statement that includes the return
  type of the function, its name, and the parameters (if any) that it needs
  to work.

  The actual logic of the function will be stored in a `.cpp` file somewhere.
  E.g. stdio.h would have a file called stdio.cpp, but to use functions from
  the `.cpp` file, you only need the header.

  _____________________________________________________________________________

  `#define`

  This is used to create constants.

  E.g.

  #define MAX_PERSONS 1024

  The preprocessor will search for the `MAX_PERSONS` text in your code,
  and replace the text with 1024.

  _____________________________________________________________________________

  `#define DEBUG_MODE` 

  This is similar to the concept of using printf() to print values,
  except that you can toggle this on and off by commenting or uncommenting
  the line.

  By the way `DEBUG_MODE` can be renamed to whatever you want.

NOTE: A cool feature about this preprocessor directive is that you can
comment it out in your code... and then enable it at compile time.
Just add `-D WHATEVER_YOU_CALLED_IT`

    run:
        mkdir -p bin/
        bear -- $(COMPILER) $(FLAGS) $(INPUT) -o $(OUTPUT)
        ./bin/main

*/

//_____________________________________________________________________________

#include <stdio.h>

#define MAX_PERSONS 1024
#define DEBUG_MODE

int main() {
 
  printf("MAX_PERSONS is set to %d\n", MAX_PERSONS);
  // MAX_PERSONS is set to 1024

  int player_id = 201;
  printf("player_id: %d\n", player_id);

  // This line of code will only run if the preprocessor sees the line
  // `#define DEBUG_MODE`
  #ifdef DEBUG_MODE
    printf("This program has been run in DEBUG_MODE\n");
  #endif
  
  return 0;
}

//_____________________________________________________________________________
