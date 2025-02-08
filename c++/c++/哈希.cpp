#include<iostream>
#include<vector>
using namespace std;


/*
顺序结构以及平衡树中，元素关键码与其存储位置之间没有对应的关系，因此在查找一个元素时，必须要经过关键码的多次比较。
顺序查找时间复杂度为O(N)，平衡树中为树的高度，即O($log_2 N$)，搜索的效率取决于搜索过程中元素的比较次数。

理想的搜索方法：可以不经过任何比较，一次直接从表中得到要搜索的元素。
如果构造一种存储结构，通过某种函数(hashFunc)使元素的存储位置与它的关键码之间能够建立一一映射的关系，那么在查找时通过该函数可以很快找到该元素。

该方式即为哈希(散列)方法，哈希方法中使用的转换函数称为哈希(散列)函数，
构造出来的结构称为哈希表(Hash Table)(或者称散列表)
例如：数据集合{1，7，6，4，5，9}；
哈希函数设置为：hash(key) = key % capacity; capacity为存储元素底层空间总的大小

不同关键字通过相同哈希哈数计算出相同的哈希地址，该种现象称为哈希冲突或哈希碰撞。

搜索树还取决于树的高度，也就是说数据量越大效率会逐步降低。
而哈希通过映射关系直接进行查找，效率非常高，那么哈希最大的问题就是如何解决哈希冲突?

直接定制法: 没有哈希冲突,每个值都映射了一个唯一位置
	如果数据分布不均匀，那么我们给每个值映射一个位置,可能会存在巨大的空间浪费

除留余数法: 不再是给每个值映射一个位置，
	在限定大小的空间中将我们的值映射进去。
	index = key % 空间大小
	带来的问题:不同的值可能会映射到相同位置上去,导致哈希冲突。哈希冲突越多整体而言效率就越低。

如何解决哈希冲突呢?

	1、闭散列--开放定制法
	当发生哈希冲突时，如果哈希表未被装满，说明在哈希表中必然还有空位置，那么可以把key存放到冲突位置中的“下一个” 空位置中去。
	(冲突了，那么按规则再给你找个位置,
		a、线性探测(挨着往后找，直到找到空位置)
		b、二次探测(按i^2，跳跃着往后找，直到找到空位置)
	不能随便物理删除哈希表中已有的元素，若直接删除元素会影响其他元素的搜索。
	线性探测采用标记的伪删除法来删除一个元素。使用State

	2、开散列法又叫链地址法(开链法)，首先对关键码集合用散列函数计算散列地址，
	具有相同地址的关键码归于同一子集合，每一个子集合称为一个桶，
	各个桶中的元素通过一个单链表链接起来，各链表的头结点存储在哈希表中。
	开散列中每个桶中放的都是发生哈希冲突的元素。

*/


//闭散列

namespace CLOSE_HASH
{
	enum State
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class T>
	struct HashData
	{
		T _data;
		State _state;
	};

