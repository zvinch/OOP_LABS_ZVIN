#include "list.h"
#define BUF_SIZE 200

void myList::swap(Node * first, Node * second)
{
	if (first != nullptr && second != nullptr){
		if ((first != &Tail) && (first != &Head) && (second != &Head) && (second != &Tail)) {
			
			if (first != second) {
				first->prev_node->next_node = second;
				second->prev_node->next_node = first;

				first->next_node->prev_node = second;
				second->next_node->prev_node = first;

				Node * tmp = first->prev_node;
				first->prev_node = second->prev_node;
				second->prev_node = tmp;
				tmp = first->next_node;
				first->next_node = second->next_node;
				second->next_node = tmp;
				
			}
		}
	}
	std::cout << *this << "swap" << std::endl;
}

void  myList::swapNodes(Node* i, Node* j)
{
	if (i->prev_node)  i->prev_node->next_node = j;
	if (j->prev_node)  j->prev_node->next_node = i;
	if (i->next_node) i->next_node->prev_node = j;
	if (j->next_node) j->next_node->prev_node = i;
	std::swap(i->prev_node, j->prev_node);
	std::swap(i->next_node, j->next_node);
	std::cout << *this << "std::swap" << std::endl;
}

void myList::swapNodes1(Node* i, Node* j)
{
	std::cout << *this << " swap 12" << std::endl;
	  i->prev_node->next_node = j;
	  j->prev_node->next_node = i;
	 i->next_node->prev_node = j;
	 j->next_node->prev_node = i;
	Node* temp;
	temp = i->prev_node;
	i->prev_node = j->prev_node;
	j->prev_node = temp;
	temp = i->next_node;
	i->next_node = j->next_node;
	j->next_node = temp;
	std::cout << *this << " swap 22" << std::endl;
}


Node* myList::swapNodes2(struct Node* node1, struct Node* node2) {
	if ((node1 != nullptr) && (node2 != nullptr))
	{
		Node* temp;
		temp = node1->next_node;
		node1->next_node = node2->next_node;
		node2->next_node = temp;
		if (node1->next_node != NULL)
			node1->next_node->prev_node = node1;
		if (node2->next_node != NULL)
			node2->next_node->prev_node = node2;
		temp = node1->prev_node;
		node1->prev_node = node2->prev_node;
		node2->prev_node = temp;
		if (node1->prev_node != NULL)
			node1->prev_node->next_node = node1;
		if (node2->prev_node == NULL)
			return node2;
		node2->prev_node->next_node = node2;
	}
	return node1;
}
myList::myList()
{
	Head.next_node = &Tail;
	Tail.prev_node = &Head;
	m_size = 0;
}

myList::myList(std::ifstream & file)
{
	
	Head.next_node = &Tail;
	Tail.prev_node = &Head;
	m_size = 0;
	unsigned short version = 1;
	switch (version)
	{
	case 1:
		if (file.is_open()) //Version 1 How to skip empty lines without buffer?
		{
			double x = 0;
			double y = 0;
			unsigned int radius = 0;
			while (file >> x >> y >> radius)// goodbit
			{
					this->append(Circle(Point(x, y), radius));
					std::cout << *this << std::endl;
			}
		}
	case 2:
		if (file.is_open()) //Version 2 bare bones Buff
		{
			double x = 0;
			double y = 0;
			unsigned int radius = 0;
			char buf[BUF_SIZE] = "";
			while (!(file.rdstate()&std::iostream::goodbit))
			{
				file.getline(buf, BUF_SIZE);
				if (buf[0] == '\0')
				{
					break;
				}
				sscanf_s(buf, "%lf %lf %u", &x, &y, &radius);
				this->append(Circle(Point(x, y), radius));
				std::cout << *this << std::endl;

				if (file.eof())
				{
					break;
				}
			}
		}
		break;
	case 3:
		if (file.is_open())
		{
			std::string line;
			while (std::getline(file, line))
			{

			}
		}
		break;

	default:
		break;
	}
	


}

void myList::insert(Node & parent,const  Circle & tobeadded){
	new Node(parent,tobeadded);
	m_size++;

}

void myList::kill(Node & dead){
	m_size--;
	delete &dead;
}

