#include"Shape.h"

Shape::Shape()//������ 
	:pos(0,0), angle(0.0), color(RGB_BLACK), name(" ")//�ʱ�ȭ
{
	
}

Shape::Shape(Position pos, double angle, COLORREF color, string name)//������
	: pos(pos), angle(angle), color(color), name(name)
{

}
Shape::~Shape()//�Ҹ���
{

}

void Shape::draw(ostream& fout)//draw �Ļ���ü�� draw ���
{
	fout.setf(ios::fixed);
	fout.setf(ios::uppercase);
	fout.precision(0);
	fout << "Shape::darw() => [name(" << name << "), pos(" << pos.px << "," << pos.py << "), color("
		<< setw(6) << setfill('0') << hex << color << ") ]" << endl;
}

Shape& Shape::operator=(const Shape& s)//���Կ�����
{
	name = s.name;
	pos.px = s.pos.px;
	pos.py= s.pos.py;
	angle = s.angle;
	color = s.color;

	return *this;
}