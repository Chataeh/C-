#ifndef M_A_H
#define M_A_H

#include <iostream>
#include"Mtrx.h"

using namespace std;

class Mtrx;

class MtrxArray
{
public:
	MtrxArray(int arraySize);//배열 생성자
	~MtrxArray();//소멸자
	Mtrx& operator[](int);//배열인덱스
	int getSize();//배열크기 반환

private:
	Mtrx* pMtrx;
	int mtrxArraySize;
	bool isValidIndex(int index);
};

#endif