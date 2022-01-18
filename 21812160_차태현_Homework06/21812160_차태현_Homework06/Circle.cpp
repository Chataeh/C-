#include"Circle.h"


Circle::Circle()//default ������
	:Shape()
{
	radius = 0;
}


Circle::Circle(Position pos, int r, double ang, COLORREF color, string name)//������
	:Shape(pos, ang, color, name)
{
	radius = r;
}

Circle::~Circle()
{

}

void Circle::draw(ostream& fout)
{
	fout.setf(ios::fixed);
	fout.precision(0);
	fout.setf(ios::uppercase);
	fout << "Circle::draw() => [name(" << name << "),pos(" << pos.px << "," << pos.py << "), radius(" << radius << "), color("
		<< setw(6) << setfill('0') << hex << color << "),circle area ("<<setprecision(3) << getArea() << ") ]" << endl;
}

double Circle::getArea()//�������ϱ�
{
	double result = 0.0;

	result = radius* radius *PI;//�ﰢ�� �������

	return result;
}

Circle& Circle::operator=(const Circle& cir)//���Կ�����
{
	Shape::operator=(cir);//Shape ���Կ����� ȣ��
	radius = cir.radius;

	return *this;//�ڱ��ڽŰ�ü ��ȯ
}