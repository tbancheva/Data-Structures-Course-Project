#include "Container.h"
#include <iostream>
using namespace std;

template <typename T>
struct Node{
	T data;
	Node<T> *next;
};

#ifndef _STACK
#define _STACK

template <typename T>
class Stack : public Container<T>
{
	Node<T>* top; 
	size_t size;

	void copyStack(Stack<T>&);
	void deleteStack();

public:
	Stack();   
	~Stack();
	Stack(Stack&);
	Stack& operator=(Stack&);
	 
	void add(const T&);  //push
	void remove();       //pop    
	T& getElement();     //top

	size_t getSize();
	string getType();
		
	bool isEmpty();
	void print(); 
		
	bool member(T const&);
	bool usingCondition(bool(*f)(const T& x));
	void sort();
};

#endif //_STACK


template <typename T>
Stack<T>::Stack()
{
	top = NULL;
	size = 0;
}


template <typename T>
Stack<T>::Stack(Stack<T>& other)
{
	copyStack(other);
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack& other)
{
	if (this != other)
	{
		deleteStack();
		copyStack(other);
	}
	return *this;
}

template <typename T>
Stack<T>::~Stack()
{
	deleteStack();
}

template <typename T>
void Stack<T>::add(const T& _data) //push
{
	Node<T> *temp = new Node<T>;
	temp->data = _data;
	temp->next = top;   
	top = temp;  
	size++;
}

template <typename T>
void Stack<T>::remove()  //pop
{
	if (!isEmpty())
	{
		Node<T>* temp = top;
		top = temp->next;
		delete temp;
		size--;
	}
}


template <typename T>
T& Stack<T>::getElement()  //top
{
	return top->data;
}

template <typename T>
bool Stack<T>::isEmpty()
{
	return top == NULL;
}

template<typename T>
size_t Stack<T>::getSize()
{
	return size;
}

template<typename T>
string Stack<T>::getType()
{
	return "stack";
}

template <typename T>
void Stack<T>::print()
{
	if (isEmpty())
		cout << "Empty stack" << endl;
	else
	{
		cout << "Top of stack: ";

		Node<T> *current = top;
		while (current != NULL)
		{
			cout << current->data << " -> ";
			current = current->next;
		}
		cout << "End of stack" << endl;
	}
}

template <typename T>
bool Stack<T>::member(const T& x)
{
	Node<T>* temp = new Node<T>;
	temp = top;
	while (temp)
	{
		if (temp->data == x)
			return true;
		temp = temp->next;
	}
	return false;
}

template <typename T>
bool Stack<T>::usingCondition(bool(*f)(const T& x))
{
	if (isEmpty())
		return false;
	else
	{
		Node<T>* temp = new Node<T>;
		temp = top;
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
void Stack<T>::sort()
{
	if (!isEmpty())
	{
		int counter = size;
		
		while (counter)
		{
			bool flagIsSorted = false;
			Node<T> *current = top;
			Node<T> *previous = current->next;
			while (previous != NULL)
			{
				if (current->data > previous->data)
				{
					/*T temp = current->data;      //swaping the elements without the function swap
					current->data = previous->data;
					previous->data = temp;*/
					swap(current->data, previous->data);
					flagIsSorted = true;
				}
				current = current->next;
				previous = previous->next;
			}
			counter--;
			
			if (!flagIsSorted)  // if the flag is still false then not a single swap was made 
				break;          // which means that the stack is already sorted and the loop can be exited
		}
	}
}


template <typename T>
void Stack<T>::copyStack(Stack<T>& other)
{
	Node<T>* temp = new Node<T>;
	temp = other.top;
	while (temp)
	{
		add(temp->data);
		temp = temp->next;
	}
}


template <typename T>
void Stack<T>::deleteStack()
{
	while (!isEmpty())
		remove();
}