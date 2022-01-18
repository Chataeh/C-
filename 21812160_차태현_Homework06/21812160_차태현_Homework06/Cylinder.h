#ifndef CY_H
#define CY_H

#include"Shape.h"

class Cylinder :public Shape
{
public:
	Cylinder();//default ������
	Cylinder(Position pos, int r, int h, double ang, COLORREF color, string name);//������
	~Cylinder();//�Ҹ���
	double getArea();//�ѳ��̰��
	double getVolume();//���ǰ��
	virtual void draw(ostream& fout);//�׸���
	Cylinder& operator=(const  Cylinder&cy);//���Կ�����
protected:
	int radius;//������
	int height;//����
};

#endif CY_H
