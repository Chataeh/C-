#include"Star.h"

Star::Star()//default ������
	:Shape()
{
	radius = 0;
	num_vertices = 0;

}

Star::Star(string name)//������
	:Shape(name)
{
	radius = 0;
	num_vertices = 0;
}

Star::Star(int px, int py, int radius, int num_vertices, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name)//������
	:Shape(px, py, ang, ln_clr, br_clr, pen_thick, name),radius(radius),num_vertices(num_vertices)//Shape ������ ȣ��
{

}

Star::~Star()//�Ҹ���
{

}

void Star::draw(ConsolePixelFrame cp_frame)
{
	POINT* points = (POINT*)malloc(5.0 * sizeof(POINT)); //������ 5�� 
	double rad_angle, delta_angle;
	
	int pos_center_x, pos_center_y;
	pos_center_x = cp_frame.get_pos_org_x() + get_pos_x();//���� x��ġ
	pos_center_y = cp_frame.get_pos_org_y() + get_pos_y();//���� y��ġ
	
	int x, y;
	HDC hdc;
	HPEN new_pen, old_pen;
	HBRUSH new_brush, old_brush;
	hdc = cp_frame.getConsole_DC();
	
	delta_angle = 2.0 * PI / 5.0;//5���� ������������ ����
	rad_angle = PI / 2.0;
	for (int i = 0; i < 5.0; i++, rad_angle +=	delta_angle)
	{
		x = pos_center_x + radius * cos(rad_angle);//x��ǥ
		y = pos_center_y - radius * sin(rad_angle);//y��ǥ
		points[i].x = x;
		points[i].y = y;
		
	}
	new_pen = CreatePen(PS_SOLID,pen_thickness, line_color);
	old_pen = (HPEN)SelectObject(hdc, new_pen);
	new_brush = CreateSolidBrush(brush_color);
	old_brush = (HBRUSH)SelectObject(hdc, new_brush);
	
	//���׸���
	MoveToEx(hdc, points[0].x, points[0].y, NULL);
	LineTo(hdc, points[2].x, points[2].y);
	LineTo(hdc, points[4].x, points[4].y);
	LineTo(hdc, points[1].x, points[1].y);
	LineTo(hdc, points[3].x, points[3].y);
	LineTo(hdc, points[0].x, points[0].y);
	
	SelectObject(hdc, old_pen);
	DeleteObject(new_pen);
	SelectObject(hdc, old_brush);
	DeleteObject(new_brush);
}

void Star::draw()
{
	cout << "draw() of Star";
	fprint(cout);
}

void Star::fprint(ostream& fout)
{
	Shape::fprint(fout);
	fout << ", radius (" << radius << "), num_vertices (" << num_vertices << ")" << endl;
}

Star& Star::operator=(Star& pg)//���� ������
{
	Shape::operator=(pg);//shape ���Կ����� ȣ��
	radius = pg.radius;
	num_vertices = pg.num_vertices;

	return *this;
}