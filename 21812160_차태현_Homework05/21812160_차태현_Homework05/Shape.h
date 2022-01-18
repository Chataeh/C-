#ifndef S_H
#define S_H
#include<iostream>
#include<string>
#include<Windows.h>
#include"Color.h"
using namespace std;

#define pi 3.141592//파이 값 정의
class Shape
{
	friend ostream& operator<<(ostream&, Shape&);//<<연산자 파일에출력
public:
	Shape();//default 생성자
	Shape(string name);//생성자
	Shape(int px, int py, double angle, COLORREF color, string name);//생성자
	~Shape();//소멸자
	void draw();
	void rotate(double rt_ang) { angle += rt_ang; }//각 더하기
	void move(int dx, int dy) { pos_x += dx; pos_y += dy; }//위치 이동
	void print(ostream&);//출력함수
	int get_pos_x()const { return pos_x; }//x위치
	int get_pos_y()const { return pos_y; }//y위치
	void set_pos_x(int x) { pos_x = x; }//x위치 설정
	void set_pos_y(int y) { pos_y = y; }//y위치 설정
	void setName(string n) { name = n; }//이름설정
	string getName() { return name; }//이름반환
	Shape& operator=(const Shape& s);//대입연산자
protected:
	int pos_x;//x위치
	int pos_y;//y위치
	double angle;//각
	string name;//이름
	COLORREF color;//색 지정을 위한 정의
};

#endif 
