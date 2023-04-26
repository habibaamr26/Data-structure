#include <iostream>
using namespace std;

  //Implement queue by liked list

struct Node
{
	int data;
	Node* next;
};

class Queue
{
	Node* front;             //delete
	Node* rear;             //insert
public:
	Queue()                          
	{
		front = rear =NULL;
	}

	Node* Creat()
	{
		Node* pointer = new Node;
		return pointer;
	}

	bool Is_empty()
	{ 
		if (front ==NULL)
			return 1;
		else return 0;
	}

	bool Is_full()
	{
		Node* pointer = Creat();
		if (pointer == NULL)
			return 1;
		else return 0;
	}

	
	void Enqueue(int item)                 //to insert new element
	{
		Node* newelement = Creat();
		newelement->data = item;
		newelement->next = NULL;
		if (Is_empty())
		{
			front = rear = newelement;
			
		}
		else
		{
			rear->next = newelement;
			rear = newelement;
		}

	}

	int Dequeue()                         //delet elemenet from front
	{
		int temp;
		Node* remove = Creat();
		remove = front;
		temp = remove->data;
		if (Is_empty())
			cout << "there is no element to remove" << endl;
		else if (front == rear)
		{
			front = rear = NULL;
		}
		else
		{
			front = front->next;
		}
		delete(remove);
		return temp;
	}

	int GetFront()                // to get front element
	{
		return front->data;
	}

	int GetRear()                // to get rear element
	{
		return rear->data;
	}

	void Display()
	{
		if (front == NULL)
			cout << "there is no item to display" << endl;
		else
		{
			Node* access = Creat();
			access = front;
			while (access != NULL)
			{
				cout << access->data << " ";
				access = access->next;
			}
			cout << endl;
		}
	}

	int Count()                            //to count number of element 
	{
		int counter = 0;
		Node* access = Creat();
		access = front;
		while (access != NULL)
		{
			counter++;
			access = access->next;
		}
		return counter;
	}

	bool Is_found(int item)
	{
		bool p = 0;
		Node* access = Creat();
		access = front;
		while (access != NULL)
		{
			if (access->data == item)
				p = 1;
			access = access->next;
		}
		return p;
	}

	void Clear()                // to delete all elemennt from the queue
	{
		while (!Is_empty())
			Dequeue();
	}
};

