#include"Prism.h"


Prism::Prism()
	:Shape()
{
	base = 0;
	tri_height = 0;
	height = 0;

}

Prism::Prism(string name)
	:Shape(name)
{
	base = 0;
	tri_height = 0;
	height = 0;
}

Prism::Prism(int px, int py, int b, int t_h, int h, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name)
	:Shape(px, py, ang, ln_clr, br_clr, pen_thick, name),height(h),base(b),tri_height(t_h)
{

}

Prism::~Prism()
{

}

void Prism::draw(ConsolePixelFrame cp_frame)
{
	HDC hdc;
	HPEN new_pen, old_pen;
	HBRUSH new_brush, old_brush;
	int pos_center_x, pos_center_y;
	
	pos_center_x = cp_frame.get_pos_org_x() + get_pos_x();//x좌표 설정
	pos_center_y = cp_frame.get_pos_org_y() + get_pos_y();//y좌표 설정

	hdc = cp_frame.getConsole_DC();
	new_pen = CreatePen(PS_SOLID, pen_thickness, line_color); // 펜생성
	old_pen = (HPEN)SelectObject(hdc, new_pen);
	new_brush = CreateSolidBrush(brush_color); //색 책우기 브러쉬 생성
	old_brush = (HBRUSH)SelectObject(hdc, new_brush);

	POINT p[3]; // 꼭지점 세개
	//각각의 꼭지점 기둥선을 그리기위한 위치 설정
	p[0].x = pos_center_x - base / 2;
	p[0].y = pos_center_y + tri_height * 1.0 / 2.0;
	p[1].x = pos_center_x + base / 2;
	p[1].y = pos_center_y + tri_height * 1.0 / 2.0;
	p[2].x = pos_center_x;
	p[2].y = pos_center_y - tri_height * 1.0 / 2.0;

	MoveToEx(hdc, p[0].x, p[0].y-height/2, (LPPOINT)NULL);
	LineTo(hdc, p[0].x, p[0].y+ height / 2);
	MoveToEx(hdc, p[1].x, p[1].y - height / 2, (LPPOINT)NULL);
	LineTo(hdc, p[1].x, p[1].y + height / 2);
	//MoveToEx(hdc, p[2].x, p[2].y - height / 2, (LPPOINT)NULL);
	//LineTo(hdc, p[2].x, p[2].y + height / 2);
	
	//삼각형을 그리기위한 위치 재설정
	p[0].x = pos_center_x - base / 2;
	p[0].y = pos_center_y + tri_height * 1.0 / 2.0 - height / 2;
	p[1].x = pos_center_x + base / 2;
	p[1].y = pos_center_y + tri_height * 1.0 / 2.0 - height / 2;
	p[2].x = pos_center_x;
	p[2].y = pos_center_y - tri_height * 1.0 / 2.0 - height / 2;
	
	Polygon(hdc,p, 3);
	
	MoveToEx(hdc, p[0].x, p[0].y + height, (LPPOINT)NULL);//아래 정면 선
	LineTo(hdc, p[1].x, p[1].y+height);
	


	SelectObject(hdc, old_pen);
	DeleteObject(new_pen);
	SelectObject(hdc, old_brush);
	DeleteObject(new_brush);
}

Prism& Prism::operator=(const Prism& pri)
{
	Shape::operator=(pri);
	height = pri.height;
	base = pri.base;
	tri_height = pri.tri_height;

	return *this;
}