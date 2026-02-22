/*

    ABOUT: nested for loop

    A nested for loop is used when you want to work with a list
    that contains nested lists.

    This is often called a 2D (two dimensional) array.

    Here's a practical example

    So I have a database that has a table called `Weekly Sales`
    This table contains the weekly sales for three shops.

    | Name            | Mon | Tue | Wed | Thu | Fri | Sat | Sun |
    | --------------- | --- | --- | --- | --- | --- | --- | --- |
    | Gojo Specs      | 100 | 200 | 150 | 300 | 400 | 500 | 450 |
    | Techie Haven    | 210 | 320 | 270 | 180 | 390 | 260 | 310 |
    | Raikage Tea     | 430 | 140 | 380 | 220 | 290 | 170 | 340 |

    If you had to convert this to C,
    the `Weekly Sales` table would be a list that contains three other
    lists.

    For this specific guide, I'm deliberately making two design constraints
    to keep the focus of this guide on nested lists:

    1. I have chosen to use a fixed-sized list that contains nested
    fixed-sized list so that there is no need for heap allocation.

    2. I have decided to exclude the column with the shop names so that
    there is no need for a struct because all the data
    in the weekly column is of the type `int`

    So now all the values are integers.

    | Mon | Tue | Wed | Thu | Fri | Sat | Sun |
    | --- | --- | --- | --- | --- | --- | --- |
    | 100 | 200 | 150 | 300 | 400 | 500 | 450 |
    | 210 | 320 | 270 | 180 | 390 | 260 | 310 |
    | 430 | 140 | 380 | 220 | 290 | 170 | 340 |

*/

#include <stddef.h>
// To use `size_t`

// Keep track of the number of rows and columns
#define NUM_ROWS 3
#define NUM_COLS 7

#include <stdio.h>
int main() {

    // ________________________________________________________________________

    // SECTION: Declaring a nested array

    // 2D array: 3 rows (shops) × 7 columns (sales for each day of the week)
    int weekly_sales[NUM_ROWS][NUM_COLS] = {
        // Columns:
        // 0,  1,   2,   3,   4,   5,   6
        // Mo, Tu,  We,  Th,  Fr,  Sa, Sun
        {100, 200, 150, 300, 400, 500, 450}, // Row 0: Gojo Specs
        {210, 320, 270, 180, 390, 260, 310}, // Row 1: Techie Haven
        {430, 140, 380, 220, 290, 170, 340}  // Row 2: Raikage Tea
    };

    // Since arrays are zero-indexed I have numbered the rows and columns
    // according to this to avoid complicating things:
    //
    // So the first row is called Row 0,
    // and the first column is called Column 0

    // E.g.
    // The value of Row 0, column 0 is 100
    // The value of Row 2, column 4 is 290

    // ________________________________________________________________________

    // SECTION: How to manually access a value in a nested array

    // Row 0, column 2
    printf("Sales for Gojo Specs on Wednesday: %d\n", weekly_sales[0][2]);
    // Sales for Gojo Specs on Wednesday: 150

    // ________________________________________________________________________

    // SECTION: How to iterate over the elements of a nested array

    // TIP: First I'll just perform a best practice check to ensure that the
    // weekend_sales table is not empty before I attempt to run any loops.

    if (NUM_ROWS > 0) {

        // Just an empty space before printing the contents of the list
        printf("\n");

        // Next, I need a `for loop` to go through each row
        // in the weekly_sales table (The main list).
        // This loop is called the outer loop.
        for (size_t i = 0; i < NUM_ROWS; i++) {

            // print the name of the shop based on the index,
            // the break out of the switch statement and print the data
            switch (i) {
            case 0:
                printf("😎 Gojo Specs\n");
                break;
            case 1:
                printf("💻 Techie Haven\n");
                break;
            case 2:
                printf("🧋 Raikage Tea\n");
                break;
            }

            // print a line before printing the data
            printf("=======================\n");
            printf("\n");

            // Next, you need a `for loop` to go through each column
            // in each row (each nested list)
            // Since the variable name `i` is already in use,
            // I have to use another variable name for the index.
            // So I just chose `j` because it's
            // the next letter of the alphabet.
            for (size_t j = 0; j < NUM_COLS; j++) {
                switch (j) {
                    case 0:
                        printf("Mon: %d\n", weekly_sales[i][j]);
                        break;
                    case 1:
                        printf("Tue: %d\n", weekly_sales[i][j]);
                        break;
                    case 2:
                        printf("Wed: %d\n", weekly_sales[i][j]);
                        break;
                    case 3:
                        printf("Thu: %d\n", weekly_sales[i][j]);
                        break;
                    case 4:
                        printf("Fri: %d\n", weekly_sales[i][j]);
                        break;
                    case 5:
                        printf("Sat: %d\n", weekly_sales[i][j]);
                        break;
                    case 6:
                        printf("Sun: %d\n", weekly_sales[i][j]);
                        break;
                }
            }

            // Add a space after printing out each column
            printf("\n");
        }

    } else {
        printf("The weekly_sales table is empty\n");
    }

    return 0;
}

/*
    NOTE: This should be the ouput

    The value of row 2, column 4 is: 180

    😎 Gojo Specs
    =======================

    Mon: 100
    Tue: 200
    Wed: 150
    Thu: 300
    Fri: 400
    Sat: 500
    Sun: 450

    💻 Techie Haven
    =======================

    Mon: 210
    Tue: 320
    Wed: 270
    Thu: 180
    Fri: 390
    Sat: 260
    Sun: 310

    🧋 Raikage Tea
    =======================

    Mon: 430
    Tue: 140
    Wed: 380
    Thu: 220
    Fri: 290
    Sat: 170
    Sun: 340

*/
