/**
*파일이름"21812160_차태현_Homework05"
*프로그램의 목적 및 기본 기능:
*  클래스들을 상속받아 파일로 각각의 정보를 출력.
*
*프로그램 작성자: 21812160 차태현(2021년 10월03일),
*최종 수정 및 보완: 2021년 10월 03일 (차태현)
*/
#include <iostream>
#include <fstream>
#include <string>
#include "Color.h"
#include "Shape.h"
#include "Ellipse.h" 
#include "ElpsCylinder.h" 

using namespace std;

int main()
{
	fstream fout;
	Shape shape(1, 1, 0, RGB_BLACK, "Shape");//Shape 객체 정의
	Elps red_elps(8, 8, 3.0, 4.0, 0, RGB_RED, "Red_Elps");//Elps 객체정의
	ElpsCylinder blue_elpcyl(9, 9, 5.0, 6.0, 7.0, 0.0, RGB_BLUE, "Blue_Elp_Cyl");//ElpsCylinder객체 정의
	
	fout.open("output.txt", 'w');//파일열기
	if (fout.fail())
	{
		cout << "Failed in opening output.txt file !!" << endl;
		exit;
	}
	
	fout << "List of shapes using operator<<() friend function " << endl;
	fout << shape << endl;//출력
	fout << red_elps << endl;
	fout << blue_elpcyl << endl;
	
	fout.close();//파일닫기
	return 0;
}