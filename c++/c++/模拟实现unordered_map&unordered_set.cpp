#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


template<class T>
struct HashNode
{
	HashNode(const T& data) :_data(data), _next(nullptr)
	{}
	T _data;
	HashNode<T>* _next;

};

//前置声明  因为__HashTableIterator里有HashTable成员，向前找找不到
template<class K, class T, class KOfT, class Hash>
class HashTable; 

template<class K, class T, class KOfT,class Hash>
struct __HashTableIterator
{
	typedef __HashTableIterator<K, T, KOfT,Hash> Sef;
	typedef  HashTable<K, T, KOfT, Hash> HT;
	typedef HashNode<T> Node;
	Node* _node;
	HT* _pht;
	__HashTableIterator(Node* node,HT* pht) :_node(node),_pht(pht)
	{}

	T& operator*()
	{
		return _node->_data;
	}
	T* operator->()
	{
		return &_node->_data;
	}

	//哈希表的++   (重点)
	Sef operator++()
	{
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			//找完一个桶后，找下一个桶
			KOfT koft;
			size_t index = _pht->HashFunc(koft(_node->_data)) % _pht->_tables.size();//_pht->_tables是私有成员，使用友元类
			++index;
			for (; index < _pht->_tables.size(); ++index)
			{
				if (_pht->_tables[index])
				{
					_node = _pht->_tables[index];
					return *this;
				}
			}
			_node = nullptr;
		}
		return *this;
	}

	bool operator!=(const Sef& s)
	{
		return _node != s._node;
	}
};


