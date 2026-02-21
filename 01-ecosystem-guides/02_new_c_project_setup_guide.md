# New C Project Setup Guide
_______________________________________________________________________________

Create the project directory
```sh
mkdir name-of-project
```

Enter the project directory
```sh
cd name-of-project
```

For the rest of this guide, all commands should be run from this directory.
_______________________________________________________________________________

Create the project structure
```sh
mkdir bin/
mkdir src/
mkdir include/
touch src/main.c
touch .clang-format
touch .clangd
touch Makefile
```
_______________________________________________________________________________

### Configure the project
_______________________________________________________________________________

Add this to the `src/main.c` file

```cpp
#include <stdio.h>

int main() {
    printf("C Programming Mastery\n");
    return 0;
}
```
_______________________________________________________________________________

Add this to the `.clang-format` file

```yaml
# Tell clang-format that the sytnax in the file is C code
Language: C

# 4 space indentation
IndentWidth: 4

# Lines longer than 80 characters will be wrapped
ColumnLimit: 80

AccessModifierOffset: -4
PointerAlignment: Left
AllowShortFunctionsOnASingleLine: false

# When parameters don't fit on one line, break them all onto the next line
# and place the closing parenthesis on its own line
AlignAfterOpenBracket: BlockIndent
```
_______________________________________________________________________________

Add this to the `.clangd` file

```yaml
CompileFlags:
  Add: [-std=c23, -Iinclude, -Wconversion, -Wunused-variable ]
```

`-std=c23` tells the `clangd` language server to interpret the code using 
the C23 standard.

`-Iinclude` tells the `clangd` language server that the header files of your
project can be found in the directory called `include`.

The two settings above will ensure that you don't get false warnings from
the `clangd` language server.

_______________________________________________________________________________

Add this to the `Makefile`

```make
.SILENT:
.PHONY: run clean

# Compile Settings
COMPILER = clang
FLAGS = -std=c23 -isystem /usr/include -B /usr/lib -I include -Wconversion -Wunused-variable  

# Build Settings
INPUT = src/*.c
OUTPUT = bin/main

run:
	mkdir -p bin/
	bear -- $(COMPILER) $(FLAGS) $(INPUT) -o $(OUTPUT)
	./bin/main

clean:
	rm -rf bin/
```

The flags below are needed because the `clang` package installed via `mise`
is a self-contained binary that does not include the C standard library
headers or the C runtime startup files, unlike the system `clang` package.
```
-isystem /usr/include -B /usr/lib 
```

-isystem /usr/include   tells clang where to find the C standard library
                        headers (e.g. stdio.h, stdlib.h)

-B /usr/lib             tells clang where to find the C runtime startup
                        files (e.g. Scrt1.o, crti.o) that are required
                        for linking

_______________________________________________________________________________

## How to run your project

Make sure that you are in the root of the project and then run this command:

```sh
make
```

This will generate a `compile_commands.json` file,
a `bin/main` file, and if you open a C++ file in your project,
you'll also have a `.cache` directory in your project.

_______________________________________________________________________________

To run the latest version of your compiled binary:
```
./bin/main
```
_______________________________________________________________________________
