#include "Container.h"
#include <iostream>
using namespace std;

template<typename T>
struct Elem{
	T data;
	Elem<T>* prev;
	Elem<T>* next;
};

#ifndef _DOUBLELLIST
#define _DOUBLELLIST

template <typename T>
class DoubleLList : public Container<T>
{
	Elem<T>* start;
	Elem<T>* end;
	size_t size;

	void copyDoubleLList(const DoubleLList<T>&);
	void deleteDoubleLList();

public:
	DoubleLList();
	~DoubleLList();
	DoubleLList(const DoubleLList&);
	DoubleLList& operator=(const DoubleLList&);

	bool isEmpty();
	void print();
	void sort();

	void addToFront(const T&);
	void remove();
	void add(const T&);        //add to the back
	void removeFromBack();	   //remove from the back
	
	size_t getSize();
	string getType();
	T& getElement();

	bool member(T const&);
	bool usingCondition(bool(*f)(const T& x));
};

#endif //_DOUBLELLIST


template <typename T>
DoubleLList<T>::DoubleLList()
{
	start = end = NULL;
	size = 0;
}

template <typename T>
DoubleLList<T>::DoubleLList(const DoubleLList& other)
{
	copyDoubleLList(other);
}

template <typename T>
DoubleLList<T>&	DoubleLList<T>::operator=(const DoubleLList& other)
{
	if (this != other)
	{
		deleteDoubleLList();
		copyDoubleLList(other);
	}
	return *this;
}

template <typename T>
DoubleLList<T>::~DoubleLList()
{
	deleteDoubleLList();
}

template <typename T>
void DoubleLList<T>::addToFront(const T& elem)
{
	Elem<T>* temp = new Elem<T>;
	temp->data = elem;
	if (isEmpty())
	{
		start = end = temp;
		temp->prev = temp->next = NULL;
	}
	else
	{
		temp->prev = NULL;
		temp->next = start;
		start = temp;
	}
	size++;
}

template <typename T>
void DoubleLList<T>::add(const T& elem)  // add to the back
{
	Elem<T>* temp = new Elem<T>;
	temp->data = elem;
	if (isEmpty())
	{
		start = end = temp;
		temp->prev = temp->next = NULL;
	}
	else
	{
		end->next = temp;
		temp->prev = end;
		temp->next = NULL;
		end = temp;
	}
	size++;
}

template <typename T>
void DoubleLList<T>::remove()
{
	if (!isEmpty())
	{
		if (getSize() == 1)
		{
			delete start;
			start = NULL;
		}
		else
		{
			Elem<T>* temp = start;
			start = temp->next;
			delete temp;
			start->prev = NULL;
		}
		size--;
	}
}

template <typename T>
void DoubleLList<T>::removeFromBack()   //remove from the back
{
	if (!isEmpty())
	{
		Elem<T>* temp = end;
		end = temp->prev;
		delete temp;
		end->next = NULL;
		size--;
	}
}


template<typename T>
size_t DoubleLList<T>::getSize()
{
	return size;
}

template<typename T>
string DoubleLList<T>::getType()
{
	return "list";
}

template<typename T>
T& DoubleLList<T>::getElement()
{
	return start->data;
}



template <typename T>
bool DoubleLList<T>::isEmpty()
{
	return start == NULL;
}

template <typename T>
void DoubleLList<T>::print()
{
	if (isEmpty())
		cout << "Empty list" << endl;
	else
	{
		cout << "Start of list: ";
		Elem<T>* temp = start;
		while (temp)
		{
			cout << temp->data << " ->";
			temp = temp->next;
		}
		cout << " End of list" << endl;
	}
}

template <typename T>
bool DoubleLList<T>::member(const T&x)
{
	Elem<T>* temp = new Elem<T>;
	temp=start;
	while (temp)
	{
		if (temp->data == x)
			return true;
		temp = temp->next;
	}
	return false;
}

template <typename T>
bool DoubleLList<T>::usingCondition(bool(*f)(const T& x))
{
	if (isEmpty())
		return false;
	else
	{
		Elem<T>* temp = new Elem<T>;
		temp = start;
		while (temp)
		{
			if (f(temp->data))
				return true;
			temp = temp->next;
		}
		return false;
	}
}

template <typename T>
void DoubleLList<T>::sort()
{
	if (!isEmpty())
	{
		int counter = size;

		while (counter)
		{
			bool flagIsSorted = false;
			Elem<T> *current = start;
			Elem<T> *previous = current->next;
			while (previous != NULL)
			{
				if (current->data > previous->data)
				{
					swap(current->data, previous->data);
					flagIsSorted = true;
				}
				current = current->next;
				previous = previous->next;
			}
			counter--;

			if (!flagIsSorted)  // if the flag is still false then not a single swap was made 
				break;          // which means that the list is already sorted and the loop can be exited
		}
	}
}

template <typename T>
void DoubleLList<T>::copyDoubleLList(const DoubleLList& other)
{
	Elem<T>* temp = other.start;
	while (temp)
	{
		add(temp->data);
		temp = temp->next;
	}
}

template <typename T>
void DoubleLList<T>::deleteDoubleLList()
{
	while (end != NULL)
		remove();
}
