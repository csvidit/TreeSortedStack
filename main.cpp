#include <iostream>
using namespace std;
#include "TreeSortedStack.h"

void officialTest() {
	TreeSortedStack tss(2);

	cout << "isEmpty: " << tss.isEmpty() << endl;

	cout << "push 10" << endl;
	tss.push(10);
	tss.print();

	cout << "push 12" << endl;
	tss.push(12);
	tss.print();

	cout << "push 5" << endl;
	tss.push(5);
	tss.print();

	cout << "push 7" << endl;
	tss.push(7);
	tss.print();

	cout << "push 9" << endl;
	tss.push(9);
	tss.print();

	cout << "pop: " << tss.pop() << endl;
	cout << "peek: " << tss.peek() << endl;
	tss.print();

	cout << "push 16" << endl;
	tss.push(16);
	tss.print();

	cout << "push 13" << endl;
	tss.push(13);
	tss.print();

	cout << "push 4" << endl;
	tss.push(4);
	tss.print();

	cout << "push 11" << endl;
	tss.push(11);
	tss.print();

	cout << "==========================================" << endl;

	cout << "getSize: " << tss.getSize() << endl;
	cout << "peek: " << tss.peek() << endl;

	while (!tss.isEmpty()) {
		cout << "pop: " << tss.pop() << endl;
		//cout << "Result: " << tss.pop() << endl;
		tss.print();
	}

	cout << "==========================================" << endl;
	cout << "getSize: " << tss.getSize() << endl;
	cout << "peek: " << tss.pop() << endl;
	cout << "pop: " << tss.pop() << endl;
}

void anotherTest(){
	TreeSortedStack ss(2);

	
	cout << "isEmpty: " << ss.isEmpty() << endl;

	cout << "push 10" << endl;
	ss.push(10);
	ss.print();

	cout << "push 12" << endl;
	ss.push(12);
	ss.print();

	cout << "push 5" << endl;
	ss.push(5);
	ss.print();

	cout << "push 7" << endl;
	ss.push(7);
	ss.print();

	cout << "push 9" << endl;
	ss.push(9);
	ss.print();

	cout << "pop: " << ss.pop() << endl;
	cout << "peek: " << ss.peek() << endl;
	ss.print();

	cout << "push 16" << endl;
	ss.push(16);
	ss.print();

	cout << "push 13" << endl;
	ss.push(13);
	ss.print();

	cout << "push 4" << endl;
	ss.push(4);
	ss.print();

	cout << "push 9" << endl;
	ss.push(9);
	ss.print();

	cout << "==========================================" << endl;

	cout << "getSize: " << ss.getSize() << endl;
	cout << "peek: " << ss.peek() << endl;
}


int main() {
	officialTest();

	return 0;
}

