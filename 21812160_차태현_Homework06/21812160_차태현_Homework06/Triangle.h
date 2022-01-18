#ifndef TR_H
#define TR_H

#include"Shape.h"

class Triangle :public Shape
{
public:
	Triangle();//default 생성자
	Triangle(Position pos, int b, int h, double ang, COLORREF color, string name);//생성자
	~Triangle();//소멸자
	double getArea();//면적계산
	virtual void draw(ostream& fout);//그리기
	Triangle& operator=(const Triangle& tri);//대입연산자
protected:
	int base;//삼각형 밑변
	int tri_height;//삼각형 높이
};


#endif // !TR_H
