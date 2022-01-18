#include"Cmplx.h"
#include"CmplxArray.h"

CmplxArray::CmplxArray(int size) //생성자
{
	cmplxArraysize = size;
	this->pCA = new Cmplx[size];
	for (int i = 0; i < size; i++)
	{
		this->pCA[i].real = 0.0;//실수부 초기화
		this->pCA[i].imag = 0.0;//허수부 값 초기화
	}
}

CmplxArray::~CmplxArray()//소멸자
{
	if (cmplxArraysize > 0)
		delete[]pCA;
}

Cmplx& CmplxArray::operator[](int sub)//배열 생성
{
	if (sub < 0 || sub >= cmplxArraysize)//사이즈가 범위를 벗어날 경우
	{
		cout << "ERROR:Subscript out of range." << endl;
		exit(0);
	}
	return pCA[sub];
}

bool isValidIndex(int indx)
{
	if (indx < 0 || indx >=7 )//사이즈가 범위를 벗어날 경우
	{
		return false;
	}
	else
		return true;
}
void CmplxArray::print(ostream& fout)
{
	fout << pCA;
}
void CmplxArray::sort()//선택정렬
{
	int i, j;
	int min_index;
	for ( i = 0; i < cmplxArraysize-1; i++)
	{
		min_index = i;
		for (j = i + 1; j < cmplxArraysize; j++)
		{
			if (pCA->mag() > pCA[j].mag())//복소수의 크기를 비교하여 선택정렬
				min_index = j;
		}
		if (min_index != i)
		{
			swap(pCA[i], pCA[min_index]);
		}
	}
}