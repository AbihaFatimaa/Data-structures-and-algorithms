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

public:
    CircularLinkedList()
    {
        head = nullptr;
    }

    bool isEmpty()
    {
        return head == nullptr;
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

        Node<T>* temp = head;

        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
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

        Node<T>* temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    // Display
    void display()
    {
        if (head == nullptr)
        {
            cout << "Empty list" << endl;
            return;
        }

        Node<T>* temp = head;

        do
        {
            cout << temp->info << " -> ";
            temp = temp->next;
        }
        while (temp != head);

        cout << "(back to head)" << endl;
    }

    // Search
    bool search(T v)
    {
        if (head == nullptr)
            return false;

        Node<T>* temp = head;

        do
        {
            if (temp->info == v)
                return true;

            temp = temp->next;
        }
        while (temp != head);

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

        Node<T>* tail = head;

        while (tail->next != head)
            tail = tail->next;

        Node<T>* del = head;
        head = head->next;
        tail->next = head;

        delete del;
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

        Node<T>* temp = head;

        while (temp->next->next != head)
            temp = temp->next;

        Node<T>* del = temp->next;
        temp->next = head;

        delete del;
    }

    // Destructor
    ~CircularLinkedList()
    {
        while (head != nullptr)
            removeAtHead();
    }
};

#endif
