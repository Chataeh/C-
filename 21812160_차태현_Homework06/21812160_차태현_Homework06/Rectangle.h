#ifndef RE_H
#define RE_H

#include"Shape.h"

class Rectang :public Shape
{
public:
	Rectang ();//default ������
	Rectang (Position pos, int w, int l, double ang, COLORREF color, string name);//������
	~Rectang();//�Ҹ���
	double getArea();//�������
	virtual void draw(ostream& fout);//�׸���
	Rectang& operator=(Rectang& rec);//���Կ�����
protected:
	int width;//����
	int length;//����
};
#endif // !Re_H
