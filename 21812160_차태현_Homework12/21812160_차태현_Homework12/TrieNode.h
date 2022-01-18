#ifndef TN_H
#define TN_H

#include<iostream>
#include<list>
#include<string>
#define VALUE_INTERNAL_NODE NULL

using namespace std;
typedef list<string> STL_list;

template<typename E>
class TrieNode
{
public:
	TrieNode() {}//default 생성자
	TrieNode(char k, E v) :key(k), value(v) { prev = next = parent = child = NULL; }//생성자
	void setKey(char k) { key = k; }//키 설정
	void setValue(E v) { value = v; }//값 설정
	void setNext(TrieNode<E>* nxt) { next = nxt; }//다음노드 설정
	void setPrev(TrieNode<E>* pv) { prev = pv; }//이전노드 설정
	void setParent(TrieNode<E>* pr) { parent = pr; }//부모노드 설정
	void setChild(TrieNode<E>* chld) { child = chld; }//자식노드 설정
	char getKey() { return key; }//키 반환
	E getValue() { return value; }//값 반환
	TrieNode<E>* getPrev() { return prev; }//이전노드 반환
	TrieNode<E>* getNext() { return next; }//다음노드 반환
	TrieNode<E>* getParent() { return parent; }//부모노드 반환
	TrieNode<E>* getChild() { return child; }//자식노드 반환
	void _fprint(ostream& fout, TrieNode<E>* pTN, int indent);//들여쓰기해서 출력
private:
	char key;//키
	E value;//값
	TrieNode<E>* prev;//이전
	TrieNode<E>* next;//다음
	TrieNode<E>* parent;//부모
	TrieNode<E>* child;//자식
};

template<typename E>
void TrieNode<E>::_fprint(ostream& fout, TrieNode<E>* pTN, int indent)
{
	if (pTN == NULL)
	{
		fout << endl;
		return;
	}
	else//NULL 아닐경우
	{
		fout << pTN->key;//key반환
		_fprint(fout, pTN->child, indent + 1);//자식노드에 대하여 출력 들여쓰기 증가
		if (pTN->next == NULL)
			return;
		for (int i = 0; i < indent; i++)
		{
			fout << " ";//들여쓰기
		}
		_fprint(fout, pTN->next, indent);//다음위치 출력
	}
}
#endif // !TN_H
