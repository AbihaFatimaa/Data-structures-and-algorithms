# include <iostream>
# include <string>
# include "../../ds/LinkedList.h"
using namespace std;
int main() {
	LinkedList <int>l;
	l.insertAtTail(4);
	l.insertAtTail(2);
	l.insertAtTail(8);
	l.insertAtTail(1);
	l.insertAtTail(9);
	l.insertAtTail(5);
	l.insertAtTail(6);
	l.display();
	l.moveKthNodeToFront(4);
	l.display();
	LinkedList <int>l2;
	LinkedList <int>l3;
	l.split(l2, l3);
	l2.display();
	l3.display(); 
	LinkedList <int>l4;
	l4.alternateMerge(l2,l3);
	l4.display();
	l4.reverseList();
	l4.display();
	l.insertAtTail(2);
	l.insertAtTail(2);
	l.insertAtTail(8);
	l.insertAtTail(1);
	l.insertAtTail(1);
	l.insertAtTail(5);
	l.insertAtTail(2);
	l.removeDuplicates();
	l.display();
	int val;
	l.removeKthNode(3, val);
	cout<<val<<endl;
	l.combine(l2,l4);
	l.display();
	return 0;
	   }
