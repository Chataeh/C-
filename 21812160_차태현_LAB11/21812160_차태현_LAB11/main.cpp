/**
*�����̸�"21812160_������_LAB11"
*���α׷��� ���� �� �⺻ ���:
* �ؽ��ڵ带 ����Ͽ� �ؽ����̺� Ž��
*
*���α׷� �ۼ���: 21812160 ������(2021�� 11��17��),
*���� ���� �� ����: 2021�� 11�� 17�� (������)
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
	HashDict<string, MyVoca*> myVocaDict;//����
	HashDict<string, MyVoca*>::Iterator itr;//���� ����
	HashDict<string, MyVoca*>::Range range;
	Entry<string, MyVoca*> vocaEntry;
	fout.open("output.txt");//���� ����
	if (fout.fail())
	{
		cout << "Fail to open output.txt !!" << endl;
		exit;
	}
	fout << "Inserting My Vocabularies to myVocaDict . . . " << endl;
	word_count = 0;
	for (int i = 0; i < NUM_MY_TOEIC_VOCA; i++)
	{
		pVoca = &myToeicVocaList[i];//pVoca�� ����
		keyWord = myToeicVocaList[i].getKeyWord();//Ű���� ����
		myVocaDict.insert(keyWord, pVoca);//���Խ���
	}

	fout << "Total " << myVocaDict.size() << " words in my Voca_Dictionary .." << endl;

	for (itr = myVocaDict.begin(); itr != myVocaDict.end(); ++itr)//ó������ ������ �ݺ�
	{
		pVoca = itr.getValue();
		fout << *pVoca << endl;//�� ���
	}
	fout << endl;
	string testWord = "offer";//�׽�Ʈ�� ����
	range = myVocaDict.findAll(testWord);//���� ã��
	fout << "Thesaurus of [" << testWord << "]: \n";
	for (itr = range.begin(); itr != range.end(); ++itr)//������ŭ ����
	{
		pVoca = itr.getValue();;
		fout << *pVoca << endl;//������ �ִ� �� ���
	}

	/*SkipList<string, MyVoca*> skipvoca;
	typedef SkipList<string, MyVoca*>::Position Pos_MyVoca;
	Pos_MyVoca posVoca;
	for (int i = 0; i < NUM_MY_TOEIC_VOCA; i++)
	{
		pVoca = &myToeicVocaList[i];//pVoca�� ����
		keyWord = myToeicVocaList[i].getKeyWord();//Ű���� ����
		skipvoca.SkipListInsert(fout, keyWord, &myToeicVocaList[i]);//���Խ���
		skipvoca.PrintSkipList(fout);
	}*/
	fout << endl;
	fout.close();
}