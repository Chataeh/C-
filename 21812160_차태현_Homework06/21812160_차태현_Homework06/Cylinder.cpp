#include"Cylinder.h"

Cylinder::Cylinder()
	:Shape()
{
	radius = 0;
	height = 0;

}

Cylinder::Cylinder(Position pos, int r,  int h, double ang, COLORREF color, string name)
	:Shape(pos, ang, color, name), height(h), radius(r)
{

}

Cylinder::~Cylinder()
{

}

double Cylinder::getArea()
{
	double result = 0.0;
	result = 2 *( radius * radius * PI) + (2 * PI * radius * height);//����� �ѳ���

	return result;
}

double Cylinder::getVolume()
{
	double result = 0.0;
	result = PI * radius * radius * height;//����պ���

	return result;
}

void Cylinder::draw(ostream& fout)//�ﰢ��� ���� ���
{
	fout.setf(ios::fixed);
	fout.setf(ios::uppercase);
	fout.precision(0);

	fout << "Cylinder::draw() => [name(" << name << "),pos(" << pos.px << "," << pos.py << "), radius(" <<radius << "), height("<<height<<"), color("
		<< setw(6) << setfill('0') << hex << color << "),"<<endl << "    cylinder suface area (" <<setprecision(3)<< getArea() << "), cylinder volume (" << setprecision(2) << getVolume() << ") ]" << endl;
}

Cylinder& Cylinder::operator=(const Cylinder& cy)//���Կ�����
{
	Shape::operator=(cy);
	height = cy.height;
	radius = cy.radius;
	

	return *this;//�ڽ� ��ü ��ȯ
}