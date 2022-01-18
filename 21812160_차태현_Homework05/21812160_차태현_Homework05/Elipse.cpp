#include"Ellipse.h"

ostream& operator<< (ostream& fout, const Elps& elps)//<<연산자 파일로 출력
{
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout.precision(2);
  
	fout << elps.name << ": pos ( " <<setfill(' ') << setw(3) << elps.pos_x << "," << setw(3) << elps.pos_y
		<< "), angle (" << elps.angle
		<< "), color ("<<setw(6)<<setfill('0')<<hex << elps.color << "), radius ("
		<< elps.radius_1 << ", " << elps.radius_2 << "), ellipse_area (" << elps.getArea() << ")" << endl;

	return fout;
}

Elps::Elps()//생성자
	:Shape()//부모클래스 생성자
{
	radius_1 = 0.0;
	radius_2 = 0.0;
}

Elps::Elps(string name)//생성자
	:Shape(name)//부모클래스 생성자
{
	radius_1 = 0.0;
	radius_2 = 0.0;
}

Elps::Elps(int px, int py, double r1, double r2, double ang, COLORREF clr, string name)//생성자
	:Shape(px,py,ang,clr,name)//부모클래스 생성자
{
	radius_1 = r1;
	radius_2 = r2;
}

Elps::~Elps()//소멸자
{

}

double Elps::getArea() const//타원의 면적구하기
{
	double result = 0.0;
	
	result = radius_1 * radius_2 * pi;//a*b*pi
	
	return result;
}

void Elps::draw()
{
	cout << "draw() of" << name << endl;
}

void Elps::print(ostream& fout)
{
	double result = 0.0;
	result = getArea();
	fout << name << ": pos ( " << setw(3) << pos_x << "," << setw(3) << pos_y
		<< "), angle (" << angle
		<< "), color (" << color << "), radius (" 
		<<radius_1<<", "<<radius_2<<"), ellipse_area ("<<result<<")"<< endl;
}

Elps& Elps::operator=(const Elps& elp)//대입연산자
{
	Shape::operator=(elp);//부모클래스 대입연산자 사용
	radius_1 = elp.radius_1;
	radius_2 = elp.radius_2;

	return *this;
}