// Compressed sparsed row.

# include <iostream>
# include <string>
using namespace std;
int main() {
	int sparse[7][5] = {0};
	sparse[0][0] = 8;
	sparse[0][2] = 2;
	sparse[1][2] = 5;
	sparse[4][2] = 7;
	sparse[4][3] = 1;
	sparse[4][4] = 2;
	sparse[6][3] = 9;
	
	int data[8];
	int index[8];
	int indexptr[8];
	indexptr[0] = 0;
	int k=0;
	
	for(int i=0; i<7; i++)
	{
		for(int j=0; j<5; j++)
		{
			if(sparse[i][j] != 0)
			{
				data[k] = sparse[i][j];
				index[k] = j;
				k++;
			}
		}
		indexptr[i+1] = k;
	}
	for(int i=0; i<k; i++)
	{
		cout<<"Data: "<<data[i]<<" Col no: "<<index[i]<<" indexptr: "<<indexptr[i]<<endl;
	}
	cout<<" indexptr: "<<indexptr[k];
	return 0;
	   }
