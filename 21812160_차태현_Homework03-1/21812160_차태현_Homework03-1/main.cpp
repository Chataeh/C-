/**
*�����̸�" 21812160_������_Homework03-1"
*���α׷��� ���� �� �⺻ ���:
*  ū �����迭�� ������ �����ϰ� �ð��� ������
*
*���α׷� �ۼ���: 21812160 ������(2021�� 09��15��),
*���� ���� �� ����: 2021�� 9�� 15�� (������)
*/
#include<iostream>
#include<iomanip>
#include<time.h>
#include<stdlib.h>
#include "Class_BigArray.h"
#include<Windows.h>

#define ELEMENTS_PER_LINE 10
#define SAMPLE_LINES 3

int main()
{
	ofstream fout;

	LARGE_INTEGER freq,t1,t2,t3,t4;//�ð������� ����
	long long diff1, diff2;
	double elapsed_time1, elapsed_time2;

	fout.open("output.txt");//���Ͽ���

	int base_offset = -500000;
	
	QueryPerformanceFrequency(&freq);//���ļ� ����

	BigArray array(1000000);//�迭�� �� ����
	

	fout << endl << "Generating big rand array of "
		<< array.size() << " elements with base_offset " << base_offset << " ... " 
		<< endl;
	array.genBigRandArray(base_offset);//���� �迭����
	array.fprintSample(fout,ELEMENTS_PER_LINE, SAMPLE_LINES);
	array.fprintStatistics(fout);//������� ���

	QueryPerformanceCounter(&t1);
	array.quick_sort();//����Ʈ
	QueryPerformanceCounter(&t2);
	diff1 = t2.QuadPart - t1.QuadPart;
	elapsed_time1 = (double)diff1 / freq.QuadPart;//����Ʈ �ϴµ� �ɸ��ð�
	
	array.fprintSample(fout, ELEMENTS_PER_LINE, SAMPLE_LINES);
	
	fout << "Quick sorting took" << elapsed_time1 * 1000 << " [milli-seconds]" << endl;

	
	fout << "After suffle" << endl;
	array.suffle();//�����ؼ� �ٽ� ���������� ����
	array.fprintSample(fout, ELEMENTS_PER_LINE, SAMPLE_LINES);

	QueryPerformanceCounter(&t3);
	array.selection_sort();//��������
	QueryPerformanceCounter(&t4);
	diff2 = t4.QuadPart - t3.QuadPart;
	elapsed_time2 = (double)diff2 / freq.QuadPart;//�������ķ� �ɸ��ð�

	array.fprintSample(fout, ELEMENTS_PER_LINE, SAMPLE_LINES);
	fout << "Selction sorting took" << elapsed_time2 * 1000 << " [milli-seconds]" << endl;

	fout.close();//���ϴݱ�
}