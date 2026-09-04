// Chapter : Arrays
// Example 2 : Swap the contents of two variables

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int a = 14, b = 72, temp = 0;
	cout << "Before swap a = " << a << "  , b = " << b << endl
		 << endl;

	temp = a;
	a = b;
	b = temp;

	cout << "After swap a = " << a << " , b = " << b << endl;

	cout << endl;

	return 0;
};

	// Chapter : Arrays
	// Example 3 : Moving the largest element at the end of array

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int main()
{
	const int sz = 7;
	int i = 0, temp = 0;
	int g[sz] = {30, 93, 77, 24, 50, 28, 12};

	system("cls");

	cout << "\n\nContents of array g (Original) are : ";
	for (i = 0; i < sz; i++)
		cout << setw(4) << g[i];

	cout << endl;
	getch();

	// move the largest element to the RIGHT end
	for (i = 0; i < sz - 1; i++)
		if (g[i] > g[i + 1])
		{
			temp = g[i];
			g[i] = g[i + 1];
			g[i + 1] = temp;
		}

	cout << "\n\nContents of array g (Largest @ RIGHT) are : ";
	for (i = 0; i < sz; i++)
		cout << setw(4) << g[i];

	cout << endl;
	getch();

	// move the largest element to the LEFT end
	for (i = 1; i < sz; i++)
		if (g[0] < g[i])
		{
			temp = g[0];
			g[0] = g[i];
			g[i] = temp;
		}

	cout << "\n\nContents of array g (Largest @ LEFT) are : ";
	for (i = 0; i < sz; i++)
		cout << setw(4) << g[i];

	cout << endl;
	getch();

	// move the smallest element to the RIGHT end
	for (i = 0; i < sz - 1; i++)
		if (g[i] < g[i + 1])
		{
			temp = g[i];
			g[i] = g[i + 1];
			g[i + 1] = temp;
		}

	cout << "\n\nContents of array g (Smallest @ RIGHT) are : ";
	for (i = 0; i < sz; i++)
		cout << setw(4) << g[i];

	cout << endl;
	getch();

	return 0;
};

	// Chapter : Arrays
	// Example 4 : Sorting an Array

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int main()
{
	const int sz = 7;
	int a[sz] = {30, 93, 77, 24, 50, 28, 12};
	int i = 0, j = 0, temp = 0;

	system("cls");

	cout << "\n\nContents of array a (Original) are : ";
	for (i = 0; i < sz; i++)
		cout << setw(4) << a[i];

	cout << endl;
	getch();

	// Sort Array Ascending

	for (j = 0; j < sz - 1; j++)
	{
		for (i = 0; i < sz; i++)
		{
			if (a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
	}

	cout << "\n\nContents of array a (Ascending) are : ";
	for (i = 0; i < sz; i++)
		cout << setw(4) << a[i];

	cout << endl;
	getch();

	// Sort Array Descending

	for (j = 0; j < sz - 1; j++)
	{
		for (i = 0; i < sz; i++)
		{
			if (a[i] < a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
	}

	cout << "\n\nContents of array a (Descending) are : ";
	for (i = 0; i < sz; i++)
		cout << setw(4) << a[i];

	cout << endl;
	getch();

	return 0;
};

	// Chapter : Arrays
	// Example 5 (Without Functions) : Reversing an Array

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

const int sz = 11;
int i = 0, temp = 0;
int g[sz] = {30, 95, 23, 36, 77, 24, 50, 28, 12, 5, 19};

int main()
{
	system("cls");

	cout << "\n\nContents of array g (Original) are : ";
	for (i = 0; i < sz; i++)
		cout << setw(3) << g[i];
	cout << endl;
	getch();

	for (i = 0; i <= sz / 2; i++)
	{
		temp = g[i];
		g[i] = g[sz - i - 1];
		g[sz - 1 - i] = temp;
	}

	cout << "\n\nContents of array g (Reversed) are : ";
	for (i = 0; i < sz; i++)
		cout << setw(3) << g[i];
	cout << endl;
	getch();

	return 0;
};

	// Chapter : Arrays
	// Example 5 (Using Functions) : Reversing an Array

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

void print_array(int[], int);
void reverse_array(int array[], int arrsize);

int main()
{
	const int sz = 11;
	int g[sz] = {30, 95, 23, 36, 77, 24, 50, 28, 12, 5, 19};

	system("cls");

	cout << "\n\nContents of array g (Original) are : ";
	print_array(g, sz);
	cout << endl;
	getch();

	reverse_array(g, sz);
	cout << "\n\nContents of array g (Reversed) are : ";
	print_array(g, sz);
	cout << endl;
	getch();

	return 0;
};

void print_array(int array[], int arrsize)
{
	int *ptr = array;
	for (int i = 0; i < arrsize; i++)
		cout << setw(3) << *ptr++;
}

void reverse_array(int array[], int arrsize)
{
	int temp, j;
	j = arrsize - 1;
	for (int i = 0; i <= arrsize / 2; i++)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		j--;
	}
}

// Chapter : Arrays
// Example 6 : 	Illustration of Pointers

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int main()
{
	system("cls");

	int x = 5;
	int *xptr;

	xptr = &x;

	cout << "\n\nAddress of x = " << &x << endl;

	cout << "\n\nValue of xptr = " << xptr << endl;

	cout << "\n\nValue of x = " << x << endl;

	cout << "\n\nValue of *xptr = " << *xptr << endl;

	// Assigning a new value to x through pointer
	*xptr = 14;
	cout << "\n\nThe new value of x = " << x << endl;

	cout << endl;
	getch();

	return 0;
};

	// Chapter : Arrays
	// Example 7 : 	Pointer and string (array of char)

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int main()
{
	system("cls");

	char str[80] = "Long live Pakistan";

	char *ptr1;

	ptr1 = str;

	cout << "\n\n*ptr1 = " << *ptr1;			 // prints L (The First Character of string)
	cout << "\n\nstr[0] = " << str[0] << endl;	 // also prints L
	cout << "\n\n*(ptr1+10) = " << *(ptr1 + 10); // prints P
	cout << "\n\nstr[10] = " << str[10] << endl; // also prints P

	cout << "\n\n*(ptr1)+10 = " << *(ptr1) + 10; // prints a number

	cout << endl;

	getch();

	return 0;
};

	// Chapter : Arrays
	// Example 8 : 	Handling a string by Pointer

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int main()
{
	system("cls");

	char str[80] = "Long live Pakistan";

	char *ptr1;

	ptr1 = str;

	cout << "\n\nstr = " << str << endl
		 << endl;

	// print string by using the pointer ptr1 (traversing)

	cout << "\n\nstr by Traversing Pointer = ";

	for (int i = 0; *ptr1; i++)
		cout << *(ptr1++);

	cout << endl;

	getch();

	return 0;
};

	// Chapter : Arrays
	// Example 9 : 	Indexing a Pointer Like an Array

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int main()
{
	system("cls");

	char str[80] = "Long live Pakistan";

	char *ptr1;

	ptr1 = str;

	cout << "\n\nstr = " << str << endl
		 << endl;

	// print string by indexing the pointer ptr1
	cout << "\n\nstr by indexing the pointer ptr1 = ";

	for (int i = 0; ptr1[i]; i++)
		cout << ptr1[i];

	cout << endl;

	getch();

	return 0;
};

	// Chapter : Arrays
	// Example 10 :   Reversing a String using Pointers

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cstring>

using namespace std;

int main()
{
	system("cls");

	char str[80] = "naughty moodi";

	cout << "\n\nForward String = " << str << endl;

	char temp, *start, *end;

	int len = strlen(str);

	start = str;
	end = &str[len - 1];

	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}

	cout << "\n\nReversed String = " << str << endl;

	cout << endl;

	getch();

	return 0;
};

	// Chapter : Arrays
	// Example 11 : Indexing a Pointer Like an Array
	// Reverse a string in place using Pointers

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cstring>

using namespace std;

int main()
{
	system("cls");

	char str[80] = "naughty moodi";

	char temp, *start, *end;

	int len = strlen(str);

	start = str;
	end = &str[len - 1];

	cout << "\n\nForward String = " << str << endl;

	for (int i = 0; i < len / 2; i++)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}

	cout << "\n\nReversed String = " << str << endl;

	cout << endl;

	getch();

	return 0;
};
