#ifndef HE_H
#define HE_H

#include"Shape.h"

class Hexahedron : public Shape
{
public:
	Hexahedron();
	Hexahedron(Position pos, int w, int l, int h, double ang, COLORREF color, string name);
	~Hexahedron();
	double getArea();//겉넓이계산
	double getVolume();//부피계산
	virtual void draw(ostream& fout);
	Hexahedron& operator=(const Hexahedron& hex);
protected:
	int height;//각기둥의 높이
	int width;//가로
	int length;//세로
};
#endif