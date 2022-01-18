#ifndef TE_H
#define TE_H

#include<iostream>
#include<iomanip>

using namespace std;

template<typename K, typename V>
class T_Entry//템플릿 클래스
{
	friend ostream& operator<<(ostream& fout, T_Entry<K, V>& entry)
	{
		fout << "(" <<setw(8)<< entry.getKey() << ", " << *(entry.getValue()) << ")";

		return fout;//fout반환
	}
public:
	T_Entry(K key, V value) { _key = key, _value = value; }//생성자
	T_Entry() {}//default 생성자
	~T_Entry() {}//소멸자
	void setKey(const K& key) { _key = key; }//키 설정
	void setValue(const V& value) { _value = value; }//밸류 설정
	K getKey() const { return _key; }//키 반환
	V getValue() const { return _value; }//밸류 반환
	bool operator>(const T_Entry<K, V>& right) { return (_key > right.getKey()); }//키값 대소비교
	bool operator>=(const T_Entry<K, V>& right) { return (_key >= right.getKey()); }//키값 대소비교
	bool operator<(const T_Entry<K, V>& right) { return (_key < right.getKey()); }//키값 대소비교
	bool operator<=(const T_Entry<K, V>& right) { return (_key <= right.getKey()); }//키값 대소비교
	bool operator==(const T_Entry<K, V>& right) { return ((_key == right.getKey()) && (_value == right.getValue())); }//키 밸류 값모두 같은지 판별
	T_Entry& operator=(T_Entry& right);//대입 연산자
	void fprint(ostream& fout);//출력
private:
	K _key;
	V _value;
};
template<typename K, typename V>
T_Entry<K, V>& T_Entry<K, V>::operator=(T_Entry<K, V>& right)
{
	_key = right.getKey();//대입
	_value = right.getValue();//대입

	return *this;//자기자신 반환
}


template<typename K, typename V>
void T_Entry<K, V>::fprint(ostream& fout)//출력
{
	fout << "[Key:" << setw(2) << getKey() << ", " << *getValue() << "]";
}

#endif 
