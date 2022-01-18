#include"Hexahedron.h"


Hexahedron::Hexahedron()
	:Shape()
{
	width = 0;
	length = 0;
	height = 0;

}


Hexahedron::Hexahedron(Position pos, int w, int l, int h, double ang, COLORREF color, string name)
	:Shape(pos, ang, color, name), height(h), width(w), length(l)
{

}

Hexahedron::~Hexahedron()
{

}

double Hexahedron::getArea()
{
	double result = 0.0;
	result = (width * length)*2 + (width * height) * 2 + (length * height) * 2;//�ѳ��� ���

	return result;

}

double Hexahedron::getVolume()
{
	double result = 0.0;
	result = width * length * height;//���ǰ��

	return result;

}

void Hexahedron::draw(ostream& fout)//�簢��� �������
{
	fout.setf(ios::fixed);
	fout.setf(ios::uppercase);
	fout.precision(0);

	fout << "Hexahedron::draw() => [name(" << name << "),pos(" << pos.px << "," << pos.py << "), width(" << width << "), length (" << length << "), height("<<height<<"), color("
		<< setw(6) << setfill('0') << hex << color <<"),"<< endl << "    hexahedron suface area (" << getArea() << "), hexahedron volume (" << getVolume() << ") ]" << endl;
}


Hexahedron& Hexahedron::operator=(const Hexahedron& hex)
{
	Shape::operator=(hex);
	height = hex.height;
	width = hex.width;
	length = hex.length;

	return *this;
}