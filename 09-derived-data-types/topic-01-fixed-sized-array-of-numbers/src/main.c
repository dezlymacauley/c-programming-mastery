/*
    ABOUT: fixed-size array of numbers

    An array is a fixed-size,
    sequential collection of elements of the same type
    that can be accessed using a zero-based index.

*/

#include <stdio.h>

// Use the `define` preprocessor macro to define the maximum number
// of elements that the array should have
#define PLAYER_SCORES_COUNT 3

int main() {

    // This is a fixed-sized array of 3 elements

    // indexes:              0,  1, 2
    int player_scores[PLAYER_SCORES_COUNT] = {20, 18, 5};

    printf("The value at index 0 is %d\n", player_scores[0]);
    // The value at index 0 is 20

    printf("The value at index 1 is %d\n", player_scores[1]);
    // The value at index 1 is 18

    printf("The value at index 2 is %d\n", player_scores[2]);
    // The value at index 1 is 5

    printf("\n");

    printf(
        "There are %d elements in the player_scores list.\n",
        PLAYER_SCORES_COUNT
    );
}
