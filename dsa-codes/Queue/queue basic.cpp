# include <iostream>
# include <string>
# include "../../ds/Queue.h"
using namespace std;
int main() {
	Queue <int> q(3);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(4);
	q.display();
	cout<<"dequeue: "<<q.dequeue();
	cout<<"\ndequeue: "<<q.dequeue();
	cout<<"\ndequeue: "<<q.dequeue();
	return 0;
	   }
