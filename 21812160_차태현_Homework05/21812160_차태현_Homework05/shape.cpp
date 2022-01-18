#include<iostream>
#include<string>
#include<Windows.h>
#include<iomanip>
#include"Shape.h"

ostream& operator<< (ostream & fout, Shape& s)//<<������ ���Ͽ� �������
{
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout.precision(2);
	fout.setf(ios::uppercase);
	s.print(fout);

	return fout;
}

Shape::Shape()//������ 
	:pos_x(0), pos_y(0), angle(0.0), color(RGB_BLACK), name(" ")//�ʱ�ȭ
{
}
Shape::Shape(string name)
	: pos_x(0), pos_y(0), angle(0.0), color(RGB_BLACK), name(name)//�̸����� �ʱ�ȭ
{
	
}
Shape::Shape(int px, int py, double angle, COLORREF color, string name)//������
	: pos_x(px), pos_y(py), angle(angle), color(color), name(name)
{
	
}
Shape::~Shape()//�Ҹ���
{

}

void Shape::draw()
{
	cout << "draw() of" << name << endl;
}

void Shape::print(ostream&fout)//���Ͽ� ���
{
	fout <<name<< ": pos ( " << setw(3) << pos_x << "," << setw(3) << pos_y
		<< "), angle (" <<angle
		<< "), color ("<<setw(6)<<setfill('0') << hex << color << ")" << endl;
}

Shape& Shape::operator=(const Shape& s)//���Կ�����
{
	name = s.name;
	pos_x = s.pos_x;
	pos_y = s.pos_y;
	angle = s.angle;
	color = s.color;

	return *this;
}