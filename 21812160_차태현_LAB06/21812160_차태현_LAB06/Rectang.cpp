#include"Rectang.h"

Rectang::Rectang()//default ������
	:Shape()
{
	width = 0;
	length = 0;

}

Rectang::Rectang(string name)//������
	:Shape(name)
{
	width = 0;
	length = 0;
}

Rectang::Rectang(int px, int py, int w, int l, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name)//������
	:Shape(px,py,ang,ln_clr,br_clr,pen_thick,name)
{
	width = w;
	length = l;
}
Rectang::~Rectang()
{

}

double Rectang::getArea()//�簢�� �������
{
	double result = 0.0;

	result = width * length;//�簢�� ����

	return result;
}

void Rectang::draw(ConsolePixelFrame cp_frame)
{
	HDC hdc;
	HPEN new_pen, old_pen;
	HBRUSH new_brush, old_brush;
	int pos_center_x, pos_center_y;
	pos_center_x = cp_frame.get_pos_org_x() + get_pos_x();//x��ǥ����
	pos_center_y = cp_frame.get_pos_org_y() + get_pos_y();//y��ǥ����

	POINT p[4]; //������ 4�� 
	//�� ������ ��ġ����
	p[0].x = pos_center_x - width / 2;
	p[0].y = pos_center_y - length / 2;
	p[1].x = pos_center_x + width / 2;
	p[1].y = pos_center_y - length / 2.0;
	p[2].x = pos_center_x + width / 2;
	p[2].y = pos_center_y + length / 2.0;
	p[3].x = pos_center_x - width / 2;
	p[3].y = pos_center_y + length / 2.0;
	
	hdc = cp_frame.getConsole_DC();
	new_pen = CreatePen(PS_SOLID, pen_thickness, line_color);//�����
	old_pen = (HPEN)SelectObject(hdc, new_pen);
	new_brush = CreateSolidBrush(brush_color);//�귯�� ����
	old_brush = (HBRUSH)SelectObject(hdc, new_brush);

	Polygon(hdc, p, 4); //4�������� �ٰ��� ����
	SelectObject(hdc, old_pen);
	DeleteObject(new_pen);
	SelectObject(hdc, old_brush);
	DeleteObject(new_brush);
}

void Rectang::fprint(ostream& fout)//�������
{
	Shape::fprint(fout);
	fout << ", width (" << width << "), length(" << length << ")" << endl;
}

Rectang& Rectang::operator=(Rectang& rec)//���Կ�����
{
	Shape::operator=(rec);//Shape ���Կ�����ȣ��
	
	width = rec.width;
	length = rec.length;

	return *this;
}