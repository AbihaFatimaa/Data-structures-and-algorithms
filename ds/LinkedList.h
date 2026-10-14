
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class LinkedList
{
private:
    Node<T>* head;

public:
    // Constructor
    LinkedList()
    {
        head = nullptr;
    }
	LinkedList(const LinkedList<T>& other)
	{
	    head = nullptr;
	
	    Node<T>* temp = other.head;
	
	    while(temp != nullptr)
	    {
	        insertAtTail(temp->info);
	        temp = temp->next;
	    }
	}
    // Insert at head
    void insertAtHead(T v)
    {
        Node<T>* temp = new Node<T>(v);
        temp->next = head;
        head = temp;
    }

    // Insert at tail
   void insertAtTail(T v)
{
    if(head != nullptr)
    {
        Node<T>* temp = head;

        while(temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = new Node<T>(v);
    }
    else
    {
        head = new Node<T>(v);
    }
}

    // Display the list
    void display()
    {
        Node<T>* current = head;

        while (current != nullptr)
        {
            cout << current->info << " -> ";
            current = current->next;
        }

        cout << "NULL" << endl;
    }

    // Check if the list is empty
    bool isEmpty()
    {
        return head == nullptr;
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

    // Delete at head
    void removeAtHead()
    {
        if (head == nullptr)
            return;

        Node<T>* temp = head->next;
        delete head;
        head = temp;
    }

    // Delete at tail
    void removeAtTail()
    {
        if (head == nullptr)
            return;

        // Only one node
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node<T>* temp = head;
        Node<T>* prev = head;


        // Stop at the second-last node
        while (temp->next != nullptr)
        {
        	prev = temp;
            temp = temp->next;
        }

        delete temp;
        prev->next = nullptr;

        return;
    }
    // Destructor: free all nodes
    ~LinkedList()
    {
        while (head != nullptr)
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void insertAfter(T key, T v)
{
    Node<T>* temp = head;

    while(temp != nullptr)
    {
        if(temp->info == key)
        {
            Node<T>* newNode = new Node<T>(v);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }

        temp = temp->next;
    }
}
void insertBefore(T key, T v)
{
    if(head == nullptr)
        return;

    if(head->info == key)
    {
        insertAtHead(v);
        return;
    }

    Node<T>* temp = head;

    while(temp->next != nullptr)
    {
        if(temp->next->info == key)
        {
            Node<T>* newNode = new Node<T>(v);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }

        temp = temp->next;
    }
}
void remove(T key)
{
    if(head == nullptr)
        return;

    if(head->info == key)
    {
        removeAtHead();
        return;
    }

    Node<T>* temp = head;

    while(temp->next != nullptr)
    {
        if(temp->next->info == key)
        {
            Node<T>* del = temp->next;
            temp->next = del->next;
            delete del;
            return;
        }

        temp = temp->next;
    }
}
void removeAfter(T key)
{
    Node<T>* temp = head;

    while(temp != nullptr)
    {
        if(temp->info == key)
        {
            if(temp->next != nullptr)
            {
                Node<T>* del = temp->next;
                temp->next = del->next;
                delete del;
            }

            return;
        }

        temp = temp->next;
    }
}
void removeBefore(T key)
{
    if(head == nullptr || head->next == nullptr)
        return;

    if(head->next->info == key)
    {
        removeAtHead();
        return;
    }

    Node<T>* prev = head;
    Node<T>* temp = head->next;

    while(temp->next != nullptr)
    {
        if(temp->next->info == key)
        {
            prev->next = temp->next;
            delete temp;
            return;
        }

        prev = temp;
        temp = temp->next;
    }
}
void update(T key, T v)
{
    Node<T>* temp = head;

    while(temp != nullptr)
    {
        if(temp->info == key)
        {
            temp->info = v;
            return;
        }

        temp = temp->next;
    }
}
// Assignment operator
LinkedList<T>& operator=(const LinkedList<T>& other)
{
    if(this == &other)
        return *this;

    // Delete existing nodes
    while(head != nullptr)
    {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    // Copy nodes from other list
    head = nullptr;
    Node<T>* temp = other.head;

    while(temp != nullptr)
    {
        insertAtTail(temp->info);
        temp = temp->next;
    }

    return *this;
}
};

#endif
