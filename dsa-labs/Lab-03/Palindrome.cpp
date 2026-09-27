# include <iostream>
# include <string>
# include "../../ds/Stack.h"
using namespace std;
bool isPalindrome(string a)
{
	string b;
	for (int i=0; i<a.length(); i++)
	{
	 	if(a[i] != ' ' || a[i]>='A' || a[i]<='Z' ||a[i]>='a' ||a[i]<='z' || a[i] >='1' || a[i]<= '9')
		{
			if (a[i] >= 'A' && a[i]<= 'Z')
			{
				a[i] = a[i]+32;
			}
			b += a[i];
	}
	}
	Stack<char> s(b.length());
	bool flag = false;
	for(int i=0; i<b.length(); i++)
	{
			s.push(b[i]);
	}
	for (int i=0; i<b.length(); i++)
	{
		if(!s.isEmpty())
		{
			if(b[i] != s.pop())
		{
			return false;
		}
	}
	}
	return true;
}
int main() 
	{
	string s;
	cout<<"enter text: \n";
	getline(cin, s);
	bool flag = isPalindrome(s);
	if(flag)
	{
		cout<<"is Palindrome \n";
	}
	else
	{
		cout<<"not a Palindrome \n";
	}
	return 0;
	   }
