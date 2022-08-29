#include "Date.h"

int Date::GetMonthDay(int year, int month)
{
	static int MonthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = MonthDay[month];

	if (month == 2 && ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
	{
		day++;
	}

	return day;
}

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;

	if (!((year > 0)
		&& (month > 0) && (month < 13)
		&& (day > 0) && (day <= GetMonthDay(year, month))))
	{
		cout << "非法日期->";
		Print();
	}
}

void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

bool Date::operator==(Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator!=(Date& d)
{
	return !(*this == d);
}


bool Date::operator<(Date& d)
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year && _month < d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day < d._day)
	{
		return true;
	}

	return false;
}

bool Date::operator<=(Date& d)
{
	return *this == d || *this < d;
}

bool Date::operator>=(Date& d)
{
	return !(*this < d);
}

bool Date::operator>(Date& d)
{
	return !(*this <= d);
}

Date Date::operator+(int day)
{
	Date ret(*this);
	ret += day;

	return ret;
}

Date& Date::operator+=(int day)
{
	_day += day;

	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;

		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}

	return *this;
}

Date& Date::operator++()
{
	*this += 1;

	return *this;
}

Date& Date::operator++(int)
{
	Date ret = *this;
	*this += 1;

	return ret;
}

Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			_month = 12;
			--_year;
		}

		_day += GetMonthDay(_year, _month);

	}

	return *this;
}

Date Date::operator-(int day)
{
	Date ret(*this);
	ret -= day;

	return ret;
}

int Date::operator-(const Date& d) const
{
	Date max = *this;
	Date min = d;
	int flag = 1;

	if (max < min)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int count = 0;
	while (min != max)
	{
		++min;
		++count;
	}

	return count * flag;


}

void Date::PrintWeekDay() const
{
	const char* arr[] = { "星期一", "星期二", "星期三", "星期四", "星期五", "星期六", "星期日" };

	int count = *this - Date(1970, 1, 1);
	cout << arr[count % 7] << endl;

}