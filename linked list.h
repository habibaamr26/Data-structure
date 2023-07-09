
// implement linked list by one pointer
#include <iostream>
#include <assert.h>
using namespace std;
template <class t>
class LinkedList
{
	struct Node
	{
		t data;
		Node* next;
	};
	Node* head;
	int length;
public:
	LinkedList()
	{
		head = NULL;
		length = 0;
	}
	bool isEmpty()
	{
		return head == NULL;
	}

	void insertFirst(t item)
	{
		Node* element = new Node;
		element->data = item;
		if (isEmpty())
		{
			head = element;
			element->next = NULL;
		}
		else
		{
			element->next = head;
			head = element;
		}
		length++;
	}
	void insertLast(t item)
	{
		Node* element = new Node;
		Node* toCheck = new Node;
		toCheck = head;
		element->data = item;
		element->next = NULL;
		if (isEmpty())
		{
			insertFirst(item);
		}
		else
		{
			while (toCheck->next != NULL)
			{
				toCheck = toCheck->next;
			}
			toCheck->next = element;
			length++;
		}
		
	}

	void insertAt(int pos, t item)
	{
		pos = pos - 1;
		if (pos<0 || pos>length)
			cout << "Out of the range" << endl;
		else
		{
			if (pos == 0)
				insertFirst(item);
			else if (pos == length)
				insertLast(item);
			else
			{
				Node* element = new Node;
				Node* toCheck = new Node;
				toCheck = head;
				element->data = item;
				for (int i = 1; i < pos; i++)
				{
					toCheck = toCheck->next;
				}
				element->next = toCheck->next;
				toCheck->next = element;
				length++;
			}
		}
	}
	void print()
	{
		Node* element = new Node;
		element = head;
		while(element!=NULL)
		{
			cout << element->data << " ";
			element = element->next;
		}
	}


	void removeFirst()
	{
		Node* toRemove = head;
		if (isEmpty())
			cout << "The list is empty" << endl;
		else if (length == 1)
		{
			head->next = NULL;
			length--;
		}
		else
		{
			head = head->next;
			length--;
		}
		delete toRemove;
	}

	void removeLast()
	{
		
		if (isEmpty())
		{
			cout << "The list is empty" << endl;
		}
		else if (length == 1)
		{
			length--;
			delete head;
		}
		else
		{
			Node* toDelete = head->next;
			Node* toCheck = head;
			while (toDelete->next!= NULL)
			{
				toCheck = toDelete;
				toDelete = toDelete->next;
			}
			toCheck->next = NULL;
			delete toDelete;
			length--;
		}
	}
	int search(t item)
	{
		Node* pointer = head;
		int counter = 0;
		while (pointer != NULL)
		{
			if (pointer->data == item)
				return counter;
			counter++;
			pointer = pointer->next;

		}
		return -1;
	}

	void removeByIndex(int pos)             //remove by index;
	{
		if (isEmpty())
		{
			cout << "The list is empty" << endl;
		}
		else
		{
			pos = pos - 1;
			if (pos<0 || pos>length)
				cout << "Out of the range" << endl;
			else
			{
				if (pos == 0)
					removeFirst();
				else if (pos == length)
					removeLast();
				else
				{
					Node* toRemove = head->next;
					Node* toHold = head;
					for (int i = 1; i < pos; i++)
					{
						toHold = toRemove;
						toRemove = toRemove->next;
					}
					toHold->next = toRemove->next;
					delete toRemove;
					length--;
				}
			}
		}
	}
	

	void removeByElement(t item)                     //remove by item
	{
		if (isEmpty())
			cout << "The list is empty" << endl;
		else
		{
			int pos = search(item);
			if (pos == -1)
				cout << "the element not found" << endl;
			else
			{

				if (pos == 0)
					removeFirst();
				else if (pos == length)
					removeLast();
				else
				{
					Node* toRemove = head->next;
					Node* toHold = head;
					for (int i = 1; i < pos; i++)
					{
						toHold = toRemove;
						toRemove = toRemove->next;
					}
					toHold->next = toRemove->next;
					delete toRemove;
					length--;
				}
			}
		}
	}

	//instead of this 2 function you can make 2 in one
	void remove()
	{
		if (isEmpty())
			cout << "The list is empty" << endl;
		else
		{
			int pos;
			int check;
			cout << "If you want to remove at position enter one \nIf you want to remove a spicefic element you don’ know it’s position enter 2" << endl;
			cin >> check;
			if (check == 1)
			{

				cout << "enter pos" << endl;
				cin >> pos;
				pos--;
			}
			else if (check == 2)
			{
				t item;
				cout << "enter item pleas" << endl;
				cin >> item;
				pos = search(item);
			}
			else
			{
				assert(check == 1 || check == 2);

			}
			// start to check on position
			if (pos<0 || pos>length)
				cout << "Out of the range" << endl;
			else
			{
				if (pos == 0)
					removeFirst();
				else if (pos == length)
					removeLast();
				else
				{
					Node* toRemove = head->next;
					Node* toHold = head;
					for (int i = 1; i < pos; i++)
					{
						toHold = toRemove;
						toRemove = toRemove->next;
					}
					toHold->next = toRemove->next;
					delete toRemove;
					length--;
				}
			}
		}


	}
	
	bool isFound(t item)
	{
		int isfound = search(item);
		if (isfound != -1)
			return 1;
		else
			return 0;
	}

	void reverse()
	{
		Node* next = head->next;
		Node* current = head;
		Node* prev = NULL;
		while (next != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}
	void clear()
	{
		Node* current;
		while (head != NULL)
		{
			current = head;
			head = head->next;
			delete current;
		}
		length = 0;
	}
	~LinkedList()
	{
		clear();
	}
	int getLenght()
	{
		return length;
	}
};

