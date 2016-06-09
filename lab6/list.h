#pragma once
#include "Node.h"

#include <iostream>
#include <fstream>
#include <string>

class myList
{
private:
	Node Head;
	Node Tail;
	
	unsigned int m_size;
	void swap(Node* first, Node* second);
public:
	myList();
	myList(std::ifstream & file);
	void insert(Node & parent, const Shape * tobeadded);
	myList(const myList & other);
	myList( myList && other);
	//void add(const Circle & newcircle);
	void add(const Shape * newcircle);
	//void append(const Circle & newcircle);
	void append(const Shape * newcircle);
	void SelectionsortByAreaASC();

	void Selectionsort(bool (*compare)(const Shape *first, const Shape *second));

	Node * min(Node * const start, bool(*compare)(const Shape *first, const Shape *second)) const;
	
	Node* min( Node*const start)const;
	void swapNodes(Node* i, Node* j);
	void swapNodes1(Node* i, Node* j);
	Node* swapNodes2(Node* node1, Node* node2);
	
	//bool seekanddestroyGREEDY(Circle & tobedeleted);
	bool seekanddestroyGREEDY(Shape * tobedeleted);
	unsigned int seekanddestroyALL(Shape * tobedeleted);
	//unsigned int seekanddestroyALL(Circle & tobedeleted);
	void clear();
	void insert(Node & parent,const Circle & tobeadded);
	void kill(Node & dead);

	myList & myList::operator= (const myList & other);

	friend std::ostream& operator<<(std::ostream& ostr, const myList& mlist);
	friend std::ofstream& operator<<(std::ofstream& ostr, const myList& mlist);
	~myList();
};

