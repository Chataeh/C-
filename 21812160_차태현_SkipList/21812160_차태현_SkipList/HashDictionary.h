#ifndef HAD_H
#define HAD_H

#include"HashMap.h"


template <typename K, typename V>
class HashDict :public HashMap<K, V>//HashMap ���
{
public:
	typedef typename HashMap<K, V>::Iterator Iterator;
	typedef typename HashMap<K, V>::Entry Entry;

	class Range //����
	{
	private:
		Iterator _begin;
		Iterator _end;
	public:
		Range() {}//default ������
		Range(const Iterator& b, const Iterator& e)//������
			:_begin(b), _end(e) {}
		Iterator& begin() { return _begin; }//���� ��ȯ
		Iterator& end() { return _end; }//�� ��ȯ
	};
public:
	HashDict(int capacity = HASH_TABLE_SIZE);//������
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
	Iterator p = this->_find(k);//��ġ ã��
	Iterator q = this->_insert(p, Entry(k, v));//����

	return q;
}

template<typename K, typename V>
typename HashDict<K, V>::Range HashDict<K, V>::findAll(const K& k)//k�� ���� ��� Entry Ž��
{
	Iterator b = this->_find(k);//��ġ ã��
	Iterator p = b;
	while (p != this->end() && (*p).getKey() == k)//���� �ƴϰ� Ű���� �������
	{
		++p;
	}
	return Range(b, p);//b�� _begin p�� _end
}

#endif // !HAD_H
