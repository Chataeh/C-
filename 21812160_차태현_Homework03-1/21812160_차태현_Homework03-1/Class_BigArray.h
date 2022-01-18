#ifndef B_A_H
#define B_A_H

#include<iostream>
#include<fstream>

using namespace std;

typedef struct {
	int min;
	int max;
	double avg;
	double var;
	double std_dev;
}ArrayStatistics;//통계정보 계산을 위한 구조체

class BigArray
{
public:
	BigArray(int n);//생성자
	~BigArray();//소멸자
	void genBigRandArray(int base_offset);//큰 크기의 난수배열 생성
	int size() { return num_elements; }
	void suffle();//순서바꾸기 셔플
	void selection_sort();//선택정렬
	void quick_sort();//퀵소트
	void getStatistics(ArrayStatistics&);//통계정보계산
	void fprintStatistics(ostream& fout);
	void fprintBigArray(ostream& fout, int elements_per_line);//배열출력
	void fprintSample(ostream& fout, int elements_per_line, int num_sample_lines);//큰 배열중 샘플만출력
private:
	int* big_array;
	int num_elements;
};

#endif