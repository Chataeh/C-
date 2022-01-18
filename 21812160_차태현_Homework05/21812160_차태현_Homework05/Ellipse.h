#ifndef E_H
#define E_H
#include"Shape.h"

class Elps : public Shape//���
{
	friend ostream& operator<<(ostream&, const Elps&);//<<������ �������

public:
	Elps();//������
	Elps(string name);//������
	Elps(int px, int py, double r1, double r2, double ang, COLORREF clr, string name);//������
	~Elps();//�Ҹ���
	double getArea() const;//Ÿ������ ���
	void draw();
	void print(ostream&);
	double getRadius_1() const { return radius_1; }//������1 
	double getRadius_2() const { return radius_2; }//������2
	void setRadius(double r1, double r2) { radius_1 = r1; radius_2 = r2; }//������ ����
	Elps& operator=(const Elps& elp);//���Կ�����
protected:
	double radius_1;
	double radius_2;

};

#endif