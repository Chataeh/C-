#ifndef CO_H
#define CO_H

#include"TA_Entry.h"
#include"T_Entry.h"
#include<fstream>

#define CBT_ROOT 1

template<typename K, typename V>
class CompleteBinaryTree :public TA_Entry<K, V>
{
public:
	CompleteBinaryTree(int capa, string nm);//생성자
	int add_at_end(T_Entry<K, V>& elem);//마지막에 원소추가
	T_Entry<K, V>& getEndElement() { return this->t_GA[end]; }//마지막 값 반환
	T_Entry<K, V>& getRootElement() { return this->t_GA[CBT_ROOT]; }//가장 처음에있는 값반환
	int getEndIndex() { return end; }//마지막 인덱스 반환
	void removeCBTEnd();//마지막 값 제거
	void fprintCBT(ostream& fout);//출력
	void fprintCBT_byLevel(ostream& fout);//단계별 출력
protected:
	void _printCBT_by_Level(ostream& fout, int p, int level);//단계별 출력
	int parentIndex(int index) { return index / 2; }//부모인덱스
	int leftChildIndex(int index) { return index * 2; }//왼쪽자식 인덱스
	int rightChildIndex(int index) { return (index * 2 + 1); }//오른쪽자식인덱스
	bool hasLeftChild(int index) { return((index * 2) <= end); }//왼쪽자식 있는지 판별
	bool hasRightChild(int index) { return ((index * 2 + 1) <= end); }//오른쪽자식 있는지 판별
	int end;//끝
};

template<typename K, typename V>
CompleteBinaryTree<K, V>::CompleteBinaryTree(int capa, string nm)
	:TA_Entry<K, V>(capa+1, nm)//생성자 호출
{
	end = 0;
}
template<typename K, typename V>
int CompleteBinaryTree<K, V>::add_at_end(T_Entry<K, V>& elem)//마지막에 추가
{
	if (end >= this->capacity)//용량보다 클시
	{
		cout << this->getName() << "is FULL now!" << endl;//가득참
		return end;
	}
	end++;//마지막을 늘려주고
	this->t_GA[end] = elem;//원소 삽입

	return end;
}

template<typename K, typename V>
void CompleteBinaryTree<K, V>::removeCBTEnd()
{
	end--;//마지막 제거
	this->num_elements--;//원소수 -1
}
template<typename K, typename V>
void CompleteBinaryTree<K, V>::fprintCBT(ostream& fout)
{
	if (end <= 0)//배열 비었을경우
	{
		fout << this->getName() << "is empty now!!" << endl;
		return;
	}
	int count = 0;
	for (int i = 1; i <= end; i++)//루트자리가 1이기때문
	{
		fout << setw(3) << this->t_GA[i];//값 출력
		
		
		if ((count+1) % 5 == 0)
			fout << endl;
		count++;
	}
}

template<typename K, typename V>
void CompleteBinaryTree<K, V>::fprintCBT_byLevel(ostream& fout)
{
	if (end <= 0)//배열 비었을경우
	{
		fout << "CBT is empty now!!" << endl;
		return;
	}
	_printCBT_by_Level(fout, CBT_ROOT, 0);//출력 함수 호출
}

template<typename K, typename V>
void CompleteBinaryTree<K, V> ::_printCBT_by_Level(ostream& fout, int p, int level)
{
	int index_child;
	if (hasRightChild(p))//오른쪽 자식이 있는경우
	{
		index_child = rightChildIndex(p);
		_printCBT_by_Level(fout, index_child, level + 1);//재귀함수
	}
	for (int i = 0; i < level; i++)
		fout << "  ";
	this->t_GA[p].fprint(fout);//출력
	fout << endl;

	if (hasLeftChild(p))//왼쪽자식이 있는경우
	{
		index_child = leftChildIndex(p);
		_printCBT_by_Level(fout, index_child, level + 1);//재귀함수 
	}
}
#endif
