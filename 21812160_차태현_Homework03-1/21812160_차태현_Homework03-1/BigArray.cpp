#include<iostream>
#include<iomanip>
#include<time.h>
#include<stdlib.h>
#include "Class_BigArray.h"

using namespace std;

BigArray::BigArray(int n)
{
	num_elements = n;
	
	big_array = (int*)new int[num_elements];//�����迭 ����
}

BigArray::~BigArray()
{
	/*
	if (big_array != NULL)
		delete[]big_array;*/
}

void BigArray::genBigRandArray(int base_offset)//��������
{
	char* flag;//�ߺ����Ÿ� ����
	int count = 0;
	int big_rand, biased_big_rand;

	srand(time(NULL));

	flag = (char*)new char[num_elements];//�����迭 ����

	while (count < num_elements)
	{
		big_rand = ((rand() << 15) | rand()) % num_elements;//ūũ���� ��������
		//�ߺ�Ȯ�� ����
		if (flag[big_rand] == 1)
			continue;
		else
		{
			flag[big_rand] = 1;
			biased_big_rand = big_rand + base_offset;
			big_array[count] = biased_big_rand;//���� ����
			count++;
		}

	}
	delete[] flag;
}

void BigArray::getStatistics(ArrayStatistics& stats)//������� ���
{
	int min = INT_MAX;
	int max = INT_MIN;
	int data;

	double sum = 0.0;
	double sq_sum_avg = 0.0;
	double diff_sq_sum = 0.0;

	for (int i = 0; i < num_elements; i++)
	{
		data = big_array[i];
		sum += data;

		if (data < min)//�ּҰ� ã��
			min = data;
		if (data > max)//�ִ밪 ã��
			max = data;

	}
	stats.avg = sum / (double)num_elements;

	for (int i = 0; i < num_elements; i++)
	{
		data = big_array[i];
		diff_sq_sum += (data - stats.avg) * (data - stats.avg);
	}
	stats.var = diff_sq_sum / (double)num_elements;//�л� ���
	stats.std_dev = sqrt(stats.var);//ǥ������ ���
	stats.min = min;
	stats.max = max;
}

void BigArray::fprintStatistics(ostream& fout)//������� ���
{
	ArrayStatistics stats;

	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout.precision(2);

	getStatistics(stats);

	fout << "Statistics" << endl;
	fout << "min (" << stats.min
		<< "),max (" << stats.max << "),avg (" << stats.avg <<
		"),var(" << stats.var << "),std_dev (" << stats.std_dev << ")" << endl;
}

void BigArray::suffle()//���� ��ó����
{
	srand(time(NULL));
	int index1, index2;
	int rand_1, rand_2;
	
	for (int i = 0; i < num_elements; i++)
	{
		rand_1 = rand();
		rand_2 = rand();
		index1 = ((rand_1 << 15) | rand_2)%num_elements;//��ġ������ ���� ���ο� �ڸ� ����

		rand_1 = rand();
		rand_2 = rand();
		index2 = ((rand_1 << 15) | rand_2) % num_elements;//��ġ������ ���� ���ο� �ڸ� ����

		swap(big_array[index1], big_array[index2]);//��ġ��ȯ
	}
}

void BigArray::selection_sort()//��������
{
	int min_index;//�ּҰ��� ��ġ

	for (int i = 0; i < num_elements - 1; i++)
	{
		min_index = i;
		for (int j = i + 1; j < num_elements; j++)
		{
			if (big_array[min_index] > big_array[j])//j��°�� ���������
				min_index = j;//�ּҰ� ��ġ��j
		}
		if (min_index != i)//�ּҰ� ��ġ�� i��°�� �ƴҰ��
		{
			swap(big_array[i], big_array[min_index]);//��ġ��ȯ
		}
	}
}

int partition(int* array, int size, int left, int right, int pivotIndex, int level)
{
	int pivotValue;
	int newPI;
	int i;

	pivotValue = array[pivotIndex];
	swap(array[pivotIndex], array[right]);//������ġ�� �ǿ�������ġ ��ȯ

	newPI = left;

	for (i = left; i <= (right - 1); i++)
	{
		if (array[i] <= pivotValue)
		{
			swap(array[i], array[newPI]);
			newPI++;
		}
	}
	swap(array[newPI], array[right]);//�����ʿ� �ִ��Ͱ� newpi��ġ�� ��ȯ �̰�� newpi��ġ�� ������ �� �Ǻ���������� ����

	return newPI;
}

void _quick_sort(int* array, int size, int left, int right, int level)//����Լ�
{
	int pI, newPI;

	if (left >= right)
		return;

	else if (left < right)
		pI = (left + right) / 2;//���ذ� ���������� ������ġ ����

	newPI = partition(array, size, left, right, pI, level);//newPI ��ġ��

	if (left < newPI - 1)//���ʰ��� ���Ͽ� 
		_quick_sort(array, size, left, newPI - 1, level + 1);
	if(newPI+1<right)//�����ʰ��� ���Ͽ�
		_quick_sort(array, size, newPI + 1,right, level + 1);
}

void BigArray::quick_sort()//����Ʈ
{
	int pI, newPI;
	_quick_sort(big_array, num_elements, 0, num_elements-1, 0);
}

void BigArray::fprintBigArray(ostream& fout, int elements_per_line)//�迭���
{
	int count = 0;

	while (count < num_elements)
	{
		fout << setw(5) << big_array[count];
		count++;
		if (count % elements_per_line == 0)//�ٹٲ� ����
			fout << endl;
	}
	fout << endl;
}

void BigArray::fprintSample(ostream& fout, int elements_per_line, int num_sample_lines)
{
	int count=0;

	for (int i = 0; i < num_sample_lines; i++)//���� ���μ� ��ŭ
	{
		for (int j = 0; j < elements_per_line; j++)//���δ� �� ��
		{
			if (count > num_elements)
			{
				fout << endl;
				return;
			}
			fout << setw(10) << big_array[count];
			count++;
		}
		fout << endl;
	}

	count = num_elements - (num_sample_lines * elements_per_line);//ū �����迭 ������ ����ϱ� ����
	
	fout << endl << "  ....." << endl;

	for (int i = 0; i < num_sample_lines; i++)//���� ���μ� ��ŭ
	{
		for (int j = 0; j < elements_per_line; j++)//���δ� �� ��
		{
			if (count > num_elements)
			{
				fout << endl;
				return;
			}
			fout << setw(10) << big_array[count];
			count++;
		}
		fout << endl;
	}
	fout << endl;
}