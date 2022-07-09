#include <iostream>
#include <string.h>
using namespace ::std;

class CircularQueue
{
private:
    int front, rear;
    int arr[6];
    int itemCount;

public:
    CircularQueue()
    {
        itemCount = 0;
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if ((rear + 1) % 6 == front)
            return true;
        else
            return false;
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Circular-Queue is Full" << endl;
            return;
        }
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % 6;
        }
        arr[rear] = val;
        itemCount++;
    }

    int dequeue()
    {
        int x;
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return 0;
        }
        else if (front == rear)
        {
            x = arr[front];
            arr[front] = 0;
            rear = -1;
            front = -1;
        }
        else
        {
            x = arr[front];
            arr[front] = 0;
            front = (front + 1) % 6;
        }
        itemCount--;
        return x;
    }

    int count()
    {
        if (isEmpty())
        {
            cout << "Queue is empty";
            return 0;
        }
        else if (isFull())
        {
            return 6;
        }
        else
        {
            return itemCount;
        }
    }

    void display()
    {
        cout << "The CircularQueue is :" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{

    CircularQueue q1;
    int option, value;

    do
    {
        cout << "Enter the option for methods on CircularQueue !! Enter 0 to exit" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Is Empty" << endl;
        cout << "4. Is Full" << endl;
        cout << "5. Count" << endl;
        cout << "6. Display" << endl;
        cout << "7. Clear Screen" << endl
             << endl;
        cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enter the value for Queue" << endl;
            cin >> value;
            q1.enqueue(value);
            break;
        case 2:
            cout << "The value dequeued is " << q1.dequeue() << endl;
            break;
        case 3:
            if (q1.isEmpty())
            {
                cout << "The CircularQueue is Empty" << endl;
            }
            else
            {
                cout << "The CircularQueue is Not Empty" << endl;
            }
            break;
        case 4:
            if (q1.isFull())
            {
                cout << "The CircularQueue is Full" << endl;
            }
            else
            {
                cout << "The CircularQueue is Not Full" << endl;
            }
            break;

        case 5:
            cout << "The total Elements in Queue is " << q1.count() << endl;
            break;
        case 6:
            q1.display();
            cout << endl;
            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "the option is wrong" << endl;
            break;
        }

    } while (option != 0);

    return 0;
}
