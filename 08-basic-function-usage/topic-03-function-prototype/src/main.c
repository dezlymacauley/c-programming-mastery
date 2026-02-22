/*
    ABOUT: Function prototype

    In C a function can't be used before the line where 
    the function defined.

    In C if you want to used a function before it is defined,
    you must have a `function declaration` (also called the function prototype)

*/

//_____________________________________________________________________________

// SECTION: How to write a function declaration

int calc_total_fruits(int num_fruit_1, int num_fruit_2);

//_____________________________________________________________________________

#include <stdio.h>

int main() {

    int num_apples = 5;
    int num_peaches = 3;
    int total_fruits = 0;

    total_fruits = calc_total_fruits(num_apples, num_peaches);
    printf("total_fruits: %d\n", total_fruits);

    return 0;
}

int calc_total_fruits(int num_fruit_1, int num_fruit_2) {
    int total = num_fruit_1 + num_fruit_2;
    return total;
}

//_____________________________________________________________________________
