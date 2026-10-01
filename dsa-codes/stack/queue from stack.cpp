# include <iostream>
# include <string>
# include "../../ds/Stack.h"
using namespace std;
class queue
{
	private:
		Stack<int> s1;
		Stack<int> s2;
	public:
		queue(int c=10):s1(c), s2(c)
		{
		}
		void enqueue(int v)
		{
			s1.push(v);
		}
		int dequeue()
		{ 
			if(s1.isEmpty()&&s2.isEmpty())
			{
				throw runtime_error("stacks are empty");
			}
			if(s2.isEmpty())
			{
				while(!s1.isEmpty())
				{
					s2.push(s1.pop());
				}
			}
			return s2.pop();
		}
		int front()
		{ 
			if(s1.isEmpty()&&s2.isEmpty())
			{
				throw runtime_error("stacks are empty");
			}
			if(s2.isEmpty())
			{
				while(!s1.isEmpty())
				{
					s2.push(s1.pop());
				}
			}
			return s2.StackTop();
		}
		bool isEmpty()
	    {
	        return s1.isEmpty() && s2.isEmpty();
	    }
			 
};
int main() {
	queue q1(4);
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(6);
	cout<<q1.dequeue()<<endl;
	cout<<q1.dequeue()<<endl;
	cout<<q1.isEmpty()<<endl;
	return 0;
	   }
