/**
*파일이름"21812160_차태현_Homework06"
*프로그램의 목적 및 기본 기능:
* 가상함수를 통해 도형들의 정보 출력
*
*프로그램 작성자: 21812160 차태현(2021년 10월08일),
*최종 수정 및 보완: 2021년 10월 08일 (차태현)
*/
#include <iostream>
#include <string>
#include <fstream>
#include "Position.h"
#include "Shape.h"
#include "Triangle.h"
#include "Prism.h"
#include "Rectangle.h"
#include "Hexahedron.h"
#include "Circle.h"
#include "Cylinder.h"
using namespace std;
#define NUM_SHAPES 7
int main()
{
	ofstream fout;
	Shape s1(Position(1, 1), 0, RGB_BLUE, "Blue Shape");
	Triangle t1(Position(2, 2), 3, 4, 0, RGB_RED, "Red Triangle");
	Prism p1(Position(3, 3), 6, 7, 8, 0, RGB_GREEN, "Green Prism");
	Rectang r1(Position(4, 4), 1, 2, 0, RGB_YELLOW, "Yellow Rectangle");
	Hexahedron hx1(Position(5, 5), 5, 6, 7, 0, RGB_ORANGE, "Orange Hexahedtron");
	Circle cir(Position(6, 6), 6, 0, RGB_MAGENTA, "Magenta Circle");
	Cylinder cyl(Position(7, 7), 8, 6, 0, RGB_WHITE, "White Cylinder");
	Shape * shapes[NUM_SHAPES]; 
	
	fout.open("Output.txt");
	if (fout.fail())
	{
		cout << "Fail to open an output file (Output.txt)₩n";
		exit(1);
	}
	
	shapes[0] = &s1;
	shapes[1] = &t1;
	shapes[2] = &p1;
	shapes[3] = &r1;
	shapes[4] = &hx1;
	shapes[5] = &cir;
	shapes[6] = &cyl;
	
	for (int i = 0; i < NUM_SHAPES; i++)
	{
		shapes[i]->draw(fout);
	}
	fout.close();
	return 0;
} 