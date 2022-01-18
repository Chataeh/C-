#ifndef C_H
#define C_H
#include<Windows.h>
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;
//색깔 정의
const COLORREF RGB_BLACK = 0x00000000;
const COLORREF RGB_RED = 0x000000FF;
const COLORREF RGB_GREEN = 0x0000FF00;
const COLORREF RGB_BLUE = 0x00FF0000;
const COLORREF RGB_ORANGE = 0x0000A5FF;
const COLORREF RGB_YELLOW = 0x0000FFFF;
const COLORREF RGB_MAGENTA = 0x00FF00FF;
const COLORREF RGB_WHITE = 0x00FFFFFF;
ostream& printRGB(ostream& ostr, const COLORREF color);//색 출력

#endif