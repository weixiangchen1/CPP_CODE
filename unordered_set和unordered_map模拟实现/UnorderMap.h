#pragma once
#include "HashTable.h"

namespace cwx
{
	template<class K, class V, class hash = Hash<K>>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename LinkHash::HashTable<K, pair<K, V>, MapKeyOfT, hash>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		bool insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

		bool erase(const K& key)
		{
			return _ht.Erase(key);
		}

		LinkHash::HashNode<pair<K, V>> find(const K& key)
		{
			return _ht.Find(key);
		}

		LinkHash::HashTable<K, pair<K, V>, MapKeyOfT, hash> _ht;
	};

	void test_unordered_map()
	{
		unordered_map<string, string> um;
		um.insert(make_pair("insert", "²åÈë"));
		um.insert(make_pair("sort", "ÅÅĞò"));
		um.insert(make_pair("left", "×ó±ß"));
		um.insert(make_pair("right", "ÓÒ±ß"));
		unordered_map<string, string>::iterator it = um.begin();

		while (it != um.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;
	}
}