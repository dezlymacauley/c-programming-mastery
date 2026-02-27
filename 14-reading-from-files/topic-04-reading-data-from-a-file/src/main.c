/*
    ABOUT: Reading data from a file

    Fun fact: SQLite, which is onethe most popular serverless databases,
    is written in C.

    And to be clear, when I say serverless, I mean truly serverless.
    Not the cloud computing definition of serverless where a cloud provider
    like AWS manages a server for you.

    With SQLite, there is no server at all. The SQLite engine is a C libray,
    and your database is in a single file.

    When SQLite opens a .sqlite file,
    the very first thing it does is read the header to understand what
    it's dealing with — before it reads a single row of data.

*/

typedef struct {
    // The version of the file type. E.g. version 1
    unsigned short version;

    // The number of employees in the database
    unsigned short employees;

    // To check if the file is corrupted?
    unsigned short filesize;
} DatabaseHeader;

#include <fcntl.h>
// This is required to use:
// `open()`, `O_RDONLY`

#include <stdio.h>
// This is required to use:
// `fprintf()`

#include <unistd.h>
// This is required to use:
// `read()`
// `close()`

int main(int argc, char* argv[]) {

    if (argc != 2) {
        fprintf(stderr, "\n");
        fprintf(stderr, "Error: You need to supply one argument\n");
        fprintf(stderr, "Usage:\n");
        fprintf(stderr, "program_name filename\n");
        fprintf(stderr, "\n");
        return 1;
    }

    char* file_name = argv[1];

    int fd = open(file_name, O_RDONLY);

    if (fd == -1) {
        fprintf(
            stderr, "Error: Failed to open the file 'src/example_one.txt'\n"
        );
        return 1;
    }

    //_________________________________________________________________________

    // SECTION: Reading from a file

    // A variable to store the database header
    DatabaseHeader db_head = {0};

    // Error handling
    if (read(fd, &db_head, sizeof(db_head)) != sizeof(db_head)) {
        fprintf(stderr, "Error: Failed to read the file %s\n", file_name);

        // Close the file
        close(fd);
        
        // Exit the program and return the exit code of 1 to main
        return 1;
    }

    // %u is the format specifier for unsigned integer
    printf("db_head.version: %u\n",db_head.version);
    printf("db_head.employees: %u\n",db_head.employees);
    printf("db_head.filesize: %u\n",db_head.filesize);

    // To run this project:
    // make run ARGS="my_db_header.sqlite"
    // db_head.version: 1
    // db_head.employees: 255
    // db_head.filesize: 8

    //_________________________________________________________________________

    // SECTION: Remember to close the file once you are done using it
    close(fd);

    //_________________________________________________________________________

    return 0;
}
