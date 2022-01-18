#include"Circle.h"

ostream& operator<<(ostream& ostr, Circle& cir)//<<������ ���
{
	cir.fprint(ostr);

	return ostr;//ostr ��ȯ
}

Circle::Circle()//default ������
	:Shape()
{
	radius = 0;//������ �ʱ�ȭ
}

Circle::Circle(string name)//������
	:Shape(name)
{
	radius = 0;//������ �ʱ�ȭ
}

Circle::Circle(int px, int py, int r, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name)//������
	:Shape(px,py,ang,ln_clr,br_clr,pen_thick,name)//Shape ������ȣ��
{
	radius = r;//������
}

Circle::~Circle()//�Ҹ���
{

}

double Circle::getArea()
{
	double result = 0.0;

	result = PI * radius * radius;//���� ���� 

	return result;
}

void Circle::draw(ConsolePixelFrame cp_frame)//�� �׸��� 
{
	HPEN new_pen, old_pen;
	HBRUSH new_brush, old_brush;
	HDC hdc;
	int pos_center_x, pos_center_y;
	
	pos_center_x = cp_frame.get_pos_org_x() + get_pos_x();//x��ǥ����
	pos_center_y = cp_frame.get_pos_org_y() + get_pos_y();//y��ǥ����
	
	hdc = cp_frame.getConsole_DC();	
	new_pen = CreatePen(PS_SOLID, pen_thickness, line_color);//�� ���� ����
	old_pen = (HPEN)SelectObject(hdc, new_pen);
	new_brush = CreateSolidBrush(brush_color);//ä��� �� ����
	old_brush = (HBRUSH)SelectObject(hdc, new_brush);
	
	Ellipse(hdc, pos_center_x - radius, pos_center_y - radius, pos_center_x + radius,	pos_center_y + radius);//�� �׸���
	
	SelectObject(hdc, old_pen);
	DeleteObject(new_pen);
	
	SelectObject(hdc, old_brush);
	DeleteObject(new_brush);
}

void Circle::fprint(ostream& fout)//����Լ�
{
	Shape::fprint(fout);
	fout << ", radius(" << radius << ")" << endl;
}

Circle& Circle::operator=(const Circle& cir)//���Կ�����
{
	Shape::operator=(cir);
	radius = cir.radius;

	return *this;
}