#include <iostream>
#include "TreeSortedStack.h"

using namespace std;

TreeSortedStack::TreeSortedStack(int initialCapacity)
{
	capacity = initialCapacity;
	elements=new int[capacity];
	firstOpenIndex=1;
}

TreeSortedStack::TreeSortedStack()
{
	capacity=0;
	elements=new int[capacity];
	firstOpenIndex=-1;
}

TreeSortedStack::~TreeSortedStack()
{
	delete []elements;
}


int TreeSortedStack::getSize()
{
	return firstOpenIndex-1;
}

bool TreeSortedStack::isEmpty()
{
	if(firstOpenIndex==-1 || firstOpenIndex==1)
		return true;
	else
		return false;
}


void TreeSortedStack::printSpaces(int numSpaces) 
{
	for (int i = 0; i < numSpaces; i++)
		cout << " ";
}




void TreeSortedStack::printHelper(int* curr, int i, int depth, char header) 
{
	if(i<firstOpenIndex) 
	{
		printSpaces(depth * 4);
		if (i!=1)
			cout << header << ": ";
		

		cout << elements[i] << endl;
		printHelper(curr, i*2, depth + 1, 'L');
		printHelper(curr, (i*2)+1, depth + 1, 'R');
	}
}


void TreeSortedStack::print() 
{

	cout << "-------------------------------" << endl;
	printHelper(elements, 1, 0, ' ');
	cout << "-------------------------------" << endl;
}

int TreeSortedStack::peek()
{
	//if(size==0)
	if(firstOpenIndex==-1 || firstOpenIndex == 1)
	{
		cout << "Structure is empty. pop returning -1 as placeholder" << endl; 
		return -1;
	}
	else
		return elements[1];
}

int TreeSortedStack::pop()
{
	//if(size==0)
	if(firstOpenIndex == -1 || firstOpenIndex==1)
	{
		cout << "Structure is empty. pop returning -1 as placeholder." << endl;
		return -1;
	}
	//else if(size==1)
	else if(firstOpenIndex==2)
	{
		//size-=1;
		firstOpenIndex-=1;
		return elements[1];
	}
	else
	{
		int toPop = elements[1];
		elements[1]=elements[firstOpenIndex-1];
		firstOpenIndex-=1;
		int parentID=1, smallestID, i, temp;
			if(firstOpenIndex<4){
			smallestID=firstOpenIndex-1;
		}
		if(elements[2]<elements[3])
			smallestID=2;
		else
			smallestID=3;
		for(; parentID<(firstOpenIndex-1) && elements[parentID]>elements[smallestID]; /*parentID++*/)
		{
			temp=elements[parentID];
			elements[parentID]=elements[smallestID];
			elements[smallestID]=temp;
			parentID=smallestID;
			if((parentID*2)==(firstOpenIndex-1))
			{
				if(elements[parentID*2]<elements[parentID])
				smallestID=parentID*2;
			}
			if(parentID*2 < firstOpenIndex-1)
			{
			if(elements[parentID*2]<elements[(parentID*2)+1])
				smallestID=parentID*2;
			else
				smallestID=(parentID*2)+1;
			}
		}
		return toPop;
	}
}




void TreeSortedStack::push(int new_element)
{
	if((firstOpenIndex==-1 || firstOpenIndex == 1) && capacity!=0)
	{
		elements[firstOpenIndex]=new_element;
		firstOpenIndex+=1;
	}
	else if((firstOpenIndex==-1 || firstOpenIndex==1) && capacity == 0)
	{
		expandArray();
		//elements[++size]=new_element;
		elements[firstOpenIndex]=new_element;
		firstOpenIndex+=1;
	}
	else{
	if(firstOpenIndex>=capacity)
		expandArray();
	elements[firstOpenIndex]=new_element;
	firstOpenIndex+=1;
	int childID=firstOpenIndex-1, parentID=(int)((firstOpenIndex-1)/2), temp;
	for(; childID>0 && elements[parentID]>elements[childID];)
	{
		temp=elements[parentID];
		elements[parentID]=elements[childID];
		elements[childID]=temp;
		childID=parentID;
		parentID=(int)(childID/2);
	}
	}
}

void TreeSortedStack::expandArray() {

	if(capacity==0)
	{
		int* bigger = new int[20];
		delete[] elements;
		elements=bigger;
		return;
	}

	int newCapacity = capacity * 2; // We'll allocate a spot in memory that's twice as big as the current spot.
	int* bigger = new int[newCapacity]; // Dynamically allocate the bigger chunk of memory.

	// Copy everything from the array named elements to the array named bigger.
	// This is a reason that adding is slow - we have to copy everything to the new memory location!
	for(int i=1; i<firstOpenIndex; i++)
		bigger[i] = elements[i];

	// Free up the old, smaller chunk of memory
	delete[] elements;

	// Update the fields to point to the new, bigger chunk of a memory
	elements = bigger;
	capacity = newCapacity;
	return;
}
