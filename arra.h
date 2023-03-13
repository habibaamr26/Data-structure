#include <iostream>
using namespace std;
template <class t>
class Array
{
	t* element;
	int size;        //to know size the user enter
	int lenght;      //to know the number of elenemt
public:
	Array(int arr_size)
	{
		element = new int[arr_size];
		size = arr_size;
		lenght = 0;
	}
	void Fill()
	{
		cout << "How many item you need to fill" << endl;
		int arr_size;
		cin >> arr_size;
		if (arr_size > size)
		{
			cout << "You cant exceed the array size" << endl;
			
		}
		else
		{
			for (int i = 0; i < arr_size; i++)
			{
				cout <<"Enter the item number " << i + 1 << " please" << endl;
				cin >> element[i];
				lenght++;
			}
		}

	}
	void Display()
	{
		cout << "Display array content" << endl;
		for (int i = 0; i < lenght; i++)
			cout << element[i] << "\t";
		cout << endl;
	}
	int getsize()
	{
		return size;
	}
	int getlenght()
	{
		return lenght;
	}
	int Search(t item)  //search by value
	{
		int index=-1;
		for (int i = 0; i < lenght; i++)
		{
			if (element[i] == item)
				index = i;
		}
		return index;
	}
	void Append(t newitem)
	{
		if (lenght >= size)
			cout << "You cant exceed the array size" << endl;
		else
		{
			element[lenght] = newitem;
			lenght++;
		}
	}
	void Insert(t newitem,int index)   //to add item at any place
	{
		if (index<0 && index >= size)
			cout << "Index out of range" << endl;
		else {
			for (int i = lenght; i > index; i--)
			{
				element[i] = element[i - 1];

			}
			element[index] = newitem;
			lenght++;
		}
	}
	void Delete(int index)
	{
		if (index<0 && index >= size)
			cout << "Index out of range" << endl;
		else {
			for (int i = index; i < lenght - 1; i++)
			{
				element[i] = element[i + 1];
			}
			lenght--;
		}
	}
	void Enlarge(int newsize)           //to increase size of array by make a new array by large size and copy item
	{
		if (newsize <= size)
		{
			cout << "New size must be larger" << endl;
			return;
		}

		else
		{
			t* old = element;
			element = new int[newsize];
			for (int i = 0; i < lenght; i++)
			{
				element[i]=old[i];
			}
			size = newsize;
			delete [] old;
		}
	}
	void Merge(Array other)
	{
		int newsize = size + other.getsize();
		size = newsize;
		t* old = element;
		element = new int[newsize];
		int i;
		for (i = 0; i < lenght; i++)
		{
			element[i] = old[i];
		}
		delete[]old;
		int j = i;
		for (i = 0; i < other.getlenght(); i++)
		{
			element[j++] = other.element[i];
			lenght++;
		}
	}
};