void myList::clear(){
	
	m_size = 0;
	{
		while (Head.next_node != &Tail)
		{
			delete Head.next_node;
		}
	}

}


void myList::add(const Circle & newcircle){
	this->insert(Head, newcircle);
}
void myList::append(const Circle & newcircle){
	this->insert(*(Tail.prev_node),newcircle);
}

void myList::SelectionsortByAreaASC()
{
	
	Node * cursor = Head.next_node;
	Node* t_ptr = &Tail;
	while (cursor!=t_ptr)
	{
		Node* next_cur = cursor->next_node;
		swapNodes2(cursor, min(cursor));
		cursor =next_cur;

	}

}



Node * myList::min( Node *const  start)const
{
	Node* iter = start;
	Node* min = nullptr;
	int i = 0;
	if (iter->next_node->next_node != nullptr)
	{	
		min = iter->next_node;
		while (iter->next_node != nullptr)
		{
			if (iter->m_circle.area() < min->m_circle.area())
			{
				min = iter;
			}
			iter = iter->next_node;
			i++;
		}
	}
	
	return min;
}



bool myList::seekanddestroyGREEDY(Circle & tobedeleted){
	Node * node_ptr = Head.next_node;
	while (node_ptr != &Tail)
	{
		if ((node_ptr)->m_circle == tobedeleted)
		{
			delete node_ptr;
			m_size--;
			return 1;
		}
		node_ptr = node_ptr->next_node;
	}
	return 0;
}
unsigned int myList::seekanddestroyALL(Circle & tobedeleted){
	Node * node_ptr = Head.next_node;
	unsigned int retval = 0;
	while (node_ptr != &Tail)
	{
		Node*  pn = node_ptr->next_node;
		if ((node_ptr)->m_circle == tobedeleted)
		{
			delete node_ptr;
			m_size--;
			retval++;
		}
		node_ptr = pn;
	}
	return retval;
}



myList::~myList()
{
	this->clear();
}
std::ostream& operator<<(std::ostream& ostr, const myList& mlist)
{

	ostr << "++++++++++++++++++++++++++++++" << std::endl;
	Node * np = mlist.Head.next_node;
	unsigned int rank = 0;
	while (np != &mlist.Tail)
	{
		ostr <<rank <<" -- "<< np->m_circle<<" this "<< *(np) <<" prev "<<*(np->prev_node)<< " next "<<*(np->next_node)<< std::endl;
		rank++;
		np = np->next_node;
	}
	ostr << "++++++++++++++++++++++++++++++" << std::endl;
	return ostr;
}
std::ofstream& operator<<(std::ofstream& ostr, const myList& mlist)
{

	
	Node * np = mlist.Head.next_node;
	
	while (np != &mlist.Tail)
	{
		ostr << np->m_circle<< std::endl;
		np = np->next_node;
	}
	
	return ostr;
}

myList::myList(const myList & other)
{
	Head.next_node = &Tail;
	Tail.prev_node = &Head;
	
	Node * p_node = other.Head.next_node;
	while (p_node != &other.Tail)
	{
		this->append(p_node->m_circle);
		p_node = p_node->next_node;
	}
}

myList::myList( myList && other)
{
	if (other.m_size)
	{
		this->Head.next_node = other.Head.next_node;
		this->Tail.prev_node = other.Tail.prev_node;
		this->Head.next_node->prev_node = &Head;
		this->Tail.prev_node->next_node = &Tail;
		this->m_size = other.m_size;
		other.Head.next_node = &other.Tail;
		other.Tail.prev_node = &other.Head;
		other.m_size = 0;
	}
	else
	{
		Head.next_node = &Tail;
		Tail.prev_node = &Head;
		m_size = 0;
	}
}

myList & myList::operator = (const myList & other)
{

		Node* p_other = other.Head.next_node;
		Node* p_this = Head.next_node;
		while (p_other != &other.Tail)
		{
			if (p_this != &Tail)
			{
				p_this->m_circle = p_other->m_circle;
				p_this = p_this->next_node;
			}
			else
			{
				this->append(p_other->m_circle);
				
			}
			p_other = p_other->next_node;
		}
		
		
		while (p_this != &Tail)
		{
			Node* tmp = p_this;
			p_this = p_this->next_node;
			delete tmp;
			
		}
	
	m_size=other.m_size;
	return *this;
}