#include <iostream>
#include "linkedList.h"

int main()
{
    linked_list obj;

p:

    int choice;

    std::cout << "\n\t\t\t\t ********Welcome to the student Management system application*******" << std::endl;
    std::cout << "\n\t\t\t\t Please select an option from the list below" << std::endl;
    std::cout << "\n\t\t\t\tS.NO      Function     \t\t\t\t   Description";
    std::cout << "\n\t\t\t\t1 \tInsert Record \t\t\t\t   Insert Student record";
    std::cout << "\n\t\t\t\t2 \tSearch Record \t\t\t\t   Search Student record";
    std::cout << "\n\t\t\t\t3 \tCount  Record \t\t\t\t   Count Student  record";
    std::cout << "\n\t\t\t\t4 \tUpdate Record \t\t\t\t   Update Student record";
    std::cout << "\n\t\t\t\t5 \tDelete Record \t\t\t\t   Delete Student record";
    std::cout << "\n\t\t\t\t6 \tShow All Record \t\t\t   Show Student record";
    std::cout << "\n\t\t\t\t7 \tDisplay Record from file \t\t   Show Student record from file";
    std::cout << "\n\t\t\t\t8 \tExit";
    std::cout << "\n";
    std::cout << "\n\t\t\t\t\tMake a choice: \t\t\t\t\t";
    std::cin >> choice;

    switch (choice)
    {
    case 1:

        obj.Insert();
        break;
    case 2:

        obj.Search();
        break;
    case 3:

        obj.Count();
        break;
    case 4:

        obj.update();
        break;
    case 5:

        obj.Del();
        break;
    case 6:

        obj.show();
        break;
    case 7:

        obj.ShowFile();
        break;
    case 8:
        exit(0);
    default:
        std::cout << "\n\t\t\t\tInvalid choice\t";
    }
    getchar();
    goto p;
    return 0;
};
