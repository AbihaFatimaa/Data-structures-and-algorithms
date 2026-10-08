# include <iostream>
# include <string>
using namespace std;
int factorial(int n)
{
	if(n==0)
	{
		return 1;
	}
	return n*factorial(n-1);
}
void dtob(int n)
{
	if(n==0)
	return;
	dtob(n/2);
	cout<<n%2;
}
int main() {
	cout<<"factorial(5): "<<factorial(5)<<endl;
	dtob(9);
	return 0;
	   }
