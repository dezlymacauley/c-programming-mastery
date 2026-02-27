.SILENT:
.PHONY: run clean

# Compile Settings
COMPILER = clang
FLAGS = -std=c23 -isystem /usr/include -B /usr/lib -I include -Wconversion -Wunused-variable  

# Additional arguments
# Leave the right side empty
ADDITIONAL_ARGS =

# Build Settings
INPUT = src/*.c
OUTPUT = bin/main

run:
	mkdir -p bin/
	bear -- $(COMPILER) $(FLAGS) $(INPUT) -o $(OUTPUT)
	./bin/main $(ADDITIONAL_ARGS)

clean:
	rm -rf bin/
