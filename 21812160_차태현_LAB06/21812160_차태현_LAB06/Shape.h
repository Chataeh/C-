#ifndef  S_H
#define S_H

#include <string>
#include <Windows.h>
#include <conio.h>
#include "ConsolePixelDrawing.h"
#include "Color.h"

using namespace std;

#define PI 3.14159 

class ConsolePixelFrame;

class Shape
{
	friend ostream& operator<<(ostream&, Shape&);//<<������
public:
	Shape();//default ������
	Shape(string name);//������
	Shape(int px, int py, double angle, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);//������
	virtual ~Shape();//�Ҹ��� ����
	virtual void draw(ConsolePixelFrame cp_frame);//����
	void fprint(ostream&);//���Ͽ� ���
	int get_pos_x() const { return pos_x; }//x��ġ ��ȯ
	int get_pos_y() const { return pos_y; }//y��ġ ��ȯ
	void set_pos_x(int x) { pos_x = x; }// x��ġ ����
	void set_pos_y(int y) { pos_y = y; }// y��ġ ����
	string getName() { return name; }//�̸���ȯ
	void setName(string n) { name = n; }//�̸�����
	Shape& operator=(const Shape& s);//���Կ�����
protected:
	int pos_x;//x��ġ
	int pos_y;//y��ġ
	double angle;//��
	string name;//�̸�
	int pen_thickness;//�� �β�
	COLORREF line_color;//���� ��
	COLORREF brush_color;//�귯�� ��

};


#endif // ! S_H
