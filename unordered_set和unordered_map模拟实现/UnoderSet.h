#pragma once
#include "HashTable.h"

namespace cwx
{
	template<class K, class hash = Hash<K>>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	
	public:
		typedef typename LinkHash::HashTable<K, K, SetKeyOfT, hash>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		bool insert(const K& key)
		{
			return _ht.Insert(key);
		}

	private:
		LinkHash::HashTable<K, K, SetKeyOfT, hash> _ht;
	};

	void test_unordered_set()
	{
		unordered_set<int> us;
		us.insert(2);
		us.insert(22);
		us.insert(23);
		us.insert(24);
		unordered_set<int>::iterator it = us.begin();
		while (it != us.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		unordered_set<string> uss;
		uss.insert("insert");
		uss.insert("map");
		uss.insert("set");
	}
}