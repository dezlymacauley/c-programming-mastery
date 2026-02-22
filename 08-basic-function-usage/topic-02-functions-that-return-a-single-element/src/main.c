/*
    ABOUT: Functions that return a single element

*/

//_____________________________________________________________________________


#include <stdio.h>

int calc_total_fruits(int num_fruit_1, int num_fruit_2) {
    int total = num_fruit_1 + num_fruit_2;
    return total;
}

//_____________________________________________________________________________

// `main` is a function that tells the C++ compiler where it should start
// executing the the program.

// The function `main` returns an integer to the `caller`.
// `0` will be returned if `main` reaches the last line.

int main() {

    int num_apples = 5;
    int num_peaches = 3;
    int total_fruits = 0;

    total_fruits = calc_total_fruits(num_apples, num_peaches);
    printf("total_fruits: %d\n", total_fruits);

    return 0;
}

