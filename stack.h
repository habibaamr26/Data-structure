#include <iostream>
using namespace std;
struct  node
{
	int data;
	node* next;
};

class Stack
{
	node* top;

public:
	Stack()
	{
		top = NULL;
	}
	node* Creat()
	{
		node* pointer = new node;
		return pointer;
	}
	bool Is_empty()
	{
		return(top == NULL);
	}
	void Push(int element)                    // to insert new element into the stack
	{
		node* newelemwnt = Creat();
		newelemwnt->data = element;
		if (Is_empty())
		{
			top = newelemwnt;
			newelemwnt->next = NULL;
		}
		else
		{
			newelemwnt->next = top;
			top = newelemwnt;
		}
	}

	void Display()
	{
		node* access = Creat();
		access = top;
		while (access != NULL)
		{
			cout << access->data<<" ";
			access = access->next;
		}
	}

	int Pop()                             //to delete top element in the stack 
	{
		int temp=0;
		if (Is_empty())
		{
			cout << "The list is empty" << endl;
		
		}
		else
		{
			
			node* to_remove = Creat();
			to_remove = top;
			temp = to_remove->data;
			top = to_remove->next;
			delete(to_remove);
		
		}
		return temp;
	}


	int Peek()                           // to display the last element enter in the stack 
	{
		int temp=0;
		if (Is_empty())
			cout << "there is no element in the stack" << endl;
		else
		{
			node* display = Creat();
			display = top;
			temp = display->data;
		
		}
		return temp;
	}

	int Count()                           //count number of element
	{
		int counter = 0;
		node* access = Creat();
		access = top;
		while (access != NULL)
		{
			counter++;
			access = access->next;
		}
		return counter;
	}

	bool Search(int item)                    //search a spacific item
	{
		node* access = Creat();
		access = top;
		bool found = 0;
		while (access!=NULL)
		{
			if (access->data == item)
				found = 1;
			access = access->next;
		}
		return found;
	}

	void Is_full()            //to check memory
	{
		node* pointer = Creat();
		if (pointer == NULL)
			cout << "the memory is full can’t creat another element" << endl;
	}
};