	template<class K, class T, class KOfT>
	class HashTable
	{
		typedef HashData<T> HashData;
	public:
		bool Insert(const T& d)
		{
			/*
			哈希表不会满，会有一个负载因子(一种空间换时间的思路)
			负载因子 = 表中数据 / 表的大小 衡量哈希表满的程度
			表越接近满，插入数据越容易冲突，冲突越多，效率越低
			哈希表并不是满了才增容，闭散列(开放定制法)中，一般负载因子到了0.7左右就开始增容
			负载因子越小，冲突概率越低，整体效率越高，但是负载因子过小，浪费的空间越大，
			所以负载因子一般取一个折中值
			*/
			/*
			KOfT koft;
			if (_tables.size()==0 || _num * 10 / _tables.size() >= 7)
			{
				//增容:1、开一个2倍的空间出来。 2、将旧表中的数据重新映射到新表 3、释放旧表的空间
				vector<HashData> newtable;
				size_t newsize = _tables.size() == 0 ? 10 : 2 * _tables.size();
				newtable.resize(newsize);
				int i = 0;
				for (i = 0; i < _tables.size(); ++i)
				{
					if (_tables[i]._state == EXIST)
					{
						//计算旧表中的数据重新映射到新表的位置
						size_t index = koft(_tables[i]._data) % newtable.size();
						while (newtable[index]._state == EXIST)
						{

							index++;
							if (index == newtable.size())
								index = 0;
						}
						newtable[index] = _tables[i];

					}
				}
				_tables.swap(newtable);
			}
			*/
			if (_tables.size() == 0 || _num * 10 / _tables.size() >= 7)
			{
				//增容:1、开一个2倍的空间出来。 2、将旧表中的数据重新映射到新表 3、释放旧表的空间
				HashTable<K, T, KOfT> newht;
				size_t newsize = _tables.size() == 0 ? 1 : 2 * _tables.size();
				newht._tables.resize(newsize);
				for (int i = 0; i < _tables.size(); ++i)
				{
					if (_tables[i]._state == EXIST)
					{
						newht.Insert(_tables[i]._data);
					}
				}
				_tables.swap(newht._tables);
			}

			KOfT koft;
			//计算d中的key在表中的映射位置
			//state为空或者删除，进行插入

			/*
			//线性探测，依次++index
			size_t index = koft(d) % _tables.size();
			while (_tables[index]._state == EXIST)
			{
				if (koft(_tables[index]._data == koft(d)))
				{
					return false;
				}
				++index;
				if (index == _tables.size())
				{
					index = 0;
				}
			}
			*/
			//二次探测
			//二次探测让冲突的一片数据相对更分散了，不会聚集到一起，形成连片冲突。
			size_t start = koft(d) % _tables.size();
			size_t index = start;
			int i = 1;
			while (_tables[index]._state == EXIST)
			{
				if (koft(_tables[index]._data) == koft(d))
				{
					return false;
				}
				index = start + i * i;
				++i;
				index %= _tables.size();
			}


			_tables[index]._data = d;
			_tables[index]._state = EXIST;
			++_num;
			return true;
		}
		HashData* Find(const K& key)
		{
			KOfT koft;
			int i = 0;
			while (_tables[i].state != EMPTY)
			{
				if (koft(_tables[i]._data) == key) //这时候状态可能为EXIST,或者Delete
				{
					if (_tabels[i]._state == EXIST)
					{
						return &_tables[i];
					}
					//因为哈希表中的key不允许重复，加上Find是从下表0开始找，不会出现两个key值一样的数据，即使state为Delete
					else if (_tabels[i]._state == DELETE)
					{
						return nullptr;
					}
				}
				++i;
				if (i == _tables.size())
				{
					i = 0;
				}
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_num;
				return true;
			}
			return false;
		}

	private:
		vector<HashData> _tables;
		size_t _num = 0;//表中有效数据的数量
	};

	template<class K>
	struct SetKeyOfT
	{
		const K& operator()(const K& k)
		{
			return k;
		}
	};

	void TestHashTable()
	{
		HashTable<int, int, SetKeyOfT<int>> ht;
		ht.Insert(3);
		ht.Insert(13);
		ht.Insert(23);
		ht.Insert(33);
		ht.Insert(43);
		ht.Insert(53);
		ht.Insert(63);
		ht.Insert(73);

	}
}

/*
我们可以看到闭散列-开放定制法不是一种好的解决方式，
因为他是一种我的位置被占了，我就去抢别人的位置思路。
也就是说他的哈希冲突的会互相影响，我冲突占你的，你冲突了占他的，
他冲突了.…，没完没了，整体效率都遍低。

开散列的哈希桶，可以解决上面的问题
我冲突了，我自力更生解决，不占用你的位置，我自己挂起来
*/

//开散列

