# include <iostream>
# include <string>
# include "../../ds/Queue.h"
using namespace std;
int printer(int arr[],int n, int k)
{
	Queue<int> q(n);
	int count=0;
	for(int i=0; i<n; i++)
	{
		q.enqueue(arr[i]);
		
	}
	for(int i=0; !q.isEmpty(); i++)
	{
		int pages = q.dequeue()-1;
		count++;
		if(pages != 0)
		{
			q.enqueue(pages);
		}
		if(q.getfront()==k)
		{
			arr[k] = pages;
			if(arr[k] == 0)
			{
				return count;
			}
		}
	}
	return count;
}
int main() {
	int arr[4] = {3,3,1,2};
	int k=0;
	cout<<"time: "<<printer(arr,4,k)<<endl;
	return 0;
	   }
