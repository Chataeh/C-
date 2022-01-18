#include"Triangle.h"

Triangle::Triangle()//default 생성자
	:Shape()
{
	base = 0;
	tri_height = 0;
}

Triangle::Triangle(string name)//생성자
	:Shape(name)
{
	base = 0;
	tri_height = 0;
}

Triangle::Triangle(int px, int py, int b, int h, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name)//생성자
	:Shape(px,py,ang,ln_clr,br_clr,pen_thick,name)
{
	base = b;
	tri_height = h;
}

Triangle::~Triangle()//소멸자
{

}

double Triangle::getArea()//면적구하기
{
	double result = 0.0;

	result = (base * tri_height) / 2;//삼각형 면적계산

	return result;
}

void Triangle::draw(ConsolePixelFrame cp_frame)
{
	HDC hdc;
	HPEN new_pen, old_pen;
	HBRUSH new_brush, old_brush;
	int pos_center_x, pos_center_y;
	pos_center_x = cp_frame.get_pos_org_x() + get_pos_x();//x좌표 설정
	pos_center_y = cp_frame.get_pos_org_y() + get_pos_y();//y좌표 설정
	
	POINT p[3]; // 꼭지점 세개
	//각각의 꼭지점 위치 설정
	p[0].x = pos_center_x - base / 2;
	p[0].y = pos_center_y + tri_height * 1.0 / 2.0;
	p[1].x = pos_center_x + base / 2;
	p[1].y = pos_center_y + tri_height * 1.0 / 2.0;
	p[2].x = pos_center_x;
	p[2].y = pos_center_y - tri_height * 1.0 / 2.0;
	
	hdc = cp_frame.getConsole_DC();
	new_pen = CreatePen(PS_SOLID, pen_thickness, line_color); // 펜생성
	old_pen = (HPEN)SelectObject(hdc, new_pen); 
	new_brush = CreateSolidBrush(brush_color); //색 책우기 브러쉬 생성
	old_brush = (HBRUSH)SelectObject(hdc, new_brush);

	Polygon(hdc, p, 3);//다각형 출력
	SelectObject(hdc, old_pen); 
	DeleteObject(new_pen); 
	SelectObject(hdc, old_brush); 
	DeleteObject(new_brush); 
}


void Triangle::fprint(ostream& fout)//파일출력
{
	Shape::fprint(fout);
	fout << ", base (" << base << "), tri_height (" << tri_height << ")" << endl;
}

Triangle& Triangle::operator=(const Triangle& tri)//대입연산자
{
	Shape::operator=(tri);//Shape 대입연산자 호출
	base = tri.base;
	tri_height = tri.tri_height;

	return *this;//자기자신객체 반환
}