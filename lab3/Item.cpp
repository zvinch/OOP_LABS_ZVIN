#include "Item.h"


Item::Item()
{
}

Item::Item(MyString str, Data dat) : m_data(dat), m_string(str)
{
	
}

 Data & Item::getData()
{
	return m_data;
}
const MyString & Item::getTag()
{
	return m_string;
}


