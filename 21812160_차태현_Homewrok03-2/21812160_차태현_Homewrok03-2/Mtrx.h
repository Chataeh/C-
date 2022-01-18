#ifndef M_H
#define M_H
#include<iostream>
#include<fstream>

using namespace std;
#define MAX_SIZE 100

class Mtrx {
public:
	Mtrx(int num_row, int num_col);//������
	//Mtrx(double* dA, int num_data, int num_row, int num_col);
	Mtrx(istream& fin);
	~Mtrx(); //�Ҹ���
	int getN_row() { return n_row; }
	int getN_col() { return n_col; }
	void fprintMtrx(ostream& fout);//��� ���(����)
	void setName(string nm) { name = nm; };
	string getName() { return name; }
	Mtrx add(const Mtrx& mA);//��� ����
	Mtrx sub(const Mtrx& mA);//��� ����
	Mtrx multiply(const Mtrx& mA);//��İ���
private:
	string name;
	int n_row;
	int n_col;
	double** dM;
};
#endif