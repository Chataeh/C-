#ifndef RE_H
#define RE_H

#include"Shape.h"

class Rectang :public Shape
{
public:
	Rectang ();//default 생성자
	Rectang (Position pos, int w, int l, double ang, COLORREF color, string name);//생성자
	~Rectang();//소멸자
	double getArea();//면적계산
	virtual void draw(ostream& fout);//그리기
	Rectang& operator=(Rectang& rec);//대입연산자
protected:
	int width;//가로
	int length;//세로
};
#endif // !Re_H
