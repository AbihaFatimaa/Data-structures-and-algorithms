# include <iostream>
# include <string>
# include "../../ds/Stack.h"
using namespace std;
bool isValid(string eq)
{
	bool flag = false;
	Stack<char>s(eq.length());
	for(int i=0; i<eq.length(); i++)
	{
		char nextch = eq[i];
		if(nextch == '(' || nextch == '{' || nextch == '[') 
		{
			s.push(nextch);
		}
		else if(nextch == ')' || nextch == '}' || nextch == ']')
		{
			flag = false;

			if(!s.isEmpty())
			{
			char ch = s.StackTop();
			flag = false;
			if(nextch == ')'&& ch == '(' )
				s.pop();
			else if (nextch == '}'&& ch == '{' )
				s.pop();
			else if (nextch == ']'&& ch == '[')
			{
				s.pop();
			}
			else
			{
				flag = false;
			}
		}
	}}
	if(s.isEmpty())
	{
		if(flag)
		{
			return true;
		} 
	}
	else if(s.isEmpty())
	{
		if(!flag)
			return false;
	}
}
int main() {
	string eq;
	cout<<"enter equation: \n";
	getline(cin, eq);
	bool flag = isValid(eq);
	if(flag)
	{
		cout<<"is Good\n";
	}
	else
	{
		cout<<"not Bad\n";
	}
	return 0;
	   }
