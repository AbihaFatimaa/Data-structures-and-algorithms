# include <iostream>
# include <string>
using namespace std;
int reverse(int n, int i=0)
{
	if(n==0)
	{
		return i;
	}
	//i=n%10;
	return reverse(n/10, i*10+n%10);
}
int main()
{
	int n=56321;
	cout << "Reversed number: " << reverse(n) << endl;
	n=89641;
	cout << "Reversed number: " << reverse(n) << endl;
	return 0;
}