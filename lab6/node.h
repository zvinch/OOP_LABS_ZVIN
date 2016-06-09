#pragma once
#include "Circle.h"
#include "myRect.h"

class Node
{
private:
	Node * next_node;
	Node * prev_node;
	Shape * data;

public:
	Node();
	
	Node(Node & parent, const Shape*  o_shape );
	
	
	friend class myList;
	friend std::ostream& operator<<(std::ostream& ostr,const Node& mNode);
	friend std::ostream& operator<<(std::ostream& ostr, const myList& mlist);
	friend std::ofstream& operator<<(std::ofstream& ostr, const myList& mlist);
	friend std::ofstream& operator<<(std::ofstream& ostr, const Node& mNode);
	~Node();
};

