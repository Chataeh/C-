/**
*파일이름"21812160_차태현_Homework11-01"
*프로그램의 목적 및 기본 기능:
*
*
*프로그램 작성자: 21812160 차태현(2021년 11월21일),
*최종 수정 및 보완: 2021년 11월 21일 (차태현)
*/
#include<iostream>
#include<string>


using namespace std;

#define BIT_SHIFTS 5
#define BITS_INT 32
#define BIT_SHIFTS 5
#define BITS_INT 32
#define NUM_MY_TOEIC_VOCA 20

int CyclicShiftHash(const string key);
int main()
{
	
	const string str[] = { "prescribe","regulate","prescribe","regulate", "plentiful","ample","lavish" ,"busy","decorated","refined" ,
	"detailed","careful" ,"burden","abstain" ,"melody","theme","force","necessitate","obilge","inevitable" };

	int h = 0;
	for (int i = 0; i < NUM_MY_TOEIC_VOCA; i++)
	{
		h=CyclicShiftHash(str[i]);
		cout <<"Key Value ["<< h <<"]"<< endl;
	}
}


int CyclicShiftHash(const string key)
{
	
	int len = key.length();//길이설정
	unsigned int h = 0;//32비트로 설정
	for (int i = 0; i < len; i++)//문자열 길이만큼 반복
	{
		h = (h << BIT_SHIFTS) | (h >> (BITS_INT - BIT_SHIFTS));//(h 왼쪽으로 5만큼이동) or연산 (h 오른쪽으로 27번이동)
		h += (unsigned int)key.at(i);//i번째 위치 문자값 더해줌
	}
	return h%64;
}