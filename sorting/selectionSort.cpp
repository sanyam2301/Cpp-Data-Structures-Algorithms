#include <iostream>
using namespace ::std;

void selectionSort(int arr[], int n)
{
    int min = 0;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {

            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            arr[min] = arr[min] + arr[i];
            arr[i] = arr[min] - arr[i];
            arr[min] = arr[min] - arr[i];
        }
    }
    cout << "The sorted array is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
}

int main()
{
    int n;
    cout << "Enter the size of Array" << endl;
    cin >> n;
    int *arr = new int(n);
    cout << "Enter the elements for sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selectionSort(arr, n);

    return 0;
}