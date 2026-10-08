# include <iostream>
# include <string>
# include "../../ds/Queue.h"
using namespace std;

int printer(int arr[],int n, int k)
{
	int time=0;
	Queue <int> q(n);
	Queue <int> a(n);
	for(int i=0; i<n; i++)
	{
		q.enqueue(arr[i]);
		a.enqueue(i);
	}
	for(int i=0; !q.isEmpty(); i++)
	{
		int pages = q.dequeue()-1;
		time++;
		int ind = a.dequeue();
		if(pages != 0)
		{
			q.enqueue(pages);
			a.enqueue(ind);
		}
		if(ind == k)
		{
			if(pages == 0)
			{
				return time;
			}
		}
	}
	return time;
}
int main() {
	int arr[4] = {5,1,1,1};
	int k=0;
	cout<<"time: "<<printer(arr,4,k)<<endl;
	int a[5]={2,2,2,3,2};
	int c=3;
	cout<<"time: "<<printer(a,5,c)<<endl;

	
	return 0;
	   }
