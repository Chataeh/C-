#ifndef SH_H
#define SH_H
#include"Position.h"
#include<Windows.h>
#include<string>
#include<iomanip>
using namespace std;

#define PI 3.141592

const COLORREF RGB_BLACK = 0x00000000;
const COLORREF RGB_RED = 0x000000FF;
const COLORREF RGB_GREEN = 0x0000FF00;
const COLORREF RGB_BLUE = 0x00FF0000;
const COLORREF RGB_ORANGE = 0x0000A5FF;
const COLORREF RGB_YELLOW = 0x0000FFFF;
const COLORREF RGB_MAGENTA = 0x00FF00FF;
const COLORREF RGB_WHITE = 0x00FFFFFF;

class Shape {
public:
	Shape();//default 생성자
	Shape(Position pos, double angle, COLORREF color, string name);//생성자
	~Shape();//소멸자
	virtual void draw(ostream& fout);//가상함수
	Shape& operator=(const Shape& s);//대입연산자

protected:
	Position pos;//x,y위치
	double angle;//각
	string name;//이름
	COLORREF color;//색 지정을 위한 정의
};


#endif SH_H
