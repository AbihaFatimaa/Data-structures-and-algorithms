# include <iostream>
# include <string>
# include "../../ds/Stack.h"
using namespace std;
bool ishomogeneousValid(string infix)
{
	Stack<char> s(infix.length());
	for (int i=0; i<infix.length(); i++)
	{
		char nextch = infix[i];
		if(nextch == '(')
		{
			s.push(nextch);
		}
		else if(nextch == ')')
		{
			if(s.isEmpty())
			{
				return false;
			}
			char stop = s.pop();
			if(stop != '(')
			{
				return false;
			}
		}
	}
	if (s.isEmpty())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool ishetroValid(string infix)
{
	Stack<char> s(infix.length());
	for(int i=0; i<infix.length(); i++)
	{
		char nextch = infix[i];
		if(nextch == '(' || nextch == '{'|| nextch == '[')
		{
			s.push(nextch);
		}
		else if (nextch == ')'|| nextch == '}'|| nextch == ']')
		{
			if(s.isEmpty())
			{
				return false;
			}
				char stop = s.pop();
				if ((stop == '(' && nextch != ')') ||
    				(stop == '{' && nextch != '}') ||
   					(stop == '[' && nextch != ']'))
				{
					return false;
				}
		}
	}
	if(s.isEmpty())
		{
			return true;
		}
		else
		{
			return false;
		}
}

int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '(')
    {
        return 0;
    }

    return -1;
}
bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}


bool isOperand(char ch)
{
    return (ch >= 'A' && ch <= 'Z') ||
           (ch >= 'a' && ch <= 'z') ||
           (ch >= '0' && ch <= '9');
}
string toPostfix(string infix)
{
    Stack<char> s(infix.length());
    string postfix = "";

    int i = 0;

    while (i < infix.length())
    {
        char nextch = infix[i];

        // If operand
        if (isOperand(nextch))
        {
            postfix += nextch;
        }

        // If opening bracket
        else if (nextch == '(')
        {
            s.push(nextch);
        }

        // If closing bracket
        else if (nextch == ')')
        {
            while (!s.isEmpty() && s.StackTop() != '(')
            {
                postfix += s.pop();
            }

            // Pop '('
            if (!s.isEmpty())
            {
                s.pop();
            }
        }

        // If operator
        else if (isOperator(nextch))
        {
           while (!s.isEmpty() &&
		       s.StackTop() != '(' &&
		       precedence(s.StackTop()) >= precedence(nextch))
		{
		    postfix += s.pop();
		}

            s.push(nextch);
        }

        i++;
    }

    // Pop remaining operators
    while (!s.isEmpty())
    {
        postfix += s.pop();
    }

    return postfix;
} 
int evalpostfix(string postfix)
{
    Stack<int> s(postfix.length());

    for(int i=0; i<postfix.length(); i++)
    {
        char nextch = postfix[i];

        if(isOperand(nextch))
        {
            s.push(nextch - '0');
        }
        else if(isOperator(nextch))
        {
            int op2 = s.pop();
            int op1 = s.pop();

            if(nextch == '+')
            {
                s.push(op1 + op2);
            }
            else if(nextch == '-')
            {
                s.push(op1 - op2);
            }
            else if(nextch == '*')
            {
                s.push(op1 * op2);
            }
            else if(nextch == '/')
            {
                s.push(op1 / op2);
            }
        }
    }
    return s.pop();
}

