#ifndef M_H
#define M_H
#include<iostream>
#include<fstream>

using namespace std;
#define MAX_SIZE 100

class Mtrx {
public:
	Mtrx(int num_row, int num_col);//»ı¼ºÀÚ
	//Mtrx(double* dA, int num_data, int num_row, int num_col);
	Mtrx(istream& fin);
	~Mtrx(); //¼Ò¸êÀÚ
	int getN_row() { return n_row; }
	int getN_col() { return n_col; }
	void fprintMtrx(ostream& fout);//Çà·Ä Ãâ·Â(ÆÄÀÏ)
	void setName(string nm) { name = nm; };
	string getName() { return name; }
	Mtrx add(const Mtrx& mA);//Çà·Ä µ¡¼À
	Mtrx sub(const Mtrx& mA);//Çà·Ä »¬¼À
	Mtrx multiply(const Mtrx& mA);//Çà·Ä°ö¼À
private:
	string name;
	int n_row;
	int n_col;
	double** dM;
};
#endif