#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <ctime>
#include <sstream>
#include <limits>
#include <regex>
#include <cctype>
#include <cmath>
#include <vector>
#include <iomanip>
#include <regex>
#include "linkedList.h"
using std::numeric_limits;
using std::string;
using std::vector;

using namespace std;

// function to validate the ID
template <typename T>
T &validateInput(T &r)
{
    while (true)
    {

        if (cin >> r)
        {
            break;
        }
        else
        {

            cout << std::setw(60) << "Enter a valid integer value!";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return r;
}

Node::~Node()
{
}

void linked_list::Insert()
{

    fstream file;
    file.open("file.txt", ios::app);

    int r;
    std::string n;
    std::string c;
    std::string e;
    // int ph;
    std::string ph;

    cout << std::setw(60) << " Enter student Id:\t";
    validateInput(r);
    cout << std::setw(60) << " Enter student FirstName:\t";
    std::cin >> n;
    cout << std::setw(60) << " Enter LastName:\t";
    cin >> c;
    cout << std::setw(60) << " Enter student department:\t";
    // cin >> e;
    cin.ignore(); // Ignore the newline character left by previous cin
    std::getline(cin, e);

    // Validate and get a valid phone number
    bool isValid = false;
    do
    {
        cout << std::setw(60) << " Enter Phone number (xxx-xxx-xxxx):\t";
        std::cin >> ph;
        isValid = isValidPhoneNumber(ph);

        if (!isValid)
        {
            cout << "\n\t\t\t\tInvalid phone number format. Please enter in xxx-xxx-xxxx format." << endl;
        }
    } while (!isValid);

    Node *new_node = new Node(r, n, c, e, ph);

    file << new_node->rollNum << "\n";
    file << new_node->name << "\n";
    file << new_node->course << "\n";
    file << new_node->quali << "\n";
    file << new_node->phoneNum << "\n";

    file.close();

    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        Node *ptr = head;
        while (ptr->data != nullptr)
        {
            ptr = ptr->data;
        }
        ptr->data = new_node;
    }
    cout << "\n\t\t\t\t Student Record Inserted Successfully!\t" << endl;
}

bool linked_list::isValidPhoneNumber(const std::string &phoneNumber)
{
    // Define a regex pattern for xxx-xxx-xxxx format
    std::regex pattern("\\b\\d{3}-\\d{3}-\\d{4}\\b");

    // Use regex_match to check if the phone number matches the pattern
    return std::regex_match(phoneNumber, pattern);
}

void linked_list::Search()
{
    if (head == nullptr)
    {
        cout << "\n\t\t\t\tlinked List is empty\t";
    }
    else
    {
        int r;
        int found = 0;
        cout << std::setw(60) << "Enter student id for search:\t";
        cin >> r;
        Node *ptr = head;
        while (ptr != nullptr)
        {
            if (r == ptr->rollNum)
            {
                cout << "\n\t\t\t\tStudent ID:\t" << ptr->rollNum;
                cout << "\n\t\t\t\tStudent Firstname:\t" << ptr->name;
                cout << "\n\t\t\t\tStudent Lastname:\t" << ptr->course;
                cout << "\n\t\t\t\tStudent Department:\t" << ptr->quali;
                cout << "\n\t\t\t\tStudent PhoneNumber:\t" << ptr->phoneNum;
                found++;
            }
            ptr = ptr->data;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t\tStudent with given id number cannot be found\t";
        }
    }
}

void linked_list::Count()
{
    if (head == nullptr)
    {
        cout << "\n\t\t\t\tLinked list is empty!\t";
    }
    else
    {
        int c = 0;
        Node *ptr = head;
        while (ptr != nullptr)
        {
            c++;
            ptr = ptr->data;
        }
        cout << "\n\t\t\t\tNumber of records found:\t"
             << c;
    }
}

void linked_list::update()
{
    if (head == nullptr)
    {
        cout << "\n\t\t\t\tLinked list is empty!\t";
    }
    else
    {
        int r;
        int found = 0;
        cout << "\n\t\t\t\tEnter the Student ID to update:\t";
        cin >> r;
        Node *ptr = head;
        while (ptr != nullptr && found == 0)
        {
            if (r == ptr->rollNum)
            {
                cout << "\n\t\t\t\tEnter new Student ID:\t";
                cin >> ptr->rollNum;
                cout << "\n\t\t\t\tEnter  Student name:\t";
                cin >> ptr->name;
                cout << "\n\t\t\t\tEnter new Student surname:\t";
                cin >> ptr->course;
                cout << "\n\t\t\t\tEnter new Student Department:\t";
                cin >> ptr->quali;
                cout << "\n\t\t\t\tEnter new Student phone number:\t";
                cin >> ptr->phoneNum;
                cout << "\n\t\t\t\tRecord updated successfully!!\t";
            }
            ptr = ptr->data;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t\tUpdate student id " << r << "cannot be found\t";
        }
    }
}
void linked_list::Del()
{

    if (head == nullptr)
    {
        cout << "\n\t\t\t\tLinked list is empty!\t";
        return;
    }

    int targetID;
    cout << "\n\t\t\t\tEnter the Student ID to delete:\t";
    cin >> targetID;

    Node *ptr = head;
    Node *pre = nullptr;
    int found = 0;

    // Check if the target ID is in the first node
    if (targetID == head->rollNum)
    {
        head = head->data;
        delete ptr;
        found = 1;
        cout << "\n\t\t\t\tRecord Deleted successfully\t";
    }
    else
    {
        // Search for the target ID in the rest of the linked list
        while (ptr != nullptr)
        {
            if (targetID == ptr->rollNum)
            {
                pre->data = ptr->data;
                delete ptr;
                found = 1;
                cout << "\n\t\t\t\tRecord Deleted Successfully\t";
                break;
            }

            pre = ptr;
            ptr = ptr->data;
        }
    }

    if (found == 0)
    {
        cout << "\n\t\t\t\tStudent ID " << targetID << " not found\t";
    }
}

void linked_list::show()
{

    fstream file;
    file.open("file.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    if (head == nullptr)
    {
        cout << std::setw(60) << "linked List is empty\t";
    }
    else
    {
        Node *ptr = head;
        while (ptr != nullptr)
        {
            int rollNum;
            string name, course, quali;
            string phone_no;

            // Read record from the file
            file >> rollNum >> name >> course >> quali >> phone_no;

            cout << "\n\t\t\t\t Student ID:\t" << rollNum;
            cout << "\n\t\t\t\t Student FirstName:\t" << name;
            cout << "\n\t\t\t\t Student LastName:\t" << course;
            cout << "\n\t\t\t\t Student department:\t" << quali;
            cout << "\n\t\t\t\t Student PhoneNumber:\t" << phone_no;

            ptr = ptr->data;
        }
    }
    file.close();
}

void linked_list::ShowFile()
{

    ifstream in("file.txt");
    string line;

    cout << "\n\t\t\t\t Student records from the file:\n\n";

    while (getline(in, line))
    {
        cout << "\n\t\t\t\t Student ID is:" << line << endl;

        if (getline(in, line))
            cout << "\n\t\t\t\t Student Name is:" << line << endl;

        if (getline(in, line))
            cout << "\n\t\t\t\t Student Surname is:" << line << endl;

        if (getline(in, line))
            cout << "\n\t\t\t\t Student Depratment is:" << line << endl;

        if (getline(in, line))
            cout << "\n\t\t\t\t Student Phone Number is:" << line << endl;

        cout << "\n\t\t\t\t-----------------------------------------\n";
    }
}
