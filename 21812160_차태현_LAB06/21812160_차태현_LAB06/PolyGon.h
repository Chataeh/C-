#ifndef PO_H
#define PO_H

#include"Shape.h"

class PolyGon :public Shape
{
public:
	PolyGon();//생성자
	PolyGon(string name);//생성자
	PolyGon(int px, int py, int radius, int num_poly, double ang, COLORREF ln_clr, COLORREF br_clr,	int pen_thick, string name);//생성자
	~PolyGon();//소멸자
	virtual void draw(ConsolePixelFrame cp_frame);//그리기
	void fprint(ostream&);//파일 출력
	int getRadius() { return radius; }//반지름 반환
	int getNumPoly() { return num_poly; }//각의 수 반환
	PolyGon& operator=(PolyGon& pg);//대입연산자
protected:
	int radius;//반지름
	int num_poly;//각의 수
};

#endif // !PO_H
