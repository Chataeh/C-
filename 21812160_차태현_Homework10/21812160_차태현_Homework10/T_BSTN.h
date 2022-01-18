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
	T_BSTN() :entry(), pPr(NULL), pLc(NULL), pRc(NULL) {}//default ������
	T_BSTN(T_Entry<K, V> e) :entry(e), pPr(NULL), pLc(NULL), pRc(NULL) {}//������
	K getKey() { return entry.getKey(); }//Ű ��ȯ
	V getValue() { return entry.getValue(); }//�� ��ȯ
	T_Entry<K, V>& getEntry() { return entry; }//���� 
	T_BSTN<K, V>* getpPr() { return pPr; }//�θ� 
	T_BSTN<K, V>* getpLc() { return pLc; }//�����ڽ� 
	T_BSTN<K, V>* getpRc() { return pRc; }//������ �ڽ� 
	T_BSTN<K, V>** getppLc() { return &pLc; }//�����ڽ� �ּ�
	T_BSTN<K, V>** getppRc() { return &pRc; }//������ �ڽ� �ּ�
	void setpPr(T_BSTN<K, V>* pTN) { pPr = pTN; }//�θ� �� ����
	void setpLc(T_BSTN<K, V>* pTN) { pLc = pTN; }//�����ڽ� �� ����
	void setpRc(T_BSTN<K, V>* pTN) { pRc = pTN; }//������ �ڽ� ������
	T_Entry<K, V>& operator* () { return entry; }
private:
	T_Entry<K, V> entry;//����
	T_BSTN<K, V>* pPr;//�θ�
	T_BSTN<K, V>* pLc;//�����ڽ�
	T_BSTN<K, V>* pRc;//������ �ڽ�
};

#endif TB_H
