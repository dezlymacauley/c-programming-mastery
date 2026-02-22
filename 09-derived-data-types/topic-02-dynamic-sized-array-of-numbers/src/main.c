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

// #include <print>
// using std::println;
//
// #include <vector>
// using std::vector;

#include <stddef.h>
// This is required to use the data type `size_t`

int main() {

    // SECTION: Declaring a vector object on the stack

    // A fixed-sized array has a known size at compile time,
    // so the variable and its contents can both placed on the stack.

    // This is not the case with a dynamic-sized array.
    // For a dynamic-sized array, the variable is stored on the stack,
    // while the actual elements of the variable are stored on the heap.

    // E.g. A quick detour to C++... 

    // In C++ if you wanted to create a dynamic-sized array of numbers 
    // you would import the `#include <vector>` header file,
    // then use the built-in data structure called `vector` 
    // by using std::vector<T>.
    //
    // T is the variable type of each element
    // in the list.

    //_________________________________________________________________________
    
    // std::vector contains three things:
    // 1. A pointer, T* (E.g. *int),
    // which contains the memory address of the location of in heap memory,
    // where the actual contents of the elements are stored.
    //
    // 2. A variable to keep track of the current number of elements (size_t)
    //
    // 3. A variable to keep track of the capacity (size_t)
    // The capacity is set when you create the list.
    // The capacity is basically the maximum number of elements,
    // that a dynamic-sized list can store before reallocation happens.
    // Realocation is basically a request to the the operating system for 
    // more memory to store more elements. 
    // After that, the capacity is updated.
    
    //_________________________________________________________________________

    // In C, there's no built-in vector data structure, 
    // so you have to create it yourself.

    int* player_scores = nullptr;
    size_t

    // vector<int> player_scores{20, 75, 48};

    //_________________________________________________________________________

    // SECTION: How to print the number of elements

    // println("There are {} elements in player_scores", player_scores.size());
    // There are 3 elements in player_scores

    //_________________________________________________________________________

    // SECTION: How to print the size of a vector

    // println("The size of player_scores is {} bytes", sizeof(player_scores));
    // The size of player_scores is 24 bytes

    //_________________________________________________________________________

    // SECTION: Understanding how the size of a vector is made up

    // NOTE: Unlike a fixed size array the size of a vector is NOT:
    // The size of each element * number of elements.

    // E.g.
    // vector<int> player_scores{50, 40, 20};

    // This vector contains 3 elements,
    // and each element is an int.
    // The size of an int is 4 bytes.

    // However 4 bytes * 3 elements = 12 bytes

    // However when `sizeof` was used, it showed that the size of the vector,
    // was actually 24 bytes.

    // So what is taking up the extra 12 bytes?

    //_________________________________________________________________________

    // SECTION: In C++ a vector stores three things

    //  1. a pointer (a memory address) to the location of the elements
    //  in heap memory.
    //  This is stored in the data type:
    //  T* (where T is the data type of the elements).
    // println("1. Pointer size: {} bytes", sizeof(int*));
    // 8 bytes

    //  2. The current number of elements.
    //  This is stored in the data type:
    //  size_t (which is an integer with a platform dependent size)
    //  On a 32 bit system, size_t is 32 bits (4 bytes)
    //  On a 64 bit system, size_t is 64 bits (8 bytes)
    // println("2. size_t = {} bytes", sizeof(size_t));

    //  3. The maximum elements the vector can store before reallocation
    //  happens.
    //  This is stored in the data type:
    //  size_t (which is an integer with a platform dependent size)
    //  On a 32 bit system, size_t is 32 bits (4 bytes)
    //  On a 64 bit system, size_t is 64 bits (8 bytes)
    // println("3. another size_t = {} bytes", sizeof(size_t));
    // // 8 bytes

    // So 8 bytes + 8 bytes + 8 bytes = 24 bytes

    // And that's why this is 24 bytes
    // println("The size of player_scores is {} bytes", sizeof(player_scores));
    // The size of player_scores is 24 bytes

    //_________________________________________________________________________

    return 0;
}
