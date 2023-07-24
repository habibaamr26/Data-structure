

#include <iostream>
using namespace std;
template<class t>
class BST
{
	struct Node
	{
		t data;
		Node* left, * right;
		Node(t item)
		{
			data = item;
			left = right = NULL;
		}
	};
	Node* insert(Node* totrace, t item)
	{
		Node* toinsert = new Node(item);
		if (totrace == NULL)                                                              //base case
		{
			totrace = toinsert;
			return totrace;
		}
		else if (totrace->data > item)                                  //root bigger than so go left
			totrace->left = insert(totrace->left, item);

		else                                                   //root smaller than go right
			totrace->right = insert(totrace->right, item);



		return totrace;
	}
	bool search(Node* tofind, t item)
	{
		if (tofind == NULL)                                       //base case
		{
			return 0;
		}
		else if (tofind->data == item)
			return 1;
		else if (tofind->data > item)
		{
			search(tofind->left, item);
		}
		else
			search(tofind->right, item);
	}

	Node* getMinmum(Node* tofined)                                  // to find min
	{
		if (tofined == NULL)
			return tofined;
		while (tofined->left != NULL)
		{
			tofined = tofined->left;
		}
		return tofined;
	}

	Node* getMaxmum(Node* tofined)
	{

		if (tofined == NULL)
			return NULL;
		while (tofined->right != NULL)
		{
			tofined = tofined->right;
		}
		return tofined;
	}

	Node* remove(Node* todelete, t item)
	{
		if (todelete == NULL)
			return todelete;
		else if (item < todelete->data)
			todelete->left = remove(todelete->left, item);

		else if (item > todelete->data)
			todelete->right = remove(todelete->right, item);
		else
		{
			//no child  (leave node)
			if (todelete->left == NULL && todelete->right == NULL)
			{
				delete todelete;
				todelete = NULL;
			}
			//one child at left
			else if (todelete->left != NULL)
			{
				Node* temp = todelete;
				todelete = temp->left;
				delete temp;

			}
			//one child at right
			else if (todelete->right != NULL)
			{
				Node* temp = todelete;
				todelete = temp->right;
				delete temp;
			}
			//2 child
			else
			{
				Node* maxvalue = getMaxmum(todelete->left);
				todelete->data = maxvalue->data;
				todelete->left = remove(todelete->left, maxvalue->data);

			}

		}
		return todelete;
	}

public:
	Node* root;                                     //must be public to send to print functions
	BST()
	{
		root = NULL;
	}
	void insert(t item)                                              //make another function private to make esiar on user
	{
		root=insert(root, item);                                    //send root bec. every time you insert on the same tree
	}
	bool search(t item)
	{
		return search(root, item);
	}
	t getMinmum()
	{
		Node* temp = getMinmum(root);
		return temp->data;
	}

	t getMaxmum()
	{
		Node* temp = getMaxmum(root);
		return temp->data;
	}

	void remove(t item)                                  
	{
		root = remove(root, item);
	}


	void preorder(Node* toprint)                                     //print root _ left _ right
	{
		if (toprint == NULL)
			return;
		
			cout << toprint->data << " ";
			preorder(toprint->left);
			preorder(toprint->right);
	}
	void ineorder(Node* toprint)                                     //print left _ root _right
	{
		if (toprint == NULL)
			return;
		
			ineorder(toprint->left);
			cout << toprint->data << " ";
			ineorder(toprint->right);
		
	}
	void posteorder(Node* toprint)                                 //print left _ right _ root
	{
		if (toprint == NULL)
			return;
		
			posteorder(toprint->left);
			posteorder(toprint->right);
			cout << toprint->data << " ";
		
	}
};