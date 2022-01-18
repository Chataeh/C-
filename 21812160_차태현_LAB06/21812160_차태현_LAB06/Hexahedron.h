#ifndef He_H
#define He_H

#include"Shape.h"

class Hexahedron : public Shape
{
public:
	Hexahedron();
	Hexahedron(string name);
	Hexahedron(int px, int py, int w, int l, int h, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);
	~Hexahedron();
	virtual void draw(ConsolePixelFrame cp_frame);
	Hexahedron& operator=(const Hexahedron& hex);

protected:
	int height;//각기둥의 높이
	int width;//가로
	int length;//세로
};




#endif