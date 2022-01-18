#include"ElpsCylinder.h"

ostream& operator<<(ostream& ostr, const ElpsCylinder& elpcyl)//<<������ ��ºκ�
{
	ostr.setf(ios::fixed);
	ostr.setf(ios::showpoint);
	ostr.precision(2);//�Ҽ��� ��°¥�� ���
	ostr.setf(ios::uppercase);
	ostr << elpcyl.name << ": pos ( " << setfill(' ') << setw(3) << elpcyl.pos_x << "," << setw(3) << elpcyl.pos_y
		<< "), angle (" << elpcyl.angle
		<< "), color ("<<setw(6) << setfill('0') << hex << elpcyl.color << "), radius ("
		<< elpcyl.radius_1 << ", " << elpcyl.radius_2 << "), height (" << elpcyl.height << "),"<<endl<<" ellipse_area (" << elpcyl.Elps::getArea() << "), elp_cyl area ("
		<< elpcyl.getArea() << "), elp_cyl volume (" << elpcyl.getVolume() << ")" << endl;

	return ostr;
}

ElpsCylinder::ElpsCylinder()//������
	:Elps()//�θ�Ŭ���� ������
{
	height = 0.0;
}

ElpsCylinder::ElpsCylinder(string n)//������
	:Elps(n)//�θ�Ŭ���� ������
{
	height = 0.0;
}
ElpsCylinder::ElpsCylinder(int px, int py, double r1, double r2, double h, double ang, COLORREF clr, string n)//������
	:Elps(px,py,r1,r2,ang,clr,n)//�θ�Ŭ���� ������
{
	height = h;
}

ElpsCylinder::~ElpsCylinder()//�Ҹ���
{

}

double ElpsCylinder::getArea() const//ǥ�������ϱ�
{
	double result = 0.0;
	result=((Elps::getArea() * 2) + (3 * (radius_1 + radius_2) - sqrt((3 * radius_1 + radius_2) * (radius_1 + 3 * radius_2))) * pi * height);
	return result;
}

double ElpsCylinder::getVolume() const//���Ǳ��ϱ�
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

ElpsCylinder& ElpsCylinder::operator =(const ElpsCylinder& right)//���Կ�����
{
	Elps::operator=(right);//�θ�Ŭ���� ���Կ�����
	height= right.height;

	return *this;
}