#ifndef V_H
#define V_H

#include<vector>
#include<algorithm>

using namespace std;

template <typename T>//���ø� T ����

void printVector(vector<T>& v)
{
	string typeName = typeid(T).name();//T�� �ڷ����� �̸����� ����
	cout << "Vetor size(" << v.size() << "),elements:" << endl;
	typename vector<T>::iterator p;
	for (p = v.begin(); p != v.end(); p++)//ù��°���� ������ ���� ����
	{
		cout << *p << "";//�������
		if (typeName == "class Date" || typeName == "class Time")
			continue;
		else
			cout << endl;
	}
	cout << endl;
}

#endif 

