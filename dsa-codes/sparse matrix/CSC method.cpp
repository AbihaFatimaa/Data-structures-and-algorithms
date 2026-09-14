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
	int indexptr[6];
	indexptr[0] = 0;
	int k=0;
	
	for(int j = 0; j<5; j++)
	{
		for(int i=0; i<7; i++)
		{
			if(sparse[i][j] != 0)
			{
				data[k] = sparse[i][j];
				index[k] = i;
				k++;
			}
		}
		indexptr[j+1] = k;

	}
	for(int i=0; i<k; i++)
	{
		cout<<"Data: "<<data[i]<<" Row no: "<<index[i]<<" indexptr: "<<indexptr[i]<<endl;
	}
	return 0;
	   }
