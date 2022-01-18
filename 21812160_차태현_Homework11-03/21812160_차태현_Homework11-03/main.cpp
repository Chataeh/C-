/**
*파일이름"21812160_차태현_Homework11-03"
*프로그램의 목적 및 기본 기능:
*스킵리스트를 통한 삽입 삭제기능
*
*프로그램 작성자: 21812160 차태현(2021년 11월22일),
*최종 수정 및 보완: 2021년 11월 22일 (차태현)
*/
#include <iostream>
#include <fstream>
#include "Generic_Skip_List.h"
#include"MyVoca.h"
#include"MyVocaList.h"

#define NUM_MY_TOEIC_VOCA 20

int main()
{
	ofstream fout;
	string keyWord;
	MyVoca* pVoca;

	fout.open("output.txt");


	fout << "\n=================" << endl;
	fout << "Testing SkipList<int, MyVoca*> ..." << endl;
	SkipList<string, MyVoca*> vocaSkipList;//스킵리스트 생성
	typedef SkipList<string, MyVoca*>::Position Pos_myVoca ;
	Pos_myVoca posVoca;
	
	//삭제할 목록
	 string deleteList[] = { "resume","stipulate","abundant", "recruit","proficient","entail" ,"endure","resume","stipulate" ,
	"recruit","succinct" ,"elaborate","refrain" ,"abide","obligate","resolve","elaborate","refrain","obligate","resolve" };

	for (int i = 0; i < NUM_MY_TOEIC_VOCA; i++)
	{
		fout << "Inserting Voca[";fout << i << "]: "  << endl;
		
		keyWord = myToeicVocaList[i].getKeyWord();//키워드 받아오기
		vocaSkipList.SkipListInsert(fout, keyWord, &myToeicVocaList[i]);//스킵리서트에 삽입
		vocaSkipList.PrintSkipList(fout);//출력
		fout << endl;
	}
	fout << "\n********************************* " << endl;
	//타워 삭제
	for (int i = 0; i < NUM_MY_TOEIC_VOCA; i++)
	{
		fout << "Search VocaSkipList and delete the Voca(" << deleteList[i] << ") : ";
		posVoca = vocaSkipList.SkipListSearch(deleteList[i]);//삭제할 값 찾기
		if (posVoca != Pos_myVoca(NULL))//존재 할경우
		{
			pVoca = *posVoca;
			vocaSkipList.SkipListRemove(fout, deleteList[i]);//삭제 실시
		}
		vocaSkipList.PrintSkipList(fout);
		fout << endl;
	}
}