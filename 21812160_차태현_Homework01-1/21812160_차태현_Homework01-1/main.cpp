/**
*�����̸�"21812160_������_Homework01-1 "
*���α׷��� ���� �� �⺻ ���:
*  ���Ͽ��� ���� �޾ƿ� ���м����ϴ� ���α׷�
*
*���α׷� �ۼ���: 21812160 ������(2021�� 9��2��),
*���� ���� �� ����: 2021�� 9�� 2�� (������)
*/
#include<iostream>
#include<fstream>
#include<math.h>
#define NUM 10

using namespace std;

int fileInputData(ifstream& fin, int* data_array, int max_num_data);//���Ϸκ��� ������ �޾ƿ���
void getStatistics_fileOut(int* data_array, int num_data, ofstream& fout);//����������

int main()
{
	ifstream fin;
	ofstream fout;

	int data[NUM] = {};
	int num = 0;
	
	fin.open("input.txt");
	fout.open("output.txt");

	num=fileInputData(fin, data,NUM);//������ ����

	fout << "Total 10 input from input data file." << endl;
	fout << "Total 10 integer data : {";
	for (int i = 0; i < num; i++)
	{
		fout << data[i] << ",";//���Ϸ� �޾ƿµ����� �ٸ����Ϸ� ���
	}
	fout << "}" << endl;

	getStatistics_fileOut(data, num, fout);//������� ���
	
	fin.close();
	fout.close();

	
}


int fileInputData(ifstream& fin, int* data_array, int max_num_data)//���Ϸκ��� ������ �޾ƿ���
{
	int num = 0;
	for (int i = 0; i < max_num_data; i++)
	{
		fin >> data_array[i];//������ �޾ƿ���
		num++;//�ڷ��� ���� 
	}
	return num;
}

void getStatistics_fileOut(int* data_array, int num_data, ofstream& fout)//������� ���Ͽ� ���
{
	int min, max;
	double avg = 0.0, var, diff, sq_diff_sum=0.0, sum = 0.0, std_dev;

	min = INT_MAX;
	max = INT_MIN;
	for (int i = 0; i < num_data; i++)
	{
		if (data_array[i] < min)//�ּҰ� ã��
			min = data_array[i];
		if (data_array[i] > max)//�ִ밪 ã��
			max = data_array[i];

		sum += data_array[i];
	}
	avg = sum / num_data;

	for (int j = 0; j < num_data; j++)
	{
		diff = avg - data_array[j];
		sq_diff_sum += diff * diff;
	}
	var = sq_diff_sum / num_data;
	std_dev = sqrt(var);

	fout << "min(" << min << "), max(" << max << "), sum(" << sum << "),  avg(" << avg << "), var(" << var << "), std_dev(" << std_dev << ")";
}
