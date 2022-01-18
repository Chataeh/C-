#include"Circle.h"

ostream& operator<<(ostream& ostr, Circle& cir)//<<연산자 출력
{
	cir.fprint(ostr);

	return ostr;//ostr 반환
}

Circle::Circle()//default 생성자
	:Shape()
{
	radius = 0;//반지름 초기화
}

Circle::Circle(string name)//생성자
	:Shape(name)
{
	radius = 0;//반지름 초기화
}

Circle::Circle(int px, int py, int r, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name)//생성자
	:Shape(px,py,ang,ln_clr,br_clr,pen_thick,name)//Shape 생성자호출
{
	radius = r;//반지름
}

Circle::~Circle()//소멸자
{

}

double Circle::getArea()
{
	double result = 0.0;

	result = PI * radius * radius;//원의 면적 

	return result;
}

void Circle::draw(ConsolePixelFrame cp_frame)//원 그리기 
{
	HPEN new_pen, old_pen;
	HBRUSH new_brush, old_brush;
	HDC hdc;
	int pos_center_x, pos_center_y;
	
	pos_center_x = cp_frame.get_pos_org_x() + get_pos_x();//x좌표설정
	pos_center_y = cp_frame.get_pos_org_y() + get_pos_y();//y좌표설정
	
	hdc = cp_frame.getConsole_DC();	
	new_pen = CreatePen(PS_SOLID, pen_thickness, line_color);//펜 생성 직선
	old_pen = (HPEN)SelectObject(hdc, new_pen);
	new_brush = CreateSolidBrush(brush_color);//채우기 색 설정
	old_brush = (HBRUSH)SelectObject(hdc, new_brush);
	
	Ellipse(hdc, pos_center_x - radius, pos_center_y - radius, pos_center_x + radius,	pos_center_y + radius);//원 그리기
	
	SelectObject(hdc, old_pen);
	DeleteObject(new_pen);
	
	SelectObject(hdc, old_brush);
	DeleteObject(new_brush);
}

void Circle::fprint(ostream& fout)//출력함수
{
	Shape::fprint(fout);
	fout << ", radius(" << radius << ")" << endl;
}

Circle& Circle::operator=(const Circle& cir)//대입연산자
{
	Shape::operator=(cir);
	radius = cir.radius;

	return *this;
}