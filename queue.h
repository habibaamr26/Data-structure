
//Implement queue using array
#include <iostream>
using namespace std;
const int Size = 5;
template <class t>
class Queue
{
	t array[Size];
	int rear, front;                 
public:
      Queue():rear(-1),front(-1){}

	  bool isEmpty()
	  {
		  return rear == -1;
	  }

	  bool isFull()
	  {
		  return rear == Size-1;
	  }

	  void enqueu(t item)                         //to add a new element
	  {
		  if (isEmpty())
		      front++; 
		  
		  else if (isFull())
		  {
			  cout << "Queue is full" << endl;
			   return ;
		  }
	     rear++;
	     array[rear] = item;
	  }

	  void dequeue()                                    // to delete an element
	  {
		  if (isEmpty())
		  {
			  cout << "Queue is empty" << endl;
			  return;
		  }
		  else
		  {
			  front++;
		  }
	  }

	  t getFront()
	  {
		  return array[front];
	  }

	  t getRear()
	  {
		  return array[rear];
	  }

	  void display()
	  {
		  for (int i = front; i <= rear; i++)
		  {
			  cout << array[i] << " ";
		  }
		  cout << endl;
	  }
};
