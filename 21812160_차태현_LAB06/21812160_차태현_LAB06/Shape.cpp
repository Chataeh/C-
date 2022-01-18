#include"Shape.h"

ostream& operator<<(ostream& ostr, Shape& s)//<<연산자
{
	s.fprint(ostr);//아래 생성한 fprint 함수를 통한 s객체 출력
	return ostr;
}

Shape::Shape()//default 생성자
{
	pos_x = 0;
	pos_y = 0;
	angle = 0;
	line_color = RGB_BLACK;
	brush_color = RGB_BLACK;
	name = "no_name";

	cout << "Shape default 생성자(" << name << ")" << endl;
}

Shape::Shape(string n)//생성자
{
	name = n;
	pos_x = 0;
	pos_y = 0;
	angle = 0;
	line_color = RGB_BLACK;
	brush_color = RGB_BLACK;

	cout << "Shape 생성자 name만(" << name << ")" << endl;
}

Shape::~Shape()//소멸자
{
	cout << "Shape 소멸자" << name << endl;
}

Shape::Shape(int px, int py, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name)//생성자
{
	//값들 받아오기
	pos_x = px;
	pos_y = py;
	angle = ang;
	line_color = ln_clr;
	brush_color = br_clr;
	pen_thickness = pen_thick;
	name = name;

	//cout << "Shape 생성자(" << name << ")" << endl;
}

void Shape::fprint(ostream& fout)//파일로 출력
{
	fout << name << ": pos(" << pos_x << "," << pos_y << "), line_color(";
	fprintRGB(fout, line_color);
	fout << "), brush_color(";
	fprintRGB(fout, brush_color);
	fout << ")";

}

void Shape::draw(ConsolePixelFrame cp_frame)//draw 파생객체의 draw 사용
{

}

Shape& Shape::operator=(const Shape& s)//대입연산자
{
	//자신객체에 s객체값 대입
	pos_x = s.pos_x;
	pos_y = s.pos_y;
	angle = s.angle;
	name = s.name;
	line_color = s.line_color;
	brush_color = s.brush_color;

	return *this;//자신 객체반환
}


