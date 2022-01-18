#ifndef ST_H 
#define ST_H

#include "Shape.h"

class Star : public Shape
{
public:
	Star();//default ������
	Star(string name);//������
	Star(int px, int py, int radius, int num_vertices, double ang, COLORREF ln_clr,	COLORREF br_clr, int pen_thick, string name);//������
	~Star();//�Ҹ���
	virtual void draw(ConsolePixelFrame cp_frame);//�׸���
	virtual void draw(); 
	void fprint(ostream&);//���
	int getRadius() { return radius; }//������ ��ȯ
	int getNumPoly() { return num_vertices; }//������ �� ��ȯ
	Star& operator=(Star& pg);//���Կ�����
protected:
	int radius;//������
	int num_vertices;//������
};
#endif