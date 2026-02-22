/*

    ABOUT: dynamic-sized array of numbers

    This is a dynamically sized list,
    where each element in the list must have the same variable type.

    `Dynamically sized` simply means that the list does not have
    a fixed size.

    The vector object can be stored in stack memory or in heap memory,
    however, the content of the vector (the elements inside) are always
    stored in heap memory.
*/

#include <stddef.h>
// <stddef.h> is required to use the data type `size_t`

#include <stdlib.h>
// <stdlib.h> is required to use the `malloc()` function

#include <stdio.h>
// <stdio.h> is required to use the `printf()` function

int main() {

    // SECTION: Declaring a vector object on the stack

    // A fixed-sized array has a known size at compile time,
    // so the variable and its contents can both placed on the stack.

    // This is not the case with a dynamic-sized array.
    // For a dynamic-sized array, the variable is stored on the stack,
    // while the actual elements of the variable are stored on the heap.

    //_________________________________________________________________________

    // SECTION: A quick detour to C++...

    // In C++ if you wanted to create a dynamic-sized array of numbers
    // you would import the `#include <vector>` header file,
    // then use the built-in data structure called `vector`,
    //
    // then use `using std::vector;` to bring the `vector` data type into
    // scope from the C++ standard library,
    // so that you can just type `vector<T>` to use it,
    // rather than `std::vector<T>`
    //
    // T is the variable type of each element
    // in the list. So if you wanted a list of `int` elements,
    // then you would use: vector<int>

    // Here's an example of a vector of 8 elements
    // vector<int> player_scores{20, 75, 48, 50, 2, 10, 4, 17};

    // The variable player_scores is stored on the stack,
    // but its elements are stored on the heap.

    // std::vector data structure contains three things:
    //
    // 1. A pointer, T* (E.g. *int),
    // which contains the memory address of the location of in heap memory,
    // where the actual contents of the elements are stored.
    //
    // 2. A variable to keep track of the current number of elements in
    // the vector (size_t)
    //  size_t (which is an integer with a platform dependent size)
    //  On a 32 bit system, size_t is 32 bits (4 bytes)
    //  On a 64 bit system, size_t is 64 bits (8 bytes)

    // 3. A variable to keep track of the capacity (size_t)
    // The capacity is set when you create the vector.
    //
    // The capacity is basically the maximum number of elements,
    // that the vector can store before reallocation happens.
    //
    // Realocation is basically a request to the the operating system for
    // more memory so that the vector can store more elements.
    // After reallocation, the capacity is updated.
    //
    // So if the capacity of the vector = 8, that means:
    // When this vector is created it will be given enough space to store
    // at least 8 elements

    //_________________________________________________________________________

    // SECTION: Now back to C...

    // In C, there's no built-in vector data structure,
    // so you have to create this yourself:

    // First initialize the variables
    int* player_scores = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    //_________________________________________________________________________

    // Next request memory from the operating system

    // I want enough space to store 8 elements,
    // before reallocation happens.
    capacity = 8;

    // malloc returns `void*`
    // Which means a pointer to raw memory. Also known as untyped memory.
    // malloc only allocates, you are in charge of setting the data type.

    // The malloc function requires you to enter the number of bytes in
    // as a size_t data type:
    //
    // Number of bytes required for a dynamic-sized list of `int` data types
    // with an initial capacity of 8 elements can be calculated like this:
    // capacity * the size of an int in bytes
    player_scores = malloc(capacity * sizeof(int));

    if (player_scores == nullptr) {
        printf("Error: Failed to allocate memory to player_scores\n");
        return 1;
    }

    //_________________________________________________________________________

    // Add 8 values to player_scores
    player_scores[0] = 20;
    player_scores[1] = 75;
    player_scores[2] = 48;
    player_scores[3] = 50;
    player_scores[4] = 2;
    player_scores[5] = 10;
    player_scores[6] = 4;
    player_scores[7] = 17;

    // Remember to update the size
    size = 8;

    //_________________________________________________________________________
    
    return 0;
}
