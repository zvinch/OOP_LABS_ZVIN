
#include"list.h"


int main()
{
	myList stuuf;

	stuuf.add(Circle(Point(1, 2), 8));
	stuuf.add(Circle(Point(3, 4), 9));
	stuuf.add(Circle(Point(11, 12), 2));
	//stuuf.add(Circle(Point(5, 6), 4));
	//stuuf.add(Circle(Point(7, 8), 7));
	//stuuf.add(Circle(Point(9, 10), 4));
	////std::cout << stuuf;
	//stuuf.add(Circle(Point(13, 14), 5));
	////std::cout << stuuf;
	//stuuf.append(Circle(Point(15, 16), 6));
	////std::cout << stuuf;
	//stuuf.add(Circle(Point(17, 18), 5));
	////std::cout << stuuf;
	//stuuf.add(Circle(Point(19, 19), 5));
	//std::cout << stuuf;
	//stuuf.seekanddestroyGREEDY(Circle(Point(5, 5), 5));
	//std::cout << stuuf;

	//std::cout <<"Функция вернула = " << stuuf.seekanddestroyALL(Circle(Point(5, 5), 5))<<std::endl<< stuuf;
	//std::cout << "Функция вернула = " << stuuf.seekanddestroyALL(Circle(Point(10, 10), 10)) << std::endl << stuuf;
	//myList list2(stuuf);

	stuuf.add(Rect(1,2,3,4, GREEN));
	stuuf.add(Rect(1, 2, 3333, 80, RED));

	std::cout << stuuf;
	stuuf.SelectionsortByAreaASC();
	std::cout << stuuf;

	stuuf.Selectionsort(Shape::areaCompare);
	std::cout << stuuf;
	stuuf.Selectionsort(Shape::coordCompare);
	std::cout << stuuf;
	stuuf.Selectionsort(Shape::colorCompare);
	std::cout << stuuf;
	stuuf.Selectionsort(Shape::areaCompare);
	std::cout << stuuf;
	//std::cout << list2;
	//std::cout << stuuf;

	//myList list3 =std::move(list2);

	std::ofstream ofile;
	ofile.open("List dump.txt");
	ofile << stuuf;
	ofile.close();

	std::ifstream ifile;
	ifile.open("List dump.txt");
	myList ilist(ifile);
	std::cout << ilist;
	ifile.close();

	ilist.add(Circle(Point(589, 367), 450));
	ilist.add(Circle(Point(89, 36), 45));
	ilist.add(Circle(Point(9, 6), 2));

	std::cout << ilist;
	ilist.SelectionsortByAreaASC();
	std::cout << ilist;





	myList smallList;
	smallList.append(Circle(Point(589, 367), 450));
	smallList.add(Circle(Point(89, 36), 45));


	myList bigList;
	bigList.append(Circle(Point(589, 367), 450));
	bigList.append(Circle(Point(5, 37), 40));
	bigList.add(Rect(1, 2, 3333, 80, RED));

	std::cout << smallList;
	std::cout << bigList;

	//smallList = bigList;
	bigList = smallList;
	std::cout << smallList;
	std::cout << bigList;

	stuuf.clear();
	std::cout << stuuf;

	return 0;

}	