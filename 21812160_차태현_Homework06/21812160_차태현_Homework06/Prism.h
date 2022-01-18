#ifndef PR_H
#define PR_H

#include"Shape.h"

class Prism : public Shape
{
public:
	Prism();//default 생성자
	Prism(Position pos, int b, int t_h,int h, double ang, COLORREF color, string name);//생성자
	~Prism();//소멸자
	double getArea();//겉넓이계산
	double getVolume();//부피계산
	virtual void draw(ostream& fout);//그리기
	Prism& operator=(const  Prism& pri);//대입연산자

protected:
	int base;//삼각형 밑변
	int tri_height;//삼각형 높이
	int height;//기둥 높이
};


#endif // !PR_H
