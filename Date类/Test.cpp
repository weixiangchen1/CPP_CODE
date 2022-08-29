#include "Date.h"

void TestDate1()
{
	Date d1(2022, 1, 32);
	Date d2(2022, 2, 29);
	Date d3(2020, 2, 29);
	Date d4(2000, 2, 29);
}

void TestDate2()
{
	Date d1(2000, 2, 29);
	d1 += 100;
	d1.Print();

	Date ret = d1 + 100;
	ret.Print();
}

void TestDate3()
{
	Date d1(2022, 2, 13);
	d1++;
	d1.Print();

	++d1;
	d1.Print();
}

void TestDate4()
{
	Date d1(2022, 2, 1);
	Date d2(2022, 3, 4);

	int sub1 = d2 - d1;
	cout << sub1 << endl;
	int sub2 = d1 - d2;
	cout << sub2 << endl;

}

int main()
{
	//TestDate1();
	//TestDate2();
	//TestDate3();
	TestDate4();
}