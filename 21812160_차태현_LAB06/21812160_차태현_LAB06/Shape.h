#ifndef  S_H
#define S_H

#include <string>
#include <Windows.h>
#include <conio.h>
#include "ConsolePixelDrawing.h"
#include "Color.h"

using namespace std;

#define PI 3.14159 

class ConsolePixelFrame;

class Shape
{
	friend ostream& operator<<(ostream&, Shape&);//<<연산자
public:
	Shape();//default 생성자
	Shape(string name);//생성자
	Shape(int px, int py, double angle, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);//생성자
	virtual ~Shape();//소멸자 가상
	virtual void draw(ConsolePixelFrame cp_frame);//가상
	void fprint(ostream&);//파일에 출력
	int get_pos_x() const { return pos_x; }//x위치 반환
	int get_pos_y() const { return pos_y; }//y위치 반환
	void set_pos_x(int x) { pos_x = x; }// x위치 설정
	void set_pos_y(int y) { pos_y = y; }// y위치 설정
	string getName() { return name; }//이름반환
	void setName(string n) { name = n; }//이름설정
	Shape& operator=(const Shape& s);//대입연산자
protected:
	int pos_x;//x위치
	int pos_y;//y위치
	double angle;//각
	string name;//이름
	int pen_thickness;//펜 두께
	COLORREF line_color;//라인 색
	COLORREF brush_color;//브러쉬 색

};


#endif // ! S_H
