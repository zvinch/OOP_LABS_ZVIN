// ����:
// ������� ������������. ����������� �������. ����������� ������.
// ������� ����.


#include <tchar.h>
#define	  stop __asm nop

#include "shape.h"
#include "myRect.h"
#include "circle.h"
#include "myByte.h"

int _tmain(int argc, _TCHAR* argv[])
{


	////������� 1.������� ������������.��������� ������������,
	//// ������������ � ������� �����.

	////�������� �������� �������:
	////������� ����� Shape (������� ��������� ����� ������)
	////� ��� ����������� ������ Rect � Circle.
	////���������: ����� ������ � ������ ����� ������ � �������
	////� ����������� ������ (��������, ����� ������ ����� �������
	////������� => � ������� ������ ����� ������ ����������, �������
	////����� ���������� ���� ������.
	////���������: ��� �������� ����� �������� ������������ (RED,GREEN,BLUE...);

	//Shape sh1;
	//Rect rect1;
	//rect1.SetAll(1, 2, 3, 4);
	//rect1.SetColor(myColor::BLUE);
	//Circle ball(3, 3, 1);


	////� ������������� ����������� ������� ������������� ��������
	////���������-����� ������������ �������� ������.
	////��� �������� � ����������� ������� ������������ ���� ����������
	////������������������ ������� ������������� � ������������ ��������
	////� ������������ �������

	//Rect rect2(3, 4, 5, 6, myColor::BLUE);
	//stop;
	//// ����->��� ~���->����




	stop
		//////////////////////////////////////////////////////////////////////

		//������� 2.����������� �������.
		//2�) ������������� ������ Shape,Rect � Circle:
		//�������� � ������ ����� public ����� void WhereAmI().
		//���������� ������ ������� ������ �������� ��������� 
		//���������� ���� "Now I am in class Shape(Rect ��� Circle)".
		//��������� ����������� ��������, ��������� ���������.

		//2�) �������� ����� WhereAmI() �����������.
		//����� ��������� ����������� ��������, ��������� �������.

	//{
	//	Shape s;
	//	Rect r;
	//	Circle c;


	//	//����� ������ ������ ���������� � ��������� ��������???
	//	s.WhereAmI();	//	??? Shape                                               
	//	r.WhereAmI();	//	??? Rect
	//	c.WhereAmI();	//	??? cIRCLE
	//	stop


	//	Shape* pShape = &s;
	//	Shape* pRect = &r;
	//	Shape* pCircle = &c;
	//	pShape->WhereAmI();	//	??? shape                                               shape             
	//	pRect->WhereAmI();	//	??? shape												rect
	//	pCircle->WhereAmI(); //	??? shape ������ ��� ����� ������ ����					circle

	//	stop


	//		//��������� ... �������� ������������
	//		Shape& rShape = s; //��������� s
	//	Shape& rRect = r; //��������� r
	//	Shape& rCircle = c; //��������� c
	//	(rShape).WhereAmI();	//����� ����������� rShape	??? shape                  shape	
	//	(rRect).WhereAmI();	//����� �����������	rRect	??? shape						rect
	//	(rCircle).WhereAmI(); //����� ����������� rCircle	??? shape					circle
	//	stop
	//}


	//////////////////////////////////////////////////////////////////////

	//������� 3.����������� �����������.
	//������������� ������:
	//a) ������� ���������������
	// ����������� (��� ��������� ����� virtual).
	//���������� ������� �����������
	//������ �������� ��������� ���������� ����
	// "Now I am in Shape's destructor!" ���
	// "Now I am in Rect's destructor!"
	//��������� ��������. ��������� ���������.
	stop
		//{
		//	Shape s;       //���������� � ������� �������� �������� � ������������� ��� � ������� ���
		//	Rect r;
		//	Circle c;
		//}
			stop
			// b) �������� � ���������� ������������ �������� ����� virtual 
			//��������� ��������.��������� �������.


			//���������: ����� ������������ ���������� � ��������� ������?
			//���� � ������������� ������� �����-�� �������������
			//�� ������� - ����������
			//���� �� ��������, ��� � ����������� ��������� ����-��
			//�� ������� - ��������
			stop
	/*	{
			Rect r(1, 2, 3, 4, GREEN);
			Shape* ar[] = { new Shape(r), new Rect(r), new Circle(r), new Circle() };
			for (int i = 0; i < 4; i++)
			{
				(*ar[i]).WhereAmI();
			}

			for (int i = 0; i < 4; i++)
			{
				delete ar[i];
			}
		}*/
			stop
		//�������� ��� ������� �������� ������� ����� WhereAmI()
	

	stop



	//������� 4*. � ��� ����������� ������� 1) � 2)
	//{
	//	Shape* pShapes = new Rect[10];//1)
	//	Rect* pRects = new Rect[10];//2)
	// 
	//	//���������� ������� ����� WhereAmI() ��� ������� �������� ����� �������� -
	//	//� ��� ����������� ��������???
	//	
	//	

	//	for (int i = 0; i < 10; i++)
	//	{
	//	//	Rect* tmp = static_cast<Rect*> (&pShapes[i]);
	//		//(*tmp).WhereAmI();
	//		static_cast<Rect*> (pShapes)[i].WhereAmI();
	//		pRects[i].WhereAmI();
	//	}
	//	stop

	//	//���������� ����������� ����������� ������
	//	
	//	delete[] pShapes;
	//	delete[] pRects;
	//	
	//stop	
	//}



//////////////////////////////////////////////////////////////////////

	////������� 5.����������� ������� � �������� ���������� ������� ���������. 

	{
		//Rect r;
		//Shape* p = &r;	
		//p->WhereAmI();//...
		//stop
	
		//
		////4a �������� ���������� ������� ���������.
		////����������� ������� r � ��������� p �������� ����������� �������
		////WhereAmI()������ Shape
		//Shape* p2 = &r;
		//p->Shape::WhereAmI();
		//stop
		//	
			
	}


//////////////////////////////////////////////////////////////////////

	//������� 6.����� ����������� �������. 
	//������� � ������� ����� ����� void Inflate(int); ���������:
	//����� �� ����������� ����� ����� ��� �������� ������? => ��� ��� ����� ��������.
	//���������� ���� ����� ��� ����������� �������.
	{
		Rect r(1,2,3,4);
		Shape* p = &r;
		p->Inflate(5);
		Circle c(3,3,1);
		p = &c;
		p->Inflate(5);
		stop
	}
	stop

//////////////////////////////////////////////////////////////////////

	//������� 7.����������� (union) C++. ������� ����.
	//1.
	//�������� ��������� ������ ��� ��������� ������������� �������� �����:
	//Bin - ��� ��������� �������������
	//Hex - ��� ����������������� �������������
	//Oct - ��� ������������� �������������.
	//��������� 1: - ��� �������� ����������� ������� ����.
	//��������� 2: - ������������� � ����� ��������������� ������� ���� �� ������,
	//��� ��� ��� ��� ����� ������� ����������� (union).
	//2.
	//� ������ ������ ������� ����� Show, ������� ������ �������� �������� �
	//��������������� ����
	//3.
	//����������� ����������� MyByte ������������ ������������ ����������� ��������������
	//����� � ��� �� ��������� ��-�������:
	//�) ��������: ����������, �����������������, ������������, �������� �������� ����� 
	//          � ����� ������, ��������������� ��������� �������� (���� ���� ������������);
	//�) �������� ��������� (��������� ����������� ���������) �����������������,
	//			������������, �������� �����;
	//�) �������� ��������� ��������, ������������ ��� ����������������� �����;

	MyByte byte(0x1f);
	byte.ShowHex();
	byte.ShowBin();
	byte.ShowOct();

	byte.ShowBin();
	byte.ShowBitBin(3);
	byte.ShowBin();
	byte.ShowHex();
	byte.ShowOct();
	byte.SetBit(2, 0);
	byte.ShowBin();
	byte.ShowHex();
	byte.ShowOct();

	byte.SetBit(2, 1);
	byte.ShowBin();
	byte.ShowHex();
	byte.ShowOct();

	byte.SetHex(1, 0xA);
	byte.ShowBin();
	byte.ShowHex();
	byte.ShowOct();
	byte.SetHex(1, 1);
	byte.ShowBin();
	byte.ShowHex();
	byte.ShowOct();

	

	byte.SetOct(1, 4);

	byte.ShowBin();
	byte.ShowHex();
	byte.ShowOct();

	byte.SetOct(1, 3);


	byte.ShowBin();
	byte.ShowHex();
	byte.ShowOct();
	
	//...
	stop




	
	return 0;
}//endmain
