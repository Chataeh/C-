/**
*파일이름"21812160_차태현_Homework01-1 "
*프로그램의 목적 및 기본 기능:
*  파일에서 수를 받아와 통계분석을하는 프로그램
*
*프로그램 작성자: 21812160 차태현(2021년 9월2일),
*최종 수정 및 보완: 2021년 9월 2일 (차태현)
*/
#include<iostream>
#include<fstream>
#include<math.h>
#define NUM 10

using namespace std;

int fileInputData(ifstream& fin, int* data_array, int max_num_data);//파일로부터 데이터 받아오기
void getStatistics_fileOut(int* data_array, int num_data, ofstream& fout);//통계정보계산

int main()
{
	ifstream fin;
	ofstream fout;

	int data[NUM] = {};
	int num = 0;
	
	fin.open("input.txt");
	fout.open("output.txt");

	num=fileInputData(fin, data,NUM);//데이터 개수

	fout << "Total 10 input from input data file." << endl;
	fout << "Total 10 integer data : {";
	for (int i = 0; i < num; i++)
	{
		fout << data[i] << ",";//파일로 받아온데이터 다른파일로 출력
	}
	fout << "}" << endl;

	getStatistics_fileOut(data, num, fout);//통계정보 계산
	
	fin.close();
	fout.close();

	
}


int fileInputData(ifstream& fin, int* data_array, int max_num_data)//파일로부터 데이터 받아오기
{
	int num = 0;
	for (int i = 0; i < max_num_data; i++)
	{
		fin >> data_array[i];//데이터 받아오기
		num++;//자료의 개수 
	}
	return num;
}

void getStatistics_fileOut(int* data_array, int num_data, ofstream& fout)//통계정보 파일에 출력
{
	int min, max;
	double avg = 0.0, var, diff, sq_diff_sum=0.0, sum = 0.0, std_dev;

	min = INT_MAX;
	max = INT_MIN;
	for (int i = 0; i < num_data; i++)
	{
		if (data_array[i] < min)//최소값 찾기
			min = data_array[i];
		if (data_array[i] > max)//최대값 찾기
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
