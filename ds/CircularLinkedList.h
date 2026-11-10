#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class CircularLinkedList
{
private:
    Node<T>* head;

    // Find the last node. Assumes the list is not empty.
    Node<T>* getTail()
    {
        Node<T>* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        return temp;
    }

    // Delete all nodes without breaking the circular structure incorrectly.
    void clear()
    {
        if (head == nullptr)
            return;

        Node<T>* tail = getTail();
        tail->next = nullptr;

        while (head != nullptr)
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

public:

    // Constructor
    CircularLinkedList()
    {
        head = nullptr;
    }

    // Copy constructor
    CircularLinkedList(const CircularLinkedList<T>& other)
    {
        head = nullptr;

        if (other.head == nullptr)
            return;

        Node<T>* temp = other.head;

        do
        {
            insertAtTail(temp->info);
            temp = temp->next;
        }
        while (temp != other.head);
    }

    // Insert at head
    void insertAtHead(T v)
    {
        Node<T>* newNode = new Node<T>(v);

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node<T>* tail = getTail();

        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }

    // Insert at tail
    void insertAtTail(T v)
    {
        Node<T>* newNode = new Node<T>(v);

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node<T>* tail = getTail();

        tail->next = newNode;
        newNode->next = head;
    }

    // Display the list
    void display()
    {
        if (head == nullptr)
        {
            cout << "Empty list" << endl;
            return;
        }

        Node<T>* current = head;

        do
        {
            cout << current->info << " -> ";
            current = current->next;
        }
        while (current != head);

        cout << "(back to head)" << endl;
    }

    // Check if the list is empty
    bool isEmpty()
    {
        return head == nullptr;
    }

    // Search for a value
    bool search(T v)
    {
        if (head == nullptr)
            return false;

        Node<T>* current = head;

        do
        {
            if (current->info == v)
                return true;

            current = current->next;
        }
        while (current != head);

        return false;
    }

    // Delete at head
    void removeAtHead()
    {
        if (head == nullptr)
            return;

        // Only one node
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node<T>* tail = getTail();
        Node<T>* temp = head;

        head = head->next;
        tail->next = head;

        delete temp;
    }

    // Delete at tail
    void removeAtTail()
    {
        if (head == nullptr)
            return;

        // Only one node
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node<T>* prev = head;

        while (prev->next->next != head)
        {
            prev = prev->next;
        }

        Node<T>* del = prev->next;

        prev->next = head;
        delete del;
    }

    // Destructor
    ~CircularLinkedList()
    {
        clear();
    }

    // Insert after the first occurrence of key
    void insertAfter(T key, T v)
    {
        if (head == nullptr)
            return;

        Node<T>* temp = head;

        do
        {
            if (temp->info == key)
            {
                Node<T>* newNode = new Node<T>(v);

                newNode->next = temp->next;
                temp->next = newNode;

                return;
            }

            temp = temp->next;
        }
        while (temp != head);
    }

    // Insert before the first occurrence of key
    void insertBefore(T key, T v)
    {
        if (head == nullptr)
            return;

        if (head->info == key)
        {
            insertAtHead(v);
            return;
        }

        Node<T>* prev = head;
        Node<T>* temp = head->next;

        while (temp != head)
        {
            if (temp->info == key)
            {
                Node<T>* newNode = new Node<T>(v);

                prev->next = newNode;
                newNode->next = temp;

                return;
            }

            prev = temp;
            temp = temp->next;
        }
    }

    // Remove the first occurrence of key
    void remove(T key)
    {
        if (head == nullptr)
            return;

        if (head->info == key)
        {
            removeAtHead();
            return;
        }

        Node<T>* prev = head;
        Node<T>* temp = head->next;

        while (temp != head)
        {
            if (temp->info == key)
            {
                prev->next = temp->next;
                delete temp;
                return;
            }

            prev = temp;
            temp = temp->next;
        }
    }

    // Remove the node after the first occurrence of key
    void removeAfter(T key)
    {
        if (head == nullptr)
            return;

        Node<T>* temp = head;

        do
        {
            if (temp->info == key)
            {
                // A single node is its own next node.
                if (temp->next == temp)
                {
                    removeAtHead();
                    return;
                }

                Node<T>* del = temp->next;

                // If deleting head, move head forward.
                if (del == head)
                    head = head->next;

                temp->next = del->next;
                delete del;

                return;
            }

            temp = temp->next;
        }
        while (temp != head);
    }

    // Remove the node before the first occurrence of key
    // Keeps the original linear-list behavior when key is head:
    // nothing is removed before the first node.
    void removeBefore(T key)
    {
        if (head == nullptr || head->next == head)
            return;

        if (head->info == key)
            return;

        Node<T>* prevPrev = head;
        Node<T>* prev = head->next;
        Node<T>* current = prev->next;

        while (current != head)
        {
            if (current->info == key)
            {
                prevPrev->next = current;
                delete prev;
                return;
            }

            prevPrev = prev;
            prev = current;
            current = current->next;
        }
    }

    // Update the first occurrence of key
    void update(T key, T v)
    {
        if (head == nullptr)
            return;

        Node<T>* temp = head;

        do
        {
            if (temp->info == key)
            {
                temp->info = v;
                return;
            }

            temp = temp->next;
        }
        while (temp != head);
    }

    // Assignment operator
    CircularLinkedList<T>& operator=(
        const CircularLinkedList<T>& other)
    {
        if (this == &other)
            return *this;

        clear();

        if (other.head == nullptr)
            return *this;

        Node<T>* temp = other.head;

        do
        {
            insertAtTail(temp->info);
            temp = temp->next;
        }
        while (temp != other.head);

        return *this;
    }

    // Count nodes
    int countNodes()
    {
        if (head == nullptr)
            return 0;

        int count = 0;
        Node<T>* current = head;

        do
        {
            count++;
            current = current->next;
        }
        while (current != head);

        return count;
    }

    // Task 1: Move the kth node to the front
    bool moveKthNodeToFront(int k)
    {
        int len = countNodes();

        if (k < 1 || k > len)
            return false;

        if (k == 1)
            return true;

        Node<T>* prev = head;
        Node<T>* curr = head->next;

        for (int i = 2; i < k; i++)
        {
            prev = curr;
            curr = curr->next;
        }

        Node<T>* tail = getTail();

        prev->next = curr->next;
        curr->next = head;
        head = curr;

        // Tail remains the same, but its link must point to new head.
        tail->next = head;

        return true;
    }

    // Task 2: Split into odd-position and even-position nodes.
    // list1 receives positions 1, 3, 5, ...
    // list2 receives positions 2, 4, 6, ...
    // The original list becomes empty.
    void split(CircularLinkedList<T>& list1,
               CircularLinkedList<T>& list2)
    {
        if (this == &list1 || this == &list2 ||
            &list1 == &list2)
            return;

        list1.clear();
        list2.clear();

        if (head == nullptr)
            return;

        Node<T>* current = head;

        do
        {
            Node<T>* nextNode = current->next;

            // Detach current node before appending it.
            current->next = current;

            if (list1.countNodes() % 2 == 0)
            {
                if (list1.head == nullptr)
                {
                    list1.head = current;
                }
                else
                {
                    Node<T>* tail = list1.getTail();
                    tail->next = current;
                    current->next = list1.head;
                }
            }
            else
            {
                if (list2.head == nullptr)
                {
                    list2.head = current;
                }
                else
                {
                    Node<T>* tail = list2.getTail();
                    tail->next = current;
                    current->next = list2.head;
                }
            }

            // Ensure a newly created one-node list is circular.
            if (list1.head == current)
                current->next = list1.head;
            else if (list2.head == current)
                current->next = list2.head;

            current = nextNode;
        }
        while (current != head);

        head = nullptr;
    }

    // Reverse the circular linked list
    void reverseList()
    {
        if (head == nullptr || head->next == head)
            return;

        Node<T>* oldHead = head;
        Node<T>* prev = head;
        Node<T>* current = head->next;
        Node<T>* nextNode = nullptr;

        // Reverse every link except the first node.
        while (current != oldHead)
        {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        oldHead->next = prev;
        head = prev;
    }

    // Task 3: Alternate merge list1 and list2 into this list.
    // Remaining nodes from either list are also included.
    void alternateMerge(CircularLinkedList<T>& list1,
                        CircularLinkedList<T>& list2)
    {
        if (this == &list1 || this == &list2 ||
            &list1 == &list2)
            return;

        clear();

        Node<T>* current1 = list1.head;
        Node<T>* current2 = list2.head;

        int len1 = list1.countNodes();
        int len2 = list2.countNodes();

        // Break the input circles so we can process nodes linearly.
        if (list1.head != nullptr)
            list1.getTail()->next = nullptr;

        if (list2.head != nullptr)
            list2.getTail()->next = nullptr;

        list1.head = nullptr;
        list2.head = nullptr;

        Node<T>* tail = nullptr;

        while (current1 != nullptr || current2 != nullptr)
        {
            if (current1 != nullptr)
            {
                Node<T>* next1 = current1->next;
                current1->next = nullptr;

                if (head == nullptr)
                    head = current1;
                else
                    tail->next = current1;

                tail = current1;
                current1 = next1;
            }

            if (current2 != nullptr)
            {
                Node<T>* next2 = current2->next;
                current2->next = nullptr;

                if (head == nullptr)
                    head = current2;
                else
                    tail->next = current2;

                tail = current2;
                current2 = next2;
            }
        }

        // Close the resulting list into a circle.
        if (head != nullptr)
            tail->next = head;
    }

    // Remove duplicate values, keeping the first occurrence
    void removeDuplicates()
    {
        if (head == nullptr || head->next == head)
            return;

        Node<T>* current = head;

        do
        {
            Node<T>* prev = current;
            Node<T>* temp = current->next;

            while (temp != head)
            {
                if (temp->info == current->info)
                {
                    Node<T>* del = temp;

                    prev->next = temp->next;
                    temp = temp->next;

                    // If deleting the tail, prev now points to head.
                    delete del;
                }
                else
                {
                    prev = temp;
                    temp = temp->next;
                }
            }

            current = current->next;
        }
        while (current != head);
    }

    // Remove kth node and return its value through val
    bool removeKthNode(int k, int& val)
    {
        int len = countNodes();

        if (k < 1 || k > len)
            return false;

        Node<T>* current = head;

        if (k == 1)
        {
            val = head->info;
            removeAtHead();
            return true;
        }

        Node<T>* prev = head;

        for (int i = 1; i < k; i++)
        {
            prev = current;
            current = current->next;
        }

        val = current->info;
        prev->next = current->next;

        delete current;

        return true;
    }

    // Combine list1 followed by list2 into this list.
    // The two source lists become empty.
    void combine(CircularLinkedList<T>& list1,
                 CircularLinkedList<T>& list2)
    {
        if (this == &list1 || this == &list2 ||
            &list1 == &list2)
            return;

        clear();

        if (list1.head == nullptr && list2.head == nullptr)
            return;

        if (list1.head == nullptr)
        {
            head = list2.head;
            list2.head = nullptr;
            return;
        }

        if (list2.head == nullptr)
        {
            head = list1.head;
            list1.head = nullptr;
            return;
        }

        Node<T>* tail1 = list1.getTail();
        Node<T>* tail2 = list2.getTail();

        head = list1.head;

        tail1->next = list2.head;
        tail2->next = head;

        list1.head = nullptr;
        list2.head = nullptr;
    }
};

#endif
