Linked List Datastructure Project

Overview

This project implements a linked list data structure to manage student records. It allows operations such as insertion, searching, updating, deletion, counting, and display student records.
Contents:

    Introduction
    Classes and Functions
    Usage
    Contributing
    License

Introduction

The project consists of two main classes:

    Node: Represents a node in the linked list, containing information about a single student, including roll number, name, course, qualifications, phone number, and a pointer to the next node.
    linked_list: Manages the linked list operations such as insertion, searching, updating, deletion, counting, and displaying student records.

Classes and Functions
Node Class
Attributes

    rollNum: Integer representing the roll number of the student.
    name: String representing the name of the student.
    course: String representing the course of the student.
    quali: String representing the department of the student.
    phoneNum: String representing the phone number of the student.
    data: Pointer to the next node in the linked list.

Constructor

    Node(int r, const std::string &n, const std::string &c, const std::string &e, const std::string &ph): Initializes a node with the provided student information.

linked_list Class
Attributes

    head: Pointer to the head of the linked list.

Functions

    isValidPhoneNumber(const std::string &phoneNumber): Checks if a phone number is valid.
    Insert(): Inserts a new student record into the linked list.
    Search(): Searches for a student record in the linked list.
    Count(): Counts the number of student records in the linked list.
    update(): Updates an existing student record in the linked list.
    Del(): Deletes a student record from the linked list.
    show(): Displays all student records in the linked list.
    ShowFile(): Displays student records stored in a file.

Usage

To use this project, follow these steps:

    Include the linked_list.h header file in your project.
    Instantiate an object of the linked_list class.
    Call the appropriate functions to perform desired operations on student records.

Contributing

Contributions to this project are welcome. If you find any bugs or have suggestions for improvement, please submit an issue or create a pull request on the GitHub repository.
License

This project is free for duplication and upgrade.
