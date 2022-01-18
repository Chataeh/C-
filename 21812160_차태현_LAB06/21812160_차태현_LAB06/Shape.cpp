#include"Shape.h"

ostream& operator<<(ostream& ostr, Shape& s)//<<������
{
	s.fprint(ostr);//�Ʒ� ������ fprint �Լ��� ���� s��ü ���
	return ostr;
}

Shape::Shape()//default ������
{
	pos_x = 0;
	pos_y = 0;
	angle = 0;
	line_color = RGB_BLACK;
	brush_color = RGB_BLACK;
	name = "no_name";

	cout << "Shape default ������(" << name << ")" << endl;
}

Shape::Shape(string n)//������
{
	name = n;
	pos_x = 0;
	pos_y = 0;
	angle = 0;
	line_color = RGB_BLACK;
	brush_color = RGB_BLACK;

	cout << "Shape ������ name��(" << name << ")" << endl;
}

Shape::~Shape()//�Ҹ���
{
	cout << "Shape �Ҹ���" << name << endl;
}

Shape::Shape(int px, int py, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name)//������
{
	//���� �޾ƿ���
	pos_x = px;
	pos_y = py;
	angle = ang;
	line_color = ln_clr;
	brush_color = br_clr;
	pen_thickness = pen_thick;
	name = name;

	//cout << "Shape ������(" << name << ")" << endl;
}

void Shape::fprint(ostream& fout)//���Ϸ� ���
{
	fout << name << ": pos(" << pos_x << "," << pos_y << "), line_color(";
	fprintRGB(fout, line_color);
	fout << "), brush_color(";
	fprintRGB(fout, brush_color);
	fout << ")";

}

void Shape::draw(ConsolePixelFrame cp_frame)//draw �Ļ���ü�� draw ���
{

}

Shape& Shape::operator=(const Shape& s)//���Կ�����
{
	//�ڽŰ�ü�� s��ü�� ����
	pos_x = s.pos_x;
	pos_y = s.pos_y;
	angle = s.angle;
	name = s.name;
	line_color = s.line_color;
	brush_color = s.brush_color;

	return *this;//�ڽ� ��ü��ȯ
}


