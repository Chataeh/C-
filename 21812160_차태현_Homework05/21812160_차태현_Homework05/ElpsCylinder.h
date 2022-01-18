#ifndef EC_H
#define EC_H
#include"Ellipse.h"


class ElpsCylinder : public Elps//���
{
	friend ostream& operator<< (ostream& ostr, const ElpsCylinder& elpcyl);//<<������ ��±��

public:
	ElpsCylinder(); // default ������
	ElpsCylinder(string n);//������
	ElpsCylinder(int px, int py, double r1, double r2, double h, double ang, COLORREF clr, string n);//������
	virtual ~ElpsCylinder();
	double getArea() const;//ǥ�������ϱ�
	double getVolume() const;//���Ǳ��ϱ�
	void draw();
	void print(ostream&);
	ElpsCylinder& operator=(const ElpsCylinder& right);//���Կ�����
protected:
	double height;
};




#endif