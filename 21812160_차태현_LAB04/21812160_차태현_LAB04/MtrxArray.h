#ifndef M_A_H
#define M_A_H

#include <iostream>
#include"Mtrx.h"

using namespace std;

class Mtrx;

class MtrxArray
{
public:
	MtrxArray(int arraySize);//�迭 ������
	~MtrxArray();//�Ҹ���
	Mtrx& operator[](int);//�迭�ε���
	int getSize();//�迭ũ�� ��ȯ

private:
	Mtrx* pMtrx;
	int mtrxArraySize;
	bool isValidIndex(int index);
};

#endif