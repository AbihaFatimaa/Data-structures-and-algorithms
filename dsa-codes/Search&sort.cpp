# include <iostream>
# include <string>
using namespace std;
bool linearSearch(int arr[], int n, int key)
{
	for(int i=0; i<n; i++)
	{
		if(arr[i] == key)return true;
	}
	return false;
}
bool binarySearch(int arr[], int n, int key)
{
	int start=0; int end = n-1;
	while(start<=end)
	{
		int mid = (end+start)/2;
		if(arr[mid] == key) return true;
		else if(arr[mid]>key) end = mid-1;
		else if(arr[mid]<key) start = mid+1;
	}
	return false;
}
void bubbleSort(int a[], int n)
{
	for(int j=0; j<n-1; j++)
	{
		bool flag=false;
		for(int i=0; i<n-j-1; i++)
		{
			if(a[i]>a[i+1])
			{
				swap(a[i], a[i+1]);
				flag=true;
			}
		}
		if(!flag)
		{
			break;
		}
	}
}
void selectionSort(int arr[], int n)
{
	for(int i=0; i<n; i++)
	{
		int min_ind=i;
		for(int j=i; j<n; j++)
		{
			if(arr[min_ind]>arr[j])
			{
				min_ind=j;
			}
		}
		swap
		(arr[i], arr[min_ind]);
	}
}
void insertionSort(int arr[], int n)
{
	for(int i=0; i<n; i++)
	{
		int key=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}
int main() {
	int n=5;
	int arr[n]={1,2,5,4,3};
	bool t = linearSearch(arr, n, 3);
	cout<<t<<endl;
	int a[n] = {1,2,3,4,5};
	t=binarySearch(a, n, 3);
	cout<<t<<endl;
	bubbleSort(arr, n);
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int ab[n] = {2,4,8,7,6};
	selectionSort(ab, n);
	for(int i=0; i<n; i++)
	{
		cout<<ab[i]<<" ";
	}
	cout<<endl;
	int abc[n] = {2,4,8,7,6};
	insertionSort(abc, n);
	for(int i=0; i<n; i++)
	{
		cout<<abc[i]<<" ";
	}
	cout<<endl;
	return 0;
	   }
