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
	Cmplx(double real = 0.0, double imag = 0.0);//생성자
	~Cmplx();
	double mag() const;// 크키반환
	const Cmplx operator+(const Cmplx&);//복소수 덧셈
	const Cmplx operator-(const Cmplx&);//복소수 뺄셈
	const Cmplx operator*(const Cmplx&);//복소수 곱셈
	const Cmplx operator/(const Cmplx&);//복소수의 나눗셈
	const Cmplx operator~();//켤레복소수
	bool operator==(const Cmplx&);//복소수 일치
	bool operator!=(const Cmplx&);//복소수 일치하지않음
	bool operator<(const Cmplx&);//크기비교
	bool operator>(const Cmplx&);//크기비교
	const Cmplx operator=(const Cmplx&);


private:
	double real;
	double imag;
};

#endif