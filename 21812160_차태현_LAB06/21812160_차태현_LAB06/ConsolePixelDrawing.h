#ifndef P_H
#define P_H

#include<iostream>
#include<string>
#include<Windows.h>
#include<conio.h>
#include"Shape.h"
#include"Color.h"

using namespace std;

#define PS_SOLID 0
#define PS_DASH 1
#define PS_DOT 2
#define PS_DASHDOT 3
#define PS_DASHDOTDOT 4
#define PS_NULL 5
#define PS_INSIDEFRAME 6
#define PS_USERSTYLE 7
#define PS_ALTERNATE 8

#define MAX_NUM_SHAPES 100

class Shape;

class ConsolePixelFrame
{
public:
	ConsolePixelFrame(int org_x, int org_y);//생성자
	~ConsolePixelFrame();//소멸자
	void addShape(Shape* new_shape);
	void drawShapes();//그리기
	int get_pos_org_x() { return pos_org_x; }
	int get_pos_org_y() { return pos_org_y; }
	HDC getConsole_DC() { return console_DC; }

private:
	HWND console;
	HDC console_DC;
	Shape** pShapes;//도형들
	int num_shapes;//도형의 수
	int capacity;//용량
	int pos_org_x;//x위치
	int pos_org_y;//y위치
	bool isValidIndex(int sub);//범위 안에 속하게되는가 판별
};


#endif P_H