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

int main() {

    // open(filepath, flags separated by this `|` character )
    int fd = open("./example_one.txt", O_RDWR | O_CREAT, 0644);

    //_________________________________________________________________________

    // O_RDWR and O_CREAT are flags you pass to the open() system call
    // to control how the file is opened.

    // O_RDWR means:
    // O = Open file
    // RD = Reading
    // WR = Writing

    // In simple terms, I want to open the file "./example_one.txt",
    // and I want to be able to read its contents, and modify its contents.

    //_________________________________________________________________________

    // O_CREAT means that the file "./example_one.txt" will be created if
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



    return 0;
}
