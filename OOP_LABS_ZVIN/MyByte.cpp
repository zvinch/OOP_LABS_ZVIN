#include "MyByte.h"
#include <iostream>
char hexchars[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'F' };
wchar_t octchars[] = { '0', '1', '2', '3', '4', '5', '6', '7' };


void BIN::Show()
{
	std::wcout <<"bx" << bin7 << bin6 << bin5 << bin4 << bin3 << bin2 << bin1 << bin0 <<std::endl;
}

void HEX::Show()
{
	std::wcout << "0x"<< hexchars[hex1] << hexchars[hex0-1] << std::endl;
}

void OCT::Show()
{
	std::wcout << "8x" << octchars[oct2] << octchars[oct1] << octchars[oct0] << std::endl;
}

void MyByte::ShowBin()
{
	m_bins.Show();
}

void MyByte::ShowOct()
{
	m_octs.Show();
}

MyByte::MyByte(const unsigned char val)
{
	m_char = val;
}

void MyByte::ShowHex()
{
	m_hexs.Show();
}

void BIN::SetBit(unsigned char pos, bool state)
{
	switch (pos)
	{
	case 0:
		bin0 = state;
		break;
	case 1:
		bin1 = state;
		break;
	case 2:
		bin2 = state;
		break;
	case 3:
		bin3 = state;
		break;
	case 4:
		bin4 = state;
		break;
	case 5:
		bin5 = state; 
		break;
	case 6:
		bin6 = state; 
		break;
	case 7:
		bin7 = state; 
		break;

	default:
		std::cout << "unknown pos" << std::endl;

	}


}

void OCT::SetOct(unsigned char pos, unsigned char state)
{
	switch (pos)
	{
	case 0:
		oct0 = state; 
		break;
	case 1:
		oct1 = state; 
		break;
	case 2:
		oct2 = state; 
		break;
	default:
		std::cout << "unknown pos" << std::endl;

	}

}

void HEX::SetHex(unsigned char pos, unsigned char state)
{
	
	switch (pos)
	{
	case 0:
		hex0 = pos; 
		break;
	case 1:
		hex1 = pos; 
		break;
	default:
		std::cout << "unknown pos" << std::endl;

	}

}



void BIN::ShowBit(unsigned char pos)
{
	bool retval = (bin0 >> pos) & 1;
	std::wcout << retval << std::endl;
}

void MyByte::ShowBitBin(unsigned char pos)
{
	m_bins.ShowBit(pos);
}

void MyByte::SetBit(unsigned int pos,bool state)
{
	m_bins.SetBit(pos, state);
}

void MyByte::SetHex(unsigned int pos, unsigned char state)
{
	m_hexs.SetHex(pos, state);
}

void MyByte::SetOct(unsigned int pos, unsigned char state)
{
	m_octs.SetOct(pos, state);
}