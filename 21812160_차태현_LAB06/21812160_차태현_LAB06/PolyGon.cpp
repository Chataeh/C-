#include"PolyGon.h"

PolyGon::PolyGon()// default 생성자
	:Shape(),radius(0),num_poly(0)
{

}

PolyGon::PolyGon(string name)//생성자
	:Shape(name),radius(0), num_poly(0)
{

}

PolyGon::PolyGon(int px, int py, int radius, int num_poly, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name)//생성자
	:Shape(px, py, ang, ln_clr, br_clr, pen_thick, name), radius(radius), num_poly(num_poly)//Shape 생성자 호출
{
	
}
PolyGon::~PolyGon()//소멸자
{

}

void PolyGon::draw(ConsolePixelFrame cp_frame)
{
	POINT* points = (POINT*)malloc(num_poly * sizeof(POINT));//꼭지점 수 동적메모리 할당
	double rad_angle, delta_angle; 
	int pos_center_x, pos_center_y;
	pos_center_x = cp_frame.get_pos_org_x() + get_pos_x();//x좌표 설정
	pos_center_y = cp_frame.get_pos_org_y() + get_pos_y();//y좌표 설정
	

	int x, y;
	HDC hdc;
	HPEN new_pen, old_pen;
	HBRUSH new_brush, old_brush;
	hdc = cp_frame.getConsole_DC();

	delta_angle = 2.0 * PI / num_poly; //꼭지점 사이 각도
	rad_angle = PI / 2.0;
	
	for (int i = 0; i < num_poly; i++, rad_angle += delta_angle)//꼭지점 수 만큼 반복
	{
		x = pos_center_x + radius * cos(rad_angle); //x좌표
		y = pos_center_y - radius * sin(rad_angle); //y좌표
		points[i].x = x; 
		points[i].y = y;
	}
	

	new_pen = CreatePen(PS_SOLID, pen_thickness, line_color); //펜생성
	old_pen = (HPEN)SelectObject(hdc, new_pen);
	new_brush = CreateSolidBrush(brush_color);//브러쉬 생성
	old_brush = (HBRUSH)SelectObject(hdc, new_brush);

	Polygon(hdc, points, num_poly); //다각형 그리기
	SelectObject(hdc, old_pen);
	DeleteObject(new_pen);
	SelectObject(hdc, old_brush);
	DeleteObject(new_brush);
}

void PolyGon::fprint(ostream& fout)
{
	Shape::fprint(fout);
	fout << ", radius (" << radius << "), num_poly (" << num_poly << ")" << endl;
}

PolyGon& PolyGon ::operator=(PolyGon& pg)
{
	Shape::operator=(pg);//Shape 대입연산자 호출
	
	radius = pg.radius;
	num_poly = pg.num_poly;

	return *this;
}