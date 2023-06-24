
#include <iostream>
#include <assert.h>
using namespace std;

template<class t>
class LinkedQueue
{
	struct Node
	{
		t data;
		Node *next;
	};

	Node* front, * rear;
	int counter;                       //to count number of element in queue
public:
	LinkedQueue()
	{
		front = NULL;
		rear = NULL;
		counter = 0;
	}

	bool isEmpty()
	{
		return counter==0;
	}

	void enqueue(t item)
	{
		Node* pointer = new Node;
		pointer->data = item;
		pointer->next = NULL;
		if (isEmpty())
		{
			front = rear = pointer;
		}
		else
		{
			rear->next = pointer;
			rear = pointer;
		}
		counter++;
	}

	void dequeue()
	{
		Node* pointer = front;
		if (isEmpty())
			cout << "the queue is empty" << endl;
		else if (counter == 1)
		{
			front = rear = NULL;
		}
		else
		{
			front = front->next;
		}
		delete pointer ;
		counter--;

	}

	void dequeue(t &item)                           //to return element before erase it
	{
		Node* pointer = front;
		item = front->data;
		if (isEmpty())
			cout << "the queue is empty" << endl;
		else if (counter == 1)
		{
			front = rear = NULL;
		}
		else
		{
			front = front->next;
		}
		delete pointer;
		counter--;

	}

	t getfront()
	{
		assert(!isEmpty());
			return front->data;
	}
	t getrear()
	{
		assert(!isEmpty());
			return rear->data;
	}

	void clear()                        // to delete all element
	{
		while (!isEmpty())              //front !=NULL
			dequeue();
	}

	void display()
	{
		if (isEmpty())
			cout << "Queue is empty " << endl;
		else
		{
			Node* pointer = front;
			while (pointer != NULL)
			{
				cout << pointer->data << " ";
				pointer = pointer->next;
				
			}
			
			cout << endl;
		}
	}

	int getSize()                             //return number of element in linked list
	{
		return counter;
	}



	bool search(int item)                             //search if this item found or not
	{
		bool p = 0;
		Node* access = front;
		while (access != NULL)
		{
			if (access->data == item)
				p = 1;
			access = access->next;
		}
		return p;
	}



};














