/**
*�����̸�"21812160_������_LAB12"
*���α׷��� ���� �� �⺻ ���:
* Trie��� ������ ���
*
*
*���α׷� �ۼ���: 21812160 ������(2021�� 11��25��),
*���� ���� �� ����: 2021�� 11�� 25�� (������)
*/
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "MyVoca.h"
#include "MyVocaList.h"
#include "Trie.h"
#include "TrieNode.h"

using namespace std;

#define MAX_WORD_LENGTH 100
#define NUM_TEST_VOCAS 7 


void main()
{
	ofstream fout;
	fout.open("output.txt");//���Ͽ���
	if (fout.fail())
	{
		printf("Error in opening output file !\n");
		exit;
	}
	Trie<MyVoca*> trie_myVoca("Trie_MyVoca");
	TrieNode<MyVoca*>* pTN;
	MyVoca* pVoca;
	int word_count;
	string keyStr;
	char keyWord[MAX_WORD_LENGTH];
	List_pVoca predictVocas;
	List_pVoca_Iter itr;
	
	//���������� �۵��ϴ��� Ȯ���� ���� �׽�Ʈ
	MyVoca testVocas[NUM_TEST_VOCAS] =
	{
	MyVoca("xyz", NOUN, { "" }, { "" }),
	MyVoca("ABCD", NOUN, { "" }, { "" }),
	MyVoca("ABC", NOUN, { "" }, { "" }),
	MyVoca("AB", NOUN, { "" }, { "" }),
	MyVoca("A", NOUN, { "" }, { "" }),
	MyVoca("xy", NOUN, { "" }, { "" }),
	MyVoca("x", NOUN, { "" }, { "" }),
	};
	
	fout << "Testing basic operations of trie inserting ..... " << endl;
	for (int i = 0; i < NUM_TEST_VOCAS; i++)
	{
		trie_myVoca.insert(testVocas[i].getKeyWord(), &testVocas[i]);//����
	}
	trie_myVoca.fprintTrie(fout);//���
	
	fout << "\nTesting TrieDestroy...\n";
	trie_myVoca.eraseTrie();//���� 
	trie_myVoca.fprintTrie(fout);//��� �����Ȱ� Ȯ��
	
	fout << "Inserting My Vocabularies to myVocaDict . . . " << endl;
	word_count = 0;
	pVoca = &myToeicVocaList[0];
	while (pVoca->getKeyWord() != "-1")//Ű���尡 -1�϶����� �ݺ�
	{
		keyStr = pVoca->getKeyWord();//Ű���� ã��
		trie_myVoca.insert(keyStr, pVoca);//����
		pVoca++;
	}
	fout << "Total " << trie_myVoca.size() << " words in trie_myVoca .." << endl;
	trie_myVoca.fprintTrie(fout);
	
	//���ξ �����ϴ� �ܾ �˻��� ���� ã��
	while (1)
	{
		cout << "\nInput any prefix to search in trie (. to finish) : ";
		cin >> keyStr;//�ܾ� �˻�
		if (keyStr == string("."))//.�� ���ð�� break
			break;
		predictVocas.clear();
		trie_myVoca.findPrefixMatch(keyStr, predictVocas);//�ܾ� ã��
		cout << "list of predictive wors with prefix (" << keyStr << ") :" << endl;
		itr = predictVocas.begin();
		for (int i = 0; i < predictVocas.size(); i++)
		{
			pVoca = *itr;
			cout << *pVoca << endl;
			++itr;
		}
	}
	cout << "\nErasing trie_myVoca ...." << endl;
	fout << "\nErasing trie_myVoca ...." << endl;
	trie_myVoca.eraseTrie();
	fout.close();
}