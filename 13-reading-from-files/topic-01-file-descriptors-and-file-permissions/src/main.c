/*
    ABOUT: File descriptors

    In Linux everything is a file.

    A `file descriptors` is an integer that represents an
    open file/resource in a process.

    By default there are 3 file descriptors open for each program:

    0 = stdin
    1 = stdout
    2 = stderr

*/

#include <fcntl.h>
// This is required to use:
// `open()`, `O_RDWR`, `O_CREAT`

#include <stdio.h>
// This is required to use:
// `perror()`

int main() {

    //_________________________________________________________________________
    
    // SECTION: Creating a file descriptor

    // open(filepath, flags separated by this `|` character )
    int fd = open("./src/example_one.txt", O_RDWR | O_CREAT, 0644);

    // O_RDWR and O_CREAT are flags you pass to the open() system call
    // to control how the file is opened.

    // O_RDWR means:
    // O = Open file
    // RD = Reading
    // WR = Writing

    // In simple terms, I want to open the file "./src/example_one.txt",
    // and I want to be able to read its contents, and modify its contents.

    //_________________________________________________________________________

    // O_CREAT means that the file "./src/example_one.txt" will be created if
    // it doesn't exist.

    // O_CREAT, 0644 means if the file is created,
    // it should have the permission 0644:

    // The zero at the start tells C that this number is in octal format.
    // octal format means base 8

    // The next number is for the Owner
    // The next number is for the Group
    // The next number is for the Others

    // So 0644 means
    // The first number `0` tells C that number is in base 8 (octal format).
    // The next number is the permission for the `Owner`
    // The next number is the permission for the `Group`
    // The next number is the permission for the `Others`

    // Linux permissions are represented as three sets of bits:
    // Owner | Group | Others

    // Read (r) → 4
    // Write (w) → 2
    // Execute (x) → 1

    // I want the user that is the `Owner` of the file be able to read 
    // and write to the file:
    // 4 + 2 = 6)

    // I want any users that are part of the `Group` to be able to read the
    // the contents of the file (4)
    
    // Any other users, `Others` can read the file (4)

    //_________________________________________________________________________

    // SECTION: Error handling

    // The `open()` function returns `-1` if it fails to open the file.
    if (fd == -1) {

        // Print a message to stderr
        perror("Error: Failed to open the file 'src/example_one.txt'");

        // Exit the program and return `1` to the main function
        return 1;
    }
    
    //_________________________________________________________________________
    
    // SECTION: How to read the permissions of a file from the command line
    
    // Note this is `shell scripting`, not bash:
    //
    // ls -l example_one.txt
    //
    //.rw-r--r-- dezlymacauley dezlymacauley 47 B Fri Feb 27 06:41:46 2026  example_one.txt

    // The current file permissions are `644`

    // I want to remove all permissions for the owner, group, and others
    // deliberately so that I can check the error handling of this C program

    // chmod 000 src/example_one.txt
  
    // If I try to run this C program now, I should get this error:
    // Error: Failed to open the file 'src/example_one.txt': Permission denied
    // make: *** [Makefile:15: run] Error 1

    //_________________________________________________________________________

    // To return things back to normal

    // ls - l
    // .--------- dezlymacauley dezlymacauley 47 B Fri Feb 27 06:41:46 2026  example_one.txt

    // chmod 644 src/example_one.txt

    //_________________________________________________________________________

    return 0;
}
