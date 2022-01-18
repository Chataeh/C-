/**
*파일이름"21812160_차태현_LAB06 "
*프로그램의 목적 및 기본 기능:
*  도형의 객체를 생성해 도형을 콘솔에 그리기
*
*프로그램 작성자: 21812160 차태현(2021년 10월06일),
*최종 수정 및 보완: 2021년 10월 06일 (차태현)
*/
#include <iostream> 
#include <string> 
#include <fstream> 
#include "ConsolePixelDrawing.h" 
#include "Shape.h" 
#include "Triangle.h" 
#include "Circle.h" 
#include "Rectang.h" 
#include "Polygon.h" 
#include "Star.h" 
#include "AngledArc.h" 
#include "Cylinder.h" 
#include "Prism.h"
#include"Hexahedron.h"
using namespace std;
int main()
{
	//도형 생성
	Circle cir(100, 200, 80, 0, RGB_BLACK, RGB_RED, 3, "Circle");
	Triangle tri(300, 200, 150, 130, 0, RGB_BLACK, RGB_YELLOW, 3, "Triangle");
	Rectang rec(500, 200, 150, 150, 0, RGB_BLACK, RGB_BLUE, 4, "Rectangle");
	PolyGon poly_5(700, 200, 80, 5, 0, RGB_BLACK, RGB_GREEN, 4, "Polygon_5");
	PolyGon poly_7(100, 400, 80, 7, 0, RGB_BLACK, RGB_MAGENTA, 4, "Polygon_7"); 
	Star star_5(300, 400, 80, 5, 0, RGB_BLACK, RGB_GREEN, 4, "Star_5");
	AngledArc angle_arc(500, 400, 80, 0, 45, 270, RGB_RED, RGB_BLUE, 4, "Angle_Arc");
	Cylinder cyl(700, 400, 80, 0, 100, RGB_BLUE, RGB_WHITE, 4, "Cylinder");
	Prism pri(100, 600, 150,65, 100,0, RGB_BLACK, RGB_RED, 3, "Prism");
	Hexahedron hex(400, 600, 150, 150,100,60 * PI / 180, RGB_BLACK, RGB_RED, 4, "Hexahedron");
	ConsolePixelFrame frame(50, 50); // 콘솔 출력위치
	
	//하나의 포인터로 연결
	frame.addShape(&cir);
	frame.addShape(&tri);
	frame.addShape(&rec);
	frame.addShape(&poly_5);
	frame.addShape(&poly_7);
	frame.addShape(&star_5);
	frame.addShape(&angle_arc);
	frame.addShape(&cyl);
	frame.addShape(&pri);
	frame.addShape(&hex);

	frame.drawShapes();//도형 그리기
	
	printf("hit any key to continue ....");
	_getch();
	
	return 0;
} 