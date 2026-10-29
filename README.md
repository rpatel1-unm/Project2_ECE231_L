# Project 2 - Student Classes

## Description
This program uses object oriented programming in C++ to track students in different degree programs. There is a base class `Student` and two derived classes, `Art_Student` and `Physics_Student`.

## Classes
- **Student**: first and last name, GPA, graduation year and semester, enrolled year and semester, undergrad/grad
- **Art_Student**: adds `art_emphasis` (Art Studio, Art History, or Art Education)
- **Physics_Student**: adds `concentration` (Biophysics or Earth and Planetary Sciences)

## What the program does
- Creates 5 `Art_Student` objects and 5 `Physics_Student` objects using pointers
- Stores them in two separate `std::vector`s
- Writes all of the student information to `student_info.dat`
- Deletes all allocated memory at the end

## How to compile and run
g++ project2.cpp -o project2
./project2
cat student_info.dat

## Files
- `project2.cpp` - source code
- `student_info.dat` - output file.
