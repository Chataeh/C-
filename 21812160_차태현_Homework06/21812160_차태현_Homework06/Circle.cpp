#include"Circle.h"


Circle::Circle()//default 생성자
	:Shape()
{
	radius = 0;
}


Circle::Circle(Position pos, int r, double ang, COLORREF color, string name)//생성자
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

double Circle::getArea()//면적구하기
{
	double result = 0.0;

	result = radius* radius *PI;//삼각형 면적계산

	return result;
}

Circle& Circle::operator=(const Circle& cir)//대입연산자
{
	Shape::operator=(cir);//Shape 대입연산자 호출
	radius = cir.radius;

	return *this;//자기자신객체 반환
}