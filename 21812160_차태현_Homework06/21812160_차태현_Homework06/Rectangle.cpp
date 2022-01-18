#include"Rectangle.h"

Rectang::Rectang()//default ������
	:Shape()
{
	width = 0;
	length = 0;

}


Rectang::Rectang(Position pos, int w, int l, double ang, COLORREF color, string name)//������
	:Shape(pos, ang, color, name)
{
	width = w;
	length = l;
}
Rectang::~Rectang()
{

}

double Rectang::getArea()//�簢�� �������
{
	double result = 0.0;

	result = width * length;//�簢�� ����

	return result;
}

void Rectang::draw(ostream& fout)//�簢�� ���� ���
{
	fout.setf(ios::fixed);
	fout.setf(ios::uppercase);
	fout.precision(0);

	fout << "Rect::draw() => [name(" << name << "),pos(" << pos.px << "," << pos.py << "), width(" << width<< "), length (" << length << "), color("
		<< setw(6) << setfill('0') << hex << color << "),rectangle area (" << getArea() << ") ]" << endl;
}

Rectang& Rectang ::operator=(Rectang& rec)//���Կ�����
{
	Shape::operator=(rec);//Shape ���Կ�����ȣ��

	width = rec.width;
	length = rec.length;

	return *this;
}