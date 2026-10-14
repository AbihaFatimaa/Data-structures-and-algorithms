# ifndef NODE_H
# define NODE_H
# include <iostream>
# include <string>
using namespace std;
template <class T>
class Node
{
	public:
		T info;
		Node<T> * next;
		Node()
		{
			next=0;
		}
		Node(T v)
		{
			info = v;
			next = 0;
		}
};
# endif