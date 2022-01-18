#include"AngledArc.h"

ostream& operator<<(ostream& fout, const AngledArc& ang_arc)
{
	fout << ang_arc.name << ": pos(" << ang_arc.get_pos_x() << ", " << ang_arc.get_pos_y() << ")"<< ", line_color("; 
	fprintRGB(fout, ang_arc.line_color);
	fout<< "), brush_color("; 
	fprintRGB(fout, ang_arc.brush_color);
	fout<< "), radius(" << ang_arc.radius << "), start_ang (" << ang_arc.start_angle << "), sweep_ang(" << ang_arc.sweep_angle << ")"<< endl;
	
	return fout;
}

AngledArc::AngledArc()//생성자
	:Shape()
{
	radius = 0;
	start_angle = 0;
	sweep_angle = 0;
}

AngledArc::AngledArc(string name)//생성자
	:Shape(name)
{
	radius = 0;
	start_angle = 0;
	sweep_angle = 0;
}

AngledArc::AngledArc(int px, int py, int r, int ang, int start_ang, int sweep_ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name)
	:Shape(px, py, ang, ln_clr, br_clr, pen_thick, name)//Shape 생성자 호출
{
	radius = r;
	start_angle = start_ang;
	sweep_angle = sweep_ang;
}

AngledArc::~AngledArc()//소멸자
{

}

void AngledArc::draw()
{
	cout << "draw() of AngleArc";
	fprint(cout);
}

void AngledArc::draw(ConsolePixelFrame cp_frame)
{
	HPEN new_pen, old_pen;
	HBRUSH new_brush, old_brush;
	HDC hdc;
	int fr_px, fr_py;
	int start_px, start_py;
	double start_ang_rad;
	
	fr_px = cp_frame.get_pos_org_x() + get_pos_x();
	fr_py = cp_frame.get_pos_org_y() + get_pos_y();
	
	hdc = cp_frame.getConsole_DC();
	new_pen = CreatePen(PS_SOLID, pen_thickness, line_color);
	old_pen = (HPEN)SelectObject(hdc, new_pen);
	new_brush = CreateSolidBrush(brush_color);
	old_brush = (HBRUSH)SelectObject(hdc, new_brush);
	
	start_ang_rad = start_angle * 3.141592 / 180.0;
	start_px = fr_px + radius * cos(start_ang_rad);
	start_py = fr_py - radius * sin(start_ang_rad);
	MoveToEx(hdc, fr_px, fr_py, (LPPOINT)NULL);
	LineTo(hdc, start_px, start_py);
	AngleArc(hdc, fr_px, fr_py, radius, start_angle, sweep_angle);
	LineTo(hdc, fr_px, fr_py);
	
	SelectObject(hdc, old_pen);
	DeleteObject(new_pen);
	
	SelectObject(hdc, old_brush);
	DeleteObject(new_brush);
}

void AngledArc::fprint(ostream& fout)
{
	Shape::fprint(fout);
	fout << ", radius (" << radius << "), start_angle (" << start_angle << "), sweep_angle (" << sweep_angle << ")" << endl;
}

AngledArc& AngledArc::operator=(const AngledArc& cir)
{
	Shape::operator=(cir);//Shape 대입연산자 호출

	radius = cir.radius;
	start_angle = cir.start_angle;
	sweep_angle = cir.sweep_angle;

	return *this;
}