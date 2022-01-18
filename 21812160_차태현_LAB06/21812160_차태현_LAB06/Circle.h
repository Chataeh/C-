#ifndef CI_H
#define CI_H

#include"Shape.h"


class Circle : public Shape
{
	friend ostream& operator<<(ostream&, Circle&);//<<연산자
public:
	Circle();//default 생성자
	Circle(string name);//생성자
	Circle(int px, int py, int r, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);//생성자
	~Circle();//소멸자
	double getArea();//면적계산
	virtual void draw(ConsolePixelFrame cp_frame);//그리기
	void fprint(ostream&);//파일로 출력
	int getRadius()const { return radius; }//반지름 반환
	void setRadius(int r) { radius = r; }//반지름 설정
	Circle& operator=(const Circle& cir);//대입연산


protected:
	int radius;//반지름
};

#endif // !CI_H
