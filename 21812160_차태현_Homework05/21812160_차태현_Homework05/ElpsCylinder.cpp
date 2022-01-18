#include"ElpsCylinder.h"

ostream& operator<<(ostream& ostr, const ElpsCylinder& elpcyl)//<<연산자 출력부분
{
	ostr.setf(ios::fixed);
	ostr.setf(ios::showpoint);
	ostr.precision(2);//소수점 둘째짜리 출력
	ostr.setf(ios::uppercase);
	ostr << elpcyl.name << ": pos ( " << setfill(' ') << setw(3) << elpcyl.pos_x << "," << setw(3) << elpcyl.pos_y
		<< "), angle (" << elpcyl.angle
		<< "), color ("<<setw(6) << setfill('0') << hex << elpcyl.color << "), radius ("
		<< elpcyl.radius_1 << ", " << elpcyl.radius_2 << "), height (" << elpcyl.height << "),"<<endl<<" ellipse_area (" << elpcyl.Elps::getArea() << "), elp_cyl area ("
		<< elpcyl.getArea() << "), elp_cyl volume (" << elpcyl.getVolume() << ")" << endl;

	return ostr;
}

ElpsCylinder::ElpsCylinder()//생성자
	:Elps()//부모클래스 생성자
{
	height = 0.0;
}

ElpsCylinder::ElpsCylinder(string n)//생성자
	:Elps(n)//부모클래스 생성자
{
	height = 0.0;
}
ElpsCylinder::ElpsCylinder(int px, int py, double r1, double r2, double h, double ang, COLORREF clr, string n)//생성자
	:Elps(px,py,r1,r2,ang,clr,n)//부모클래스 생성자
{
	height = h;
}

ElpsCylinder::~ElpsCylinder()//소멸자
{

}

double ElpsCylinder::getArea() const//표면적구하기
{
	double result = 0.0;
	result=((Elps::getArea() * 2) + (3 * (radius_1 + radius_2) - sqrt((3 * radius_1 + radius_2) * (radius_1 + 3 * radius_2))) * pi * height);
	return result;
}

double ElpsCylinder::getVolume() const//부피구하기
{
	double result = 0.0;

	result = (pi * radius_1 * radius_2 * height);

	return result;
}

void ElpsCylinder::draw()
{
	cout << "draw() of" << name << endl;
}

void ElpsCylinder::print(ostream& fout)
{
	fout << name << ": pos ( " << setw(3) << pos_x << "," << setw(3) << pos_y
		<< "), angle (" << angle
		<< "), color (" << color << "), radius ("
		<< radius_1 << ", " << radius_2 <<"), height ("<<height<< "), ellipse_area (" <<Elps::getArea()<< "), elp_cyl area (" 
		<<getArea()<<"), elp_cyl volume ("<<getVolume()<<")"<<endl;
}

ElpsCylinder& ElpsCylinder::operator =(const ElpsCylinder& right)//대입연산자
{
	Elps::operator=(right);//부모클래스 대입연산자
	height= right.height;

	return *this;
}