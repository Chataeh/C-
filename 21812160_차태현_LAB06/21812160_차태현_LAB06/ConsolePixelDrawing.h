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
	ConsolePixelFrame(int org_x, int org_y);//������
	~ConsolePixelFrame();//�Ҹ���
	void addShape(Shape* new_shape);
	void drawShapes();//�׸���
	int get_pos_org_x() { return pos_org_x; }
	int get_pos_org_y() { return pos_org_y; }
	HDC getConsole_DC() { return console_DC; }

private:
	HWND console;
	HDC console_DC;
	Shape** pShapes;//������
	int num_shapes;//������ ��
	int capacity;//�뷮
	int pos_org_x;//x��ġ
	int pos_org_y;//y��ġ
	bool isValidIndex(int sub);//���� �ȿ� ���ϰԵǴ°� �Ǻ�
};


#endif P_H