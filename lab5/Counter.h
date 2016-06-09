#pragma once
class Counter
{
private:
	static Counter* Head;
	static unsigned int m_curCounters;
	char * m_pstr;
	Counter * pNext;
public:
	Counter(char* str);
	~Counter();
};

