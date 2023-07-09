
//implement double linked list by using to pointer head and tail
#include <iostream>
using namespace std;
template <class t>
class DoubleLinkedList
{
	struct Node
	{
		Node* prev;
		Node* next;
		t data;
	};
	Node* head, * tail;
	int counter;
public:
	DoubleLinkedList()
	{
		head = tail = NULL;
		counter = 0;
	}
	bool isEmpty()
	{
		return head == NULL;
	}
	void insertFirst(t item)
	{
		Node* element = new Node;
		element->data = item;
		element->prev = NULL;
		if (isEmpty())
		{
			head = tail = element;
			element->next = NULL;
		}
		else
		{
			head->prev = element;
			element->next = head;
			head = element;
		}
		counter++;
	}
	void insertLast(t item)
	{
		Node* element = new Node;
		element->data = item;
		element->prev = NULL;
		if (isEmpty())
		{
			head = tail = element;
			element->next = NULL;
		}
		else
		{
			element->prev = tail;
			tail->next = element;
			element->next = NULL;
			tail = element;
		}
		counter++;
	}

	void insertAt(int pos, t item)                   //insert in position
	{
		pos = pos - 1;                               //to make user start from 1 not 0
		if (pos<0 || pos>counter)
		{
			cout << "Out of the range" << endl;
			return;
		}
		
			if (pos == 0)
				insertFirst(item);
			else if (pos == counter)
				insertLast(item);
			else
			{
				Node* element = new Node;
				element->data = item;
				Node* current = head;
				for (int i = 0; i <= pos; i++)
				{
					current = current->next;
				}
				element->next = current->next;
				element->prev = current;
				current->next->prev = element;
				current->next = element;

				counter++;
			}
	}
	void removeFirst()
	{
		if (isEmpty())
		{
			cout << "The list is empty" << endl;
			return;
		}
		if (counter == 1) {
			delete head;
			head = tail = NULL;
		}
		else
		{
			Node* element = head;
			head = head->next;
			head->prev = NULL;
			delete element;
		}
		counter--;
	}
	void removeLast()
	{

		if (isEmpty())
		{
			cout << "The list is empty" << endl;
			return;
		}
		if (counter == 1) {
			delete head;
			head = tail = NULL;
		}
		else
		{
			Node* element = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete element;
		}
		counter--;
	}
	void removeAt(int pos)                                      //remove by index
	{
		pos--;
		if (pos<0 || pos>=counter)
		{
			cout << "Out of the range" << endl;
			return;
		}
		if (pos == 0)
			removeFirst();
		else if (pos == counter-1)
			removeLast();
		else
		{
			Node* current = head;
			for (int i = 0; i < pos; i++)
			{
				current = current->next;
			}
			current->prev->next = current->next;
			current->next->prev = current->prev;
			delete current;
			counter--;
		}

	}


	void print()
	{
		if (isEmpty())
		{
			cout << "the list is empty" << endl;
			return;
		}
		Node* element = head;
		while (element != NULL)
		{
			cout << element->data << " ";
			element = element->next;
		}

	}
	void reverse()
	{
		if (isEmpty())
		{
			cout << "the list is empty" << endl;
			return;
		}
		Node* element = tail;
		do
		{
			cout << element->data << " ";
			element = element->prev;
		} while (element!=NULL);
		cout << endl;
	}
};

