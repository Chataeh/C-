#include"Rectang.h"

Rectang::Rectang()//default 생성자
	:Shape()
{
	width = 0;
	length = 0;

}

Rectang::Rectang(string name)//생성자
	:Shape(name)
{
	width = 0;
	length = 0;
}

Rectang::Rectang(int px, int py, int w, int l, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name)//생성자
	:Shape(px,py,ang,ln_clr,br_clr,pen_thick,name)
{
	width = w;
	length = l;
}
Rectang::~Rectang()
{

}

double Rectang::getArea()//사각형 면적계산
{
	double result = 0.0;

	result = width * length;//사각형 면적

	return result;
}

void Rectang::draw(ConsolePixelFrame cp_frame)
{
	HDC hdc;
	HPEN new_pen, old_pen;
	HBRUSH new_brush, old_brush;
	int pos_center_x, pos_center_y;
	pos_center_x = cp_frame.get_pos_org_x() + get_pos_x();//x좌표설정
	pos_center_y = cp_frame.get_pos_org_y() + get_pos_y();//y좌표설정

	POINT p[4]; //꼭지점 4개 
	//각 꼭지점 위치설정
	p[0].x = pos_center_x - width / 2;
	p[0].y = pos_center_y - length / 2;
	p[1].x = pos_center_x + width / 2;
	p[1].y = pos_center_y - length / 2.0;
	p[2].x = pos_center_x + width / 2;
	p[2].y = pos_center_y + length / 2.0;
	p[3].x = pos_center_x - width / 2;
	p[3].y = pos_center_y + length / 2.0;
	
	hdc = cp_frame.getConsole_DC();
	new_pen = CreatePen(PS_SOLID, pen_thickness, line_color);//펜생성
	old_pen = (HPEN)SelectObject(hdc, new_pen);
	new_brush = CreateSolidBrush(brush_color);//브러쉬 생성
	old_brush = (HBRUSH)SelectObject(hdc, new_brush);

	Polygon(hdc, p, 4); //4개꼭지점 다각형 생성
	SelectObject(hdc, old_pen);
	DeleteObject(new_pen);
	SelectObject(hdc, old_brush);
	DeleteObject(new_brush);
}

void Rectang::fprint(ostream& fout)//파일출력
{
	Shape::fprint(fout);
	fout << ", width (" << width << "), length(" << length << ")" << endl;
}

Rectang& Rectang::operator=(Rectang& rec)//대입연산자
{
	Shape::operator=(rec);//Shape 대입연산자호출
	
	width = rec.width;
	length = rec.length;

	return *this;
}