/*
当大量的数据冲突，这些哈希冲突的数据就会挂在同一个链式桶中，查找时效率就会降低
所以开散列-哈希桶也是要控制哈希冲突的。
如何控制呢?	通过控制负载因子，
不过这里就把空间利用率提高一些，负载因子也可以高一些，一般开散列把负载因子控制到1，会比较好一些
*/
namespace OPEN_HASH
{
	template<class T>
	struct HashNode
	{
		HashNode(const T& data):_data(data),_next(nullptr)
		{}
		T _data;
		HashNode<T>* _next;

	};

	template<class K, class T, class KOfT>
	class HashTable
	{
		typedef HashNode<T> Node;
	public:
		bool Insert(const T& d)
		{
			KOfT koft;
			//如果负载因子等于1，增容,避免大量的哈希冲突
			//增容:1、开一个2倍的空间出来。 2、将旧表中的数据重新映射到新表 3、释放旧表的空间
			if (_num == _tables.size())
			{
				vector<Node*> newtables;
				size_t newsize = _tables.size() == 0 ? 11 : _tables.size() * 2;
				newtables.resize(newsize);
				int i = 0;
				for (i = 0; i < _tables.size(); ++i)
				{
					Node* cur = _tables[i];
					//这里需要把每个旧桶里的数据遍历一遍，不能直接把整个哈希桶放在新表里
					//因为同一个旧桶的数据映射到新表的位置不一定相同
					while(cur)
					{
						Node* next = cur->_next;
						size_t index = koft(_tables[i]->_data) % newsize;
						cur->_next = newtables[index];//头插
						newtables[index] = cur;
						cur = next;
					}
					_tables[i] = nullptr;//swap后让newtables置空
				}
				_tables.swap(newtables);
			}


			//1.先查找表中是不是已经存在d
			//计算映射位置
			size_t index = koft(d) % _tables.size();
			Node* cur = _tables[index];
			while (cur)
			{
				if (koft(_tables[index]->_data) == koft(d))
				{
					return false;
				}
				cur = cur->_next;
			}

			//2.头插到映射的链表中（尾插也可以，需要找到尾节点）
			Node* newnode = new Node(d);
			newnode->_next = _tables[index];
			_tables[index] = newnode;

			++_num;
			return true;
		}
		Node* Find(const K& key)
		{
			KOfT koft;
			size_t index =key % _tables.size();
			Node* cur = _tables[index];
			while (cur)
			{
				if (koft(cur->_data) == key)
				{
					return cur;
				}
				cur = cur->_next;
			}
			
			return nullptr;
		}

		bool Erase(const K& key)
		{	
			KOfT koft;
			size_t index = key % _tables.size();
			Node* precur =  nullptr;
			Node* cur = _tables[index];
			while (cur)
			{
				if (koft(cur->_data) == key)
				{
					if (precur==nullptr)
					{
						//表示删的是第一个节点
						_tables[index] = cur->_next;
					}
					else
					{
						precur->_next = cur->_next;
					}
					delete cur;

					--_num;
					return true;
				}
				precur = cur;
				cur = cur->_next;
			}
			
			return false;
		}

	private:
		vector<Node*> _tables;
		size_t _num = 0;//表中有效数据的个数
	};

	template<class K>
	struct SetKeyOfT
	{
		const K& operator()(const K& k)
		{
			return k;
		}
	};

	void TestHashTable()
	{
		HashTable<int, int, SetKeyOfT<int>> ht;
		ht.Insert(3);
		ht.Insert(11);
		ht.Insert(23);
		ht.Insert(33);
		ht.Insert(41);
		ht.Insert(53);
		ht.Insert(63);
		ht.Insert(81);
		ht.Insert(93);
		ht.Insert(103);
		ht.Insert(123);
		ht.Insert(113);
		ht.Insert(71);
		if (ht.Find(103))
		{
			ht.Erase(103);
		}

		ht.Erase(113);
	}
}

int main()
{

	//CLOSE_HASH::TestHashTable();
	OPEN_HASH::TestHashTable();

	return 0;
}