string toPrefix(string infix)
{
    Stack<char> operatorStack(infix.length());
    Stack<string> operandStack(infix.length());

    int i = 0;

    while(i < infix.length())
    {
        char nextch = infix[i];

        // Operand
        if(isOperand(nextch))
        {
            string operand(1, nextch);
            operandStack.push(operand);
        }

        // Opening bracket
        else if(nextch == '(')
        {
            operatorStack.push(nextch);
        }

        // Closing bracket
        else if(nextch == ')')
        {
            while(!operatorStack.isEmpty() &&
                  operatorStack.StackTop() != '(')
            {
                char op = operatorStack.pop();

                string operand2 = operandStack.pop();
                string operand1 = operandStack.pop();

                string result = "";
                result += op;
                result += operand1;
                result += operand2;

                operandStack.push(result);
            }

            // Remove '('
            if(!operatorStack.isEmpty())
            {
                operatorStack.pop();
            }
        }

        // Operator
        else if(isOperator(nextch))
        {
            while(!operatorStack.isEmpty() &&
                  operatorStack.StackTop() != '(' &&
                  precedence(operatorStack.StackTop()) >= precedence(nextch))
            {
                char op = operatorStack.pop();

                string operand2 = operandStack.pop();
                string operand1 = operandStack.pop();

                string result = "";
                result += op;
                result += operand1;
                result += operand2;

                operandStack.push(result);
            }

            operatorStack.push(nextch);
        }

        i++;
    }

    // Process remaining operators
    while(!operatorStack.isEmpty())
    {
        char op = operatorStack.pop();

        string operand2 = operandStack.pop();
        string operand1 = operandStack.pop();

        string result = "";
        result += op;
        result += operand1;
        result += operand2;

        operandStack.push(result);
    }

    return operandStack.pop();
}


string toPrefixOneStack(string infix)
{
    // Step 1: Reverse infix and swap brackets
    string reversed = "";

    for(int i = infix.length() - 1; i >= 0; i--)
    {
        if(infix[i] == '(')
        {
            reversed += ')';
        }
        else if(infix[i] == ')')
        {
            reversed += '(';
        }
        else
        {
            reversed += infix[i];
        }
    }

    // Step 2: Scan reversed expression
    Stack<char> s(reversed.length());
    string prefix = "";

    for(int i = 0; i < reversed.length(); i++)
    {
        char nextch = reversed[i];

        // Operand
        if(isOperand(nextch))
        {
            prefix += nextch;
        }

        // Opening bracket
        else if(nextch == '(')
        {
            s.push(nextch);
        }

        // Closing bracket
        else if(nextch == ')')
        {
            while(!s.isEmpty() && s.StackTop() != '(')
            {
                prefix += s.pop();
            }

            // Remove '('
            if(!s.isEmpty())
            {
                s.pop();
            }
        }

        // Operator
        else if(isOperator(nextch))
        {
            while(!s.isEmpty() &&
                  s.StackTop() != '(' &&
                  precedence(s.StackTop()) > precedence(nextch))
            {
                prefix += s.pop();
            }

            s.push(nextch);
        }
    }

    // Step 3: Pop remaining operators
    while(!s.isEmpty())
    {
        prefix += s.pop();
    }

    // Step 4: Reverse prefix
    string finalPrefix = "";

    for(int i = prefix.length() - 1; i >= 0; i--)
    {
        finalPrefix += prefix[i];
    }

    return finalPrefix;
}

int evalPrefix(string prefix)
{
    Stack<int> s(prefix.length());

    for(int i = prefix.length() - 1; i >= 0; i--)
    {
        char nextch = prefix[i];

        // If operand
        if(isOperand(nextch))
        {
            s.push(nextch - '0');
        }

        // If operator
        else if(isOperator(nextch))
        {
            int operand1 = s.pop();
            int operand2 = s.pop();

            if(nextch == '+')
            {
                s.push(operand1 + operand2);
            }
            else if(nextch == '-')
            {
                s.push(operand1 - operand2);
            }
            else if(nextch == '*')
            {
                s.push(operand1 * operand2);
            }
            else if(nextch == '/')
            {
                s.push(operand1 / operand2);
            }
        }
    }

    return s.pop();
}
int main() {
	string infix;
	cout<<"enter infix string: \n";
	cin >> infix;
	bool valid  = ishomogeneousValid(infix);
	cout<<"homo valid: "<<valid<<"\n";
	bool v = ishetroValid(infix);
	cout<<"hetro valid: "<<v<<"\n";
	cout<<"postfix: "<<toPostfix(infix)<<"\n";
	string postfix;
	cout<<"enter postfix : \n";
	cin>>postfix;
	cout<<"eval: "<<evalpostfix(postfix)<<"\n";
	cout<<"prefix: "<<toPrefix(infix)<<"\n";
	cout<<"prefixonestack: "<<toPrefixOneStack(infix)<<"\n";
	cout<<"eval: "<<evalPrefix(toPrefix(infix))<<"\n";
	return 0;
	   }
