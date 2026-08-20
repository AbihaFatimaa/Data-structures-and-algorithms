#include <iostream>
#include <string>
using namespace std;

class stack
{
    private:
        int top;
        int arr[5];

    public:
        stack()
        {
            top = -1;
            for(int i = 0; i < 5; i++)
            {
                arr[i] = 0;
            }
        }

        bool is_empty()
        {
            return top == -1;
        }

        bool is_full()
        {
            return top == 4;
        }

        void push(int val)
        {
            if(is_full())
            {
                cout << "Stack Overflow!\n";
            }
            else
            {
                top++;
                arr[top] = val; 
            }
        }

        int pop()
        {
            if (is_empty())
            {
                cout << "Stack Underflow!\n";
                return 0; 
            }
            else
            {
                int popval = arr[top];
                arr[top] = 0;
                top--;
                return popval;
            }
        }

        int count()
        {
            return (top + 1);
        }

        int peek(int position)
        {
            if(is_empty())
            {
                cout << "Stack Underflow!\n";
                return 0;
            }
            else if(position < 0 || position > top)
            {
                cout << "Invalid position!\n";
                return 0;
            }
            else
            {
                return arr[position];
            }
        }

        void change(int pos, int val)
        {
            if (pos < 0 || pos > top)
            {
                cout << "Invalid position!\n";
            }
            else
            {
                arr[pos] = val;
                cout << val << " changed at location " << pos << endl;
            }
        }

        void display()
        {
            if (is_empty())
            {
                cout << "Stack is empty!\n";
                return;
            }
            cout << "Values of stack are:\n";
            for(int i = top; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
        }
};

int main()
{
    stack s1;
    int option, position, value;
    
    do
    {
       cout << "\nChoose an option (0 to exit):\n";
       cout << "1. Push\n"
            << "2. Pop\n"
            << "3. is_empty\n"
            << "4. is_full\n"
            << "5. Display\n"
            << "6. Change\n"
            << "7. Peek\n"
            << "8. Count\n"
            << "9. Clear screen\n";

       cin >> option;
       switch(option)
       { 
        case 0:
            break;
        case 1:
            cout << "Enter item to push: ";
            cin >> value;
            s1.push(value);
            break;
        case 2:
            if (!s1.is_empty())
                cout << "Popped value: " << s1.pop() << endl;
            else
                s1.pop(); // triggers underflow message
            break;
        case 3:
            if(s1.is_empty())
                cout << "Stack is empty!\n";
            else
                cout << "Stack is not empty!\n";
            break;
        case 4:
            if(s1.is_full())
                cout << "Stack is full!\n";
            else
                cout << "Stack is not full!\n";
            break;
        case 5:
            s1.display();
            break;
        case 6:
            cout << "Enter position and new value to change:\n";
            cin >> position >> value;
            s1.change(position, value);
            break;
        case 7:
            cout << "Enter position to peek: ";
            cin >> position;
            if (!s1.is_empty() && position >= 0 && position <= s1.count() - 1)
                cout << "Value at position " << position << " is: " << s1.peek(position) << endl;
            else
                s1.peek(position); // triggers appropriate error message
            break;
        case 8:
            cout << "Count is: " << s1.count() << endl;
            break;
        case 9:
            system("cls");
            break;
        default:
            cout << "Enter a proper option!\n";
       }

    } while(option != 0);

    return 0;
}