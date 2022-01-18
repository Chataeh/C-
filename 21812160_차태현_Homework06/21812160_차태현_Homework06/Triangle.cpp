#include"Triangle.h"


Triangle::Triangle()//default 생성자
	:Shape()
{
	base = 0;
	tri_height = 0;
}


Triangle::Triangle(Position pos, int b, int h, double ang, COLORREF color, string name)//생성자
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

double Triangle::getArea()//면적구하기
{
	double result = 0.0;

	result = (base * tri_height) / 2;//삼각형 면적계산

	return result;
}

Triangle& Triangle::operator=(const Triangle& tri)//대입연산자
{
	Shape::operator=(tri);//Shape 대입연산자 호출
	base = tri.base;
	tri_height = tri.tri_height;

	return *this;//자기자신객체 반환
}