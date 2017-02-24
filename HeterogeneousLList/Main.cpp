#include <iostream>
#include <fstream>
#include "HeterogeneousLList.h"
#include "Container.h"
#include "Queue.h"
#include "Stack.h"
#include "DoubleLList.h"
using namespace std;


int main()
{
	int n;
	cout << "Please enter the number of the containers(the number of lines in the file): ";
	cin >> n;

	ifstream input("input.txt");

	HeterogeneousLList<int> h(input,n);
	cout << h.isInTheList(40) << endl;
	cout << h.isInTheList(13) << endl;
	h.loadBalancing(7);
	h.sortList();
	h.printList();
	cout << "-------------------------------------------------" << endl;
	h.removeElement(isEven);
	h.printList();
	
	ofstream output("output.txt");
	h.resultFile(output);

	//DoubleLList<int> s;
	//s.add(7);
	//s.add(3);
	//s.add(5);
	//s.add(11);
	//s.add(5);
	//s.add(7);
	//s.add(7);
	//s.print();
	//cout << s.member(12);
	//s.removeParticularElem(6);
	//s.print();
	//cout << s.usingCondition(isEven) << endl;
	//cout << s.getElement() << endl;

	system("pause");
	return 0;
}