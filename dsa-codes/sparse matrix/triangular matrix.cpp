# include <iostream>
# include <string>
using namespace std;
int main() {
	int tri[4][4]={0};
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			if(i<=j)
			{
				tri[i][j] = 2;
			}
		}
	}
	
	int row[4];
	int col[4];
	int data[12];
	int k=0;
	for(int i=0; i<4; i++){
		for (int j=0; j<4; j++)
		{
			if(i<=j)
			{
				row[k] = i;
				col[k] = j;
				data[k] = tri[i][j];
				k++;
			}
		}
	}	
	
	for(int i=0; i<k; i++)
	{
		cout<<"Row: "<<row[i]<<" col: "<<col[i]<<" data: "<<data[i]<<"\n";
	}
	return 0;
	   }
