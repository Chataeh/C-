#ifndef AN_H 
#define AN_H 
 
#include "Shape.h" 


class AngledArc : public Shape
{
	friend ostream& operator<<(ostream&, const AngledArc&);//<<���� ��±��
public:
	AngledArc();//default ������
	AngledArc(string name);//������
	AngledArc(int px, int py, int r, int ang, int start_ang, int sweep_ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);//������
	~AngledArc();//�Ҹ���
	virtual void draw(ConsolePixelFrame cp_frame);//�׸���
	virtual void draw();
	void fprint(ostream&);//���� ���
	int getRadius() const { return radius; }//������ ��ȯ
	void setRadius(int r) { radius = r; }//����������
	AngledArc& operator=(const AngledArc& cir);//���Կ�����
protected:
	int radius;//������
	int start_angle;
	int sweep_angle;
};

#endif
