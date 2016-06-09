#pragma once
#include <iostream>
class MyString
{
    char* m_pStr;	//строка-член класса
public:
	explicit MyString(const char * str = "");

	const char* GetString() const;

	void SetNewString(const char * str);

	MyString & operator=(const MyString & other);
	MyString & operator=(const char* other);
	MyString & operator=(MyString && other);
	MyString & operator+=(const MyString & other);
	MyString  operator+(const MyString & other);
	friend std::ostream& operator<<(std::ostream& ostr,const MyString& string);

	MyString(const MyString & other);

	MyString(MyString && tmp);

	MyString::~MyString()
	{

		delete[] m_pStr;

	}
};

MyString concattoMyString(const char * str, ...);