#ifndef V_H
#define V_H

#include<vector>
#include<algorithm>

using namespace std;

template <typename T>//템플릿 T 지정

void printVector(vector<T>& v)
{
	string typeName = typeid(T).name();//T의 자료형을 이름으로 설정
	cout << "Vetor size(" << v.size() << "),elements:" << endl;
	typename vector<T>::iterator p;
	for (p = v.begin(); p != v.end(); p++)//첫번째부터 마지막 까지 실행
	{
		cout << *p << "";//원소출력
		if (typeName == "class Date" || typeName == "class Time")
			continue;
		else
			cout << endl;
	}
	cout << endl;
}

#endif 

