/*
    ABOUT: File descriptors
*/

#include <fcntl.h>
// This is required to use:
// `open()`, `O_RDWR`, `O_CREAT`

#include <stdio.h>
// This is required to use:
// `perror()`

#include <unistd.h>
// This is required to use:
// `write()`
// `close()`

#include <string.h>
// This is required to use:
// `strlen()`

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

    int fd = open(file_name, O_RDWR | O_CREAT, 0644);

    if (fd == -1) {
        perror("Error: Failed to open the file 'src/example_one.txt'");
        return 1;
    }

    //_________________________________________________________________________
   
    // SECTION: Writing data to the file

    char* my_message = "Never give up.\n";

    write(fd, my_message, strlen(my_message));

    //_________________________________________________________________________
    
    // SECTION: Remember to close the file once you are done using it

    close(fd);

    //_________________________________________________________________________

    return 0;
}
