

#include <iostream>
using namespace std;
const int Size = 5;
template<class t>
class Stack
{
	int top;
	t array[Size];
public:
	Stack() :top(-1) {}

	void Push(t item)                  //insert item
	{
		if (top == Size - 1)                                          //to check is full?   
			cout << "Error ! The stack is full" << endl;
		else
		{
			top++;
			array[top] = item;
		}
	}

	bool Isempty()
	{
		
		return top<0;
	}

	//function to only remove element
	void pop()
	{
		if (Isempty())                                                  // to check is empty?
			cout << "Error ! The stack is empty" << endl;
		else
		{
			top--;
		}
	} 
	//function to remove and return top
	// overload
	void pop(t& element)
	{
		if (Isempty())
			cout << "error ! The stack is empty" << endl;
		else
		{

			element = array[top];
			top--;
		}
	}

	void Gettop()
	{
		if (Isempty())
			cout << "error ! The stack is empty" << endl;
		else
		{
			cout << array[top] << endl;
		}
	}

	void Print()
	{
		for (int i = top; i >= 0; i--)                    //increment loop don’t show stack in right way
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
};
