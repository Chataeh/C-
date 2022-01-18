#ifndef CI_H
#define CI_H

#include"Shape.h"

class Circle : public Shape
{
public:
	Circle(); // default������
	Circle(Position pos, int r, double ang, COLORREF color, string name); //  ������
	~Circle(); // �Ҹ���
	double getArea(); //���� ���
	virtual void draw(ostream& fout); // �����Լ� 
	Circle& operator=(const Circle& cir); // ���Կ�����
protected:
	int radius; // ������
};

#endif // !CI_H
