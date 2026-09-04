/**********************************************************************************
Problem Statement: Write a class template called Set which contains a pointer to a dynamic array that stores the elements of a set, and a count of the number of elements in the set. You must provide all the member functions required for the proper execution of the following main function:

int main()
{
    int intArray[] = {2, 3, 6, 1, 2, 0, -1};
    float floatArray[] = {4.1, 3.33, 7.15};

    // makes use of the Date class you developed in problem1
    Date d1, d2, d3;
    cin >> d1 >> d2 >> d3;
    Date dateArray[] = {d1, d2, d3};

    Set<int> S1(intArray, 7);
    Set<float> S2(floatArray, 3);
    Set<Date> S3(dateArray, 3);

    // print function of Set class outputs all the data present in the // array within the Set
    S1.print();
    S2.print();
    S3.print();

    return 0;
}
***********************************************************************************/

#include <iostream>
using namespace std;

template <class T>
class Set
{
private:
    T *array;
    unsigned int size;
    void extend(int increment);

public:
    Set(T arr[], int size);
    ~Set();

    void print();
    void push(T _newValue);
    unsigned int getSize();
    T getValue(unsigned int _index);
};

template <class T>
void Set<T>::extend(int increment)
{
    size += increment;
    T *newData = new T[size];
    for (int i = 0; i < size; i++)
    {
        newData[i] = array[i];
    }
    delete[] array;
    array = newData;
}

template <class T>
Set<T>::Set(T arr[], int size)
{
    array = new T[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = arr[i];
    }
    this->size = size;
}

template <class T>
Set<T>::~Set()
{
    delete[] array;
}

template <class T>
void Set<T>::push(T _newValue)
{
    extend(1);
    array[size - 1] = _newValue;
}

template <class T>
inline unsigned int Set<T>::getSize() { return size; }

template <class T>
T Set<T>::getValue(unsigned int _index)
{
    return array[_index];
}

template <class T>
void Set<T>::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << ", ";
    }
    cout << endl;
}

int main()
{
    int intArray[] = {2, 3, 6, 1, 2, 0, -1};
    float floatArray[] = {4.1, 3.33, 7.15};

    Set<int> S1(intArray, 7);
    Set<float> S2(floatArray, 3);

    // print function of Set class outputs all the data present in the // array within the Set
    S1.print();
    S2.print();
    cout << S2.getValue(2) << endl;
    cout << S1.getValue(4) << endl;
    cout << S1.getSize() << endl;
    S1.push(48);
    cout << S1.getSize() << endl;
    S1.print();

    return 0;
}