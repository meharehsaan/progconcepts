#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // If no two elements were swapped in the inner loop, the array is already sorted.
        if (!swapped)
        {
            break;
        }
    }
}

int main()
{
    int size;

    cout << "Entry Array size" << endl;
    cin >> size;

    int arr[size];

    // Taking array from user
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Element " << i + 1 << " :: ";
        cin >> arr[i];
    }

    bubbleSort(arr, size);

    cout << "\nSorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
