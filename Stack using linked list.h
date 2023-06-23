


// Stack with linked list
#include <iostream>
using namespace std;

template <class t>
class Stack
{
	struct node
	{
		t data;
		node* next;
	};
	node * top;

public:
	Stack():top(NULL){}
	bool Isempty()
	{
		return top == NULL;
	}
	
	void push(t item)
	{
		node* pointer = new node;
		if (pointer == NULL)                                           //to check memory is full 
			cout << "Can’t place a new item in the stack" << endl;
		else
		{
			pointer->data = item;
			if (Isempty())
			{
				pointer->next = NULL;
				top = pointer;
			}

			else
			{
				pointer->next = top;
				top = pointer;
			}

			
		}
	}
	void pop()
	{
		if (Isempty())
			cout << "There is an empty stack "<<endl ;
		else
		{
			node* toRemove = top;
			top = toRemove->next;
			delete toRemove;
		}
	}
	void pop(t& item)
	{
		if (Isempty())
			cout << "There is an empty stack " << endl;
		else
		{
			node* toRemove = top;
			top = toRemove->next;
			item = toRemove->data;
			delete toRemove;
		}
	}
	void getTop(t& item)                                               //to get last element enter
	{
		if (Isempty())
			cout << "There is an empty stack " << endl;
		else
			item = top->data;
		
	}
	void display()
	{
		if (Isempty())
			cout << "There is an empty stack " << endl;
		else
		{
			cout << "The item in stack" << endl;
			node* toDisplay = top;
			while (toDisplay != NULL)
			{
				cout << toDisplay->data << endl;
				toDisplay =toDisplay->next;
			}
		}
	}

	int Count()                           //count number of element
	{
		int counter=0;
		node* access = top;
		while(access!= NULL)
		{
			counter++;
			access = access->next;
		}
		return counter;
	}

	bool Search(t item)                    //search a spacific item
	{
		node* access = top;
		bool found = 0;
		while (access != NULL)
		{
			if (access->data == item)
				found = 1;
			access = access->next;
		}
		return found;
	}

};