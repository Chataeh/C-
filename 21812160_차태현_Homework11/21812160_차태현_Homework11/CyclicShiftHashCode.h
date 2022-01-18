#ifndef CY_H
#define CY_H

#include<string>

using namespace std;

#define BIT_SHIFTS 5
#define BITS_INT 32

class CyclicShiftHashCode
{
public:
	int operator()(const string key)
	{
		int len = key.length();//길이설정
		unsigned int h = 0;//32비트로 설정
		for (int i = 0; i < len; i++)//문자열 길이만큼 반복
		{
			h = (h << BIT_SHIFTS) | (h >> (BITS_INT - BIT_SHIFTS));//(h 왼쪽으로 5만큼이동) or연산 (h 오른쪽으로 27번이동)
			h += (unsigned int)key.at(i);//i번째 위치 문자값 더해줌
		}
		return h;//6비트 크기로 생성
	}
};


#endif