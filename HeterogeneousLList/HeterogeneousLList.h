#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Container.h"

template<typename T>
struct Element{
	Container<T>* con;
	Element<T>* next;
};

#ifndef _HETEROGENEOUSLLIST
#define _HETEROGENEOUSLLIST

template<class T>
class HeterogeneousLList{
	Element<T>* start;
	size_t size;

public:
	HeterogeneousLList();
	HeterogeneousLList(ifstream& file, int n);   // Functionality 1.
	~HeterogeneousLList();

	void pushContainer(Container<T>*);
	void removeContainer();
	bool isListEmpty();
	
	bool isInTheList(const T&);                 // Functionality 3.
	void loadBalancing(const T&);               // Functionality 4.
	void removeElement(bool(*f)(const T& x));   // Functionality 6.
	void sortList();                            // Functionality 7.
	void printList();                           // Functionality 8.
	void resultFile(ofstream& file);            // Functionality 9.
};

#endif //_HETEROGENEOUSLLIST

template <typename T>
HeterogeneousLList<T>::HeterogeneousLList()
{
	start = NULL;
	size = 0;
}

template <typename T>
HeterogeneousLList<T>::HeterogeneousLList(ifstream& file, int n)
{
	while (n)
	{
		string str;
		stringstream ss;
		getline(file, str);  
		ss << str;

		string type;
		ss >> type;   
		
		int number;

		if (type == "stack")
		{
			Stack<int>* myStack = new Stack<int>;
			while (ss >> number)
				myStack->add(number);
			pushContainer(myStack);
		}

		else if (type == "queue")
		{
			Queue<int>* myQueue = new Queue<int>;
			while (ss >> number)
				myQueue->add(number);
			pushContainer(myQueue);
		}

		else if (type == "list")
		{
			DoubleLList<int>* myDList = new DoubleLList<int>;
			while (ss >> number)
				myDList->add(number);
			pushContainer(myDList);
		}

		n--;
	}

	file.close();

}

template <typename T>
HeterogeneousLList<T>::~HeterogeneousLList()
{
	while (!isListEmpty())
	{
		removeContainer();
	}
}

template <typename T>
void HeterogeneousLList<T>::pushContainer(Container<T>* c)
{
	Element<T>* temp=new Element<T>;
	temp->con = c;
	temp->next = NULL;

	if (!start)
		start = temp;
	else
	{
		Element<T>* current = new Element<T>;
		current = start;
		while (current)
		{
			if (!current->next)
			{
				current->next = temp;
				break;
			}
			current = current->next;
		}
	}
	size++;
}

template <typename T>
void HeterogeneousLList<T>::removeContainer()
{
	if (!isListEmpty())
	{
		Element<T>* temp = start->next;
		delete start;
		start = temp;
		size--;
	}
}

template <typename T>
bool HeterogeneousLList<T>::isListEmpty()
{
	return start == NULL;
}

template <typename T>
bool HeterogeneousLList<T>::isInTheList(const T& x)
{
	Element<T>* current = new Element<T>;
	current = start;
	while (current)
	{
		if (current->con->member(x))
			return true;
		current = current->next;
	}
	
	return false;
}

template <typename T>
void HeterogeneousLList<T>::loadBalancing(const T& x)
{
	Element<T>* minSize = new Element<T>;
	minSize = start;

	Element<T>* current = new Element<T>;
	current = start;

	while (current)
	{
		if (minSize->con->getSize()  >  current->con->getSize())
			minSize = current;
		current = current->next;
	}

	minSize->con->add(x);
}

template <typename T>
bool isEven(const T& x)      // for example this condition
{
	return x % 2 == 0;
}

template <typename T>
void HeterogeneousLList<T>::removeElement(bool(*f)(const T& x))
{
	if (!isListEmpty())
	{
		Element<T>* current = new Element<T>;
		current = start;
		while (current)
		{
			if (current->con->getType() == "stack")
			{
				Stack<T>* helper = new Stack<T>;
				while (!current->con->isEmpty())
				{
					if (!f(current->con->getElement()))
						helper->add(current->con->getElement());
					current->con->remove();
				}
				while (!helper->isEmpty())
				{
					current->con->add(helper->getElement());
					helper->remove();
				}
			}
			else
			{
				Queue<T>* helper = new Queue<T>;
				while (!current->con->isEmpty())
				{
					if (!f(current->con->getElement()))
						helper->add(current->con->getElement());
					current->con->remove();
				}
				while (!helper->isEmpty())
				{
					current->con->add(helper->getElement());
					helper->remove();
				}
			}
			current = current->next;
		}
	}
}


template <typename T>
void HeterogeneousLList<T>::sortList()
{
	if (!isListEmpty())
	{
		Element<T>* current = new Element<T>;
		current = start;
		while (current)
		{
			current->con->sort();
			current = current->next;
		}
	}
}

template <typename T>
void HeterogeneousLList<T>::printList()
{
	if (!isListEmpty())
	{
		Element<T>* current = new Element<T>;
		current = start;
		int numberCont = 1;
		while (current)
		{
			cout << "Container number " << numberCont << ":" << endl;
			current->con->print();
			cout << endl;
			current = current->next;
			numberCont++;
		}
	}
}


template <typename T>
void HeterogeneousLList<T>::resultFile(ofstream& file)
{
	if (!isListEmpty())
	{
		Element<T>* current = new Element<T>;
		current = start;

		while (current)
		{
			file << current->con->getType() << " ";
			while (!current->con->isEmpty())
			{
				file << current->con->getElement() << " ";
				current->con->remove();
			}
			file << endl;
			current = current->next;
		}
		file.close();
	}
}
