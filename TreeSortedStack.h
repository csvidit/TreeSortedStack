#include <iostream>

using namespace std;

class TreeSortedStack{
	public:
		//methods below
		//***********************************
		TreeSortedStack();
		TreeSortedStack(int);
		~TreeSortedStack();
		void push(int);
		int pop();
		int peek();
		int getSize();
		bool isEmpty();
		void print();
		void printHelper(int*, int, int, char);
		void printSpaces(int);
		void expandArray();
		void shrinkArray();

		//***********************************
		//fields below
		//***********************************

		int capacity;
		//capacity is equal to the maximum number of ints the element* array can have
		int* elements;
		int firstOpenIndex;
		//int size;
		//size is always equal to the index of the last element of the array
};
