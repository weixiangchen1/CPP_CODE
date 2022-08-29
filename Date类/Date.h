#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1);
	void Print();
	int GetMonthDay(int year, int month);
	bool operator>(Date& d);
	bool operator<(Date& d);
	bool operator>=(Date& d);
	bool operator<=(Date& d);
	bool operator==(Date& d);
	bool operator!=(Date& d);
	Date operator+(int day);
	Date& operator+=(int day);
	Date operator-(int day);
	Date& operator-=(int day);
	Date& operator++();
	Date& operator++(int);
	int operator-(const Date& d) const;
	void PrintWeekDay() const;

private:
	int _year;
	int _month;
	int _day;
};