/*
    ABOUT: Functions and header files

    This is is how to modularize your code.

    Modularization simple means to split your code into multiple files,
    so that you don't have on giant `src/main.c` file

    Step 1: Create the header file (a .h file) 
    in the directory called `include`. 
    Then add the function declaration there.

    Step 2: Create a .c file in the `src` directory.
    Use an `#include "CustomFunctions.h`, to link the logic in this C
    file to the header file.

    Step 3: Create the header file in the directory called `include`

*/

// TIP: Move the cursor anywhere on "CustomFunctions.h",
// then press `Ctrl ]` to open the CustomFunctions.h header file

#include "CustomFunctions.h"

#include <stdio.h>

int main() {

    int num_apples = {5};
    int num_peaches = {3};
    int total_fruits = {0};
  
    total_fruits = calc_total_fruits(num_apples, num_peaches);
    printf("total_fruits: %d\n", total_fruits);
    
    greet_user("Dezly");

    return 0;
}
