#ifndef RE_H
#define RE_H

#include"Shape.h"

class Rectang : public Shape
{
public:
	Rectang();//default ������
	Rectang(string name);//������
	Rectang(int px, int py, int w, int l, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);//������
	~Rectang();//�Ҹ���
	double getArea();//�������
	virtual void draw(ConsolePixelFrame cp_frame);//�׸���
	void fprint(ostream&);//�������
	int getWidth() { return width; }//���ι�ȯ
	int getLength() { return length; }//���ι�ȯ
	Rectang& operator=(Rectang& rec);//���Կ�����
private:
	int width;//����
	int length;//����
};
#endif
