#pragma once
#include"Data.h"
#include"myString.h"

class Item
{
private:
	MyString m_string;
	Data m_data;
public:
	Item();
	Item(MyString str, Data dat);
	Data & Item::getData();
	const MyString & Item::getTag();
	
};

