#pragma once
#include <vector>
#include <functional>

class date
{
	friend struct LessPDate;
public:
	date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator<(const date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}

	bool operator>(const date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}

	friend ostream& operator<<(ostream& _cout, const date& d);
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
	return _cout;
}

namespace cwx
{
	template<class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue // 默认是大堆
	{
	private:
		void adjust_up(size_t child)
		{
			Compare com;
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				if (com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);

					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void adjust_down(size_t parent)
		{
			Compare com;
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
				{
					++child;
				}
				
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);

					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

	public:
		priority_queue()
		{}

		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			:_con(first, last)
		{
			// 从倒数第一个非叶子结点的子树开始调整，一直调整到子树
			for (size_t i = (_con.size() - 2) / 2; i >= 0; i--)
			{
				adjust_down(i);
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size() - 1);
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}

		const T& top()
		{
			return _con[0];
		}

		size_t size() const
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

	private:
		Container _con;
	};

	void test01()
	{
		priority_queue<int> pq;

		pq.push(3);
		pq.push(4);
		pq.push(1);
		pq.push(9);
		pq.push(7);
		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}

}