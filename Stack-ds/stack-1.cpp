#include <iostream>
#include <string.h>
using namespace ::std;

class Stack
{

private:
    int top;
    int arr[7];

public:
    Stack()
    {
        top = -1;
        for (int i = 0; i < 7; i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (top == 6)
            return true;
        else
            return false;
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            top++;          //increased the value of top variable
            arr[top] = val; //store the value passed in push method
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underFlow" << endl;
            return 0;
        }
        else
        {
            int popValue = arr[top];
            arr[top] = 0;
            top--;
            return popValue;
        }
    }

    int count()
    {
        int countValue = top + 1;
        return countValue;
    }

    int peek(int index)
    {
        if (isEmpty())
        {
            cout << "Stack underFlow" << endl;
            return 0;
        }
        else
        {
            return arr[index - 1]; //as the position or index is 1st 2nd 3rd ....  and not from one
        }
    }

    int change(int index, int val)
    {
        arr[index - 1] = val;
        cout << "item changed at location" << index << endl;
    }

    void display()
    {
        cout << " All the values of stack are as" << endl;
        for (int i = 6; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{

    Stack s1;
    int option, position, value;

    do
    {
        cout << "This is Stack menu ,please enter the suitable number for the method on stack!!Enter 0 to exit the menu " << endl;
        cout << "1.Push" << endl;
        cout << "2.Pop" << endl;
        cout << "3.Check if its empty" << endl;
        cout << "4.Check if its full" << endl;
        cout << "5.Peek with index number" << endl;
        cout << "6.Count the no of elements in the array" << endl;
        cout << "7. Change value at index number(index,value)" << endl;
        cout << "8.Display all the elements" << endl;
        cout << "9.Clear the screen" << endl
             << endl;

        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enter the item to push" << endl;
            cin >> value;
            s1.push(value);
            break;
        case 2:
            cout << "Pop function called -- popped value is " << s1.pop() << endl;
            break;
        case 3:
            if (s1.isEmpty())
            {
                cout << "The Stack is Empty" << endl;
            }
            else
            {
                cout << "The Stack is  Not Empty" << endl;
            }
            break;
        case 4:
            if (s1.isFull())
            {
                cout << "The Stack is Full" << endl;
            }
            else
            {
                cout << "The Stack is  Not Full" << endl;
            }
            break;

        case 5:
            cout << " Enter the index you want to peek at :";
            cin >> position;
            cout << "The value in Stack at postion" << position << " is " << s1.peek(position) << endl;
            break;
        case 6:
            cout << "count function called" << endl;
            cout << "the total number of values in stack : " << s1.count() << endl;
            break;
        case 7:
            cout << " Enter the index: ";
            cin >> position;
            cout << endl;
            cout << " enter the value: ";
            cin >> value;
            cout << endl;
            cout << "The new Value is stored at :" << position << " is " << s1.change(position, value) << endl;
            break;
        case 8:
            cout << "Dispaly function called--" << endl;
            s1.display();
            break;
        case 9:
            system("cls");
            break;
        default:
            cout << "the option number is wrong enter again" << endl;
            break;
        }
    } while (option != 0);

    return 0;
}