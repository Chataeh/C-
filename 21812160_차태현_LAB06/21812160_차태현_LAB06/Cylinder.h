#ifndef CY_H 
#define CY_H 

#include "Shape.h" 

class Cylinder : public Shape
{
	friend ostream& operator<<(ostream&, const Cylinder&);//<<연산 파일출력기능
public:
	Cylinder();
	Cylinder(string name);//생성자
	Cylinder(int px, int py, int r, int ang, int height, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);//생성자
	~Cylinder();//소멸자
	double getArea();//면전계산
	virtual void draw(ConsolePixelFrame cp_frame);//그리기
	virtual void draw(); 
	void fprint(ostream&);//파일에 출력
	int getRadius() const { return radius; }//반지름 바노한
	void setRadius(int r) { radius = r; }//반지름 설정
	Cylinder& operator=(const Cylinder& cir);//대입연산자
protected:
	int radius;//반지름
	int height;//높이
};
#endif