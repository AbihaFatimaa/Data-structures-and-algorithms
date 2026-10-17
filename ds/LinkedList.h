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

//---task 1----
bool moveKthNodeToFront(int k)
{
	if (k == 1)
	{
		return true;
	}
	if(k < 1)
	{
		return false;
	}
	int len = countNodes();
	if(k>len)
	{
		return false;
	}
	Node<T>* curr = head;
	Node<T>* prev = nullptr;
	for(int i=1; i<k; i++)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	curr->next = head;
	head = curr;
	
	return true;
}
//----Task 2----
void split(LinkedList<T>& list1, LinkedList<T>& list2)
{
    Node<T>* current = head;
    int position = 1;
    while (current != nullptr)
    {
        Node<T>* nextNode = current->next;

        current->next = nullptr;

        if (position % 2 != 0)
        {
            if (list1.head == nullptr)
            {
                list1.head = current;
            }
            else
            {
                Node<T>* temp = list1.head;

                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }

                temp->next = current;
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
                Node<T>* temp = list2.head;

                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }

                temp->next = current;
            }
        }

        current = nextNode;
        position++;
    }

    head = nullptr;
}
void reverseList()
{
    Node<T>* prev = nullptr;
    Node<T>* current = head;
    Node<T>* nextNode = nullptr;
    while (current != nullptr)
    {
        nextNode = current->next;

        current->next = prev;

        prev = current;
        current = nextNode;
    }
    head = prev;
}

//---task 3-----
void alternateMerge (LinkedList& list1, LinkedList& list2)
{
    Node<T>* current1 = list1.head;
    Node<T>* current2 = list2.head;
    Node<T>* tail = nullptr;
    while (current1 != nullptr && current2 != nullptr)
    {
        // Save the next nodes before changing links
        Node<T>* next1 = current1->next;
        Node<T>* next2 = current2->next;
        // Take a node from list1
        current1->next = nullptr;

        if (head == nullptr)
        {
            head = current1;
        }
        else
        {
            tail->next = current1;
        }
        tail = current1;
        // Take a node from list2
        current2->next = nullptr;
        tail->next = current2;
        tail = current2;
        // Move to the next nodes of the original lists
        current1 = next1;
        current2 = next2;
    }
    // Empty the original lists
    list1.head = nullptr;
    list2.head = nullptr;
}
void removeDuplicates()
{
    Node<T>* current = head;
    while (current != nullptr)
    {
        Node<T>* previous = current;
        Node<T>* temp = current->next;
        while (temp != nullptr)
        {
            if (temp->info == current->info)
            {
                previous->next = temp->next;
                delete temp;

                temp = previous->next;
            }
            else
            {
                previous = temp;
                temp = temp->next;
            }
        }

        current = current->next;
    }
}
bool removeKthNode(int k, int& val)
{
    if (k <= 0 || head == nullptr)
    {
        return false;
    }

    Node<T>* current = head;
    Node<T>* previous = nullptr;

    int position = 1;

    while (current != nullptr && position < k)
    {
        previous = current;
        current = current->next;
        position++;
    }

    if (current == nullptr)
    {
        return false;
    }

    val = current->info;

    if (previous == nullptr)
    {
        head = head->next;
    }
    else
    {
        previous->next = current->next;
    }

    delete current;

    return true;
}
void combine(LinkedList<T>& list1, LinkedList<T>& list2)
{
    if (list1.head == nullptr)
    {
        head = list2.head;
    }
    else
    {
        head = list1.head;

        Node<T>* temp = list1.head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = list2.head;
    }

    list1.head = nullptr;
    list2.head = nullptr;
}
};

#endif
