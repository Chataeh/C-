#include"Mtrx.h"
#include"MtrxArray.h"

MtrxArray::MtrxArray(int arraysize)//������
{
	mtrxArraySize = arraysize;
	pMtrx = new Mtrx[arraysize];//���� �迭����

}
MtrxArray::~MtrxArray()
{
	if (pMtrx != NULL)
		delete[]pMtrx;
}

bool MtrxArray::isValidIndex(int index)
{
	if (index < 0 || index >= mtrxArraySize)// �ε����� 0���� �۰ų� �迭ũ�⺸�� Ŭ��� false
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