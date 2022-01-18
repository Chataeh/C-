#ifndef TR_H
#define TR_H

#include"Shape.h"


class Triangle:public Shape
{
public:
	Triangle();//default 생성자
	Triangle(string name);//생성자
	Triangle(int px, int py, int b, int h, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);//생성자
	~Triangle();//소멸자
	double getArea();//면적계산
	virtual void draw(ConsolePixelFrame cp_frame);//그리기
	void fprint(ostream&);//파일 출력
	int getBase() { return base; }//밑변 반환
	int getHeight() { return tri_height; }//s높이반환
	Triangle& operator=(const Triangle& tri);//대입연산자

protected:
	int base;//밑변
	int tri_height;//높이
};

#endif // !TR_H

