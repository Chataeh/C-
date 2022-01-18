#include"Rectangle.h"

Rectang::Rectang()//default 생성자
	:Shape()
{
	width = 0;
	length = 0;

}


Rectang::Rectang(Position pos, int w, int l, double ang, COLORREF color, string name)//생성자
	:Shape(pos, ang, color, name)
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

void Rectang::draw(ostream& fout)//사각형 정보 출력
{
	fout.setf(ios::fixed);
	fout.setf(ios::uppercase);
	fout.precision(0);

	fout << "Rect::draw() => [name(" << name << "),pos(" << pos.px << "," << pos.py << "), width(" << width<< "), length (" << length << "), color("
		<< setw(6) << setfill('0') << hex << color << "),rectangle area (" << getArea() << ") ]" << endl;
}

Rectang& Rectang ::operator=(Rectang& rec)//대입연산자
{
	Shape::operator=(rec);//Shape 대입연산자호출

	width = rec.width;
	length = rec.length;

	return *this;
}