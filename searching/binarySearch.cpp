#include <iostream>
using namespace ::std;

int binarySearch(int arr[], int num, int n)
{
    int left = 0, right = n - 1, mid = 0;
    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (arr[mid] == num)
        {
            return mid;
        }
        else if (arr[mid]< num)
        {
            left = mid + 1;
        }
        else if (arr[mid] > num)
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int num, n;
    int *arr = new int(n);
    cout << "enter the size of Array  " << endl;
    cin >> n;
    cout << "enter the Array in sorted order(ascending order) " << endl;
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }
    cout << "enter the element to be searched" << endl;
    cin >> num;
    int x = binarySearch(arr, num, n);
    if (x == -1)
    {
        cout << "No element found " <<endl;
    }
    else
    {
        cout << "element is found is at position " << x + 1 << endl;
    }
}