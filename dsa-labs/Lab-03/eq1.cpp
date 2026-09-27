# include <iostream>
# include <string>
# include "../../ds/Stack.h"
using namespace std;
bool isvalid(string a)
{
	bool flag = false;
	Stack<char> s(a.length());
	for(int i=0;  i<a.length(); i++)
	{
		flag = false;
		char nextch = a[i];
		if(nextch == '('||nextch == '{'||nextch=='[')
		{
			s.push(nextch);
		}
		else if (nextch ==')'||nextch == '}'||nextch==']')
		{	if (s.isEmpty())
   			 	return false;
			char ch = s.pop();
			if ((nextch == ')' && ch == '(') ||
			    (nextch == '}' && ch == '{') ||
			    (nextch == ']' && ch == '['))
		 	{
				flag = true;
			}
			
		
	}
	if(s.isEmpty())
	{
		if(flag)
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}
}
int main() {
		string eq;
	cout<<"enter equation: \n";
	getline(cin, eq);
	bool flag = isvalid(eq);
	if(flag)
	{
		cout<<"is Good\n";
	}
	else
	{
		cout<<"is Bad\n";
	}
	return 0;
	   }
