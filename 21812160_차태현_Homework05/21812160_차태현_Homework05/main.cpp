/**
*�����̸�"21812160_������_Homework05"
*���α׷��� ���� �� �⺻ ���:
*  Ŭ�������� ��ӹ޾� ���Ϸ� ������ ������ ���.
*
*���α׷� �ۼ���: 21812160 ������(2021�� 10��03��),
*���� ���� �� ����: 2021�� 10�� 03�� (������)
*/
#include <iostream>
#include <fstream>
#include <string>
#include "Color.h"
#include "Shape.h"
#include "Ellipse.h" 
#include "ElpsCylinder.h" 

using namespace std;

int main()
{
	fstream fout;
	Shape shape(1, 1, 0, RGB_BLACK, "Shape");//Shape ��ü ����
	Elps red_elps(8, 8, 3.0, 4.0, 0, RGB_RED, "Red_Elps");//Elps ��ü����
	ElpsCylinder blue_elpcyl(9, 9, 5.0, 6.0, 7.0, 0.0, RGB_BLUE, "Blue_Elp_Cyl");//ElpsCylinder��ü ����
	
	fout.open("output.txt", 'w');//���Ͽ���
	if (fout.fail())
	{
		cout << "Failed in opening output.txt file !!" << endl;
		exit;
	}
	
	fout << "List of shapes using operator<<() friend function " << endl;
	fout << shape << endl;//���
	fout << red_elps << endl;
	fout << blue_elpcyl << endl;
	
	fout.close();//���ϴݱ�
	return 0;
}