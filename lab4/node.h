#pragma once
#include "Circle.h"

class Node
{
private:
	Node * next_node;
	Node * prev_node;
	Circle m_circle;

public:
	Node();
	
	Node(Node & parent, const Circle & o_circle );
	
	
	friend class myList;
	friend std::ostream& operator<<(std::ostream& ostr,const Node& mNode);
	friend std::ostream& operator<<(std::ostream& ostr, const myList& mlist);
	friend std::ofstream& operator<<(std::ofstream& ostr, const myList& mlist);
	friend std::ofstream& operator<<(std::ofstream& ostr, const Node& mNode);
	~Node();
};

