/*
    ABOUT: `while loop`

    Use this when you don't know how many times the loop needs to run

*/

#include <stddef.h>
// <stddef> is required to use the `size_t` data type

#include <stdio.h>
// <stdio> is required to use the `printf()` function

// Use the `define` preprocessor macro to define the maximum number
// of elements that the array should have
#define PLAYER_SCORES_SIZE 8

int main() {

    // This is a fixed-sized array of 8 elements

    // indexes:                               0,  1,  2,  3, 4,  5, 6,  7
    int player_scores[PLAYER_SCORES_SIZE] = {15, 24, 8, 40, 9, 19, 5, 10};

    printf("There are %d scores in player_scores\n", PLAYER_SCORES_SIZE);

    printf("\n");

    // Unlike a `for loop`, i is declared outside the
    size_t i = 0;

    while (i < PLAYER_SCORES_SIZE) {
        printf("The value at index %zu is: %d\n", i, player_scores[i]);
        i++;
    }

    // The value at index 0 is: 15
    // The value at index 1 is: 24
    // The value at index 2 is: 8
    // The value at index 3 is: 40
    // The value at index 4 is: 9
    // The value at index 5 is: 19
    // The value at index 6 is: 5
    // The value at index 7 is: 10
}
