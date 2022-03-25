#pragma once
#include <cstring>
#include <cassert>
namespace myString
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str)),
			_capacity(_size)
		{
			_str = new char[_capacity + 1]; 
			strcpy(_str, str);
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_capacity, s._capacity);
			std::swap(_size, s._size);
		}

		//string(const string& s)
		//	:_size(s._size),
		//	_capacity(s._capacity)
		//{
		//	_str = new char[_capacity + 1];
		//	strcpy(_str, s._str);
		//}

		//现代写法 - 复用
		string(const string& s)
			:_str(nullptr),
			_capacity(0),
			_size(0)
		{
			string tmp(s._str);
			swap(tmp);
		}

		// s3 = s2
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		char* tmp = new char[s._capacity + 1];
		//		strcpy(tmp, s._str);
		//		delete[] _str;
		//		_str = tmp;
		//		_size = s._size;
		//		_capacity = s._capacity;
		//	}

		//	return *this;
		//}

		//现代写法
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		string tmp(s);
		//		swap(tmp._str, _str);
		//	}
		// 
		//	return *this;
		//}

		//现代写法
		string& operator=(string s)
		{
			swap(s);

			return *this;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		size_t size() const
		{ 
			return _size;
		}

		const char* c_str() const
		{
			return _str;
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;

				_str = tmp;
				_capacity = n;
			}
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n <= _capacity)
			{
				_str[n] = '\0';
				_capacity = n;
			}
			else
			{
				if (n > _capacity)
				{
					reserve(n);
				}

				memset(_str + _size, ch, n - _size);
				_size = n;
				_str[_size] = '\0';
			}
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			strcpy(_str + _size, str);
			_size += len;
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		size_t find(char ch)
		{
			for (size_t i = 0; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}

			return npos;
		}

		size_t find(const char* s, size_t pos = 0)
		{
			const char* ptr = strstr(_str+pos, s);
			
			if (ptr == nullptr)
			{
				return npos;
			}
			else
			{
				return ptr - _str;
			}
		}

		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);

			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			size_t end = _size + 1;
			while (pos < end)
			{
				_str[end] = _str[end - 1];
				end--;
			}

			_str[pos] = ch;
			_size++;
		}

		string& insert(size_t pos, const char* s)
		{
			assert(pos <= _size);
			size_t len = strlen(s);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			size_t end = _size + len;
			while (end >= pos + len)
			{
				_str[end] = _str[end - len];
				end--;
			}
			 
			strncpy(_str + pos, s, len);
			_size += len;

			return *this;
		}

		string& erase(size_t pos = 0, size_t len = npos)
		{
			assert(pos < _size);
			if (len == npos || _size - pos > len)
			{
				_str[pos] = '\0';
				_size -= len;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}

			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static const size_t npos;
	};

	const size_t string::npos = -1;

	ostream& operator<<(ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			out << s[i];
		}

		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char ch = in.get();
		while (ch != '\0' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}

		return in;
	}

	bool operator>(const string& s1, const string& s2)
	{
		size_t index1 = 0, index2 = 0;
		while (index1 < s1.size() && index2 < s2.size())
		{
			if (s1[index1] > s2[index2])
			{
				return true;
			}
			else if (s1[index1] < s2[index2])
			{
				return false;
			}
			else
			{
				index1++;
				index2++;
			}
		}

		return s1.size() > s2.size() ? true : false;
	}

	bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}

	bool operator>=(const string& s1, const string& s2)
	{
		return s1 > s2 || s1 == s2;
	}

	bool operator<(const string& s1, const string& s2)
	{
		return !(s1 > s2) && !(s1 == s2);
	}

	bool operator<=(const string& s1, const string& s2)
	{
		return !(s1 > s2);
	}

	bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}

	void test_string01()
	{
		string s1("hello world");
		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

	}

	void test_string02()
	{
		string s1("hello world");
		string s2(s1);
		string s3;
		s3 = s2;

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		cout << s3.c_str() << endl;
	}

	void test_string03()
	{
		string s("hello world");
		s.push_back('x');
		s.append("abcd");

		cout << s.c_str() << endl;
	}

	void test_string04()
	{
		string s1("hello");
		s1 += ' ';
		s1 += "world";

		cout << s1.c_str() << endl;
	}

	void test_string05()
	{
		string s1("hello world");
		s1.insert(0, "aa");

		cout << s1.c_str() << endl;
	}

	void test_string06()
	{
		string s("hello world");
		s.erase(6, 5);

		cout << s.c_str() << endl;

		s.insert(0, "ab");
		cout << s.c_str() << endl;
	}

	void test_string07()
	{
		string s1("abcd");
		string s2("abc");

		cout << (s1 > s2) << endl;
		cout << (s1 >= s2) << endl;
		cout << (s1 == s2) << endl;
		cout << (s1 < s2) << endl;
		cout << (s1 <= s2) << endl;
	}

}
