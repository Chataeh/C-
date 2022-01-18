/**
*파일이름" 21812160_차태현_Homework03-1"
*프로그램의 목적 및 기본 기능:
*  큰 난수배열을 생성해 정렬하고 시간을 측정함
*
*프로그램 작성자: 21812160 차태현(2021년 09월15일),
*최종 수정 및 보완: 2021년 9월 15일 (차태현)
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

	LARGE_INTEGER freq,t1,t2,t3,t4;//시간측정을 위함
	long long diff1, diff2;
	double elapsed_time1, elapsed_time2;

	fout.open("output.txt");//파일열기

	int base_offset = -500000;
	
	QueryPerformanceFrequency(&freq);//주파수 측정

	BigArray array(1000000);//배열의 수 정의
	

	fout << endl << "Generating big rand array of "
		<< array.size() << " elements with base_offset " << base_offset << " ... " 
		<< endl;
	array.genBigRandArray(base_offset);//난수 배열생성
	array.fprintSample(fout,ELEMENTS_PER_LINE, SAMPLE_LINES);
	array.fprintStatistics(fout);//통계정보 계산

	QueryPerformanceCounter(&t1);
	array.quick_sort();//퀵소트
	QueryPerformanceCounter(&t2);
	diff1 = t2.QuadPart - t1.QuadPart;
	elapsed_time1 = (double)diff1 / freq.QuadPart;//퀵소트 하는데 걸린시간
	
	array.fprintSample(fout, ELEMENTS_PER_LINE, SAMPLE_LINES);
	
	fout << "Quick sorting took" << elapsed_time1 * 1000 << " [milli-seconds]" << endl;

	
	fout << "After suffle" << endl;
	array.suffle();//셔플해서 다시 랜덤순서로 정렬
	array.fprintSample(fout, ELEMENTS_PER_LINE, SAMPLE_LINES);

	QueryPerformanceCounter(&t3);
	array.selection_sort();//선택정렬
	QueryPerformanceCounter(&t4);
	diff2 = t4.QuadPart - t3.QuadPart;
	elapsed_time2 = (double)diff2 / freq.QuadPart;//선택정렬로 걸린시간

	array.fprintSample(fout, ELEMENTS_PER_LINE, SAMPLE_LINES);
	fout << "Selction sorting took" << elapsed_time2 * 1000 << " [milli-seconds]" << endl;

	fout.close();//파일닫기
}