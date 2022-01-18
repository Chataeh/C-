#ifndef ST_H 
#define ST_H

#include "Shape.h"

class Star : public Shape
{
public:
	Star();//default 생성자
	Star(string name);//생성자
	Star(int px, int py, int radius, int num_vertices, double ang, COLORREF ln_clr,	COLORREF br_clr, int pen_thick, string name);//생성자
	~Star();//소멸자
	virtual void draw(ConsolePixelFrame cp_frame);//그리기
	virtual void draw(); 
	void fprint(ostream&);//출력
	int getRadius() { return radius; }//반지름 반환
	int getNumPoly() { return num_vertices; }//꼭지점 수 반환
	Star& operator=(Star& pg);//대입연산자
protected:
	int radius;//반지름
	int num_vertices;//꼭지점
};
#endif