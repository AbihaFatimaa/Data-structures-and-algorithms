# include <iostream>
# include <string>
using namespace std;
int pow (int number, int power)
{
	if(power == 0)
	{
		return 1;
	}
	return number*pow(number, power-1);
}
int digits(int n)
{
	if(n<=0) return 0;
	return 1+digits(n/10);
	
}
string reverse(string s, int len)
{
    if(len == 0)
        return "";

    return s[len - 1] + reverse(s, len - 1);
}
int squares_sum(int n)
{
    if(n == 0)
        return 0;

    return n * n + squares_sum(n - 1);
}
int gcd(int a, int b)
{
    if(b == 0)
        return a;

    return gcd(b, a % b);
}
void bitstrings(int* bits, int n, int index)
{
    if(index == n)
    {
        for(int i = 0; i < n; i++)
            cout << bits[i];

        cout << endl;
        return;
    }

    bits[index] = 0;
    bitstrings(bits, n, index + 1);

    bits[index] = 1;
    bitstrings(bits, n, index + 1);
}
void pattern(int n)
{
    if(n == 0)
        return;

    pattern(n - 1);

    for(int i = 0; i < n; i++)
        cout << "*";

    cout << endl;
}
void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if(n == 1)
    {
        cout << "Move disc 1 from tower " << source
             << " to tower " << destination << endl;
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary);

    cout << "Move disc " << n << " from tower "
         << source << " to tower " << destination << endl;

    towerOfHanoi(n - 1, auxiliary, source, destination);
}
int countWays(int numStairs)
{
    if(numStairs == 0 || numStairs == 1)
        return 1;

    return countWays(numStairs - 1) + countWays(numStairs - 2);
}
int reverseNumber(int n, int rev)
{
    if(n == 0)
        return rev;

    return reverseNumber(n / 10, rev * 10 + n % 10);
}
bool palindrome(string s, int left, int right)
{
    if(left >= right)
        return true;

    if(s[left] != s[right])
        return false;

    return palindrome(s, left + 1, right - 1);
}
void subsets(int arr[], int n, int index)
{
    if(index == n)
    {
        cout << endl;
        return;
    }

    // Don't include arr[index]
    subsets(arr, n, index + 1);

    // Include arr[index]
    cout << arr[index] << " ";
    subsets(arr, n, index + 1);
}
int main() {
	cout<<pow(2,3)<<endl;
	cout<<digits(20)<<endl;
	cout<<reverse("hi",2)<<endl;
	cout<<squares_sum(3)<<endl;
	cout<<gcd(15,10)<<endl;
	int bits[3];
	bitstrings(bits, 3, 0);
	pattern(4);
	towerOfHanoi(3,'A','B','C');
	cout<<countWays(4);
	return 0;
	   }
