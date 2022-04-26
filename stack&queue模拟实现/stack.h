#pragma once
#include <deque>

namespace cwx
{
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		stack()
		{}

		size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}

		const T& top() const
		{
			return _con.back();
		}

		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

	private:
		Container _con;
	};

	void test_stack()
	{
		stack<int> st;
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		st.push(5);

		while (!st.empty())
		{
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}

}