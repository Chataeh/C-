#ifndef E_H
#define E_H
#include"Shape.h"

class Elps : public Shape//상속
{
	friend ostream& operator<<(ostream&, const Elps&);//<<연산자 파일출력

public:
	Elps();//생성자
	Elps(string name);//생성자
	Elps(int px, int py, double r1, double r2, double ang, COLORREF clr, string name);//생성자
	~Elps();//소멸자
	double getArea() const;//타원면적 계산
	void draw();
	void print(ostream&);
	double getRadius_1() const { return radius_1; }//반지름1 
	double getRadius_2() const { return radius_2; }//반지름2
	void setRadius(double r1, double r2) { radius_1 = r1; radius_2 = r2; }//반지름 설정
	Elps& operator=(const Elps& elp);//대입연산자
protected:
	double radius_1;
	double radius_2;

};

#endif