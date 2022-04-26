#pragma once
#include <deque>

namespace cwx
{
	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		queue()
		{}

		size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}

		const T& front() const
		{
			return _con.front();
		}

		const T& back() const
		{
			return _con.back();
		}

		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_front();
		}

	private:
		Container _con;
	};

	void test_queue()
	{
		queue<int> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);
		q.push(5);

		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}

}
