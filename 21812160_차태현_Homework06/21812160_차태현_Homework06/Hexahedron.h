#ifndef HE_H
#define HE_H

#include"Shape.h"

class Hexahedron : public Shape
{
public:
	Hexahedron();
	Hexahedron(Position pos, int w, int l, int h, double ang, COLORREF color, string name);
	~Hexahedron();
	double getArea();//�ѳ��̰��
	double getVolume();//���ǰ��
	virtual void draw(ostream& fout);
	Hexahedron& operator=(const Hexahedron& hex);
protected:
	int height;//������� ����
	int width;//����
	int length;//����
};
#endif