#include"Color.h"

ostream& printRGB(ostream& ostr, const COLORREF color)
{
	ostr << setw(6) << uppercase << setfill('0') << hex << color;//color Ãâ·Â

	return ostr;
}
