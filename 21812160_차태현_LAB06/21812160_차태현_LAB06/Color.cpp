#include"Color.h"

ostream& fprintRGB(ostream& fout, COLORREF color)//���� ��� ���� �ʷ� �Ķ�
{
	int red, blue, green;

	red = (color & 0x000000FF);//����
	green = (color & 0x0000FF00) >> 8;//�ʷ�
	blue = (color & 0x00FF0000) >> 16;//�Ķ�
	
	fout << "RGB(" << setw(3) << red << ", " << setw(3) << green << ", "	<< setw(3) << blue << ")";
	
	return fout;
}