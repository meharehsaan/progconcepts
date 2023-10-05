#include <iostream>

// Need n-1 iterations to sort the array

using namespace std;

void insertion_sort(int arr[], int size)
{
    int key;
    int j;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];    // assigning key the 2nd value in array at index 1
        j = i - 1;      // j become behind the i

        //if j goes out of index and key greater than previous element loop terminates
        while (j > -1 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; 
            j = j - 1;
        }

        arr[j + 1] = key;   // moving key to j + 1 position
    }

    cout << "Sorted Array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
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
        cout << "Enter Element " << i+1 << " :: ";
        cin >> arr[i];
    }

    //calling insertion sort
    insertion_sort(arr, size);
}