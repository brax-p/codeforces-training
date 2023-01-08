@echo off
echo Compiling with g++17
call g++ main.cpp -o main
echo Compilation finished.
main.exe 0 < samples\data.in > main.out
call check.exe
