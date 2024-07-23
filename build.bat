@echo off

REM Create build directory if it doesn't exist
if not exist build (
    mkdir build
)

REM Navigate to source directory
cd src
echo Compiling src files...

REM Compile all source files in src to object files
g++ -c algorithms.cpp -o ../build/algorithms.o
g++ -c dsets.cpp -o ../build/dsets.o
g++ -c graphs.cpp -o ../build/graphs.o
g++ -c io_general.cpp -o ../build/io_general.o

REM Navigate to test directory
cd ../test
echo Compiling test files...

REM Compile all source files in test to object files
g++ -c io_test.cpp -o ../build/io_test.o

REM Navigate to main directory
cd ..
echo Compiling main file...

REM Compile main.cpp to an object file
g++ -c main.cpp -o build/main.o

REM Link all object files into a single executable named main
echo Linking object files...
g++ -o build/main.exe build/algorithms.o build/dsets.o build/graphs.o build/io_general.o build/io_test.o build/main.o

REM Run the executable
echo Running the executable...
build\main.exe
