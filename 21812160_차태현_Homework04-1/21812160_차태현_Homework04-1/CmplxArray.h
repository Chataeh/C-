#ifndef M_A_H
#define M_A_H
#include<iostream>
#include"Cmplx.h"

using namespace std;

class CmplxArray {
public:
	CmplxArray(int size);//생성자
	~CmplxArray();//소멸자
	int size() { return cmplxArraysize; }//복소수배열 크기 반환
	Cmplx& operator[](int);//복소수 배열 생성
	void print(ostream& fout);//출력
	void sort();//선택정렬
private:
	Cmplx* pCA;
	int cmplxArraysize;
	bool isValidIndex(int indx);
};





#endif