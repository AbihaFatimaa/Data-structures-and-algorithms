# ifndef QUEUE_H
# define QUEUE_H
# include <iostream>
# include <string>
using namespace std;
template <typename T>
class Queue
{
	private:
		T* data;
		int capacity;
		int elements;
		int front;
		int rear;
		
		void resize()
		{
			int newcap = capacity*2;
			T * newdata = new T [newcap];
			for(int i=0; i<elements; i++)
			{
				newdata[i] = data[(front+i)%capacity];
			}
			delete[] data;
			data = newdata;
			capacity = newcap;
			front = 0;
			rear = elements-1;
		}
		
	public:
		Queue(int c=10)
		{
			if(c<=0)
			{
				throw invalid_argument("capacity cant be negative");
			}
			capacity = c;
			data = new T[capacity];
			front = -1;
			rear = -1;
			elements = 0;
		}
		Queue(const Queue &c)
		{
			capacity = c.capacity;
			front = c.front;
			rear = c.rear;
			elements = c.elements;
			data = new T[capacity];
			for(int i=0; i<capacity; i++)
			{
				data[i] = c.data[i];
			}
		}
		Queue<T>& operator=(const Queue &c)
		{
			if(&c == this)
			{
				return *this;
			}
			delete[]data;
			capacity = c.capacity;
			data = new T[capacity];
			for(int i=0; i<capacity; i++)
			{
				data[i] = c.data[i];
			}
			front = c.front;
			rear = c.rear;
			elements = c.elements;
			return *this;
		}
		~Queue()
		{
			delete[] data;
		}
		bool isEmpty()
		{
			return elements == 0;
		}
		bool isFull()
		{
			return elements == capacity;
		}
		void enqueue(const T& value)
		{
			if(isFull())
				resize();
			if(elements == 0)
			{
				rear = 0;
				front = 0;
			}
			else
			{
			rear = (rear+1)%capacity;
			}
			data[rear] = value;
			elements++;
		}
		T dequeue()
		{
			if(isEmpty())
				throw invalid_argument("cannot pop from an empty stack\n");
			T value = data[front];
			front = (front+1)%capacity;
			elements--;
			return value;
		}
		void display()
		{
			if(isEmpty())
			{
				throw invalid_argument("cant dequeue from empty queue");
			}
			cout<<"queue: ";
			for(int i=0; i<elements; i++)
			{
				cout<<data[(front+i)%capacity]<<" ";	
			}
			cout<<"\n";
		}
		void clear()
		{
			front = capacity-1;
			rear = capacity-1;
			elements = 0;
		}
};
# endif