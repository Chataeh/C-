#include"Mtrx.h"
#include"MtrxArray.h"

MtrxArray::MtrxArray(int arraysize)//생성자
{
	mtrxArraySize = arraysize;
	pMtrx = new Mtrx[arraysize];//동적 배열생성

}
MtrxArray::~MtrxArray()
{
	if (pMtrx != NULL)
		delete[]pMtrx;
}

bool MtrxArray::isValidIndex(int index)
{
	if (index < 0 || index >= mtrxArraySize)// 인덱스가 0보다 작거나 배열크기보다 클경우 false
		return false;
	else
		true;
}

Mtrx& MtrxArray::operator[](int sub)
{
	if (isValidIndex(sub))
		return pMtrx[sub];
	else
		cout << "ERROR: Subscript out of range." << endl;
	exit(0);
}
int MtrxArray::getSize()
{
	return mtrxArraySize;
}