
#ifndef CIRCULARDoublyLINKEDLIST_H
#define CIRCULARDoublyLINKEDLIST_H

#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class CircularDoublyLinkedList
{
private:
    Node<T>* head;

    // Find last node. Assumes list is not empty.
    Node<T>* getTail()
    {
        Node<T>* temp = head;

        while (temp->next != head)
            temp = temp->next;

        return temp;
    }

    // Delete all nodes
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

    // Append a detached node
    void appendNode(Node<T>* node)
    {
        if (head == nullptr)
        {
            head = node;
            node->next = node;
            node->prev = node;
            return;
        }

        Node<T>* tail = getTail();

        tail->next = node;
        node->prev = tail;
        node->next = head;
        head->prev = node;
    }

public:

    // Constructor
    CircularDoublyLinkedList()
    {
        head = nullptr;
    }

    // Copy constructor
    CircularDoublyLinkedList(
        const CircularDoublyLinkedList<T>& other)
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
            newNode->next = newNode;
            newNode->prev = newNode;
            return;
        }

        Node<T>* tail = getTail();

        newNode->next = head;
        newNode->prev = tail;

        tail->next = newNode;
        head->prev = newNode;

        head = newNode;
    }

    // Insert at tail
    void insertAtTail(T v)
    {
        Node<T>* newNode = new Node<T>(v);

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
            return;
        }

        Node<T>* tail = getTail();

        tail->next = newNode;
        newNode->prev = tail;

        newNode->next = head;
        head->prev = newNode;
    }

    // Display forward
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
            cout << current->info << " <-> ";
            current = current->next;
        }
        while (current != head);

        cout << "(back to head)" << endl;
    }

    // Display backward
    void displayBackward()
    {
        if (head == nullptr)
        {
            cout << "Empty list" << endl;
            return;
        }

        Node<T>* current = head->prev;

        do
        {
            cout << current->info << " <-> ";
            current = current->prev;
        }
        while (current != head->prev);

        cout << "(back to tail)" << endl;
    }

    // Check if empty
    bool isEmpty()
    {
        return head == nullptr;
    }

    // Search
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

    // Remove at head
    void removeAtHead()
    {
        if (head == nullptr)
            return;

        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node<T>* tail = getTail();
        Node<T>* del = head;

        head = head->next;

        tail->next = head;
        head->prev = tail;

        delete del;
    }

    // Remove at tail
    void removeAtTail()
    {
        if (head == nullptr)
            return;

        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node<T>* tail = getTail();

        tail->prev->next = head;
        head->prev = tail->prev;

        delete tail;
    }

    // Destructor
    ~CircularDoublyLinkedList()
    {
        clear();
    }

    // Insert after first occurrence of key
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
                Node<T>* nextNode = temp->next;

                newNode->prev = temp;
                newNode->next = nextNode;

                temp->next = newNode;
                nextNode->prev = newNode;

                return;
            }

            temp = temp->next;
        }
        while (temp != head);
    }

    // Insert before first occurrence of key
    void insertBefore(T key, T v)
    {
        if (head == nullptr)
            return;

        Node<T>* temp = head;

        do
        {
            if (temp->info == key)
            {
                if (temp == head)
                {
                    insertAtHead(v);
                    return;
                }

                Node<T>* newNode = new Node<T>(v);

                newNode->prev = temp->prev;
                newNode->next = temp;

                temp->prev->next = newNode;
                temp->prev = newNode;

                return;
            }

            temp = temp->next;
        }
        while (temp != head);
    }

    // Remove first occurrence of key
    void remove(T key)
    {
        if (head == nullptr)
            return;

        Node<T>* temp = head;

        do
        {
            if (temp->info == key)
            {
                if (temp == head)
                    removeAtHead();
                else if (temp->next == head)
                    removeAtTail();
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                }

                return;
            }

            temp = temp->next;
        }
        while (temp != head);
    }

    // Remove node after first occurrence of key
    void removeAfter(T key)
    {
        if (head == nullptr)
            return;

        Node<T>* temp = head;

        do
        {
            if (temp->info == key)
            {
                if (temp->next == temp)
                {
                    removeAtHead();
                    return;
                }

                Node<T>* del = temp->next;

                if (del == head)
                    head = head->next;

                del->prev->next = del->next;
                del->next->prev = del->prev;

                delete del;
                return;
            }

            temp = temp->next;
        }
        while (temp != head);
    }

    // Remove node before first occurrence of key
    void removeBefore(T key)
    {
        if (head == nullptr)
            return;

        Node<T>* temp = head;

        do
        {
            if (temp->info == key)
            {
                if (temp->next == temp)
                {
                    return;
                }

                Node<T>* del = temp->prev;

                if (del == head && temp == head->next)
                {
                    removeAtHead();
                    return;
                }

                del->prev->next = del->next;
                del->next->prev = del->prev;

                delete del;
                return;
            }

            temp = temp->next;
        }
        while (temp != head);
    }

    // Update first occurrence of key
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
    CircularDoublyLinkedList<T>& operator=(
        const CircularDoublyLinkedList<T>& other)
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

    // Move kth node to front
    bool moveKthNodeToFront(int k)
    {
        int len = countNodes();

        if (k < 1 || k > len)
            return false;

        if (k == 1)
            return true;

        Node<T>* curr = head;

        for (int i = 1; i < k; i++)
            curr = curr->next;

        // Detach curr
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        // Insert at front
        Node<T>* tail = head->prev;

        curr->next = head;
        curr->prev = tail;

        tail->next = curr;
        head->prev = curr;

        head = curr;

        return true;
    }

    // Split odd-position nodes into list1,
    // even-position nodes into list2.
    void split(CircularDoublyLinkedList<T>& list1,
               CircularDoublyLinkedList<T>& list2)
    {
        if (this == &list1 || this == &list2 ||
            &list1 == &list2)
            return;

        list1.clear();
        list2.clear();

        int len = countNodes();
        Node<T>* current = head;

        for (int i = 1; i <= len; i++)
        {
            Node<T>* nextNode = current->next;

            current->next = current;
            current->prev = current;

            if (i % 2 != 0)
                list1.appendNode(current);
            else
                list2.appendNode(current);

            current = nextNode;
        }

        head = nullptr;
    }

    // Reverse the circular doubly linked list
    void reverseList()
    {
        if (head == nullptr || head->next == head)
            return;

        Node<T>* current = head;

        do
        {
            Node<T>* temp = current->next;

            current->next = current->prev;
            current->prev = temp;

            // After swapping, prev is the original next node.
            current = current->prev;
        }
        while (current != head);

        // The old tail becomes the new head.
        head = head->next;
    }

    // Alternate merge list1 and list2 into this list
    // Leftover nodes from the longer list are preserved.
    void alternateMerge(CircularDoublyLinkedList<T>& list1,
                        CircularDoublyLinkedList<T>& list2)
    {
        if (this == &list1 || this == &list2 ||
            &list1 == &list2)
            return;

        clear();

        int len1 = list1.countNodes();
        int len2 = list2.countNodes();

        Node<T>* current1 = list1.head;
        Node<T>* current2 = list2.head;

        list1.head = nullptr;
        list2.head = nullptr;

        for (int i = 0; i < len1 || i < len2; i++)
        {
            if (i < len1)
            {
                Node<T>* next1 = current1->next;
                current1->next = current1;
                current1->prev = current1;

                appendNode(current1);
                current1 = next1;
            }

            if (i < len2)
            {
                Node<T>* next2 = current2->next;
                current2->next = current2;
                current2->prev = current2;

                appendNode(current2);
                current2 = next2;
            }
        }
    }

    // Remove duplicate values, keeping first occurrences
    void removeDuplicates()
    {
        if (head == nullptr || head->next == head)
            return;

        Node<T>* current = head;

        do
        {
            Node<T>* temp = current->next;

            while (temp != head)
            {
                if (temp->info == current->info)
                {
                    Node<T>* del = temp;
                    temp = temp->next;

                    // If deleting head, move head forward.
                    if (del == head)
                        head = head->next;

                    del->prev->next = del->next;
                    del->next->prev = del->prev;

                    delete del;
                }
                else
                {
                    temp = temp->next;
                }
            }

            current = current->next;
        }
        while (current != head);
    }

    // Remove kth node and return its value
    bool removeKthNode(int k, T& val)
    {
        int len = countNodes();

        if (k < 1 || k > len)
            return false;

        Node<T>* current = head;

        for (int i = 1; i < k; i++)
            current = current->next;

        val = current->info;

        if (current == head)
            removeAtHead();
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }

        return true;
    }

    // Combine list1 followed by list2 into this list.
    // Both source lists become empty.
    void combine(CircularDoublyLinkedList<T>& list1,
                 CircularDoublyLinkedList<T>& list2)
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
        list2.head->prev = tail1;

        tail2->next = head;
        head->prev = tail2;

        list1.head = nullptr;
        list2.head = nullptr;
    }
};

#endif
