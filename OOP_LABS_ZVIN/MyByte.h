#pragma once



class BIN{

	bool bin0 : 1;
	bool bin1 : 1;
	bool bin2 : 1;
	bool bin3 : 1;
	bool bin4 : 1;
	bool bin5 : 1;
	bool bin6 : 1;
	bool bin7 : 1;
	void Show();
	void SetBit(unsigned char pos, bool state);
	void ShowBit(unsigned char pos);
	friend union MyByte;
};

class OCT{

	unsigned char oct0 : 3;
	unsigned char oct1 : 3;
	unsigned char oct2 : 2;
	void Show();
	void SetOct(unsigned char pos, unsigned char state);
	
	friend union MyByte;
};

class HEX{

	unsigned char hex0 : 4;
	unsigned char hex1 : 4;
	void Show();
	void ShowDigit(unsigned char);
	void SetHex(unsigned char pos, unsigned char state);
	friend union MyByte;
};

union MyByte
{
	unsigned char m_char;
	BIN m_bins;
	OCT m_octs;
	HEX m_hexs;
	MyByte(const unsigned char val);
	void ShowBin();
	void ShowOct();
	void ShowHex();
	void ShowBitBin(unsigned char pos);
	void SetBit(unsigned int pos,bool state);
	void SetOct(unsigned int pos, unsigned char state);
	void SetHex(unsigned int pos, unsigned char state);
};

