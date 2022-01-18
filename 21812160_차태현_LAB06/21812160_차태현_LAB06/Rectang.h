#ifndef RE_H
#define RE_H

#include"Shape.h"

class Rectang : public Shape
{
public:
	Rectang();//default 생성자
	Rectang(string name);//생성자
	Rectang(int px, int py, int w, int l, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);//생성자
	~Rectang();//소멸자
	double getArea();//면적계산
	virtual void draw(ConsolePixelFrame cp_frame);//그리기
	void fprint(ostream&);//파일출력
	int getWidth() { return width; }//가로반환
	int getLength() { return length; }//세로반환
	Rectang& operator=(Rectang& rec);//대입연산자
private:
	int width;//가로
	int length;//세로
};
#endif
