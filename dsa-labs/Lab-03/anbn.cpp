#include <iostream>
#include <string>
#include "../../ds/Stack.h"

using namespace std;

int main()
{
    string a;
    cout << "Enter string: ";
    cin >> a;

    Stack<char> s(a.length());
    bool flag = true;
    int i = 0;

    while (i < a.length() && a[i] == 'a')
    {
        s.push(a[i]);
        i++;
    }

    while (i < a.length() && a[i] == 'b')
    {
        if (s.isEmpty())
        {
            flag = false;
            break;
        }

        s.pop();
        i++;
    }

    if (!s.isEmpty() || i != a.length())
        flag = false;

    if (flag)
        cout << "is anbn";
    else
        cout << "not anbn";

    return 0;
}