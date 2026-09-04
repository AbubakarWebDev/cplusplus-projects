#include <iostream>
using namespace std;
class Dynamic
{
public:
    int data;
    int maxList;
    int length;
    int *arr;

    Dynamic(int max)
    {
        maxList = max;
        arr = new int[maxList];
    }
    
    void insert()
    {
        length = 0;
        int element;
        do
        {
            cout << "Enter an element\n ";
            cin >> element;
            arr[length] = element;
            length++;
            cout << "Elements of the array and enter -1 to stop inserting element: \n";

            for (int i = 0; i < length; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;

            if (length == maxList)
            {
                maxList = maxList + 100;
                int new_size = maxList;
                int *new_arr = new int[new_size];
                copy(arr, arr + min(maxList, new_size), new_arr);
                delete[] arr;
                arr = new_arr;
            }
        } while (element != -1);
        cout << "Stopped\n";
    }

    void deleteElement(int del)
    {
        int count = 0;
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == del)
            {
                for (int j = i; j < (length - 1); j++)
                {
                    arr[j] = arr[j + 1];
                }
                count++;
                break;
            }
        }
    }
};

int main()
{
    Dynamic d(10);
    d.insert();
}
