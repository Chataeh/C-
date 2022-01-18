#ifndef CY_H 
#define CY_H 

#include "Shape.h" 

class Cylinder : public Shape
{
	friend ostream& operator<<(ostream&, const Cylinder&);//<<���� ������±��
public:
	Cylinder();
	Cylinder(string name);//������
	Cylinder(int px, int py, int r, int ang, int height, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);//������
	~Cylinder();//�Ҹ���
	double getArea();//�������
	virtual void draw(ConsolePixelFrame cp_frame);//�׸���
	virtual void draw(); 
	void fprint(ostream&);//���Ͽ� ���
	int getRadius() const { return radius; }//������ �ٳ���
	void setRadius(int r) { radius = r; }//������ ����
	Cylinder& operator=(const Cylinder& cir);//���Կ�����
protected:
	int radius;//������
	int height;//����
};
#endif