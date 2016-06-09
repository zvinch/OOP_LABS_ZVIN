#include <string>
#include "myString.h"
#include <cstdarg>
using namespace std;

// Определение конструктора.
MyString::MyString(const char * str)
{
	m_pStr = new char[strlen(str) + 1];
	strcpy_s(m_pStr, strlen(str) + 1, str);
}

MyString::MyString(const MyString & other)
{
	m_pStr = nullptr;
	*this = other;
}

//Move
MyString::MyString(MyString && tmp)
{

	this->m_pStr = tmp.m_pStr;
	tmp.m_pStr = nullptr;
}

MyString & MyString::operator=(const MyString & other)
{
	if (this != &other){
		delete[] m_pStr;
		m_pStr = new char[strlen(other.m_pStr) + 1];
		strcpy_s(m_pStr, strlen(other.GetString()) + 1, other.GetString());
		
	}
	return *this;
}
MyString & MyString::operator=(MyString && other){
	if (this != &other){
		this->m_pStr = other.m_pStr;
		other.m_pStr = nullptr;

	}
	return *this;
}


MyString & MyString::operator=(const char* other)
{
	delete[] m_pStr;
	m_pStr = new char[strlen(other) + 1];
	strcpy_s(m_pStr, strlen(other) + 1, other);
	return *this;
}

// Определение деструктора.



// GetString
const char* MyString::GetString() const
{
	return (m_pStr);
}

// copy

void MyString::SetNewString(const char * str) 
{
	delete[] m_pStr;
	m_pStr = new char[strlen(str) + 1];
	strcpy_s(m_pStr, (strlen(str) + 1), str);
	
}

MyString concattoMyString(const char * p, ...)
{
	va_list args;
	unsigned int num = 0;

	unsigned int strTotSize =0;
	char * accamulator;
	unsigned int check = 1;
	va_start(args,p);

	strTotSize += strlen(p);
	num++;

	while (check)
	{
		
		const char * tmp = va_arg(args, const char *);
		
		if (!tmp)
		{
			check = 0;
			
		}
		else
		{
			strTotSize+=strlen(tmp);
			num++; 
		}
		
	}
	accamulator = new char[strTotSize+1];
	accamulator[0] = 0;
	va_end(args, p);
	va_start(args, p); 
	strcat_s(accamulator, strTotSize + 1, p);
	for (int i = 0; i < num-1; i++)
	{
		strcat_s(accamulator, strTotSize + 1, va_arg(args, const char *));
	}
	va_end(args, p);
	MyString reval (accamulator);

	delete[] accamulator;

	return std::move(reval);
	
}

std::ostream& operator<<(std::ostream& ostr,const  MyString& string)
{
	ostr << "contents:  " << string.m_pStr;
	return ostr;
}

MyString &  MyString::operator+=(const MyString & other)
{
	*this = concattoMyString(this->GetString(), other.GetString(), 0);
	return *this;
}
MyString MyString::operator+(const MyString & other)
{
	return MyString(concattoMyString(this->GetString(), other.GetString(), 0));
}