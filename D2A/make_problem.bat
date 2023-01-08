@echo off

set contest=%1
pushd ..
set tempDir=%CD%\template.cpp
popd


copy %CD%\assets\getProblems.py %CD%\getProblems.py
call python3 getProblems.py %CD% %contest%
del getProblems.py

copy assets\check_problems.cpp %CD%\check_problems.cpp
echo Compiling check_problems with g++
call g++ check_problems.cpp -o %CD%\%contest%\check
echo Compilation finished
del check_problems.cpp

copy %CD%\assets\run_samples.bat %CD%\%contest%\run_samples.bat
copy %tempDir% %CD%\%contest%\main.cpp
copy %CD%\assets\clean.bat %CD%\%contest%\clean.bat
copy %CD%\assets\dbug.bat %CD%\%contest%\dbug.bat
