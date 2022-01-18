#ifndef TE_H
#define TE_H

#include<iostream>
#include<iomanip>

using namespace std;

template<typename K>
class T_Entry//���ø� Ŭ����
{
	friend ostream& operator<<(ostream& fout, K& entry)
	{
		fout << "[" << entry.getKey()  <<  "]";

		return fout;//fout��ȯ
	}
public:
	T_Entry(K key) { _key = key; }//������
	T_Entry() { _key = 999; }//default ������
	~T_Entry() {}//�Ҹ���
	void setKey(const K& key) { _key = key; }//Ű ����
	K getKey() const { return _key; }//Ű ��ȯ
	bool operator>(const K& right) { return (_key > right.getKey()); }//Ű�� ��Һ�
	bool operator>=(const K & right) { return (_key >= right.getKey()); }//Ű�� ��Һ�
	bool operator<(const K& right) { return (_key < right.getKey()); }//Ű�� ��Һ�
	bool operator<=(const K& right) { return (_key <= right.getKey()); }//Ű�� ��Һ�
	bool operator==(const K& right) { return (_key == right.getKey()); }//Ű ��� ����� ������ �Ǻ�
	K& operator=(K& right);//���� ������
	void fprint(ostream& fout);//���
private:
	K _key;
	
};
template<typename K>
K& T_Entry<K>::operator=(K& right)
{
	_key = right.getKey();//����

	return *this;//�ڱ��ڽ� ��ȯ
}


template<typename K>
void T_Entry<K>::fprint(ostream& fout)//���
{
	fout << "[Key:" << setw(2) << getKey()  << "]";
}

#endif 
