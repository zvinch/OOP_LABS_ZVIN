#pragma once
#include"item.h"
class BD
{
	
private:
	Item ** m_data_list;
	unsigned int m_capacity;
	unsigned int m_stored;

public:
	
	BD();
	void Delete(const char *);
	BD(const BD& other);
	
	BD& BD::operator=(const BD & other);
	Data & BD::operator[](const char * tag);
	friend std::ostream& operator<<(std::ostream& ostr, BD& bd);

	~BD();
};

