#ifndef SH_H
#define SH_H
#include"Position.h"
#include<Windows.h>
#include<string>
#include<iomanip>
using namespace std;

#define PI 3.141592

const COLORREF RGB_BLACK = 0x00000000;
const COLORREF RGB_RED = 0x000000FF;
const COLORREF RGB_GREEN = 0x0000FF00;
const COLORREF RGB_BLUE = 0x00FF0000;
const COLORREF RGB_ORANGE = 0x0000A5FF;
const COLORREF RGB_YELLOW = 0x0000FFFF;
const COLORREF RGB_MAGENTA = 0x00FF00FF;
const COLORREF RGB_WHITE = 0x00FFFFFF;

class Shape {
public:
	Shape();//default ������
	Shape(Position pos, double angle, COLORREF color, string name);//������
	~Shape();//�Ҹ���
	virtual void draw(ostream& fout);//�����Լ�
	Shape& operator=(const Shape& s);//���Կ�����

protected:
	Position pos;//x,y��ġ
	double angle;//��
	string name;//�̸�
	COLORREF color;//�� ������ ���� ����
};


#endif SH_H
