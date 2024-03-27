Linked List Data structure Project

Overview

This project implements a linked list data structure to manage student records. It allows operations such as insertion, searching, deletion, and listing of student records.
Contents:

    Introduction
    Classes and Functions
    Usage
    Contributing
    Running the program

Introduction

    Node: Represents a node in the linked list, containing information about a single student, including roll number, name, course, qualifications, phone number, and a pointer to the next node.
    linked_list: Manages the linked list operations such as insertion, searching, deletion, counting, and displaying student records.

Classes and Functions
Node Class
Attributes

    rollNum: Integer representing the roll number of the student.
    name: String representing the name of the student.
    course: String representing the course of the student.
    quali: String representing the department of the student.
    phoneNum: String representing the phone number of the student.
    next: Pointer to the next node in the linked list.

Constructor

    Node(int r, const std::string &n, const std::string &c, const std::string &e, const std::string &ph): Initializes a node with the provided student information.

linked_list Class
Attributes

    head: Pointer to the head of the linked list.

Functions

The major functions include

    isValidPhoneNumber(const std::string &phoneNumber): Checks if a phone number is valid.
    Insert(): Inserts a new student record into the linked list.
    Search(): Searches for a student record in the linked list.
    Count(): Counts the number of student records in the linked list.
    Del(): Deletes a student record from the linked list.
    show(): Displays all student records in the linked list.

Contributing:

Contributions to this project are welcome. If you find any bugs or have suggestions for improvement, please submit an issue or create a pull request on the GitHub repository.
License

Running the program
To run the program, you need to first compile it. Compile the program in the terminal using `Make ` command. This will compile it and then you can run the project using `./Project`
