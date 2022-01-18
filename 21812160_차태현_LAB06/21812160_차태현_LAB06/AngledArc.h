#ifndef AN_H 
#define AN_H 
 
#include "Shape.h" 


class AngledArc : public Shape
{
	friend ostream& operator<<(ostream&, const AngledArc&);//<<연산 출력기능
public:
	AngledArc();//default 생성자
	AngledArc(string name);//생성자
	AngledArc(int px, int py, int r, int ang, int start_ang, int sweep_ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);//생성자
	~AngledArc();//소멸자
	virtual void draw(ConsolePixelFrame cp_frame);//그리기
	virtual void draw();
	void fprint(ostream&);//파일 출력
	int getRadius() const { return radius; }//반지름 반환
	void setRadius(int r) { radius = r; }//반지름설정
	AngledArc& operator=(const AngledArc& cir);//대입연산자
protected:
	int radius;//반지름
	int start_angle;
	int sweep_angle;
};

#endif
