


#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
class Linked_List
{
	node* head;

public:
	Linked_List()
	{
		head = NULL;
	}
	node* Creat()
	{
		node* pointer = new node;
		return pointer;
	}
	bool Is_empty()
	{
		if (head == NULL)
			return 1;
		else
			return 0;

		//return (head==NULL);
	}


	void Display()
	{
		//by traverse
		node* dis = Creat();
		dis = head;
		while (dis != NULL)
		{
			cout << dis->data <<" ";
			dis = dis->next;
		}
	}

	int Count()
	{
		int counter = 0;                             //to count how many element in liked list
		//by traverse
		node* dis = Creat();
		dis = head;
		while (dis != NULL)
		{
			counter++;
			dis = dis->next;
		}
		return counter;
	}

	bool Is_found(int x)
	{
		node* dis = Creat();
		dis = head;
		while (dis != NULL)
		{
			if (dis->data == x)
				return 1;
			dis = dis->next;
		}
		return 0;
	}
	// 3 function to insert
	void Insert_First(int data);
	void  Insert_Before(int item, int data);
	void Append(int data);                                   //to inert last

	//3 function to delet

	void DeleteFirst();
	void DeleteLast();
	void DeleteItem(int item);

	//one function to delete  instead of 3 function bu knowing the element

	void Delete(int item);

};
void Linked_List::Insert_First(int data)
{
	node* NewNode = Creat();
	NewNode->data = data;
	if (Is_empty())
	{
		head = NewNode;
		NewNode->next = NULL;
	}
	else
	{
		NewNode->next = head;
		head = NewNode;
	}
}

void Linked_List::Insert_Before(int item, int data)
{
	if (Is_empty())
	{
		Insert_First(data);
	}
    if (Is_found(item))
	{
		node* New = Creat();
		New->data = data;
		node* found = Creat();
		found = head;
		while (found->next->data != item && found != NULL) {
			found = found->next;
		}
		New->next = found->next;
		found->next = New;
	}
	else
		cout << "Sorry item is not found" << endl;
}

void Linked_List::Append(int data)
{
	if (Is_empty())
		Insert_First(data);
	else
	{
		node* newelement = Creat();
		newelement->data = data;
		newelement->next = NULL;
		node* traverse = Creat();
		traverse = head;
		while (traverse->next != NULL)
		{
			traverse = traverse->next;
		}
		traverse->next = newelement;
	}
}


void Linked_List::DeleteFirst()
{
	node* check = Creat();
	check = head;
	if (Is_empty())
		cout << "Sorry it’s no item to delete list id empty" << endl;
	if (check->next == NULL)
		head = NULL;
	
	else
	  head = check->next;

	delete(check);
}

void Linked_List::DeleteLast()
{
	if (Is_empty())
		cout << "there is no element" << endl;
	if (head->next == NULL)
		DeleteFirst();
	else
	{
		node* remove = Creat();    // hold node you want to remove
		node* check = Creat();             //hold the previous node
		check = remove = head;
		while (remove->next != NULL)
		{
			check = remove;
			remove = remove->next;

		}
		check->next = NULL;
		delete(remove);
	}
}


void Linked_List::DeleteItem(int item)
{
	node* pointer = Creat();
	if (pointer->next == NULL)
		DeleteFirst();
	else
	{
		node* remove = Creat();    // hold node you want to remove
		node* check = Creat();             //hold the previous node
		check = remove = head;
		while (remove->data != item)
		{
			check = remove;
			remove = remove->next;

		}
		check->next = remove->next;
		delete(remove);
	}


}


void Linked_List::Delete(int item)
{
	if (Is_empty())
		cout << "there is no element to delete" << endl;

	if (head->data == item)
	{
		node* check = Creat();
		check = head;
		head = head->next;
		delete(check);
	}
	else
	{
		node* remove = Creat();    // hold node you want to remove
		node* check = Creat();             //hold the previous node
		check = head;
	  remove = head;
		while (remove->data != item)
		{
			check = remove;
			remove = remove->next;

		}
		check->next = remove->next;
		delete(remove);

	}
}
