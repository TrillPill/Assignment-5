//Michael Shearer//
// Did not have time to finish //

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//GLOBAL VARIABLES
const int READERROR = 100;
const int WRITEERROR = 200;
const int ARRAYSIZE = 100;


//NODE CLASS
class node
{
	int data; // this could be any type or object
	node *next;
public:
	node(int x);
	friend class MyList;
};

//NODE CONSTRUCTOR
node::node(int x)
{
	data = x;
	next = NULL;
}

//MYLIST CLASS
class MyList
{
	node *head;
	node *tail;
	int numRecords;
	int listSize;
public:
	MyList();
	void addNodeToEnd(node *nptr);
	void addNodeToHead(node *nptr);
	int insertAfter(node *ptr, int i);
	int removeNode(int i);
	void showList();
	node * findItem(int i);
	int ReadMyList(string filename);
};

//MYLIST CONSTRUCTOR
MyList::MyList()
{
	head = NULL;
	tail = NULL;
}

//NODE FUNCTIONS 

//ADDNODETOEND FUNCTION
void MyList::addNodeToEnd(node *ptr)
{
	// if list is empty
	if (head == NULL)
	{
		head = ptr;
		tail = ptr;
	}
	else
	{
		tail->next = ptr;
		tail = ptr;
	}
}

//ADDNODETOHEAD FUNCTION
void MyList::addNodeToHead(node *ptr)
{
	if (head == NULL)
	{
		head = ptr;
		tail = ptr;
	}
	else
	{
		ptr->next = head;
		head = ptr;
	}
}

//INSERTAFTER FUNCTION
int MyList::insertAfter(node *newnode, int i)
{
	node *ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == i) // we found the node to insert after
		{
			newnode->next = ptr->next;
			ptr->next = newnode;
			if (tail == ptr) // repoint tail if we added to end
				tail = newnode;
			return 0;
		}
		ptr = ptr->next;
	}
	return -1;
}

//REMOVENODE FUNCTION
int MyList::removeNode(int i)
{
	node *ptr = head;
	if (ptr == NULL)  // empty list
		return -1;

	// if node is at the head
	if (head->data == i)
	{
		//if only 1 node in the list
		if (head == tail)
		{
			head = NULL;
			tail = NULL;
		}
		else
			head = head->next;
		delete ptr;
		return 0;
	}

	while (ptr != NULL)
	{
		if (ptr->next && (ptr->next)->data == i)
		{
			if (tail == ptr->next)
				tail = ptr;
			node *tbd = ptr->next;
			ptr->next = (ptr->next)->next;
			delete tbd;
			return 0;
		}
		ptr = ptr->next;
	}
	return -1;
}

//SHOWLIST FUNCTION
void MyList::showList()
{
	node *ptr;
	ptr = head;
	cout << "****  List Contents *****" << endl;
	if (ptr == NULL)
	{
		cout << "list is empty " << endl;
		return;
	}
	cout << "(head is " << head->data << " tail is " << tail->data << ")" << endl;
	while (ptr != NULL)
	{
		cout << "data is " << ptr->data << endl;
		ptr = ptr->next;
	}
}

//FINDITEM FUNCTION
node * MyList::findItem(int i)
{
	node *ptr;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == i)
		{
			cout << "found it!" << endl;
			return ptr;
		}
		ptr = ptr->next;
	}

	cout << "Not found" << endl;
	return NULL;
}

int MyList :: ReadMyList(string filename) {
	string loc, dDate, depth, timeBelow;
	ifstream infile(filename, ios::in);
	if (!infile)
	{
		cout << "File could not be opened for reading" << endl;
		return READERROR;
	}


	while (!infile.eof())
	{
		getline(infile, loc, '|');
		if (!loc.empty())
		{
			getline(infile, dDate, '|');
			getline(infile, depth, '|');
			double dDepth = stod(depth);
			getline(infile, timeBelow);
			MyList[numRecords] = new MyPlaylist(loc, dDate, dDepth, timeBelow);
			numRecords++;
		}
	}

	infile.close();
	return 0;
}

//PLAY FUNCTION

//SKIP FUNCTION

//DELETE FUNCTION

//QUIT/WRITE FUNCTION

//MAIN FUNCTION
int main()
{
	MyList *MyPlaylist = new MyList();
	string filename, answer;
	cout << "What is the full path name of the file you would like to use?: " << endl;
	cin >> filename;
	int error;
	error = MyList.ReadMyList(filename);
	if (error)
	{
		cout << "Cannot read data - continue creating new list? Y/N -->";
		getline(cin, answer);
		if (answer != "Y" && answer != "y")
		{
			return 1;
		}
	}

	//OPEN FILE CHECK / TEST IF LIST IS EMPTY

	//READFILE

	

	//SAVE LIST TO LIST

	//DISPLAY LIST LOOP
		//PLAY SKIP OR DELETE

    return 0;
}

// Did not have time to finish //
