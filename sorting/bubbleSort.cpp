#include <iostream>
using namespace ::std;

void bubbleSort(int arr[], int n)
{
    int rounds = 0;

    for (int i = 0; i < n; i++)
    {
        rounds++;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                arr[j] = arr[j] + arr[j + 1];
                arr[j + 1] = arr[j] - arr[j + 1];
                arr[j] = arr[j] - arr[j + 1]; //Swapping function
            }
        }
    }

    cout << "The sorted Array is" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << "\t";
    }
    cout << endl
         << "The No of rounds are " << rounds << endl;
}

int main()
{
    int n;
    cout << "Enter the Size of Array" << endl;
    cin >> n;
    int *arr = new int(n);
    cout << "Enter the unsorted array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    return 0;
}