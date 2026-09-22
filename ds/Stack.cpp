# ifndef STACK_H
# define STACK_H

# include <iostream>
using namespace std;
template <class T>
class Stack
{
	private:
		T * data;
		int capacity;
		int top;
		
		void resize()
		{
			int newcap = capacity*2;
			T *newdata = new T[newcap];
			for(int i=0; i<top; i++)
			{
				newdata[i] = data[i];
			}
			delete[] data;
			data = newdata;
			capacity = newcap;
		}
	public:
		Stack(int capacity = 10)
		{
			if (capacity <= 0) 
			{ 
				throw invalid_argument("Stack capacity must be greater than 0."); 
			}
			this->capacity = capacity;
			this->top = 0;
			data = new T[capacity];
		}
		Stack(const Stack &s)
		{
			this->capacity = s.capacity;
			this->top = s.top;
			data = new T[capacity];
			for(int i=0; i<top; i++)
			{
				data[i] = s.data[i];
			}
		}
		Stack& operator=(const Stack &s)
		{
			if(this == &s)
			{
				return *this;
			}
			delete[] data;
			
			this->capacity = s.capacity;
			this->top = s.top;
			data = new T[capacity];
			for(int i=0; i<top; i++)
			{
				data[i] = s.data[i];
			}
			return *this;
		}
		bool isFull() const
		{
			if(top == capacity)
			{
				return true;
			}
			return false;
		}
		bool isEmpty() const
		{
			if(top == 0)
			{
				return true;
			}
			return false;
		}
		void push(T val)
		{
			if(isFull())
			{
				resize();
			}
			data[top] = val;
			top++;
		}
		T pop()
		{
			if (isEmpty()) 
			{
				throw underflow_error("Cannot pop from an empty stack."); 
			}
				top--;
				return data[top];
		}
		~Stack()
		{
			delete[] data;
		}
		T getTop()
		{
			if (isEmpty()) 
			{
				throw underflow_error("Cannot access top from an empty stack."); 
			}
			return top;
		}
		T StackTop()
		{
			return data[top-1];
		}
		int getCapacity()
		{
			return capacity;
		}
# endif
};