#ifndef TR_H
#define TR_H

#include"Shape.h"


class Triangle:public Shape
{
public:
	Triangle();//default ������
	Triangle(string name);//������
	Triangle(int px, int py, int b, int h, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);//������
	~Triangle();//�Ҹ���
	double getArea();//�������
	virtual void draw(ConsolePixelFrame cp_frame);//�׸���
	void fprint(ostream&);//���� ���
	int getBase() { return base; }//�غ� ��ȯ
	int getHeight() { return tri_height; }//s���̹�ȯ
	Triangle& operator=(const Triangle& tri);//���Կ�����

protected:
	int base;//�غ�
	int tri_height;//����
};

#endif // !TR_H

