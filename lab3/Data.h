#pragma once
#include "myString.h"

enum SEX{MALE,FEMALE,UNKNOWN};

class Data
{
private:
	enum::SEX m_sex;
	unsigned int m_age;
	MyString  m_job;
	double m_slary;
public:
	Data();
	Data(enum::SEX sex,unsigned char age,MyString & job, double salary);
	Data(enum::SEX sex, unsigned char age, const char* job, double salary);
	//Data(const Data & other);
	friend std::ostream& operator<<(std::ostream& ostr, const Data& dat);
	
	
};

