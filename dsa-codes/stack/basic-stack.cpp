# include "../../ds/Stack.h"
# include <iostream>
# include <string>
using namespace std;
int main() 
{
	Stack <float> s(7);
	s.push(2);
	s.push(3);
	s.push(4);
	try
	{
		cout<<"s.pop: "<<s.pop()<<"\n";
	}
	catch (const underflow_error& e)
	{
    	cout << e.what() << endl;
	}
	try
	{
		cout<<"s.pop: "<<s.pop()<<"\n";
	}
	catch (const underflow_error& e)
	{
    	cout << e.what() << endl;
	}
	cout<<"Top: "<<s.getTop()<<"\n";
	cout<<"StackTop: "<<s.StackTop()<<"\n";
	cout<<"capacity: "<<s.getCapacity()<<"\n";
	Stack<string> s1(10);
	s1.push("A");
	s1.push("ball");
	s1.push("bat");
	cout<<"s1 pop: "<<s1.pop()<<"\n";
	cout<<"s1 pop: "<<s1.pop()<<"\n";
	cout<<"s1 pop: "<<s1.pop()<<"\n";

	return 0;
}
