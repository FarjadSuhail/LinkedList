#include<iostream>
using namespace std;

template <class T>
class node
{
public:
	T data;
	node* next;

};



template <class T>
class LLADT
{
	node <T>* first;

public:
	LLADT()
	{

		first = 0;
	}


	~LLADT()
	{
		node<T>* curr = first;

		while (curr != NULL)
		{
			first = first->next;
			delete curr;
			curr = first;
		}

	}

	void insert(T num) //insert the node at the end.
	{
		node<T>* temp = new node<T>;
		temp->data = num;
		temp->next = NULL;

		if (first == 0)
		{
			first = temp;
		}

		else
		{
			node<T>* curr = first;

			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = temp;
		}
	}

	void printForward()  //print forward
	{
		node<T>* curr = first;

		while (curr != NULL)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}

	}


	int count()  //return total entries
	{
		int Counter = 0;

		node<T>* curr = first;

		while (curr->next != NULL)
		{
			curr = curr->next;
			Counter++;
		}

		return Counter;
	}


	int valAtCenterNode() //val at center node
	{

		node<T>* curr = first;

		int size = count();

		size = size / 2;
		int i = 0;

		while (i < size)	//till node no reached 
		{
			curr = curr->next;
			i++;
		}

		return curr->data;
	}


	bool remove(T a)  //remove if present
	{
		node <T>* curr = first;
		node <T>* prev = 0;

		bool flag = false;

		while (curr != NULL)
		{
			if (curr->data == a)
			{
				flag = true;
				break;
			}
			prev = curr;
			curr = curr->next;
		}

		return flag;
	}

	int removefromPosition(int index) //returns 0 if index is out of bounds.
	{
		int size = count();
		int i = 0;

		node <T>* curr = first;
		node <T>* prev = 0;


		if (size >= 0 && index <= size)
		{
			while (i < index)
			{
				prev = curr;
				curr = curr->next;
				i++;
			}

			prev->next = curr->next;
			return curr->data;

		}
		else
		{
			cout << "Index Out Of Bounds!" << endl;
			return 0;

		}

	}

	void printBackward()
	{
		node <T>* curr = first;
		node <T>* prev = 0;
		node <T>* Next = 0;

		if (curr == NULL)
		{
			cout << "NULL";
		}

		while (curr != NULL)
		{
			Next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = Next;
		}
		first = prev;

		node <T>* temp = first;

		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

};


void main()
{


LLADT<int> L;
for (int i = 0; i < 10; i++)
	L.insert(i * 2);

cout << "Value at Center Node : " << L.valAtCenterNode();
cout << "\nRemoving: " << L.removefromPosition(6) << endl;
cout << "Value at Center Node : " << L.valAtCenterNode() << endl << endl;

if (L.remove(10))
	cout << "Removed" << endl << endl;
else
	cout << "No Removed" << endl << endl;

cout << "Nodes Printed in Reverse : ";
L.printBackward();

cout << endl << "--------------------------------------------------------------------";
cout << endl << endl;


system("pause");

}