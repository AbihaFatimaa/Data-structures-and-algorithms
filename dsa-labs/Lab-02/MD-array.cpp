# include <iostream>
# include <string>
using namespace std;
class NDarray{
	private:
		int *size;
		int dim;
		int tsize;
		int *arr;
		
	public:
		NDarray(int dim, int size[])
		{
			tsize = 1;
			this->dim = dim;
			this->size = new int[dim];
			for(int i=0; i<dim; i++)
			{
				this->size[i] = size[i];
				tsize *= size[i];
			}
			arr = new int[tsize];
			for(int i=0; i<tsize; i++)
			{
				arr[i] = 0;
			}
			
		}
		~NDarray()
		{
			delete[] size;
			delete[] arr;
		}
		int calculateIndex(int* index)
		{
			int ind=1;
			for(int i=0; i<dim; i++)
			{
				
				ind *= index[i];
			}
			return ind;	
		}
		void setValue(int* index, int val)
		{			
			int ind = calculateIndex(index);
			if(ind >= tsize)
			{
				cout<<"index do not exist";
			}
			
			arr[ind - 1] = val;
		}
		int getValue(int *index)
		{
			int ind = calculateIndex(index);
			return arr[ind-1];
		}
		void display()
		{
			for(int i=0; i<tsize; i++)
			{
				cout<<arr[i]<<" ";
			}
		}	
};
int main() {
	int dim_size[3]={5,3,10};
	NDarray arr(3, dim_size);
	cout<<"array init\n";
	int indexset[3]={4,2,8};
	cout<<"index: "<<arr.calculateIndex( indexset )<<endl;
	arr.setValue( indexset , 3);
	cout<<"\nvalue: "<<arr.getValue(indexset);
	int	iindexset [3]={1,2,3};
	arr.setValue(iindexset, 8);
	cout<<"\n value: "<<arr.getValue(iindexset);
	cout<<endl;
//	arr.display();
	return 0;
	   }
