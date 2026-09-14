// Coordinated list format.

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
	
	int row[7];
	int col[7];
	int data[7];
	int k=0;
	for(int i=0; i<7; i++)
	{
		for(int j=0; j<5; j++)
		{
			if(sparse[i][j] != 0)
			{
				data[k] = sparse[i][j];
				row[k] = i;
				col[k] = j;
				k++;
			}
		}         
	}
	cout<<"Coo Array: \n";
	for(int i=0; i<k; i++)
	{
		cout<<"Row: "<<row[i]<<" Col: "<<col[i]<<" data: "<<data[i]<<"\n";
	}
	return 0;
	   }
