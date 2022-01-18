#include"Shape.h"

Shape::Shape()//생성자 
	:pos(0,0), angle(0.0), color(RGB_BLACK), name(" ")//초기화
{
	
}

Shape::Shape(Position pos, double angle, COLORREF color, string name)//생성자
	: pos(pos), angle(angle), color(color), name(name)
{

}
Shape::~Shape()//소멸자
{

}

void Shape::draw(ostream& fout)//draw 파생객체의 draw 사용
{
	fout.setf(ios::fixed);
	fout.setf(ios::uppercase);
	fout.precision(0);
	fout << "Shape::darw() => [name(" << name << "), pos(" << pos.px << "," << pos.py << "), color("
		<< setw(6) << setfill('0') << hex << color << ") ]" << endl;
}

Shape& Shape::operator=(const Shape& s)//대입연산자
{
	name = s.name;
	pos.px = s.pos.px;
	pos.py= s.pos.py;
	angle = s.angle;
	color = s.color;

	return *this;
}