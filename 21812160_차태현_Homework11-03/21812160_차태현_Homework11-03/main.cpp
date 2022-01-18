/**
*�����̸�"21812160_������_Homework11-03"
*���α׷��� ���� �� �⺻ ���:
*��ŵ����Ʈ�� ���� ���� �������
*
*���α׷� �ۼ���: 21812160 ������(2021�� 11��22��),
*���� ���� �� ����: 2021�� 11�� 22�� (������)
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
	SkipList<string, MyVoca*> vocaSkipList;//��ŵ����Ʈ ����
	typedef SkipList<string, MyVoca*>::Position Pos_myVoca ;
	Pos_myVoca posVoca;
	
	//������ ���
	 string deleteList[] = { "resume","stipulate","abundant", "recruit","proficient","entail" ,"endure","resume","stipulate" ,
	"recruit","succinct" ,"elaborate","refrain" ,"abide","obligate","resolve","elaborate","refrain","obligate","resolve" };

	for (int i = 0; i < NUM_MY_TOEIC_VOCA; i++)
	{
		fout << "Inserting Voca[";fout << i << "]: "  << endl;
		
		keyWord = myToeicVocaList[i].getKeyWord();//Ű���� �޾ƿ���
		vocaSkipList.SkipListInsert(fout, keyWord, &myToeicVocaList[i]);//��ŵ����Ʈ�� ����
		vocaSkipList.PrintSkipList(fout);//���
		fout << endl;
	}
	fout << "\n********************************* " << endl;
	//Ÿ�� ����
	for (int i = 0; i < NUM_MY_TOEIC_VOCA; i++)
	{
		fout << "Search VocaSkipList and delete the Voca(" << deleteList[i] << ") : ";
		posVoca = vocaSkipList.SkipListSearch(deleteList[i]);//������ �� ã��
		if (posVoca != Pos_myVoca(NULL))//���� �Ұ��
		{
			pVoca = *posVoca;
			vocaSkipList.SkipListRemove(fout, deleteList[i]);//���� �ǽ�
		}
		vocaSkipList.PrintSkipList(fout);
		fout << endl;
	}
}