#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
布隆过滤器
我们在使用新闻客户端看新闻时，它会给我们不停地推荐新的内容，它每次推荐时要去重，去掉
那些已经看过的内容。问题来了，新闻客户端推荐系统如何实现推送去重的？ 用服务器记录了用
户看过的所有历史记录，当推荐系统推荐新闻时会从每个用户的历史记录里进行筛选，过滤掉那
些已经存在的记录。 如何快速查找呢？
1. 用哈希表存储用户记录，缺点：浪费空间
2. 用位图存储用户记录，缺点：位图一般只能处理整形，如果内容编号是字符串，就无法处理了。
3. 将哈希与位图结合，即布隆过滤器, 将字符串通过字符串哈希算法，转成整形
	优点：节省空间
	问题：存在哈希冲突，哈希冲突解决不了，只能缓解问题
	缓解哈希冲突方法：一个值映射到多个位置，降低冲突的概率，类型不一定是字符串
	提出这种方法的人 叫 布隆


布隆过滤器:
优点:节省空间，高效，可以标记存储任意类型
缺点:存在误判，不支持删除
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

			_bits[index] |= (1 << pos);//第pos位 置1
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

	//BKDR Hash 
	struct HashStr1
	{
		size_t operator()(const string& str)
		{
			int i = 0;
			size_t hash = 0;
			for (i = 0; i < str.length(); ++i)
			{
				hash *= 131;
				hash += str[i];
			}
			return hash;
		}
	};

	//AP Hash 
	struct HashStr2
	{
		size_t operator()(const string& s)
		{
			size_t hash = 0;
			for (long i = 0; i < s.size(); i++)
			{
				if ((i & 1) == 0)
				{
					hash ^= ((hash << 7) ^ s[i] ^ (hash >> 3));
				}
				else
				{
					hash ^= (~((hash << 11) ^ s[i] ^ (hash >> 5)));
				}
			}
			return hash;
		}
	};

	//DJB Hash 
	struct HashStr3
	{
		size_t operator()(const string& s)
		{
			size_t hash = 5381;
			for (auto ch : s)
			{
				hash += (hash << 5) + ch;
			}
			return hash;
		}
	};

	//通过多个仿函数，将同一个K映射到不同的位置上,用的最多的是字符串，所以默认类型为字符串
	template<class K = string,class Hash1= HashStr1,class Hash2= HashStr2,class Hash3= HashStr3>
	class bloomfilter
	{
	public:
		/*
		选择哈希函数个数和布隆过滤器长度
		过小的布隆过滤器很快所有的 bit 位均为 1，那么查询任何值都会返回“可能存在”，起不到过滤的目的了。
		布隆过滤器的长度会直接影响误报率，布隆过滤器越长其误报率越小。

		另外，哈希函数的个数也需要权衡，
		个数越多则布隆过滤器 bit 位置位 1 的速度越快，且布隆过滤器的效率越低；
		但是如果太少的话，那我们的误报率会变高。
		
		如何选择适合业务的 k 和 m 值
		k = m/n * ln2
		k 为哈希函数个数，m 为布隆过滤器长度，n 为插入的元素个数，p 为误报率
		*/
		//这里实现的哈希函数个数k =3；则m=4.3*n  这里选的5
		bloomfilter(size_t num):_bs(5*num),_N(5*num)
		{}

		void set(const K& key)
		{
			//Hash1()是一个匿名对象
			size_t index1 = Hash1()(key) % _N;
			size_t index2 = Hash2()(key) % _N;
			size_t index3 = Hash3()(key) % _N;

			cout << index1 << endl;
			cout << index2 << endl;
			cout << index3 << endl << endl;

			_bs.set(index1);
			_bs.set(index2);
			_bs.set(index3);
		}

		void reset(size_t x)
		{
			//不可以直接置位0，因为一个值有多个映射位置
			// 不支持删除，删除可能会影响其他值。
		}

		bool test(const K& key)
		{
			size_t index1 = Hash1()(key) % _N;
			if (_bs.test(index1) == false)
				return false;
			size_t index2 = Hash2()(key) % _N;
			if (_bs.test(index2) == false)
				return false;
			size_t index3 = Hash3()(key) % _N;
			if (_bs.test(index3) == false)
				return false;

			return true;//这里也不是真正的存在，存在误判

			//判断在，不准确，存在误判
			//判断不在，是准确的
		}
	private:
		bitset _bs;
		size_t _N;
	};
}

void test_bloomfilter()
{
	//cr::bloomfilter<> bf(100);//有缺省值，可以省略类型，但不可省略<>
	cr::bloomfilter<string> bf(100);
	bf.set("abcd");
	bf.set("acbd");
	bf.set("aadd");

	cout << bf.test("abcd");
	cout << bf.test("acbd");
	cout << bf.test("aadd");
}
int main()
{
	test_bloomfilter();
	return 0;
}
