#ifndef CY_H
#define CY_H

#include"Shape.h"

class Cylinder :public Shape
{
public:
	Cylinder();//default 생성자
	Cylinder(Position pos, int r, int h, double ang, COLORREF color, string name);//생성자
	~Cylinder();//소멸자
	double getArea();//겉넓이계산
	double getVolume();//부피계산
	virtual void draw(ostream& fout);//그리기
	Cylinder& operator=(const  Cylinder&cy);//대입연산자
protected:
	int radius;//반지름
	int height;//높이
};

#endif CY_H
