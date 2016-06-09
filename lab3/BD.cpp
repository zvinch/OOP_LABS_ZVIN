#include "BD.h"
#define INIT_CAPACITY 10

BD::BD()
{
	this->m_data_list = new Item*[INIT_CAPACITY];
	this->m_capacity = INIT_CAPACITY;
	this->m_stored = 0;
}
void Delete(const char *)
{

}

BD::BD(const BD& other)
{
	this->m_capacity = other.m_stored;
	this->m_data_list = new Item*[this->m_capacity];
	this->m_stored = other.m_stored;
	for (int i = 0; i < m_stored; i++)
	{
		this->m_data_list[i] = new Item(*other.m_data_list[i]);
	}
}

BD& BD::operator=(const BD & other) 
{
	for (int i = 0; i < this->m_stored; i++)
	{
		delete this->m_data_list[i];
	}
	this->m_stored = 0;

	for (int i = 0; i < other.m_stored; i++)
	{
		m_data_list[i] = new Item(*other.m_data_list[i]);
		this->m_stored++;
	}
	return *this;
}

Data & BD::operator[](const char * tag)
{
	this->m_data_list[m_stored] = new Item(MyString(tag),Data());
	m_stored++;
	return this->m_data_list[m_stored - 1]->getData();
}

std::ostream& operator<<(std::ostream& ostr, BD & bd)
{
	for (int i = 0; i < bd.m_stored; i++)
	{
		ostr << bd.m_data_list[i]->getData() << std::endl;
	}
	return ostr;
}
BD::~BD()
{
	for (int i = 0; i < m_stored; i++)
	{
		delete	m_data_list[i];
	}
	delete[] m_data_list;
}
