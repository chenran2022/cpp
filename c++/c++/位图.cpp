#include<iostream>
#include<vector>

/*
面试题
给40亿个不重复的无符号整数，没排过序。给一个无符号整数，如何快速判断一个数是否在这40亿个数中。【腾讯】
40亿个不重复的无符号整数占16G
1、排序，二分查找
2、set/unordered_set(红黑树/哈希表)存起来再查找
以上方案的问题:数据量太大，放不到内存中

3. 位图解决
数据是否在给定的整形数据中，结果是在或者不在，刚好是两种状态，
那么可以使用一个二进制比特位来代表数据是否存在的信息，如果二进制比特位为1，代表存在;为0代表不存在

所谓位图，就是用每一位来存放某种状态，适用于海量数据，数据无重复的场景
通常是用来判断某个数据存不存在的。

位图的应用
1. 快速查找某个数据是否在一个集合中
2. 排序 + 去重
3. 求两个集合的交集、并集等
4. 操作系统中磁盘块标记

优点:节省空间、效率高
缺点:只能处理整形
*/

namespace cr
{
	class bitset
	{
	public:
		bitset(size_t N)
		{
			_bits.resize(N / 32 + 1, 0);//一个整型32位，要除以32，+1是因为除数只保留整数
			_num = 0;
		}

		void set(size_t x)
		{
			size_t index = x / 32;//x映射的位在第几个整形里
			size_t pos = x % 32;//x映射的位在这个整形的第几位里

			_bits[index] |= (1 << pos);//第pos位置1
			++_num;
		}

		void reset(size_t x)
		{
			size_t index = x / 32;//x映射的位在第几个整形里
			size_t pos = x % 32;//x映射的位在这个整形的第几位里

			_bits[index] &= ~(1 << pos);//第pos位置0
			--_num;
		}

		//判断数据x是否存在
		bool test(size_t x)
		{
			size_t index = x / 32;//x映射的位在第几个整形里
			size_t pos = x % 32;//x映射的位在这个整形的第几位里

			return _bits[index] & (1 << pos);//判断第pos位 是否为1			
		}
	private:
		//int* _bits;
		std::vector<int> _bits;	//使用vector就直接用vector的内置函数
		size_t _num;//映射存储数据的数量		
	};
}

void test_bitset()
{
	cr::bitset bs(100);
	bs.set(99);
	bs.set(98);
	bs.set(97);
	bs.set(1);
	bs.set(2);
	bs.reset(99);
	bs.reset(2);

	for (int i = 0; i < 100; ++i)
	{
		printf("[%d]:%d\n", i, bs.test(i));
	}

	//cr::bitset bs(-1);//因为是size_t  -1表示全1，代表最大数
}
int main()
{
	test_bitset();
	return 0;
}
