#ifndef PR_H
#define PR_H

#include"Shape.h"

class Prism : public Shape
{
public:
	Prism();
	Prism(string name);
	Prism(int px, int py, int b, int t_h, int h, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);
	~Prism();
	virtual void draw(ConsolePixelFrame cp_frame);
	Prism& operator=(const Prism& pri);

protected:
	int height;//∞¢±‚µ’¿« ≥Ù¿Ã
	int base;//πÿ∫Ø
	int tri_height;//ªÔ∞¢«¸¿« ≥Ù¿Ã
};




#endif