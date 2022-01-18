#ifndef EC_H
#define EC_H
#include"Ellipse.h"


class ElpsCylinder : public Elps//상속
{
	friend ostream& operator<< (ostream& ostr, const ElpsCylinder& elpcyl);//<<연산자 출력기능

public:
	ElpsCylinder(); // default 생성자
	ElpsCylinder(string n);//생성자
	ElpsCylinder(int px, int py, double r1, double r2, double h, double ang, COLORREF clr, string n);//생성자
	virtual ~ElpsCylinder();
	double getArea() const;//표면적구하기
	double getVolume() const;//부피구하기
	void draw();
	void print(ostream&);
	ElpsCylinder& operator=(const ElpsCylinder& right);//대입연산자
protected:
	double height;
};




#endif