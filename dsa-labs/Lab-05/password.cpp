
#include <iostream>
#include <string>
using namespace std;

bool isValidPassword(const string &s, int index = 0)
{
    // Base case: all characters have been checked
    if (index == s.length())
    {
        return true;
    }

    // Even indices must contain digits
    if (index % 2 == 0)
    {
        if (!(s[index] >= '0' && s[index] <= '9'))
        {
            return false;
        }
    }
    // Odd indices must contain lowercase letters
    else
    {
        if (!(s[index] >= 'a' && s[index] <= 'z'))
        {
            return false;
        }
    }

    // Check the next character recursively
    return isValidPassword(s, index + 1);
}

int main()
{
    string passwords[] = {
        "1a2b3c",
        "23478",
        "1a2B3c",
        "5x7y"
    };

    for (string password : passwords)
    {
        bool is_valid = isValidPassword(password);

        cout << "Password: " << password
             << " is "
             << (is_valid ? "Valid" : "Invalid")
             << endl;
    }

    return 0;
}