template<class K, class T, class KOfT, class Hash>
class HashTable
{

public:
	typedef HashNode<T> Node;
	typedef  __HashTableIterator<K, T, KOfT, Hash> iterator;
	friend struct __HashTableIterator<K, T, KOfT, Hash>;
	//找到第一个桶
	iterator begin()
	{
		for (int i = 0; i < _tables.size(); ++i)
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

	pair<iterator,bool> Insert(const T& d)
	{
		KOfT koft;
		//如果负载因子等于1，增容,避免大量的哈希冲突
		//增容:1、开一个2倍的空间出来。 2、将旧表中的数据重新映射到新表 3、释放旧表的空间
		if (_num == _tables.size())
		{
			vector<Node*> newtables;
			//这里扩容的大小给素数是合适的，可以给一个素数数组，扩容时从数组里取
			//利用取余运算时，由于素数作为哈希表的长度，可以产生最分散的余数，从而尽可能减小哈希冲突。
			size_t newsize = _tables.size() == 0 ? 11 : _tables.size() * 2;
			newtables.resize(newsize);
			int i = 0;
			for (i = 0; i < _tables.size(); ++i)
			{
				Node* cur = _tables[i];
				//这里需要把每个旧桶里的数据遍历一遍，不能直接把整个哈希桶放在新表里
				//因为同一个旧桶的数据映射到新表的位置不一定相同
				while (cur)
				{
					Node* next = cur->_next;

					//当K为string之类的类型时，不能进行%操作,需要再加一个防函数,在进行 % 运算的时候使用
					//size_t index = koft(_tables[i]->_data) % newsize;
					size_t index = HashFunc(koft(_tables[i]->_data)) % newsize;

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
		size_t index = HashFunc(koft(d)) % _tables.size();
		Node* cur = _tables[index];
		while (cur)
		{
			if (koft(_tables[index]->_data) == koft(d))
			{
				return make_pair(iterator(cur,this), false);
			}

			cur = cur->_next;
		}

		//2.头插到映射的链表中（尾插也可以，需要找到尾节点）
		Node* newnode = new Node(d);
		newnode->_next = _tables[index];
		_tables[index] = newnode;

		++_num;
		return make_pair(iterator(newnode, this), true);
	}
	//查找时间复杂度为O（1）
	Node* Find(const K& key)
	{
		KOfT koft;
		size_t index = HashFunc(key) % _tables.size();
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
		if (_tables.size() == 0)
		{
			return false;
		}
		KOfT koft;
		size_t index = HashFunc(key) % _tables.size();
		Node* precur = nullptr;
		Node* cur = _tables[index];
		while (cur)
		{
			if (koft(cur->_data) == key)
			{
				if (precur == nullptr)
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

	size_t HashFunc(const K& key)
	{
		Hash hash;
		return hash(key);
	}

	~HashTable()
	{
		Clear();
	}
	void Clear()
	{
		for (int i = 0; i < _tables.size(); ++i)
		{
			Node* cur = _tables[i];
			while (cur)
			{
				Node* next = cur->_next;
				delete cur;
				cur = next;
			}
			_tables[i] = nullptr;
		}
		_num = 0;
	}
private:
	vector<Node*> _tables;
	size_t _num = 0;//表中有效数据的个数
};


namespace cr
{
	template<class K>
	struct __Hash
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};

	//因为string也是常见的类型，
	//在定义unordered_map使用string时并没有使用仿函数，是因为对仿函数进行了特化，让他们使用同一个仿函数
	//特化
	template<>
	struct __Hash<string>
	{
		//字符串哈希算法，把字符串转成整形，例如BKDR Hash
		//BKDR Hash:每次相加后乘以131。 
		//这样让不同的字符串尽量映射在不同的位置
		size_t operator()(const string& str)
		{
			size_t hash = 0;
			for (int i = 0; i < str.length(); ++i)
			{
				hash *= 131;
				hash += str[i];
			}
			return hash;
		}
	};


	template<class K, class Hash = __Hash<K>>
	class unordered_set
	{
		
	public:
		struct KOfSet
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};

		//typename的作用是让编译器知道HashTable<K, K, KOfSet, Hash>是一个类
		typedef typename HashTable<K, K, KOfSet, Hash>::iterator iterator;
		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}

		pair<iterator, bool> insert(const K& k)
		{
			return _ht.Insert(k);
		}

	private:
		HashTable<K, K, KOfSet,Hash> _ht;
	};

	template<class K,class V, class Hash=__Hash<K>>
	class unordered_map
	{
	public:
		struct KOfMap
		{
			const K& operator()(const pair<K,V>& kv)
			{
				return kv.first;
			}
		};
		typedef typename HashTable<K, pair<K, V>, KOfMap, Hash>::iterator iterator;
		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

		V& operator[](const K& k)
		{
			pair<iterator, bool> ret = insert(make_pair(k, V()));
			return ret.first->second;
		}
	private:
		HashTable<K, pair<K, V>, KOfMap,Hash> _ht;
	};
}
void test_unordered_set()
{
	//当前实现的unordered_set与std里的unordered_set遍历顺序不一样，
	//C++11 std里的unordered_set遍历顺序是按照插入的顺序进行遍历（有序）
	//要实现std里的unordered_set遍历顺序，需要在HashNode里加两个结点指针
	//HashNode<T>* _linknext;
	//HashNode<T>* _linkprev;
	//_linknext指向下一个插入的节点，_linkprev指向上一个插入的节点

	cr::unordered_set<int> uset;
	uset.insert(1);
	uset.insert(5);
	uset.insert(2);
	uset.insert(3);
	uset.insert(10);
	uset.insert(6);
	cr::unordered_set<int>::iterator it = uset.begin();
	while (it != uset.end())
	{
		cout << *it << "  ";
		++it;
	}
	cout << endl;

	std::unordered_set<int> uset2;
	uset2.insert(1);
	uset2.insert(5);
	uset2.insert(2);
	uset2.insert(3);
	uset2.insert(10);
	uset2.insert(6);
	unordered_set<int>::iterator it2 = uset2.begin();
	while (it2 != uset2.end())
	{
		cout << *it2 << "  ";
		++it2;
	}
	cout << endl;
}

void test_unordered_map()
{
	cr::unordered_map<string,string> um;
	um.insert(make_pair("string","str"));
	um.insert(make_pair("char", "ch"));
	um.insert(make_pair("abcd", "a"));
	um.insert(make_pair("addd", "b"));
	um.insert(make_pair("aadd", "c"));
	um.insert(make_pair("s", "d"));
	um["s"] = "wdx";
	cr::unordered_map<string, string>::iterator it = um.begin();
	while (it != um.end())
	{
		cout << it->first << "  " << it->second << endl;
		++it;
	}


}
int main()
{
	test_unordered_set();
	test_unordered_map();

	return 0;
}

