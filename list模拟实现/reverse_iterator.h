#pragma once
namespace myList
{
	template<class Iterator, class Ref, class Ptr>
	//template<class Iterator>
	class reverse_iterator
	{
		typedef reverse_iterator<Iterator, Ref, Ptr> self;
		//typedef reverse_iterator<Iterator> self;
	public:
		reverse_iterator(Iterator it)
			:_it(it)
		{}

		//typename Iterator::pointer operator->()
		//{
		//	return &operator*();
		//}

		//typename Iterator::reference operator*()
		//{
		//	Iterator prev = _it;
		//	return *--prev;
		//}

		Ptr operator->()
		{
			return &operator*();
		}

		Ref operator*()
		{
			Iterator prev = _it;
			return *--prev;
		}
		self& operator++()
		{
			--_it;
			return *this;
		}

		self& operator--()
		{
			++_it;
			return *this;
		}

		bool operator!=(const self& rit) const
		{
			return _it != rit._it;
		}

	private:
		Iterator _it;
	};
}