
#include <iostream>
#include <cassert>
using namespace std;
//implement circular queue by dynamic array
template <class t>
class CircularQueue
{
	int front, rear;
	int counter;                           //count element in queue
	t* array;
	int maxSize;
public:
	CircularQueue(int size)
	{
		if (size <= 0)
			maxSize = 100;
		else
			maxSize = size;
		array = new int[maxSize];
		front = 0;
		rear = maxSize - 1;
		counter = 0;
	}

	bool isEmpty()
	{
		return counter == 0;
	}
	bool isFull()
	{
		return counter == maxSize;
	}

	void enqueue(t item)
	{
		if (isFull())
			cout << "queue is full" << endl;
		else
		{
			rear = (rear + 1) % maxSize;
			array[rear] = item;
			counter++;
		}
	}
	
	void dequeue()
	{
		if (isEmpty())
			cout << "queue is empty " << endl;
		else
		{
			front = (front + 1) % maxSize;
			--counter;
		}
		
	}
	void dequeue(t &item)
	{
		if (isEmpty())
			cout << "queue is empty " << endl;
		else
		{
			item = array[front];
			front = (front + 1) % maxSize;
			counter--;
		}

	}

	t getfront()
	{
		assert(!isEmpty());
			return array[front];
	}
	/*void getfront(t &item)                            use call by refrence
	{
		if (isEmpty())                   
			cout << "queue is empty" << endl;
		else
			item = array[front];
	}*/

	t getrear()
	{
		assert(!isEmpty());
			return array[rear];
	}

	/*void getrear(t &item)                            use call by refrence
	{
		if (isEmpty())
			cout << "queue is empty" << endl;
		else
			item = array[rear];
	}*/

 
	void display()
	{
		if (isEmpty())
			cout << "Empty Queue " << endl;
		else
		{
			for (int i = front; i !=rear; i = (i + 1) % maxSize)                 //print all element except last element
			{
				cout << array[i] << " ";
			}
			cout << array[rear];                                                 // print rear
			cout << endl;
		}
	}

	int search(t item)                                         // return index of item
	{
		int pos = -1;
		if (isEmpty())
		{
			cout << "queue is empty" << endl;
		}
		else
		{
			for (int i = front; i != rear; i = (i + 1) % maxSize)     //check on all element except rear
			{
				if (array[i] == item)
				{
					pos = i;
					break;
				}
			}
			if (pos==-1)                                    // to check on rear
			{
				if (array[rear] == item)
					pos = rear;
			}
		}
		if (pos != -1)
			return pos + 1;
		else
		{
			cout << "can’t find item " ;
			return -1;
		}
	}
};

















