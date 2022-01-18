#ifndef CI_H
#define CI_H

#include"Shape.h"

class Circle : public Shape
{
public:
	Circle(); // default생성자
	Circle(Position pos, int r, double ang, COLORREF color, string name); //  생성자
	~Circle(); // 소멸자
	double getArea(); //면적 계산
	virtual void draw(ostream& fout); // 가상함수 
	Circle& operator=(const Circle& cir); // 대입연산자
protected:
	int radius; // 반지름
};

#endif // !CI_H
