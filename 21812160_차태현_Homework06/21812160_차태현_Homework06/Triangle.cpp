#include"Triangle.h"


Triangle::Triangle()//default ������
	:Shape()
{
	base = 0;
	tri_height = 0;
}


Triangle::Triangle(Position pos, int b, int h, double ang, COLORREF color, string name)//������
	:Shape(pos, ang, color, name)
{
	base = b;
	tri_height = h;
}

Triangle::~Triangle()
{

}

void Triangle::draw(ostream& fout)
{
	fout.setf(ios::fixed);
	fout.setf(ios::uppercase);
	fout.precision(0);
	
	fout << "Triangle::draw() => [name(" << name << "),pos(" << pos.px << "," << pos.py << "), base(" << base << "), tri_height (" << tri_height << "), color("
		<< setw(6) << setfill('0') << hex << color << "),triangle area (" << getArea() << ") ]" << endl;
}

double Triangle::getArea()//�������ϱ�
{
	double result = 0.0;

	result = (base * tri_height) / 2;//�ﰢ�� �������

	return result;
}

Triangle& Triangle::operator=(const Triangle& tri)//���Կ�����
{
	Shape::operator=(tri);//Shape ���Կ����� ȣ��
	base = tri.base;
	tri_height = tri.tri_height;

	return *this;//�ڱ��ڽŰ�ü ��ȯ
}