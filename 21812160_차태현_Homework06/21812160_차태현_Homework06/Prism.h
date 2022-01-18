#ifndef PR_H
#define PR_H

#include"Shape.h"

class Prism : public Shape
{
public:
	Prism();//default ������
	Prism(Position pos, int b, int t_h,int h, double ang, COLORREF color, string name);//������
	~Prism();//�Ҹ���
	double getArea();//�ѳ��̰��
	double getVolume();//���ǰ��
	virtual void draw(ostream& fout);//�׸���
	Prism& operator=(const  Prism& pri);//���Կ�����

protected:
	int base;//�ﰢ�� �غ�
	int tri_height;//�ﰢ�� ����
	int height;//��� ����
};


#endif // !PR_H
