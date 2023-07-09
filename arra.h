
//implemenrt array as an dynamic
#include <iostream>
using namespace std;
template <class t>
class arraylist
{
	t* element;                   
	int maxSize;                     // size the user enter
	int lenght;                     // number of element in array
public:
	arraylist(int size=10)
	{
		if (size <= 0)
		{
			cout << "this size is wrong" << endl<<" the program put an defult size =100"<<endl;
			maxSize = 100;
		}
		else
		{
			maxSize = size;
		}
		element = new t[size];
		lenght = 0;
	}
	bool isEmpty()
	{
		return lenght == 0;
	}

	bool isFull()
	{
		return lenght == maxSize;
	}
	int getlenght()                                 //return number of element in the array
	{
		return lenght;
	}

	void print()
	{
		for (int i =0 ; i < lenght; i++)
		{
			cout << element[i] << endl;
		}
	}
	void insertAt(int pos,t item)  
	{
		pos = pos - 1;                              // to make user start fron 1 not zero
		if (isFull())
		{
			cout << "array is full" << endl;
		}
		else if (pos<0 || pos>lenght)
			cout << "cant enter element in this place" << endl;
		else
		{
			for (int i = lenght; i > pos; i--)
			{
				element[i] = element[i-1];   
			}
			 element[pos]=  item;
			lenght++;
		}
	}

	void removeAt(int pos)                     //index as input
	{
		pos = pos - 1;
		if (isEmpty())
			cout << "The list is empty" << endl;
		else if (pos<0||pos > lenght)
			cout << "Therer is no element to remove" << endl;
		else
		{
			for (int i = pos; i < lenght-1; i++)
			{
					element [i] = element[i + 1];
			}
			lenght--;
		}
	}
	void remove(t item)                     
	{
		
		if (isEmpty())
			cout << "The list is empty" << endl;
		else
		{
			int x = search(item);
			if (x == -1)
				cout << "The element is not in the list" << endl;
			else
			    removeAt(x+1);
		}
	}

	int search(t item)
	{
		
			for (int i = 0; i < lenght; i++)
			{
				if (element[i] == item)
					return i;
			}
			return -1;
		
	}

	void insertAtEnd(t item)
	{
		if (isFull())
			cout << "The list is full" << endl;
		else
		    element[lenght++] = item;
	}
	void removeAtEnd()
	{
		if (isEmpty())
			cout << "The list is empty" << endl;
		else
			lenght--;
	}
	void insertNoDuplicate(t item)
	{
		
		if (isFull())
			cout << "The list is full" << endl;
		else
		{
			int isFound = search(item);
			if (isFound == -1)
				element[lenght++] = item;
			else
				cout << "the item is found in the list" << endl;
		}
	}

	void updateAt(int pos, t item)
	{
		if (isEmpty())
			cout << "the list is empty" << endl;
		else if (pos<0 || pos>lenght)
			cout << "Out of the range" << endl;
		else
			element[pos-1] = item;
	}

	t getElement(int pos)
	{
		pos = pos - 1;
		if(isEmpty())
			cout << "The list is empty" << endl;
		else if (pos<0 || pos>lenght)
			cout << "Out of the range" << endl;
		else
		{
			return element[pos];
		}
	}

	void clear()
	{
		lenght = 0;
	}

	~arraylist()
	{
		delete[]element;
	}
};

