#include "Data.h"


Data::Data()
{

}

Data::Data(enum::SEX sex, unsigned char age, MyString & job, double salary) : m_job(job)
{
	this->m_age = age;
	this->m_sex = sex;
	
	this->m_slary = salary;
}
Data::Data(enum::SEX sex, unsigned char age, const char* job, double salary) : m_job(job)
{
	this->m_age = age;
	this->m_sex = sex;

	this->m_slary = salary;
}  
//Data::Data(const Data & other)
//{
//	delete this->m_job;
//	this->m_job = other.m_job;
//	this->m_age = other.m_age;
//	this->m_sex = other.m_sex;
//	this->m_slary = other.m_slary;
//
//}

std::ostream& operator<<(std::ostream& ostr, const Data& dat)
{
	ostr << "contents:  " << dat.m_job << " " << dat.m_age << " " << ((dat.m_sex)?"FEMALE":"MALE") << " " << dat.m_slary;
	return ostr;
}

