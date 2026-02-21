/*
    ABOUT: if statement

    This is best for handling 1 to 3 potential outcomes

*/

#include <stdio.h>
int main() {

    int num_apples= 10;

    printf("num_apples is %d\n", num_apples);

    if (num_apples > 10) {
        printf("num_apples is greater than 10\n");
    } else if (num_apples == 10) {
        printf("There are exactly 10 apples\n");
    } else {
        printf("There are less than 10 apples\n");
    }

    return 0;
}
