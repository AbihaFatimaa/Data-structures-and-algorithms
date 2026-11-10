
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class DoublyLinkedList
{
private:
    Node<T>* head;

    // Find the last node
    Node<T>* getTail()
    {
        if (head == nullptr)
            return nullptr;

        Node<T>* temp = head;

        while (temp->next != nullptr)
            temp = temp->next;

        return temp;
    }

    // Delete all nodes
    void clear()
    {
        while (head != nullptr)
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Append an existing detached node
    void appendNode(Node<T>* node)
    {
        node->next = nullptr;
        node->prev = nullptr;

        if (head == nullptr)
        {
            head = node;
            return;
        }

        Node<T>* tail = getTail();

        tail->next = node;
        node->prev = tail;
    }

public:

    // Constructor
    DoublyLinkedList()
    {
        head = nullptr;
    }

    // Copy constructor
    DoublyLinkedList(const DoublyLinkedList<T>& other)
    {
        head = nullptr;

        Node<T>* temp = other.head;

        while (temp != nullptr)
        {
            insertAtTail(temp->info);
            temp = temp->next;
        }
    }

    // Insert at head
    void insertAtHead(T v)
    {
        Node<T>* newNode = new Node<T>(v);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
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
            return;
        }

        Node<T>* tail = getTail();

        tail->next = newNode;
        newNode->prev = tail;
    }

    // Display forward
    void display()
    {
        Node<T>* current = head;

        while (current != nullptr)
        {
            cout << current->info << " <-> ";
            current = current->next;
        }

        cout << "NULL" << endl;
    }

    // Display backward
    void displayBackward()
    {
        Node<T>* current = getTail();

        while (current != nullptr)
        {
            cout << current->info << " <-> ";
            current = current->prev;
        }

        cout << "NULL" << endl;
    }

    // Check if empty
    bool isEmpty()
    {
        return head == nullptr;
    }

    // Search for a value
    bool search(T v)
    {
        Node<T>* current = head;

        while (current != nullptr)
        {
            if (current->info == v)
                return true;

            current = current->next;
        }

        return false;
    }

    // Remove at head
    void removeAtHead()
    {
        if (head == nullptr)
            return;

        Node<T>* temp = head;

        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;

        delete temp;
    }

    // Remove at tail
    void removeAtTail()
    {
        if (head == nullptr)
            return;

        Node<T>* tail = getTail();

        if (tail == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        tail->prev->next = nullptr;

        delete tail;
    }

    // Destructor
    ~DoublyLinkedList()
    {
        clear();
    }

    // Insert after the first occurrence of key
    void insertAfter(T key, T v)
    {
        Node<T>* temp = head;

        while (temp != nullptr)
        {
            if (temp->info == key)
            {
                Node<T>* newNode = new Node<T>(v);

                newNode->next = temp->next;
                newNode->prev = temp;

                if (temp->next != nullptr)
                    temp->next->prev = newNode;

                temp->next = newNode;

                return;
            }

            temp = temp->next;
        }
    }

    // Insert before the first occurrence of key
    void insertBefore(T key, T v)
    {
        Node<T>* temp = head;

        while (temp != nullptr)
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
    }

    // Remove the first occurrence of key
    void remove(T key)
    {
        Node<T>* temp = head;

        while (temp != nullptr)
        {
            if (temp->info == key)
            {
                if (temp == head)
                {
                    removeAtHead();
                    return;
                }

                if (temp->next == nullptr)
                {
                    removeAtTail();
                    return;
                }

                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                delete temp;
                return;
            }

            temp = temp->next;
        }
    }

    // Remove the node after the first occurrence of key
    void removeAfter(T key)
    {
        Node<T>* temp = head;

        while (temp != nullptr)
        {
            if (temp->info == key)
            {
                if (temp->next == nullptr)
                    return;

                Node<T>* del = temp->next;

                temp->next = del->next;

                if (del->next != nullptr)
                    del->next->prev = temp;

                delete del;
                return;
            }

            temp = temp->next;
        }
    }

    // Remove the node before the first occurrence of key
    void removeBefore(T key)
    {
        Node<T>* temp = head;

        while (temp != nullptr)
        {
            if (temp->info == key)
            {
                if (temp == head || temp->prev == head)
                {
                    if (temp->prev == head)
                        removeAtHead();

                    return;
                }

                Node<T>* del = temp->prev;

                del->prev->next = temp;
                temp->prev = del->prev;

                delete del;
                return;
            }

            temp = temp->next;
        }
    }

    // Update the first occurrence of key
    void update(T key, T v)
    {
        Node<T>* temp = head;

        while (temp != nullptr)
        {
            if (temp->info == key)
            {
                temp->info = v;
                return;
            }

            temp = temp->next;
        }
    }

    // Assignment operator
    DoublyLinkedList<T>& operator=(
        const DoublyLinkedList<T>& other)
    {
        if (this == &other)
            return *this;

        clear();

        Node<T>* temp = other.head;

        while (temp != nullptr)
        {
            insertAtTail(temp->info);
            temp = temp->next;
        }

        return *this;
    }

    // Count nodes
    int countNodes()
    {
        int count = 0;
        Node<T>* current = head;

        while (current != nullptr)
        {
            count++;
            current = current->next;
        }

        return count;
    }

    // Task 1: Move kth node to front
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

        // Detach curr from its current position
        curr->prev->next = curr->next;

        if (curr->next != nullptr)
            curr->next->prev = curr->prev;

        // Insert curr at head
        curr->prev = nullptr;
        curr->next = head;
        head->prev = curr;
        head = curr;

        return true;
    }

    // Task 2: Split odd-position and even-position nodes
    // list1 receives positions 1, 3, 5, ...
    // list2 receives positions 2, 4, 6, ...
    void split(DoublyLinkedList<T>& list1,
               DoublyLinkedList<T>& list2)
    {
        if (this == &list1 || this == &list2 ||
            &list1 == &list2)
            return;

        list1.clear();
        list2.clear();

        Node<T>* current = head;
        int position = 1;

        head = nullptr;

        while (current != nullptr)
        {
            Node<T>* nextNode = current->next;

            current->next = nullptr;
            current->prev = nullptr;

            if (position % 2 != 0)
                list1.appendNode(current);
            else
                list2.appendNode(current);

            current = nextNode;
            position++;
        }
    }

    // Reverse the list
    void reverseList()
    {
        Node<T>* current = head;
        Node<T>* temp = nullptr;

        while (current != nullptr)
        {
            // Swap next and prev
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            // Move using the original next pointer
            current = current->prev;
        }

        if (temp != nullptr)
            head = temp->prev;
    }

    // Task 3: Alternate merge two lists into this list
    // Also preserves leftover nodes from a longer list
    void alternateMerge(DoublyLinkedList<T>& list1,
                        DoublyLinkedList<T>& list2)
    {
        if (this == &list1 || this == &list2 ||
            &list1 == &list2)
            return;

        clear();

        Node<T>* current1 = list1.head;
        Node<T>* current2 = list2.head;

        list1.head = nullptr;
        list2.head = nullptr;

        while (current1 != nullptr || current2 != nullptr)
        {
            if (current1 != nullptr)
            {
                Node<T>* next1 = current1->next;
                appendNode(current1);
                current1 = next1;
            }

            if (current2 != nullptr)
            {
                Node<T>* next2 = current2->next;
                appendNode(current2);
                current2 = next2;
            }
        }
    }

    // Remove duplicate values, keeping first occurrences
    void removeDuplicates()
    {
        Node<T>* current = head;

        while (current != nullptr)
        {
            Node<T>* temp = current->next;

            while (temp != nullptr)
            {
                if (temp->info == current->info)
                {
                    Node<T>* del = temp;

                    temp = temp->next;

                    if (del->prev != nullptr)
                        del->prev->next = del->next;

                    if (del->next != nullptr)
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
    }

    // Remove kth node and return its value
    bool removeKthNode(int k, T& val)
    {
        if (k < 1)
            return false;

        Node<T>* current = head;
        int position = 1;

        while (current != nullptr && position < k)
        {
            current = current->next;
            position++;
        }

        if (current == nullptr)
            return false;

        val = current->info;

        if (current == head)
        {
            removeAtHead();
        }
        else if (current->next == nullptr)
        {
            removeAtTail();
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;

            delete current;
        }

        return true;
    }

    // Combine list1 followed by list2 into this list
    // Both source lists become empty
    void combine(DoublyLinkedList<T>& list1,
                 DoublyLinkedList<T>& list2)
    {
        if (this == &list1 || this == &list2 ||
            &list1 == &list2)
            return;

        clear();

        // Transfer list1
        if (list1.head != nullptr)
        {
            head = list1.head;
            list1.head = nullptr;
        }

        // Append list2
        if (list2.head != nullptr)
        {
            if (head == nullptr)
            {
                head = list2.head;
            }
            else
            {
                Node<T>* tail = getTail();

                tail->next = list2.head;
                list2.head->prev = tail;
            }

            list2.head = nullptr;
        }
    }
};

#endif
