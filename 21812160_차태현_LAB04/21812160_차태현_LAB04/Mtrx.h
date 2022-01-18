#ifndef M_H
#define M_H

#include<string>

using namespace std;
class MtrxArray;
class Mtrx {
	friend ostream& operator<<(ostream&, const Mtrx&);
	friend istream& operator>>(istream&,  Mtrx&);
public:
	Mtrx();
	Mtrx(string nm, int n_row, int n_col);//생성자
	//Mtrx(string nm, double* pA, int n_row, int n_col);//생성자
	Mtrx(istream& fin);//2차원 배열 생성
	~Mtrx();//소멸자
	void init(int n_row, int n_col);//행렬 초기화
	void set_name(string nm){name = nm; }//이름설정
	string get_name() { return name; }//이름반환
	int get_n_row() const { return n_row; }//행크기 반환
	int get_n_col() const { return n_col; }//열크기 반환
	const Mtrx operator +(const Mtrx&);//행렬의 덧셈
	const Mtrx operator -(const Mtrx&);//행렬의 나눗셈
	const Mtrx operator *(const Mtrx&);//행렬의 곱셈
	const Mtrx operator ~();//치환행렬
	const Mtrx operator =(const Mtrx&);//행렬의 대입
	bool operator == (const Mtrx&);
	bool operator !=(const Mtrx&);
	void mtrxstatics(ostream& fout, const Mtrx& m);

private:
	string name;
	int n_row;
	int n_col;
	double** dM;
};



#endif