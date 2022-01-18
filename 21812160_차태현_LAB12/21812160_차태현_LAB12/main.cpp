/**
*파일이름"21812160_차태현_LAB12"
*프로그램의 목적 및 기본 기능:
* Trie노드 구현및 사용
*
*
*프로그램 작성자: 21812160 차태현(2021년 11월25일),
*최종 수정 및 보완: 2021년 11월 25일 (차태현)
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
	fout.open("output.txt");//파일열기
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
	
	//정상적으로 작동하는지 확인을 위한 테스트
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
		trie_myVoca.insert(testVocas[i].getKeyWord(), &testVocas[i]);//삽입
	}
	trie_myVoca.fprintTrie(fout);//출력
	
	fout << "\nTesting TrieDestroy...\n";
	trie_myVoca.eraseTrie();//삭제 
	trie_myVoca.fprintTrie(fout);//출력 삭제된것 확인
	
	fout << "Inserting My Vocabularies to myVocaDict . . . " << endl;
	word_count = 0;
	pVoca = &myToeicVocaList[0];
	while (pVoca->getKeyWord() != "-1")//키워드가 -1일때까지 반복
	{
		keyStr = pVoca->getKeyWord();//키워드 찾기
		trie_myVoca.insert(keyStr, pVoca);//삽입
		pVoca++;
	}
	fout << "Total " << trie_myVoca.size() << " words in trie_myVoca .." << endl;
	trie_myVoca.fprintTrie(fout);
	
	//접두어를 포함하는 단어를 검색을 통해 찾기
	while (1)
	{
		cout << "\nInput any prefix to search in trie (. to finish) : ";
		cin >> keyStr;//단어 검색
		if (keyStr == string("."))//.이 들어올경우 break
			break;
		predictVocas.clear();
		trie_myVoca.findPrefixMatch(keyStr, predictVocas);//단어 찾기
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