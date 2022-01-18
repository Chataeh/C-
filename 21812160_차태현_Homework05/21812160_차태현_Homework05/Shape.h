#ifndef S_H
#define S_H
#include<iostream>
#include<string>
#include<Windows.h>
#include"Color.h"
using namespace std;

#define pi 3.141592//���� �� ����
class Shape
{
	friend ostream& operator<<(ostream&, Shape&);//<<������ ���Ͽ����
public:
	Shape();//default ������
	Shape(string name);//������
	Shape(int px, int py, double angle, COLORREF color, string name);//������
	~Shape();//�Ҹ���
	void draw();
	void rotate(double rt_ang) { angle += rt_ang; }//�� ���ϱ�
	void move(int dx, int dy) { pos_x += dx; pos_y += dy; }//��ġ �̵�
	void print(ostream&);//����Լ�
	int get_pos_x()const { return pos_x; }//x��ġ
	int get_pos_y()const { return pos_y; }//y��ġ
	void set_pos_x(int x) { pos_x = x; }//x��ġ ����
	void set_pos_y(int y) { pos_y = y; }//y��ġ ����
	void setName(string n) { name = n; }//�̸�����
	string getName() { return name; }//�̸���ȯ
	Shape& operator=(const Shape& s);//���Կ�����
protected:
	int pos_x;//x��ġ
	int pos_y;//y��ġ
	double angle;//��
	string name;//�̸�
	COLORREF color;//�� ������ ���� ����
};

#endif 
