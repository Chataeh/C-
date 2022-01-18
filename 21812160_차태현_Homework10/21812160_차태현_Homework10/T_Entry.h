#ifndef TE_H
#define TE_H

#include<iostream>
#include<iomanip>

using namespace std;

template<typename K, typename V>
class T_Entry//���ø� Ŭ����
{
	friend ostream& operator<<(ostream& fout, T_Entry<K, V>& entry)
	{
		fout << "(" <<setw(8)<< entry.getKey() << ", " << *(entry.getValue()) << ")";

		return fout;//fout��ȯ
	}
public:
	T_Entry(K key, V value) { _key = key, _value = value; }//������
	T_Entry() {}//default ������
	~T_Entry() {}//�Ҹ���
	void setKey(const K& key) { _key = key; }//Ű ����
	void setValue(const V& value) { _value = value; }//��� ����
	K getKey() const { return _key; }//Ű ��ȯ
	V getValue() const { return _value; }//��� ��ȯ
	bool operator>(const T_Entry<K, V>& right) { return (_key > right.getKey()); }//Ű�� ��Һ�
	bool operator>=(const T_Entry<K, V>& right) { return (_key >= right.getKey()); }//Ű�� ��Һ�
	bool operator<(const T_Entry<K, V>& right) { return (_key < right.getKey()); }//Ű�� ��Һ�
	bool operator<=(const T_Entry<K, V>& right) { return (_key <= right.getKey()); }//Ű�� ��Һ�
	bool operator==(const T_Entry<K, V>& right) { return ((_key == right.getKey()) && (_value == right.getValue())); }//Ű ��� ����� ������ �Ǻ�
	T_Entry& operator=(T_Entry& right);//���� ������
	void fprint(ostream& fout);//���
private:
	K _key;
	V _value;
};
template<typename K, typename V>
T_Entry<K, V>& T_Entry<K, V>::operator=(T_Entry<K, V>& right)
{
	_key = right.getKey();//����
	_value = right.getValue();//����

	return *this;//�ڱ��ڽ� ��ȯ
}


template<typename K, typename V>
void T_Entry<K, V>::fprint(ostream& fout)//���
{
	fout << "[Key:" << setw(2) << getKey() << ", " << *getValue() << "]";
}

#endif 
