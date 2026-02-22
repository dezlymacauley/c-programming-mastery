#include "CustomFunctions.h"

#include <stdio.h>

int calc_total_fruits(int num_fruit_1, int num_fruit_2) {
    int total = num_fruit_1 + num_fruit_2;
    return total;
}

void greet_user(char* user_name) {
    printf("Hello %s\n", user_name);
}
