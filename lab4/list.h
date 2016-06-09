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
	myList(const myList & other);
	myList( myList && other);
	void add(const Circle & newcircle);
	void append(const Circle & newcircle);
	void SelectionsortByAreaASC();
	
	Node* min( Node*const start)const;
	void swapNodes(Node* i, Node* j);
	void swapNodes1(Node* i, Node* j);
	Node* swapNodes2(struct Node* node1, struct Node* node2);
	
	bool seekanddestroyGREEDY(Circle & tobedeleted);
	unsigned int seekanddestroyALL(Circle & tobedeleted);
	void clear();
	void insert(Node & parent,const Circle & tobeadded);
	void kill(Node & dead);

	myList & myList::operator= (const myList & other);

	friend std::ostream& operator<<(std::ostream& ostr, const myList& mlist);
	friend std::ofstream& operator<<(std::ofstream& ostr, const myList& mlist);
	~myList();
};

