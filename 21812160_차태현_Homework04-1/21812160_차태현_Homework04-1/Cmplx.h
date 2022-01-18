#ifndef C_H
#define C_H
#include<iostream>
#include<fstream>

using namespace std;
class CmplxArray;

class Cmplx
{
	friend ostream& operator <<(ostream&, const Cmplx&);
	friend istream& operator >>(istream&, Cmplx&);
	friend class CmplxArray;
public:
	Cmplx(double real = 0.0, double imag = 0.0);//������
	~Cmplx();
	double mag() const;// ũŰ��ȯ
	const Cmplx operator+(const Cmplx&);//���Ҽ� ����
	const Cmplx operator-(const Cmplx&);//���Ҽ� ����
	const Cmplx operator*(const Cmplx&);//���Ҽ� ����
	const Cmplx operator/(const Cmplx&);//���Ҽ��� ������
	const Cmplx operator~();//�ӷ����Ҽ�
	bool operator==(const Cmplx&);//���Ҽ� ��ġ
	bool operator!=(const Cmplx&);//���Ҽ� ��ġ��������
	bool operator<(const Cmplx&);//ũ���
	bool operator>(const Cmplx&);//ũ���
	const Cmplx operator=(const Cmplx&);


private:
	double real;
	double imag;
};

#endif