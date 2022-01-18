/**
*파일이름"21812160_차태현_Homework04-1 "
*프로그램의 목적 및 기본 기능:
*  파일로부터 복소수를 받아와 사칙연산을 하는 프로그램.
*
*프로그램 작성자: 21812160 차태현(2021년 09월24일),
*최종 수정 및 보완: 2021년 9월 24일 (차태현)
*/
#include<iostream>
#include<fstream>
#include"Cmplx.h"
#include"CmplxArray.h"

using namespace std;

int main()
{
	
	ifstream fin;

	CmplxArray cmplxs(7);//7개의 복소수 배열생성

	fin.open("input.txt");//파일열기

	fin >> cmplxs[0] >> cmplxs[1];//파일로 제공된 복소수 받아오기

	cmplxs[2] = cmplxs[0] + cmplxs[1];//복소수의 덧셈
	cmplxs[3] = cmplxs[0] - cmplxs[1];//복소수의 뺄셈
	cmplxs[4] = cmplxs[0] * cmplxs[1];//복소수의 곱셈
	cmplxs[5] = cmplxs[0] / cmplxs[1];//복소수의 나눗셈
	cmplxs[6] = ~cmplxs[0] ;//켤레복소수

	//복소수 출력
	cout << "cmplxs[0] = " << cmplxs[0] << endl;
	cout << "cmplxs[1] = " << cmplxs[1] << endl;
	cout<< "cmplxs[2] = cmplxs[0] + cmplxs[1]= "<<cmplxs[2]<< endl;
	cout << "cmplxs[3] = cmplxs[0] - cmplxs[1]= " << cmplxs[3] << endl;
	cout << "cmplxs[4] = cmplxs[0] * cmplxs[1]= " << cmplxs[4] << endl;
	cout << "cmplxs[5] = cmplxs[0] / cmplxs[1]= " << cmplxs[5] << endl;
	cout << "cmplxs[6] = ~cmplxs[0] (coniugate)" << cmplxs[6] << endl;

	if (cmplxs[0] == cmplxs[1])//파일로 주어진 두 복소수가 같은지 판별
	{
		cout << "cmplxs[0] is equal to cmplxs[1]" << endl;
	}
	else
		cout << "cmplxs[0] is not equal to cmplxs[1]" << endl;

	cmplxs[1] = cmplxs[0];//파일로 받아온 복소수를 같게 설정
	cout << "After cmplxs[1]==cmplxs[0];==>"<<endl;

	if (cmplxs[0] == cmplxs[1])//파일로 주어진 두 복소수가 같은지 판별
	{
		cout << "cmplxs[0] is equal to cmplxs[1]" << endl;
	}
	else
		cout << "cmplxs[0] is not equal to cmplxs[1]" << endl;

	fin.close();//파일닫기
}