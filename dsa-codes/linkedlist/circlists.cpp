#include <iostream>
#include "../../ds/CircularLinkedList.h"

using namespace std;

int main()
{
    CircularLinkedList<int> list;

    cout << "===== INSERTION =====" << endl;

    list.insertAtHead(20);
    list.insertAtHead(10);
    list.insertAtTail(30);
    list.insertAtTail(40);

    cout << "Original list: ";
    list.display();

    list.insertAfter(20, 25);
    cout << "After inserting 25 after 20: ";
    list.display();

    list.insertBefore(30, 27);
    cout << "After inserting 27 before 30: ";
    list.display();

    cout << "\n===== SEARCH =====" << endl;

    cout << "Search 25: " << list.search(25) << endl;
    cout << "Search 100: " << list.search(100) << endl;

    cout << "\n===== UPDATE =====" << endl;

    list.update(25, 26);
    list.display();

    cout << "\n===== COUNT =====" << endl;

    cout << "Number of nodes: " << list.countNodes() << endl;

    cout << "\n===== REMOVE =====" << endl;

    list.remove(27);
    cout << "After removing 27: ";
    list.display();

    list.removeAfter(20);
    cout << "After removing node after 20: ";
    list.display();

    list.removeBefore(40);
    cout << "After removing node before 40: ";
    list.display();

    cout << "\n===== REMOVE HEAD AND TAIL =====" << endl;

    list.removeAtHead();
    cout << "After removing head: ";
    list.display();

    list.removeAtTail();
    cout << "After removing tail: ";
    list.display();

    cout << "\n===== MOVE KTH NODE TO FRONT =====" << endl;

    list.insertAtTail(50);
    list.insertAtTail(60);
    list.insertAtTail(70);

    cout << "Before moving: ";
    list.display();

    list.moveKthNodeToFront(3);

    cout << "After moving 3rd node to front: ";
    list.display();

    cout << "\n===== REMOVE KTH NODE =====" << endl;

    int val;

    if (list.removeKthNode(2, val))
    {
        cout << "Removed value: " << val << endl;
        list.display();
    }
    else
    {
        cout << "Invalid position" << endl;
    }

    cout << "\n===== REVERSE =====" << endl;

    list.reverseList();
    list.display();

    cout << "\n===== DUPLICATES =====" << endl;

    CircularLinkedList<int> dup;

    dup.insertAtTail(10);
    dup.insertAtTail(20);
    dup.insertAtTail(10);
    dup.insertAtTail(30);
    dup.insertAtTail(20);

    cout << "Before removing duplicates: ";
    dup.display();

    dup.removeDuplicates();

    cout << "After removing duplicates: ";
    dup.display();

    cout << "\n===== COPY CONSTRUCTOR =====" << endl;

    CircularLinkedList<int> copied(dup);

    cout << "Copied list: ";
    copied.display();

    cout << "\n===== ASSIGNMENT OPERATOR =====" << endl;

    CircularLinkedList<int> assigned;

    assigned = dup;

    cout << "Assigned list: ";
    assigned.display();

    cout << "\n===== SPLIT =====" << endl;

    CircularLinkedList<int> original;
    CircularLinkedList<int> odd;
    CircularLinkedList<int> even;

    original.insertAtTail(1);
    original.insertAtTail(2);
    original.insertAtTail(3);
    original.insertAtTail(4);
    original.insertAtTail(5);
    original.insertAtTail(6);

    cout << "Original: ";
    original.display();

    original.split(odd, even);

    cout << "Odd positions: ";
    odd.display();

    cout << "Even positions: ";
    even.display();

    cout << "Original after split: ";
    original.display();

    cout << "\n===== ALTERNATE MERGE =====" << endl;

    CircularLinkedList<int> a;
    CircularLinkedList<int> b;
    CircularLinkedList<int> merged;

    a.insertAtTail(1);
    a.insertAtTail(3);
    a.insertAtTail(5);

    b.insertAtTail(2);
    b.insertAtTail(4);
    b.insertAtTail(6);
    b.insertAtTail(8);

    merged.alternateMerge(a, b);

    cout << "Merged list: ";
    merged.display();

    cout << "\n===== COMBINE =====" << endl;

    CircularLinkedList<int> first;
    CircularLinkedList<int> second;
    CircularLinkedList<int> combined;

    first.insertAtTail(10);
    first.insertAtTail(20);

    second.insertAtTail(30);
    second.insertAtTail(40);

    combined.combine(first, second);

    cout << "Combined list: ";
    combined.display();

    cout << "First list after combine: ";
    first.display();

    cout << "Second list after combine: ";
    second.display();

    cout << "\n===== EMPTY LIST CHECK =====" << endl;

    CircularLinkedList<int> empty;

    cout << "Is empty? " << empty.isEmpty() << endl;

    empty.removeAtHead();
    empty.removeAtTail();
    empty.display();

    cout << "\n===== END OF TESTS =====" << endl;

    return 0;
}