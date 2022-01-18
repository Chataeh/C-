/**
*파일이름"21812160_차태현_Homework-01-2"
*프로그램의 목적 및 기본 기능:
*  1~32까지의 수의 10진수 8진수 16진수 2진수로 출력
*
*프로그램 작성자: 21812160 차태현(2021년 9월2일),
*최종 수정 및 보완: 2021년 9월 2일 (차태현)
*/
#include<iostream>
#include<iomanip>
#include<bitset>
#define NUM 33

using namespace std;

int main()
{

	for (int i = 0; i < NUM; i++)//32번 반복
	{
		cout.setf(ios::showbase);//정수의 출력형식 표시
		cout.setf(ios::right);//오른쪽 줄 맞춤
		cout.setf(ios::uppercase);//대문자 출력
		cout << setw(10) << dec<<i << setw(10) << oct<<i <<setw(10) << hex <<i<< setw(10) <<  bitset<8>(i) << endl;
	}

}