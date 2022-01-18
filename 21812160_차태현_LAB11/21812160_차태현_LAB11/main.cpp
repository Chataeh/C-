/**
*파일이름"21812160_차태현_LAB11"
*프로그램의 목적 및 기본 기능:
* 해시코드를 사용하여 해쉬테이블 탐색
*
*프로그램 작성자: 21812160 차태현(2021년 11월17일),
*최종 수정 및 보완: 2021년 11월 17일 (차태현)
*/
#include <iostream>
#include <fstream>
#include <string>
#include "HashMap.h"
#include "HashMap.cpp"
#include "CyclicShiftHashCode.h"
#include "Entry.h"
#include "HashDictionary.h"
#include "MyVoca.h"
#include "MyVocaList.h"
#include"Generic_Skip_List.h"
void main()
{
	ofstream fout;
	MyVoca* pVoca, voca;
	List_Str thesaurus;
	List_Str usages;
	int word_count;
	MyVoca mv;
	string keyWord;
	HashDict<string, MyVoca*> myVocaDict;//생성
	HashDict<string, MyVoca*>::Iterator itr;//변수 지정
	HashDict<string, MyVoca*>::Range range;
	Entry<string, MyVoca*> vocaEntry;
	fout.open("output.txt");//파일 열기
	if (fout.fail())
	{
		cout << "Fail to open output.txt !!" << endl;
		exit;
	}
	fout << "Inserting My Vocabularies to myVocaDict . . . " << endl;
	word_count = 0;
	for (int i = 0; i < NUM_MY_TOEIC_VOCA; i++)
	{
		pVoca = &myToeicVocaList[i];//pVoca에 저장
		keyWord = myToeicVocaList[i].getKeyWord();//키워드 저장
		myVocaDict.insert(keyWord, pVoca);//삽입실행
	}

	fout << "Total " << myVocaDict.size() << " words in my Voca_Dictionary .." << endl;

	for (itr = myVocaDict.begin(); itr != myVocaDict.end(); ++itr)//처음부터 끝까지 반복
	{
		pVoca = itr.getValue();
		fout << *pVoca << endl;//값 출력
	}
	fout << endl;
	string testWord = "offer";//테스트를 위해
	range = myVocaDict.findAll(testWord);//영역 찾기
	fout << "Thesaurus of [" << testWord << "]: \n";
	for (itr = range.begin(); itr != range.end(); ++itr)//범위만큼 실행
	{
		pVoca = itr.getValue();;
		fout << *pVoca << endl;//영역에 있는 값 출력
	}

	/*SkipList<string, MyVoca*> skipvoca;
	typedef SkipList<string, MyVoca*>::Position Pos_MyVoca;
	Pos_MyVoca posVoca;
	for (int i = 0; i < NUM_MY_TOEIC_VOCA; i++)
	{
		pVoca = &myToeicVocaList[i];//pVoca에 저장
		keyWord = myToeicVocaList[i].getKeyWord();//키워드 저장
		skipvoca.SkipListInsert(fout, keyWord, &myToeicVocaList[i]);//삽입실행
		skipvoca.PrintSkipList(fout);
	}*/
	fout << endl;
	fout.close();
}