#ifndef M_A_H
#define M_A_H
#include<iostream>
#include"Cmplx.h"

using namespace std;

class CmplxArray {
public:
	CmplxArray(int size);//������
	~CmplxArray();//�Ҹ���
	int size() { return cmplxArraysize; }//���Ҽ��迭 ũ�� ��ȯ
	Cmplx& operator[](int);//���Ҽ� �迭 ����
	void print(ostream& fout);//���
	void sort();//��������
private:
	Cmplx* pCA;
	int cmplxArraysize;
	bool isValidIndex(int indx);
};





#endif