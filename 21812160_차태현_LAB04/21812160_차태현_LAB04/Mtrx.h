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
	Mtrx(string nm, int n_row, int n_col);//������
	//Mtrx(string nm, double* pA, int n_row, int n_col);//������
	Mtrx(istream& fin);//2���� �迭 ����
	~Mtrx();//�Ҹ���
	void init(int n_row, int n_col);//��� �ʱ�ȭ
	void set_name(string nm){name = nm; }//�̸�����
	string get_name() { return name; }//�̸���ȯ
	int get_n_row() const { return n_row; }//��ũ�� ��ȯ
	int get_n_col() const { return n_col; }//��ũ�� ��ȯ
	const Mtrx operator +(const Mtrx&);//����� ����
	const Mtrx operator -(const Mtrx&);//����� ������
	const Mtrx operator *(const Mtrx&);//����� ����
	const Mtrx operator ~();//ġȯ���
	const Mtrx operator =(const Mtrx&);//����� ����
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