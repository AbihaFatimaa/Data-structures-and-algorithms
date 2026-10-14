#include <iostream>
#include "../../ds/LinkedList.h"
using namespace std;

int main()
{
    LinkedList<int> list;

    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtTail(40);

    list.insertAfter(20, 25);
    list.display();

    list.insertBefore(30, 27);
    list.display();

    list.remove(25);
    list.display();

    list.removeAfter(20);
    list.display();

    list.removeBefore(40);
    list.display();

    list.update(40, 99);
    list.display();

    LinkedList<int> list2(list);  // Copy constructor
    list2.display();

    LinkedList<int> list3;
    list3 = list;                 // Assignment operator
    list3.display();

    return 0;
}