#ifndef TR_H
#define TR_H

#include"Shape.h"

class Triangle :public Shape
{
public:
	Triangle();//default ������
	Triangle(Position pos, int b, int h, double ang, COLORREF color, string name);//������
	~Triangle();//�Ҹ���
	double getArea();//�������
	virtual void draw(ostream& fout);//�׸���
	Triangle& operator=(const Triangle& tri);//���Կ�����
protected:
	int base;//�ﰢ�� �غ�
	int tri_height;//�ﰢ�� ����
};


#endif // !TR_H
