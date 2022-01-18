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
	TrieNode() {}//default ������
	TrieNode(char k, E v) :key(k), value(v) { prev = next = parent = child = NULL; }//������
	void setKey(char k) { key = k; }//Ű ����
	void setValue(E v) { value = v; }//�� ����
	void setNext(TrieNode<E>* nxt) { next = nxt; }//������� ����
	void setPrev(TrieNode<E>* pv) { prev = pv; }//������� ����
	void setParent(TrieNode<E>* pr) { parent = pr; }//�θ��� ����
	void setChild(TrieNode<E>* chld) { child = chld; }//�ڽĳ�� ����
	char getKey() { return key; }//Ű ��ȯ
	E getValue() { return value; }//�� ��ȯ
	TrieNode<E>* getPrev() { return prev; }//������� ��ȯ
	TrieNode<E>* getNext() { return next; }//������� ��ȯ
	TrieNode<E>* getParent() { return parent; }//�θ��� ��ȯ
	TrieNode<E>* getChild() { return child; }//�ڽĳ�� ��ȯ
	void _fprint(ostream& fout, TrieNode<E>* pTN, int indent);//�鿩�����ؼ� ���
private:
	char key;//Ű
	E value;//��
	TrieNode<E>* prev;//����
	TrieNode<E>* next;//����
	TrieNode<E>* parent;//�θ�
	TrieNode<E>* child;//�ڽ�
};

template<typename E>
void TrieNode<E>::_fprint(ostream& fout, TrieNode<E>* pTN, int indent)
{
	if (pTN == NULL)
	{
		fout << endl;
		return;
	}
	else//NULL �ƴҰ��
	{
		fout << pTN->key;//key��ȯ
		_fprint(fout, pTN->child, indent + 1);//�ڽĳ�忡 ���Ͽ� ��� �鿩���� ����
		if (pTN->next == NULL)
			return;
		for (int i = 0; i < indent; i++)
		{
			fout << " ";//�鿩����
		}
		_fprint(fout, pTN->next, indent);//������ġ ���
	}
}
#endif // !TN_H
