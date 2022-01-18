#ifndef TE_H
#define TE_H

#include<iostream>
#include<iomanip>

using namespace std;

template<typename K>
class T_Entry//템플릿 클래스
{
	friend ostream& operator<<(ostream& fout, K& entry)
	{
		fout << "[" << entry.getKey()  <<  "]";

		return fout;//fout반환
	}
public:
	T_Entry(K key) { _key = key; }//생성자
	T_Entry() { _key = 999; }//default 생성자
	~T_Entry() {}//소멸자
	void setKey(const K& key) { _key = key; }//키 설정
	K getKey() const { return _key; }//키 반환
	bool operator>(const K& right) { return (_key > right.getKey()); }//키값 대소비교
	bool operator>=(const K & right) { return (_key >= right.getKey()); }//키값 대소비교
	bool operator<(const K& right) { return (_key < right.getKey()); }//키값 대소비교
	bool operator<=(const K& right) { return (_key <= right.getKey()); }//키값 대소비교
	bool operator==(const K& right) { return (_key == right.getKey()); }//키 밸류 값모두 같은지 판별
	K& operator=(K& right);//대입 연산자
	void fprint(ostream& fout);//출력
private:
	K _key;
	
};
template<typename K>
K& T_Entry<K>::operator=(K& right)
{
	_key = right.getKey();//대입

	return *this;//자기자신 반환
}


template<typename K>
void T_Entry<K>::fprint(ostream& fout)//출력
{
	fout << "[Key:" << setw(2) << getKey()  << "]";
}

#endif 
