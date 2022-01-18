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
}ArrayStatistics;//������� ����� ���� ����ü

class BigArray
{
public:
	BigArray(int n);//������
	~BigArray();//�Ҹ���
	void genBigRandArray(int base_offset);//ū ũ���� �����迭 ����
	int size() { return num_elements; }
	void suffle();//�����ٲٱ� ����
	void selection_sort();//��������
	void quick_sort();//����Ʈ
	void getStatistics(ArrayStatistics&);//����������
	void fprintStatistics(ostream& fout);
	void fprintBigArray(ostream& fout, int elements_per_line);//�迭���
	void fprintSample(ostream& fout, int elements_per_line, int num_sample_lines);//ū �迭�� ���ø����
private:
	int* big_array;
	int num_elements;
};

#endif