#pragma once
#include "reverse_iterator.h"
namespace myList
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;
		typedef reverse_iterator<iterator, T&, T*> reverse_iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const 
		{
			return _finish;
		}

		vector()
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr)
		{}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		vector(const vector<T>& v)
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}

		vector<T>& operator=(vector<T> v)
		{
			swap(v);

			return *this;
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		const T& operator[](size_t i) const
		{
			assert(i < size());
			return _start[i];
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					// memcpy会造成浅拷贝，析构会报错
					// memcpy(tmp, _start, sizeof(T) * size());
					for (size_t i = 0; i < sz; ++i)
					{
						tmp[i] = _start[i];
					}

					delete _start;
				}

				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}

		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}

				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}

			*_finish = x;
			++_finish; 
		}

		void pop_back()
		{
			assert(_finish > _start);
			
			--_finish;
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);

			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*(pos) = x;
			++_finish;

			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);

			iterator begin = pos + 1;
			while (begin < _finish)
			{
				*(begin - 1) = *begin;
				begin++;
			}
			--_finish;

			return pos;
		}

		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

	class Solution {
	public:
		vector<vector<int>> generate(int numRows) {
			vector<vector<int>> vv;
			vv.resize(numRows);
			for (int i = 0; i < numRows; ++i)
			{
				vv[i].resize(i + 1);
				vv[i][0] = 1;
				vv[i][vv[i].size() - 1] = 1;
			}

			for (int i = 0; i < numRows; ++i)
			{
				for (int j = 0; j < vv[i].size(); ++j)
				{
					if (vv[i][j] == 0)
					{
						vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
					}
				}
			}

			return vv;
		}
	};

	void test_vector01()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

		for (auto x : v)
		{
			cout << x << " ";
		}
		cout << endl;
	}

	void test_vector02()
	{
		vector<vector<int>> vv = Solution().generate(5);

		for (int i = 0; i < vv.size(); ++i)
		{
			for (int j = 0; j < vv[i].size(); ++j)
			{
				cout << vv[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	void test_vector03()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		vector<int> v2(v1);
		vector<int> v3 = v2;

		for (auto x : v1)
		{
			cout << x << " ";
		}
		cout << endl;

		for (auto x : v2)
		{
			cout << x << " ";
		}
		cout << endl;

		for (auto x : v3)
		{
			cout << x << " ";
		}
		cout << endl;

	}

	void test_vector04()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		vector<int>::iterator it = find(v1.begin(), v1.end(), 2);
		if (it != v1.end())
		{
			v1.insert(it, 20);
		}

		for (auto x : v1)
		{
			cout << x << " ";
		}
		cout << endl;

	}

	void test_vector05()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		// 删除偶数
		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			if (*it % 2 == 0)
			{
				v1.erase(it);
			}
			else
			{
				it++;
			}
		}

		for (auto x : v1)
		{
			cout << x << " ";
		}
		cout << endl;

	}

	void test_vector06()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		vector<int>::reverse_iterator rit = v1.rbegin();
		while (rit != v1.rend())
		{
			cout << *rit << " ";
			++rit;
		}
		cout << endl;
	}

}