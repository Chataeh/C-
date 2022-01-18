#ifndef E_H
#define E_H

#include<iostream>
#include<iomanip>

using namespace std;

template<typename K, typename V>
class Entry//���ø� Ŭ����
{
	friend ostream& operator<<(ostream& fout, Entry<K, V>& entry)
	{
		fout << "[" << entry.getKey() << ", " << *(entry.getValue()) << "]";

		return fout;//fout��ȯ
	}
public:
	Entry(K key, V value) :_key(key), _value(value) { }//������
	Entry() {}//default ������
	~Entry() {}//�Ҹ���
	void setKey(const K& key) { _key = key; }//Ű ����
	void setValue(const V& value) { _value = value; }//��� ����
	K getKey() const { return _key; }//Ű ��ȯ
	V getValue() const { return _value; }//��� ��ȯ
	bool operator>(const Entry<K, V>& right) { return (_key > right.getKey()); }//Ű�� ��Һ�
	bool operator>=(const Entry<K, V>& right) { return (_key >= right.getKey()); }//Ű�� ��Һ�
	bool operator<(const Entry<K, V>& right) { return (_key < right.getKey()); }//Ű�� ��Һ�
	bool operator<=(const Entry<K, V>& right) { return (_key <= right.getKey()); }//Ű�� ��Һ�
	bool operator==(const Entry<K, V>& right) { return ((_key == right.getKey()) && (_value == right.getValue())); }//Ű ��� ����� ������ �Ǻ�
	Entry& operator=(Entry& right);//���� ������
	void fprint(ostream& fout);//���
private:
	K _key;
	V _value;
};
template<typename K, typename V>
Entry<K, V>& Entry<K, V>::operator=(Entry<K, V>& right)
{
	_key = right.getKey();//����
	_value = right.getValue();//����

	return *this;//�ڱ��ڽ� ��ȯ
}


template<typename K, typename V>
void Entry<K, V>::fprint(ostream& fout)//���
{
	fout << "[Key:" << setw(2) << getKey() << ", " << *getValue() << "]";
}

#endif 
