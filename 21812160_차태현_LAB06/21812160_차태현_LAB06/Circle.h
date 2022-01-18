#ifndef CI_H
#define CI_H

#include"Shape.h"


class Circle : public Shape
{
	friend ostream& operator<<(ostream&, Circle&);//<<������
public:
	Circle();//default ������
	Circle(string name);//������
	Circle(int px, int py, int r, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);//������
	~Circle();//�Ҹ���
	double getArea();//�������
	virtual void draw(ConsolePixelFrame cp_frame);//�׸���
	void fprint(ostream&);//���Ϸ� ���
	int getRadius()const { return radius; }//������ ��ȯ
	void setRadius(int r) { radius = r; }//������ ����
	Circle& operator=(const Circle& cir);//���Կ���


protected:
	int radius;//������
};

#endif // !CI_H
