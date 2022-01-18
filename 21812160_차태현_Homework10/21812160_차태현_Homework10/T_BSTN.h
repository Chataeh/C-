#ifndef TB_H
#define TB_H

#include"T_Entry.h"
#include<string>
#include<iostream>
#include<iomanip>

using namespace std;

template<typename K, typename V>
class T_BSTN
{
public:
	T_BSTN() :entry(), pPr(NULL), pLc(NULL), pRc(NULL) {}//default 생성자
	T_BSTN(T_Entry<K, V> e) :entry(e), pPr(NULL), pLc(NULL), pRc(NULL) {}//생성자
	K getKey() { return entry.getKey(); }//키 반환
	V getValue() { return entry.getValue(); }//값 반환
	T_Entry<K, V>& getEntry() { return entry; }//원소 
	T_BSTN<K, V>* getpPr() { return pPr; }//부모 
	T_BSTN<K, V>* getpLc() { return pLc; }//왼쪽자식 
	T_BSTN<K, V>* getpRc() { return pRc; }//오른쪽 자식 
	T_BSTN<K, V>** getppLc() { return &pLc; }//왼쪽자식 주소
	T_BSTN<K, V>** getppRc() { return &pRc; }//오른쪽 자식 주소
	void setpPr(T_BSTN<K, V>* pTN) { pPr = pTN; }//부모 값 설정
	void setpLc(T_BSTN<K, V>* pTN) { pLc = pTN; }//왼쪽자식 값 설정
	void setpRc(T_BSTN<K, V>* pTN) { pRc = pTN; }//오른쪽 자식 값설정
	T_Entry<K, V>& operator* () { return entry; }
private:
	T_Entry<K, V> entry;//원소
	T_BSTN<K, V>* pPr;//부모
	T_BSTN<K, V>* pLc;//왼쪽자식
	T_BSTN<K, V>* pRc;//오른쪽 자식
};

#endif TB_H
