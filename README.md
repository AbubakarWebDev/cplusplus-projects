# C++ Projects

A collection of C++ mini projects, written in Code::Blocks with the MinGW compiler as console applications (no graphics). Suitable for school or college mini-project use.

![Repository Banner](cplusplus-projects.jpg)

## Projects

### Employee Management System
[`employee-management-system/`](employee-management-system)

A console application for managing employee records, built entirely around file handling — every record is stored in and read back from a file. Demonstrates storing, editing, searching, and deleting data on disk.

Features:
1. Build the employee table
2. List the employee table
3. Insert a new entry
4. Delete an entry
5. Edit an entry
6. Search a record
7. Sort the table

### Tic Tac Toe Game
[`tic-tac-toe-game/`](tic-tac-toe-game)

A two-player console Tic Tac Toe game built around 2D arrays for storing player input and displaying results. See [Wikipedia](https://en.wikipedia.org/wiki/Tic-tac-toe) if you're unfamiliar with the rules.

Features:
1. Two players play against each other
2. Console-based game interface
3. Input validation, with re-prompting on invalid input
4. Win, loss, and draw messages
5. Screen cleared on every move

### Student Grade Calculator
[`student-grade-calculator/`](student-grade-calculator)

Calculates letter grades (A–F) for a class of 50 students across 5 subjects, based on each student's average percentage, and reports how many students fall into each grade bracket.

### Templated Set Class
[`templated-set-class/`](templated-set-class)

A generic `Set<T>` class template backed by a dynamic array, supporting any type (`int`, `float`, custom classes, etc.). Demonstrates C++ templates, dynamic memory management, and operations like push and resize.

### Dynamic Array
[`dynamic-array/`](dynamic-array)

A minimal dynamic array implementation that grows its backing store as elements are inserted, demonstrating manual memory management with `new`/`delete` in C++.

### Array & Pointer Examples
[`array-pointer-examples/`](array-pointer-examples)

A set of small, self-contained programs demonstrating array and pointer fundamentals: swapping values, sorting and reversing arrays, and traversing/reversing C-strings with pointers.

### Linked List Coding Problems
[`linked-list-coding-problems/`](linked-list-coding-problems)

Solutions to a set of linked list coding problems:
- `find-pivot.cpp` — finds the index where all preceding elements are smaller and all following elements are larger
- `sorted-doubly-linked-list.cpp` — a doubly linked list that keeps itself sorted on insert
- `no-three-ascending-linked-list.cpp` — a linked list that rearranges itself so no three adjacent nodes are in ascending order
- `merge-sorted-linked-lists.cpp` — merges two sorted linked lists into a single sorted list

## License

This repository is licensed under the [GNU General Public License v3.0](LICENSE).
