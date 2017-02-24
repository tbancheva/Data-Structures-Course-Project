#include <string>
using namespace std;

#ifndef _CONTAINER
#define _CONTAINER

template <typename T>
class Container{

public:
	virtual bool member(const T&) = 0;

	virtual void add(const T&) = 0;       // Functionality 2.
	virtual void remove() = 0;            // Functionality 2.

	virtual bool usingCondition(bool(*f)(const T& x)) = 0;   //Functionality 5.

	virtual bool isEmpty() = 0;
	virtual void print() = 0;

	virtual size_t getSize() = 0;
	virtual string getType() = 0;
	virtual T& getElement() = 0;
	virtual void sort() = 0;
	

};

#endif //_CONTAINER