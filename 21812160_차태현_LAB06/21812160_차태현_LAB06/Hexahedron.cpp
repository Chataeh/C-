#include"Hexahedron.h"


Hexahedron::Hexahedron()
	:Shape()
{
	width= 0;
	length = 0;
	height = 0;

}

Hexahedron::Hexahedron(string name)
	:Shape(name)
{
	width = 0;
	length = 0;
	height = 0;
}

Hexahedron::Hexahedron(int px, int py, int w, int l, int h, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name)
	:Shape(px, py, ang, ln_clr, br_clr, pen_thick, name), height(h), width(w), length(l)
{

}

Hexahedron::~Hexahedron()
{

}

void Hexahedron::draw(ConsolePixelFrame cp_frame)
{
	HDC hdc;
	HPEN new_pen, old_pen;
	HBRUSH new_brush, old_brush;
	int pos_center_x, pos_center_y;
	pos_center_x = cp_frame.get_pos_org_x() + get_pos_x();//x좌표설정
	pos_center_y = cp_frame.get_pos_org_y() + get_pos_y();//y좌표설정

	int len = length * cos(angle);
	
	hdc = cp_frame.getConsole_DC();
	new_pen = CreatePen(PS_SOLID, pen_thickness, line_color);
	old_pen = (HPEN)SelectObject(hdc, new_pen);
	new_brush = CreateSolidBrush(brush_color);
	old_brush = (HBRUSH)SelectObject(hdc, new_brush);
	
	POINT p[4]; //꼭지점 4개 

	p[0].x = pos_center_x - width / 2;
	p[0].y = pos_center_y - length / 2;
	p[1].x =p[0].x +width ;
	p[1].y = p[0].y ;
	p[2].x = p[1].x - len * cos(angle);
	p[2].y = p[1].y + len * sin(angle);
	p[3].x = p[0].x - len * cos(angle);
	p[3].y = p[0].y + len * sin(angle);
	
	
	Polygon(hdc, p, 4); //4개꼭지점 다각형 생성
	
	MoveToEx(hdc, p[1].x, p[1].y  , (LPPOINT)NULL);//1번점 높이
	LineTo(hdc, p[1].x, p[1].y + height );
	MoveToEx(hdc, p[2].x, p[2].y , (LPPOINT)NULL);//2번점 높이
	LineTo(hdc, p[2].x, p[2].y + height);
	MoveToEx(hdc, p[3].x, p[3].y, (LPPOINT)NULL);//3번점 높이
	LineTo(hdc, p[3].x, p[3].y + height);
	MoveToEx(hdc, p[1].x, p[1].y + height, (LPPOINT)NULL);//1-2아래 긋기
	LineTo(hdc, p[2].x, p[2].y + height);
	MoveToEx(hdc, p[3].x, p[3].y + height, (LPPOINT)NULL);//2-3아래 긋기
	LineTo(hdc, p[2].x, p[2].y + height);
	
	

	
	SelectObject(hdc, old_pen);
	DeleteObject(new_pen);
	SelectObject(hdc, old_brush);
	DeleteObject(new_brush);
}

Hexahedron& Hexahedron::operator=(const Hexahedron& hex)
{
	Shape::operator=(hex);
	height = hex.height;
	width = hex.width;
	length = hex.length;

	return *this;
}