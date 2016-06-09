#include "node.h"


Node::Node() 
{
	next_node = nullptr;
	prev_node = nullptr;
	
}
Node::Node(Node & parent, const Shape* o_shape) 
{
	prev_node = &parent;
	next_node = parent.next_node;
	parent.next_node = this;
	next_node->prev_node = this;
	data = o_shape->clone();

}

Node::~Node()
{
	
	if (next_node != nullptr)
	{
		next_node->prev_node = prev_node;
	}
	if (prev_node != nullptr)
	{
		prev_node->next_node = next_node;
	}

}

std::ostream& operator<<(std::ostream& ostr, const Node& mNode)
{
	ostr << mNode.data;
	return ostr;
}

std::ofstream& operator<<(std::ofstream& ostr, const Node& mNode)
{
	ostr << mNode.data;
	return ostr;
}