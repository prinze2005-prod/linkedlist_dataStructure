// linked_list.h
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
#include <fstream>
#include <iomanip>

class Node
{

public:
    int rollNum;
    std::string name;
    std::string course;
    std::string quali;
    std::string phoneNum;
    Node *data;

    Node(int r, const std::string &n, const std::string &c, const std::string &e, const std::string &ph)
        : rollNum(r), name(n), course(c), quali(e), phoneNum(ph), data(nullptr)
    {
    }

    ~Node();
};

class linked_list
{
public:
    // Node *head = nullptr;
    bool isValidPhoneNumber(const std::string &phoneNumber);

    Node *head = nullptr;

    void Insert();
    void Search();
    void Count();
    void update();
    void Del();
    void show();
    void ShowFile();
};

#endif
