/*

    ABOUT: struct modifiers

    The size of the struct is the sum of all of data types of each field,
    plus (depending on the OS running your program) 
    padding characters between each field for optimization.
    The offset on one OS may be different to the offset on another system.

*/

typedef struct {
    int id;
    char firstname[64];
    char lastname[64];
    float income;
    bool is_manager;
} EmployeeNotPacked;

// The `__packed__` attribute will ensure that the compiler doesn't add any
// padding between the fields. 
// This ensures that the struct is the same size 
// on different operating systems.
typedef struct __attribute__((__packed__)) {
    int id;
    char firstname[64];
    char lastname[64];
    float income;
    bool is_manager;
} EmployeePacked;

#include <stdio.h>

int main() {

    //_________________________________________________________________________

    EmployeeNotPacked employee_01 = {
        .id = 1,
        .firstname = "Kate",
        .lastname = "Kendal",
        .income = 344.23f,
        .is_manager = true
    };

    // `%lu` is the format specifier for an `unsigned long`
    printf("Size of employee_01: %lu bytes\n", sizeof(employee_01));
   
    // Size of employee_01: 140 bytes
    
    //_________________________________________________________________________
    
    EmployeePacked employee_02 = {
        .id = 1,
        .firstname = "Kate",
        .lastname = "Kendal",
        .income = 344.23f,
        .is_manager = true
    };

    // `%lu` is the format specifier for an `unsigned long`
    printf("Size of employee_02: %lu bytes\n", sizeof(employee_02));
    // Size of employee_01: 137 bytes

    //_________________________________________________________________________
}
