#include"Cmplx.h"
#include"CmplxArray.h"

CmplxArray::CmplxArray(int size) //������
{
	cmplxArraysize = size;
	this->pCA = new Cmplx[size];
	for (int i = 0; i < size; i++)
	{
		this->pCA[i].real = 0.0;//�Ǽ��� �ʱ�ȭ
		this->pCA[i].imag = 0.0;//����� �� �ʱ�ȭ
	}
}

CmplxArray::~CmplxArray()//�Ҹ���
{
	if (cmplxArraysize > 0)
		delete[]pCA;
}

Cmplx& CmplxArray::operator[](int sub)//�迭 ����
{
	if (sub < 0 || sub >= cmplxArraysize)//����� ������ ��� ���
	{
		cout << "ERROR:Subscript out of range." << endl;
		exit(0);
	}
	return pCA[sub];
}

bool isValidIndex(int indx)
{
	if (indx < 0 || indx >=7 )//����� ������ ��� ���
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
void CmplxArray::sort()//��������
{
	int i, j;
	int min_index;
	for ( i = 0; i < cmplxArraysize-1; i++)
	{
		min_index = i;
		for (j = i + 1; j < cmplxArraysize; j++)
		{
			if (pCA->mag() > pCA[j].mag())//���Ҽ��� ũ�⸦ ���Ͽ� ��������
				min_index = j;
		}
		if (min_index != i)
		{
			swap(pCA[i], pCA[min_index]);
		}
	}
}