/*

    ABOUT: typedef struct

    This is another way of declaring a `struct` in C

    I prefer this style because it makes creating an instance much neater

*/


typedef struct {
    int id;
    char firstname[64];
    char lastname[64];
    float income;
    bool is_manager;
} Employee;

#include <stdio.h>

int main() {

    Employee employee_01 = {
        .id = 1,
        .firstname = "Kate",
        .lastname = "Kendal",
        .income = 344.23f,
        .is_manager = true
    };

    printf("id: %d\n", employee_01.id);
    printf("firstname: %s\n", employee_01.firstname);
    printf("lastname: %s\n", employee_01.lastname);

    // When using printf you use the format specifier `%f` for both
    // float and double
    printf("income: %.2f\n", employee_01.income);

    // C does not have a dedicated data type for bool
    // 0 = false
    // 1 = true
    printf("is_manager: %s\n", employee_01.is_manager ? "true" : "false");

    // id: 1
    // firstname: Kate
    // lastname: Kendal
    // income: 344.23
    // is_manager: true
}
