
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node
{
public:
    T info;
    Node<T>* next;
    Node<T>* prev;

    Node()
    {
        next = nullptr;
        prev = nullptr;
    }

    Node(T v)
    {
        info = v;
        next = nullptr;
        prev = nullptr;
    }
};

#endif
