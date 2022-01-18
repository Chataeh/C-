#ifndef CO_H
#define CO_H

#include"TA_Entry.h"
#include"T_Entry.h"

#define CBT_ROOT 1

template<typename K,typename V>
class CompleteBinaryTree :public TA_Entry<K, V>
{
public:
	CompleteBinaryTree(int capa, string nm);//������
	int add_at_end(T_Entry<K, V>& elem);//�������� �����߰�
	T_Entry<K, V>& getEndElement() { return this->t_GA[end]; }//������ �� ��ȯ
	T_Entry<K, V>& getRootElement() { return this->t_GA[CBT_ROOT]; }//���� ó�����ִ� ����ȯ
	int getEndIndex() { return end; }//������ �ε��� ��ȯ
	void removeCBTEnd();//������ �� ����
	void fprintCBT(ofstream& fout);//���
	void fprintCBT_byLevel(ofstream& fout);//�ܰ躰 ���
protected:
	void _printCBT_by_Level(ofstream& fout, int p, int level);//�ܰ躰 ���
	int parentIndex(int index) { return index / 2; }//�θ��ε���
	int leftChildIndex(int index) { return index * 2; }//�����ڽ� �ε���
	int rightChildIndex(int index) { return (index * 2 + 1); }//�������ڽ��ε���
	bool hasLeftChild(int index) { return((index * 2) <= end); }//�����ڽ� �ִ��� �Ǻ�
	bool hasRightChild(int index) { return ((index * 2 + 1) <= end); }//�������ڽ� �ִ��� �Ǻ�
	int end;//��
};

template<typename K,typename V>
CompleteBinaryTree<K, V>::CompleteBinaryTree(int capa, string nm)
	:TA_Entry<K,V>(capa,nm)//������ ȣ��
{
	end = 0;
}
template<typename K,typename V>
int CompleteBinaryTree<K, V>::add_at_end(T_Entry<K, V>& elem)//�������� �߰�
{
	if (end >= this->capacity)//�뷮���� Ŭ��
	{
		cout << this->getName() << "is FULL now!" << endl;//������
		return end;
	}
	end++;//�������� �÷��ְ�
	this->t_GA[end] = elem;//���� ����

	return end;
}

template<typename K, typename V>
void CompleteBinaryTree<K,V>::removeCBTEnd()
{
	end--;//������ ����
	this->num_elements--;//���Ҽ� -1
}
template<typename K, typename V>
void CompleteBinaryTree<K, V>::fprintCBT(ofstream& fout)
{
	if (end <= 0)//�迭 ��������
	{
		fout << this->getName() << "is empty now!!" << endl;
		return;
	}
	int count = 0;
	for (int i = 1; i <= end; i++)//��Ʈ�ڸ��� 1�̱⶧��
	{
		fout << setw(3) << this->t_GA[i] << endl;//�� ���
		count++;
	}
}

template<typename K, typename V>
void CompleteBinaryTree<K, V>::fprintCBT_byLevel(ofstream& fout)
{
	if (end <= 0)//�迭 ��������
	{
		fout << "CBT is empty now!!" << endl;
		return;
	}
	_printCBT_by_Level(fout, CBT_ROOT, 0);//��� �Լ� ȣ��
}

template<typename K, typename V>
void CompleteBinaryTree<K, V> ::_printCBT_by_Level(ofstream& fout, int p, int level)
{
	int index_child;
	if (hasRightChild(p))//������ �ڽ��� �ִ°��
	{
		index_child = rightChildIndex(p);
		_printCBT_by_Level(fout, index_child, level + 1);//����Լ�
	}
	for (int i = 0; i < level; i++)
		fout << "  ";
	this->t_GA[p].fprint(fout);//���
	fout << endl;

	if (hasLeftChild(p))//�����ڽ��� �ִ°��
	{
		index_child = leftChildIndex(p);
		_printCBT_by_Level(fout, index_child, level + 1);//����Լ� 
	}
}
#endif
