#include"Cylinder.h"

ostream& operator<<(ostream& fout, const Cylinder& cyl)
{
	fout << cyl.name << ": pos(" << cyl.get_pos_x() << ", " << cyl.get_pos_y() << "), line_color(";
	fprintRGB(fout, cyl.line_color);
	fout << "), brush_color(";
	fprintRGB(fout, cyl.brush_color);
	fout << ") radius(" << cyl.radius << "), height (" << cyl.height << ")" << endl;
	
	return fout;
}

Cylinder::Cylinder()//생성자
	:Shape()
{
	radius = 0;
	height = 0;
}

Cylinder::Cylinder(string name)
	:Shape(name)
{
	radius = 0;
	height = 0;
}

Cylinder::Cylinder(int px, int py, int r, int ang, int height, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name)//생성자
	:Shape(px, py, ang, ln_clr, br_clr, pen_thick, name),radius(r),height(height)//Shape 생성자 호출
{
	
}

Cylinder::~Cylinder()//소멸자
{

}

double Cylinder::getArea()
{
	double result = 0.0;

	result = 2 * PI * sqrt(radius * radius);

	return result;
}

void Cylinder::draw(ConsolePixelFrame cp_frame)
{
	HPEN new_pen, old_pen; 
	HBRUSH new_brush, old_brush;
	HDC hdc;
	int center_px, center_py; 
	int start_px, start_py; 
	double start_ang_rad;
	
	center_px = cp_frame.get_pos_org_x() + get_pos_x();
	center_py = cp_frame.get_pos_org_y() + get_pos_y();

	hdc = cp_frame.getConsole_DC(); 
	new_pen = CreatePen(PS_SOLID, pen_thickness, line_color); 
	old_pen = (HPEN)SelectObject(hdc, new_pen); 
	new_brush = CreateSolidBrush(brush_color);
	old_brush = (HBRUSH)SelectObject(hdc, new_brush);
	

	MoveToEx(hdc, center_px - radius, center_py - height / 2, (LPPOINT)NULL);//기둥의 선 그리기
	LineTo(hdc, center_px - radius, center_py + height / 2);
	MoveToEx(hdc, center_px + radius, center_py - height / 2, (LPPOINT)NULL);//기둥의 선 그리기
	LineTo(hdc, center_px + radius, center_py + height / 2);
	Ellipse(hdc, center_px - radius, center_py - height / 2 - 20, center_px + radius, center_py - height / 2 + 20);
	MoveToEx(hdc, center_px - radius, center_py + height / 2, (LPPOINT)NULL);
	ArcTo(hdc, center_px - radius, center_py + height / 2 - 20, center_px + radius, center_py + height / 2 + 20, center_px - radius, center_py + height / 2, center_px + radius, center_py + height / 2);//호 그림
	
	SelectObject(hdc, old_pen);
	DeleteObject(new_pen);
	
	SelectObject(hdc, old_brush);
	DeleteObject(new_brush);
}
void Cylinder::draw()
{
	cout << "draw() of Cylinder";
	fprint(cout);
}

void Cylinder::fprint(ostream& fout)
{
	Shape::fprint(fout);
	fout << ") radius(" << radius << "), height (" << height << ")" << endl;
}

Cylinder& Cylinder ::operator=(const Cylinder& cir)
{
	Shape::operator=(cir);//Shape 대입연산자 호출

	radius = cir.radius;
	height = cir.height;

	return *this;
}