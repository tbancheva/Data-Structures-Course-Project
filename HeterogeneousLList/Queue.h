#include "Container.h"
#include <iostream>
using namespace std;

template <typename T>
struct Box{
	T data;
	Box<T>* next;
};

#ifndef _QUEUE
#define _QUEUE

template <typename T>
class Queue : public Container<T>
{
	Box<T>* front;
	size_t size;

	void copyQueue(const Queue<T>&);
	void deleteQueue();

public:
	Queue();
	~Queue();
	Queue(const Queue&);
	Queue& operator=(const Queue&);

	void add(const T&); //enqueue
	void remove();      //dequeue
	T& getElement();	//front
	
	size_t getSize();
	string getType();

	void print();
	bool isEmpty();
	void sort();

	bool member(T const&);
	bool usingCondition(bool(*f)(const T& x));

};

#endif //_QUEUE

template <typename T>
Queue<T>::Queue()
{
	front = NULL;
	size = 0;
}

template <typename T>
Queue<T>::Queue(const Queue& other)
{
	copyQueue(other);
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
	if (this != other)
	{
		deleteQueue();
		copyQueue(other);
	}
	return *this;
}

template <typename T>
Queue<T>::~Queue()
{
	deleteQueue();
}

template <typename T>
void Queue<T>::add(const T& el) //enqueue
{
	Box<T>* temp = new Box<T>;
	temp->data = el;
	temp->next = NULL;

	if (isEmpty())
		front = temp;
	else
	{
		Box<T>* current = new Box<T>;
		current = front;
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
void Queue<T>::remove()   //dequeue
{
	if (!isEmpty())
	{
		Box<T>* temp = front->next;
		delete front;
		front = temp;
		size--;
	}

}


template <typename T>
bool Queue<T>::isEmpty()
{
	return front == NULL;
}

template <typename T>
T& Queue<T>::getElement()  //front
{
	return front->data;
}

template<typename T>
size_t Queue<T>::getSize()
{
	return size;
}

template<typename T>
string Queue<T>::getType()
{
	return "queue";
}

template <typename T>
void Queue<T>::print()
{
	if (isEmpty())
		cout << "Empty queue" << endl;
	else
	{
		Box<T>* temp = new Box<T>;
		temp = front;
		cout << "Front of queue: ";
		while (temp)
		{
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "End of queue" << endl;
	}
}

template <typename T>
bool Queue<T>::member(const T& x)
{
	Box<T>* temp = new Box<T>;
	temp = front;
	while (temp)
	{
		if (temp->data == x)
			return true;
		temp = temp->next;
	}
	return false;
}

template <typename T>
bool Queue<T>::usingCondition(bool(*f)(const T& x))
{
	if (isEmpty())
		return false;
	else
	{
		Box<T>* temp = new Box<T>;
		temp = front;
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
void Queue<T>::sort()
{
	if (!isEmpty())
	{
		int counter = size;

		while (counter)
		{
			bool flagIsSorted = false;
			Box<T> *current = front;
			Box<T> *previous = current->next;
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
				break;          // which means that the queue is already sorted and the loop can be exited
		}
	}
}


template <typename T>
void Queue<T>::copyQueue(const Queue<T>& other)
{
	Box<T>* temp = new Box<T>;
	temp = other.front;
	while (temp)
	{
		add(temp->data);
		temp = temp->next;
	}
}

template <typename T>
void Queue<T>::deleteQueue()
{
	while (!isEmpty())
		remove();
}