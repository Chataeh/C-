#ifndef HE_H
#define HE_H

#include"TA_Entry.h"
#include"T_Entry.h"
#include"CompleteBinaryTree.h"

template<typename K, typename V>
class HeapPrioQueue :public CompleteBinaryTree<K, V>
{
public:
	HeapPrioQueue(int capa, string nm);//������
	~HeapPrioQueue();//�Ҹ���
	bool isEmpty() { return size() == 0; }//����ִ��� �Ǻ�
	bool isFull() { return size() == this->capacity; }//�뷮�̶� �������
	int insert(T_Entry<K, V>& elem);//���� ����
	T_Entry<K, V>* removeHeapMin();//�켱���� ������ ���� �� ������
	T_Entry<K, V>* getHeapMin();//�켱���� ������ ����
	void fprint(ofstream& fout);
	int size() { return this->end; }
private:
};

template<typename K, typename V>
HeapPrioQueue<K, V>::HeapPrioQueue(int capa, string nm)//������
	:CompleteBinaryTree<K,V>(capa,nm)//������ ȣ��
{

}
template<typename K, typename V>
HeapPrioQueue<K, V>::~HeapPrioQueue()
{

}

template<typename K, typename V>
int HeapPrioQueue<K, V>::insert(T_Entry<K, V>& elem)
{
	int index, parent_index;
	T_Entry<K, V> temp;
	if (isFull())
	{
		cout << this->getName() << "is Full" << endl;
		return size();
	}
	index = this->add_at_end(elem);//�������� �����߰�

	//�������� ����
	while (index != CBT_ROOT)//��Ʈ��尡 �ƴҰ��
	{
		parent_index = this->parentIndex(index);//�θ��� ����
			if (this->t_GA[index].getKey() > this->t_GA[parent_index].getKey())//�θ��庸�� �ڽ��� ���� �� Ŭ���
				break;
			else
			{
				temp = this->t_GA[index];
				this->t_GA[index] = this->t_GA[parent_index];
				this->t_GA[parent_index] = temp;	
				index = parent_index;//�ε����� ������ �θ���μ���
			}
	}
	return size();
}

template<typename K, typename V>
T_Entry<K, V>* HeapPrioQueue<K, V>::removeHeapMin()
{
	int index_p, index_c, index_rc;
	T_Entry<K, V>* pMinElem;
	T_Entry<K, V> t_p, t_c,temp;
	int HPQ_size = size();//ť ũ�⼳��

	if (HPQ_size <= 0)//ť ũ�Ⱑ 0���� ������
		return NULL;
	pMinElem = (T_Entry<K, V>*)new T_Entry<K, V>;
	*pMinElem = this->getRootElement();//��Ʈ����� �� 
	if (HPQ_size == 1)//����� 1�ϰ��
		this->removeCBTEnd();//����ִ� ���·� ����
	else
	{
		index_p = CBT_ROOT;
		this->t_GA[CBT_ROOT] = this->t_GA[this->end];//�������� �ִ� �� ��Ʈ���� �̵�
		this->end--;
	
	//�ٿ� ������

		while (this->hasLeftChild(index_p))//�����ڽ� ��尡 �ִ°��
		{
			index_c = this->leftChildIndex(index_p);//�����ڽ� ��� ����
			index_rc = this->rightChildIndex(index_p);//������ �ڽ� ����
			if (this->hasRightChild(index_p) && (this->t_GA[index_c] > this->t_GA[index_rc]))//�켱������ �������� ��Ŭ���
				index_c = index_rc;
			t_p = this->t_GA[index_p];//�θ� ��� 
			t_c = this->t_GA[index_c];//�ڽ� ���
			if (t_p > t_c)//�θ��� �켱������ �ڽĺ��� ���ٸ�
			{
				temp = this->t_GA[index_p];
				this->t_GA[index_p] = this->t_GA[index_c];
				this->t_GA[index_c] = temp;
				index_p = index_c;//�θ��ε��� �缳��
			}
			else
				break;
		}
	}
	return pMinElem;
}

template<typename K,typename V>
T_Entry<K, V>* HeapPrioQueue<K, V>::getHeapMin()
{
	T_Entry<K, V>* pMinElem;

	if (size() <= 0)//ũŰ�� 0���� �������
		return NULL;
	pMinElem = (T_Entry<K, V>*)new T_Entry<K, V>;
	*pMinElem = this->getRootElement();//��Ʈ ��� ��(�켱������ ������� ��)

	return pMinElem;
}

template<typename K, typename V>
void HeapPrioQueue<K, V>::fprint(ofstream& fout)
{
	if (size() <= 0)
	{
		fout << "HeapPrioQueue is Empty" << endl;
		return;
	}
	else
		CompleteBinaryTree<K,V>::fprintCBT(fout);
}
#endif 