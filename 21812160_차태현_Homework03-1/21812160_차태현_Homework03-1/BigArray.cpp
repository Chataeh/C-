#include<iostream>
#include<iomanip>
#include<time.h>
#include<stdlib.h>
#include "Class_BigArray.h"

using namespace std;

BigArray::BigArray(int n)
{
	num_elements = n;
	
	big_array = (int*)new int[num_elements];//동적배열 생성
}

BigArray::~BigArray()
{
	/*
	if (big_array != NULL)
		delete[]big_array;*/
}

void BigArray::genBigRandArray(int base_offset)//난수생성
{
	char* flag;//중복제거를 위함
	int count = 0;
	int big_rand, biased_big_rand;

	srand(time(NULL));

	flag = (char*)new char[num_elements];//동적배열 생성

	while (count < num_elements)
	{
		big_rand = ((rand() << 15) | rand()) % num_elements;//큰크기의 난수생성
		//중복확인 절차
		if (flag[big_rand] == 1)
			continue;
		else
		{
			flag[big_rand] = 1;
			biased_big_rand = big_rand + base_offset;
			big_array[count] = biased_big_rand;//난수 저장
			count++;
		}

	}
	delete[] flag;
}

void BigArray::getStatistics(ArrayStatistics& stats)//통계정보 계산
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

		if (data < min)//최소값 찾기
			min = data;
		if (data > max)//최대값 찾기
			max = data;

	}
	stats.avg = sum / (double)num_elements;

	for (int i = 0; i < num_elements; i++)
	{
		data = big_array[i];
		diff_sq_sum += (data - stats.avg) * (data - stats.avg);
	}
	stats.var = diff_sq_sum / (double)num_elements;//분산 계산
	stats.std_dev = sqrt(stats.var);//표준편차 계산
	stats.min = min;
	stats.max = max;
}

void BigArray::fprintStatistics(ostream& fout)//통계정보 출력
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

void BigArray::suffle()//셔플 위처섞기
{
	srand(time(NULL));
	int index1, index2;
	int rand_1, rand_2;
	
	for (int i = 0; i < num_elements; i++)
	{
		rand_1 = rand();
		rand_2 = rand();
		index1 = ((rand_1 << 15) | rand_2)%num_elements;//위치조정을 위해 새로운 자리 생성

		rand_1 = rand();
		rand_2 = rand();
		index2 = ((rand_1 << 15) | rand_2) % num_elements;//위치조정을 위해 새로운 자리 생성

		swap(big_array[index1], big_array[index2]);//위치교환
	}
}

void BigArray::selection_sort()//선택정렬
{
	int min_index;//최소값의 위치

	for (int i = 0; i < num_elements - 1; i++)
	{
		min_index = i;
		for (int j = i + 1; j < num_elements; j++)
		{
			if (big_array[min_index] > big_array[j])//j번째가 더작을경우
				min_index = j;//최소값 위치는j
		}
		if (min_index != i)//최소값 위치가 i번째가 아닐경우
		{
			swap(big_array[i], big_array[min_index]);//위치교환
		}
	}
}

int partition(int* array, int size, int left, int right, int pivotIndex, int level)
{
	int pivotValue;
	int newPI;
	int i;

	pivotValue = array[pivotIndex];
	swap(array[pivotIndex], array[right]);//기준위치와 맨오른쪽위치 교환

	newPI = left;

	for (i = left; i <= (right - 1); i++)
	{
		if (array[i] <= pivotValue)
		{
			swap(array[i], array[newPI]);
			newPI++;
		}
	}
	swap(array[newPI], array[right]);//오른쪽에 있던것과 newpi위치와 교환 이경우 newpi위치의 왼쪽은 다 피봇밸류값보다 작음

	return newPI;
}

void _quick_sort(int* array, int size, int left, int right, int level)//재귀함수
{
	int pI, newPI;

	if (left >= right)
		return;

	else if (left < right)
		pI = (left + right) / 2;//기준값 설정을위해 기준위치 설정

	newPI = partition(array, size, left, right, pI, level);//newPI 위치값

	if (left < newPI - 1)//왼쪽값에 대하여 
		_quick_sort(array, size, left, newPI - 1, level + 1);
	if(newPI+1<right)//오른쪽값에 대하여
		_quick_sort(array, size, newPI + 1,right, level + 1);
}

void BigArray::quick_sort()//퀵소트
{
	int pI, newPI;
	_quick_sort(big_array, num_elements, 0, num_elements-1, 0);
}

void BigArray::fprintBigArray(ostream& fout, int elements_per_line)//배열출력
{
	int count = 0;

	while (count < num_elements)
	{
		fout << setw(5) << big_array[count];
		count++;
		if (count % elements_per_line == 0)//줄바꿈 실행
			fout << endl;
	}
	fout << endl;
}

void BigArray::fprintSample(ostream& fout, int elements_per_line, int num_sample_lines)
{
	int count=0;

	for (int i = 0; i < num_sample_lines; i++)//샘플 라인수 만큼
	{
		for (int j = 0; j < elements_per_line; j++)//라인당 들어갈 수
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

	count = num_elements - (num_sample_lines * elements_per_line);//큰 난수배열 뒤쪽을 출력하기 위함
	
	fout << endl << "  ....." << endl;

	for (int i = 0; i < num_sample_lines; i++)//샘플 라인수 만큼
	{
		for (int j = 0; j < elements_per_line; j++)//라인당 들어갈 수
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