#ifndef HAD_H
#define HAD_H

#include"HashMap.h"


template <typename K, typename V>
class HashDict :public HashMap<K, V>//HashMap 상속
{
public:
	typedef typename HashMap<K, V>::Iterator Iterator;
	typedef typename HashMap<K, V>::Entry Entry;

	class Range //범위
	{
	private:
		Iterator _begin;
		Iterator _end;
	public:
		Range() {}//default 생성자
		Range(const Iterator& b, const Iterator& e)//생성자
			:_begin(b), _end(e) {}
		Iterator& begin() { return _begin; }//시작 반환
		Iterator& end() { return _end; }//끝 반환
	};
public:
	HashDict(int capacity = HASH_TABLE_SIZE);//생성자
	Range findAll(const K& k);
	Iterator insert(const K& k, const V& v);
};
template<typename K, typename V>
HashDict<K, V>::HashDict(int capacity)
	:HashMap<K, V>(capacity)
{

}

template<typename K, typename V>
typename HashDict<K, V>::Iterator HashDict<K, V>::insert(const K& k, const V& v)
{
	Iterator p = this->_find(k);//위치 찾기
	Iterator q = this->_insert(p, Entry(k, v));//삽입

	return q;
}

template<typename K, typename V>
typename HashDict<K, V>::Range HashDict<K, V>::findAll(const K& k)//k에 대한 모든 Entry 탐색
{
	Iterator b = this->_find(k);//위치 찾기
	Iterator p = b;
	while (p != this->end() && (*p).getKey() == k)//끝이 아니고 키값이 같은경우
	{
		++p;
	}
	return Range(b, p);//b는 _begin p는 _end
}

#endif // !HAD_H
