#pragma once
#include <vector>
#include <string>

template<class K>
struct Hash
{
	size_t operator()(const K& key)
	{
		return key;
	}
};

// 模板全特化
template<>
struct Hash<string>
{
	size_t operator()(const string& s)
	{
		size_t value = 0;
		for (auto e : s)
		{
			value *= 31;
			value += e;
		}

		return value;
	}
};

namespace LinkHash
{
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};

	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable;

	template<class K, class T, class Ref, class Ptr, class KeyOfT, class HashFunc>
	struct __HashTableIterator
	{
		typedef HashNode<T> Node;
		Node* _node;
		HashTable<K, T, KeyOfT, HashFunc>* _pht;

		typedef __HashTableIterator<K, T, Ref, Ptr, KeyOfT, HashFunc> Self;
		
		__HashTableIterator(Node* node, HashTable<K, T, KeyOfT, HashFunc>* pht)
			:_node(node)
			, _pht(pht)
		{}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		Self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				KeyOfT kot;
				HashFunc hf;
				Node* cur = _node;
				size_t index = hf(kot(cur->_data)) % _pht->_tables.size();
				++index;

				while (index < _pht->_tables.size())
				{
					if (_pht->_tables[index])
					{
						break;
					}
					else
					{
						++index;
					}
				}

				if (index == _pht->_tables.size())
				{
					_node = nullptr;
				}
				else
				{
					_node = _pht->_tables[index];
				}

				return *this;
			}
		}

		bool operator==(const Self& s)
		{
			return _node == s._node;
		}

		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}
	};

	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable
	{
		typedef HashNode<T> Node;

		template<class K, class T, class Ref, class Ptr, class KeyOfT, class HashFunc>
		friend struct __HashTableIterator;
	public:
		typedef __HashTableIterator<K, T, T&, T*, KeyOfT, HashFunc> iterator;

		iterator begin()
		{
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				if (_tables[i])
				{
					return iterator(_tables[i], this);
				}
			}

			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		bool Erase(const K& key)
		{
			if (_tables.empty())
			{
				return false;
			}

			KeyOfT kot;
			HashFunc hf;
			size_t index = hf(kot(key)) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[index];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					if (prev == nullptr)
					{
						_tables[index] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}

					delete cur;
					--_n;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}

			}
			return false;
		}

		HashNode<T>* Find(const K& key)
		{
			KeyOfT kot;
			if (_tables.empty())
			{
				return nullptr;
			}

			HashFunc hf;
			size_t index = hf(key) % _tables.size();

			HashNode<T>* cur = _tables[index];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return cur;
				}
				else
				{
					cur = cur->_next;
				}
			}

			return nullptr;
		}

		bool Insert(const T& data)
		{
			KeyOfT kot;
			Node* res = Find(kot(data));
			if (res)
				return false;

			HashFunc hf;
			if (_n == _tables.size())
			{
				// 平衡因子等于1，扩容
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newTable;
				newTable.resize(newSize);

				for (size_t i = 0; i < _tables.size(); ++i)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t index = hf(kot(cur->_data)) % newTable.size();

						cur->_next = newTable[index];
						newTable[index] = cur;

						cur = next;
					}

					_tables[i] = nullptr;
				}
				_tables.swap(newTable);
			}

			size_t index = hf(kot(data)) % _tables.size();
			Node* newnode = new Node(data);
			// 头插
			newnode->_next = _tables[index];
			_tables[index] = newnode;

			++_n;
			return true;
		}

	private:
		vector<Node*> _tables;
		size_t _n = 0;
	};

}