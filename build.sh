#!/bin/bash

# Create build directory if it doesn't exist
mkdir -p build

# Navigate to source directory
cd src

# Compile all source files in src to object files
g++ --std=c++20 -c algorithms.cpp -o ../build/algorithms.o
g++ --std=c++20 -c dsets.cpp -o ../build/dsets.o
g++ --std=c++20 -c graphs.cpp -o ../build/graphs.o
g++ --std=c++20 -c io_general.cpp -o ../build/io_general.o

# Navigate to test directory
cd ../test

# Compile all source files in test to object files
g++ --std=c++20 -c io_test.cpp -o ../build/io_test.o

# Navigate to main directory
cd ..

# Compile main.cpp to an object file
g++ --std=c++20 -c main.cpp -o build/main.o

# Link all object files into a single executable named main
g++ -o build/main build/algorithms.o build/dsets.o build/graphs.o build/io_general.o build/io_test.o build/main.o

# Run the executable
./build/main