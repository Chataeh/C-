#include"Color.h"

ostream& fprintRGB(ostream& fout, COLORREF color)//»ö±ò Ãâ·Â »¡°­ ÃÊ·Ï ÆÄ¶û
{
	int red, blue, green;

	red = (color & 0x000000FF);//»¡°­
	green = (color & 0x0000FF00) >> 8;//ÃÊ·Ï
	blue = (color & 0x00FF0000) >> 16;//ÆÄ¶û
	
	fout << "RGB(" << setw(3) << red << ", " << setw(3) << green << ", "	<< setw(3) << blue << ")";
	
	return fout;
}