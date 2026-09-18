# include <windows.h>
# include <iostream>
# include <string>
using namespace std;
void PrintND(int dim)
{

	for(int i=1; i<=dim; i++)
	{
		cout<<"i"<<i;
		for(int j=i+1; j<=dim; j++)
		{
			cout<<"U"<<j;
		}
		if(i!=dim)
			cout<<"+";
	}
}
int main() {
	PrintND(3);
	cout<<endl;
	PrintND(2);
	cout<<endl;
	PrintND(1);
	return 0;
	   }
