#pragma once
#include <vector>

namespace bitset
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			_bs.resize(N / 8 + 1, 0);
		}

		void set(size_t x)
		{
			size_t i = x / 8;
			size_t j = x % 8;
			_bs[i] |= (1 << j);
		}

		void reset(size_t x)
		{
			size_t i = x / 8;
			size_t j = x % 8;
			_bs[i] &= (~(1 << j));
		}

		bool test(size_t x)
		{
			size_t i = x / 8;
			size_t j = x % 8;
			return _bs[i] & (1 << j);
		}

	private:
		std::vector<char> _bs;
	};

	void test_bitset()
	{
		bitset<-1> bs;
		bs.set(2);
		bs.set(21);
		bs.set(12);
		bs.set(23);
		bs.set(11);
		bs.set(87);
		bs.set(9);
		bs.set(6);

		cout << bs.test(2) << endl;
		cout << bs.test(11) << endl;
		cout << bs.test(12) << endl;
		cout << bs.test(13) << endl;
		cout << bs.test(14) << endl;
		cout << bs.test(87) << endl;
	}
}

template<size_t N>
class TwoBitSet
{
public:
	void Set(size_t x)
	{
		// 00 -> 01
		if (!_bs1.test(x) && !_bs2.test(x))
		{
			_bs2.set(x);
		}
		// 01 -> 10
		else if (!_bs1.test(x) && _bs2.test(x))
		{
			_bs1.set(x);
			_bs2.reset(x);
		}

		// 10-> 表示已经出现两次及以上，无需处理
	}

	void PrintOnceNum()
	{
		for (size_t i = 0; i < N; ++i)
		{
			if (!_bs1.test(i) && _bs2.test(i))
			{
				cout << i << endl;
			}
		}
	}

private:
	bitset::bitset<N> _bs1;
	bitset::bitset<N> _bs2;
};
	
void TestTwoBitSet()
{
	int a[] = { 99,0,4,50,33,44,2,5,99,0,50,99,50,2 };
	TwoBitSet<100> bs;
	for (auto e : a)
	{
		bs.Set(e);
	}

	bs.PrintOnceNum();
}