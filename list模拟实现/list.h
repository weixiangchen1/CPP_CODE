#pragma once
#include "reverse_iterator.h"
namespace myList
{
	template <class T>
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _data;

		ListNode(const T& data = T())
			:_next(nullptr),
			_prev(nullptr),
			_data(data)
		{}

	};

	template <class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef ListNode<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;
		//typedef Ref reference;
		//typedef Ptr pointer;
		Node* _node;

		__list_iterator(Node* x)
			:_node(x)
		{}
		// it1 = it2 属于浅拷贝
		// 拷贝构造和赋值重载无需自己实现

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		bool operator!=(const self& it) const
		{
			return _node != it._node;
		}

		bool operator==(const self & it) const
		{
			return _node == it._node;
		}
	};


	template <class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		typedef reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;
		typedef reverse_iterator<iterator, T&, T*> reverse_iterator;
		//typedef reverse_iterator<const_iterator> const_reverse_iterator;
		//typedef reverse_iterator<iterator> reverse_iterator;
		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(_head);
		}

		reverse_iterator rend()
		{
			return reverse_iterator(_head->_next);
		}

		list()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
		}

		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;

			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(const list<T>& lt)
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;

			list<T> tmp(lt.begin(), lt.end());
			std::swap(_head, tmp._head);
		}

		list<T>& operator=(list<T>& lt)
		{
			std::swap(_head, lt._head);
			return *this;
		}

		// 传统写法
		//list(const list<T>& lt)
		//{
		//	_head = new Node();
		//	_head->_next = _head;
		//	_head->_prev = _head;

		//	for (auto e : lt)
		//	{
		//		push_back(e);
		//	}
		//}

		//list<T>& operator=(const list<T>& lt)
		//{
		//	if (this != &lt)
		//	{
		//		clear();
		//		for (auto e : lt)
		//		{
		//			push_back(e);
		//		}
		//	}

		//	return *this;
		//}

		void clear()
		{
			iterator it = begin();

			while (it != end())
			{
				iterator del = it++;
				erase(del);
			}

			_head->_next = _head;
			_head->_prev = _head;

		}

		~list()
		{
			clear();

			delete _head;
			_head = nullptr;
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void push_back(const T& x)
		{
			Node* tail = _head->_prev;
 			Node* newnode = new Node(x);
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}

		void pop_front()
		{
			erase(begin());
		}

		void pop_back()
		{
			erase(--end());
		}
		
		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			return iterator(newnode);
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());

			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;
			delete pos._node;
			prev->_next = next;
			next->_prev = prev;

			return iterator(next);
		}

	private:
		Node* _head;
	};

	void testList1()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
		l1.push_back(5);

		list<int>::iterator it = l1.begin();
		while (it != l1.end())
		{
			cout << *it << " ";
			it++;
		}

	}

	void testList2()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
		l1.push_back(5);

		list<int> l2(l1);
		for (auto e : l2)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> l3;
		l3 = l1;
		for (auto e : l3)
		{
			cout << e << " ";
		}
		cout << endl;

	}

	void testList3()
	{
		struct Date
		{
			int _year;
			int _month;
			int _day;

			Date()
			{}

			Date(int year, int month, int day)
			{
				_year = year;
				_month = month;
				_day = day;
			}
		};

		list<Date> l1;
		l1.push_back(Date(2022, 4, 20));
		l1.push_back(Date(2022, 4, 20));
		l1.push_back(Date(2022, 4, 20));
		l1.push_back(Date(2022, 4, 20));
		l1.push_back(Date(2022, 4, 20));

		list<Date>::iterator it = l1.begin();
		while (it != l1.end())
		{
			cout << (*it)._day << "-" << (*it)._month << "-" << (*it)._year << endl;
			it++;
		}

		while (it != l1.end())
		{
			cout << it->_day << "-" << it->_month << "-" << it->_year << endl;
			it++;
		}
	}

	void testList5()
	{
		list<int> lt1;
		lt1.push_front(5);
		lt1.push_front(4);
		lt1.push_front(3);
		lt1.push_front(2);
		lt1.push_front(1);

		list<int>::iterator it = lt1.begin();
		while (it != lt1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		list<int>::reverse_iterator rit = lt1.rbegin();
		while (rit != lt1.rend())
		{
			cout << *rit << " ";
			++rit;
		}
		cout << endl;

	}
}