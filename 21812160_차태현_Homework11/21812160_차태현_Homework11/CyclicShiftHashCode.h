#ifndef CY_H
#define CY_H

#include<string>

using namespace std;

#define BIT_SHIFTS 5
#define BITS_INT 32

class CyclicShiftHashCode
{
public:
	int operator()(const string key)
	{
		int len = key.length();//���̼���
		unsigned int h = 0;//32��Ʈ�� ����
		for (int i = 0; i < len; i++)//���ڿ� ���̸�ŭ �ݺ�
		{
			h = (h << BIT_SHIFTS) | (h >> (BITS_INT - BIT_SHIFTS));//(h �������� 5��ŭ�̵�) or���� (h ���������� 27���̵�)
			h += (unsigned int)key.at(i);//i��° ��ġ ���ڰ� ������
		}
		return h;//6��Ʈ ũ��� ����
	}
};


#endif