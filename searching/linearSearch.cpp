#include <iostream>

using namespace ::std;

void linearSerach(int arr[], int num,int n)
{
    bool flag = true;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            cout << "Element found at the position " << i + 1 << endl;
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "No element found" << endl;
    }
}

int main()
{
    int num;
    int n;
    int *arr = new int(n);
    cout << "enter the size of array" << endl;
    cin >> n;
    cout << "Enter " << n << " elements in the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the element to be searched" << endl;
    cin >> num;
    linearSerach(arr, num,n);
    return 0;
}