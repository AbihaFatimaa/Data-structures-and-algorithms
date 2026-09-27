#include <iostream>
#include <cstring>
#include "../../ds/Stack.h"

using namespace std;

Stack<int> sum(char* a, char* b)
{
    int sizeA = strlen(a);
    int sizeB = strlen(b);

    Stack<int> na(sizeA);
    Stack<int> nb(sizeB);
    Stack<int> result(sizeA + sizeB);

    for (int i = 0; i < sizeA; i++)
    {
        na.push(a[i] - '0');
    }
    for (int i = 0; i < sizeB; i++)
    {
        nb.push(b[i] - '0');
    }

    int carry = 0;

    while (!na.isEmpty() || !nb.isEmpty())
    {
        int sum = carry;

        if (!na.isEmpty())
            sum += na.pop();

        if (!nb.isEmpty())
            sum += nb.pop();

        result.push(sum % 10);
        carry = sum / 10;
    }

    if (carry != 0)
        result.push(carry);

    return result;
}

int main()
{
    char a[26], b[26];

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    Stack<int> result = sum(a, b);

    cout << "Result is: ";

    while (!result.isEmpty())
    {
        cout << result.pop();
    }

    return 0;
}