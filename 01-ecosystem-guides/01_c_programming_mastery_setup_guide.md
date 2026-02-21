# C Programming Mastery Setup Guide
_______________________________________________________________________________

## Install `clangd` (system-wide installation)

clangd is a language server for both C and C++ code.

On Arch Linux `clangd` is bundled with the `clang` package
```sh
sudo pacman -S --needed clang
```

Note: The `clang` package that is available in `mise`,
a tool that will be installed later in this guide does not include `clangd`,
this why I installed the `clang` package from Arch Linux as well.
_______________________________________________________________________________

## Instal `bear` (system-wide installation)

`bear` is a rust-powered tool that you add to your Makefile, 
when you compile your C code with `clang` (a compiler for C) that will
be installed later in this guide.

`bear` will automatically generate a file called `compile_commands.json`,
at the root of your project directory when you compile your C code.

This file will be used by `clangd` to ensure that you get completion support
in Neovim when using `.h` files (header files).

```sh
sudo pacman -S --needed bear
```

Without bear, if you had a header file in `include/Car.h` of your project,
and then you have the file `src/Car.c` and you tried to reference the
header file like this:

```cpp
#include "Car.h"`
```

clangd would display an error message like this in Neovim:
```
'Car.h' file not found clang (pp_file_not_found) [1, 10]
```
_______________________________________________________________________________

## Create the project directory

Create a directory with this command
```sh
mkdir c-programming-mastery
```

Enter the directory
```sh
cd c-programming-mastery
```

For the rest of this guide, all commands should be run from this directory.
_______________________________________________________________________________

## Install `clang` using the `conda` backend with `mise`

What is clang?

clang is a package that includes tools for working with 
both C and C++ projects.

The clang package includes:
1. `clang` a compiler for C code.
2. `clang++` a compiler for C++ code.

Use this command to check which versions of the clang package are available
```sh
mise ls-remote conda:clang
```
_______________________________________________________________________________

Use this command if you simply want to get the latest version of clang you can
run this command:
```sh
mise latest conda:clang
```
_______________________________________________________________________________

To install and set the specific version of clang that will 
be used in the directory, run this command:
```sh
MISE_EXPERIMENTAL=1 mise use conda:clang@21.1.8
```

The `MISE_EXPERIMENTAL=1` flag is required to specifiy that that you 
want to use the `conda` backend to install a pre-compiled `clang` binary.

This should take less than 3 minutes.

Do not leave out `MISE_EXPERIMENTAL=1` or `conda:` or mise will try 
to build `clang` from source which will take over an hour and will freeze
or crash your system (not because of mise, but simply because clang 
is a massive project to build from source).
_______________________________________________________________________________

## Install the `clang-format` code formater

Same steps as installing `clang`

```sh
mise ls-remote conda:clang-format
```

```sh
mise latest conda:clang-format
```

```sh
MISE_EXPERIMENTAL=1  mise use conda:clang-format@21.1.8
```
_______________________________________________________________________________

## Install `make` so that you can use `Makefiles` to build your project

```sh
mise ls-remote conda:make
```

```sh
mise latest conda:make
```

```sh
MISE_EXPERIMENTAL=1  mise use conda:make@4.4.1
```
_______________________________________________________________________________

## Install `cmake` for building more complex C and C++ projects

```sh
mise ls-remote cmake
```

```sh
mise latest cmake
```

```sh
mise use cmake@4.2.3
```
_______________________________________________________________________________

## Install `connan`, a package manager for C and C++ projects

```sh
mise ls-remote conan
```

```sh
mise latest conan
```

```sh
mise use conan@2.25.2
```
_______________________________________________________________________________

You should have a `mise.toml` file that looks like this:

```toml
[tools]
cmake = "4.2.3"
conan = "2.25.2"
"conda:clang" = "21.1.8"
"conda:clang-format" = "21.1.8"
"conda:make" = "4.4.1"
```
_______________________________________________________________________________

### Add a `gitignore` file

```sh
touch .gitignore
```

Add this to the file:
```gitignore
# Build outputs
**/bin/

# clangd (language server) cache
**/.cache/
```
_______________________________________________________________________________
