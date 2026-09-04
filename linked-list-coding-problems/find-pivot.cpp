/*
Q # 01: Write down a function findpivot(data) where data is an integer array. Findpivot(data) returns the index of first element X such that all values before X are less than it and all elements after X are greater than it. Findpivot(data) returns -1 if no such element exists.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int findPivot(int arr[], int left, int right)
{
    int pivot = arr[left], j = left + 1;

    for (int i = left + 1; i <= right; i++)
    {
        if (arr[i] < pivot)
        {
            if (i != j)
            {
                swap(arr[i], arr[j]);
            }
            j++;
        }
    }

    arr[left] = arr[j - 1];
    arr[j - 1] = pivot;

    return j - 1;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    system("cls");
    int size;

    cout << "Please Enter Array Size: ";
    cin >> size;

    int *arr = new int[size];

    cout << "\nPlease Enter Array Values\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Array Value at index " << i << " is: ";
        cin >> arr[i];
    }

    cout << "\nGiven array is \n";
    printArray(arr, size);

    cout << "\nPivot Index: " << findPivot(arr, 0, size - 1) << "\n";

    cout << "\nAfter Creating Pivot Array is \n";
    printArray(arr, size);

    return 0;
}