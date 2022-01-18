#include"Prism.h"

Prism::Prism()
	:Shape()
{
	base = 0;
	tri_height = 0;
	height = 0;

}

Prism::Prism(Position pos, int b, int t_h, int h, double ang, COLORREF color, string name)
	:Shape(pos, ang, color, name), height(h), base(b), tri_height(t_h)
{

}

Prism::~Prism()
{

}

double Prism::getArea()
{
	double result = 0.0;
	result = base * tri_height / 2.0;//»ï°¢±ãµÕ °Ñ³ÐÀÌ

	return result;
}

double Prism::getVolume()
{
	double result = 0.0;
	result = ((base * tri_height) / 2) * height;//»ï°¢±âµÕ ºÎÇÇ

	return result;
}

void Prism::draw(ostream& fout)//»ï°¢±âµÕ Á¤º¸ Ãâ·Â
{
	fout.setf(ios::fixed);
	fout.setf(ios::uppercase);
	fout.precision(0);

	fout << "Prism::draw() => [name(" << name << "),pos(" << pos.px << "," << pos.py << "), base(" << base << "), tri_height (" << tri_height << "), height("<<height<<"), color("
		<< setw(6) << setfill('0') << hex << color <<"),"<<endl<< "    prism suface area (" << getArea() <<"), prism volume ("<<getVolume()<< ") ]" << endl;
}

Prism& Prism::operator=(const Prism& pri)//´ëÀÔ¿¬»êÀÚ
{
	Shape::operator=(pri);
	height = pri.height;
	base = pri.base;
	tri_height = pri.tri_height;

	return *this;//ÀÚ½Å °´Ã¼ ¹ÝÈ¯
}