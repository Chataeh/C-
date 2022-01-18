#ifndef HE_H
#define HE_H

#include"TA_Entry.h"
#include"T_Entry.h"
#include"CompleteBinaryTree.h"

template<typename K, typename V>
class HeapPrioQueue :public CompleteBinaryTree<K, V>
{
public:
	HeapPrioQueue(int capa, string nm);//생성자
	~HeapPrioQueue();//소멸자
	bool isEmpty() { return size() == 0; }//비어있는지 판별
	bool isFull() { return size() == this->capacity; }//용량이랑 같을경우
	int insert(T_Entry<K, V>& elem);//원소 삽입
	T_Entry<K, V>* removeHeapMin();//우선순위 높은값 추출 후 재정리
	T_Entry<K, V>* getHeapMin();//우선순위 높은값 추출
	void fprint(ofstream& fout);
	int size() { return this->end; }
private:
};

template<typename K, typename V>
HeapPrioQueue<K, V>::HeapPrioQueue(int capa, string nm)//생성자
	:CompleteBinaryTree<K,V>(capa,nm)//생성자 호출
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
	index = this->add_at_end(elem);//마지막에 원소추가

	//업힙버블링 실행
	while (index != CBT_ROOT)//루트노드가 아닐경우
	{
		parent_index = this->parentIndex(index);//부모노드 설정
			if (this->t_GA[index].getKey() > this->t_GA[parent_index].getKey())//부모노드보다 자신의 값이 더 클경우
				break;
			else
			{
				temp = this->t_GA[index];
				this->t_GA[index] = this->t_GA[parent_index];
				this->t_GA[parent_index] = temp;	
				index = parent_index;//인덱스를 이전의 부모노드로설정
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
	int HPQ_size = size();//큐 크기설정

	if (HPQ_size <= 0)//큐 크기가 0보다 작을시
		return NULL;
	pMinElem = (T_Entry<K, V>*)new T_Entry<K, V>;
	*pMinElem = this->getRootElement();//루트노드의 값 
	if (HPQ_size == 1)//사이즈가 1일경우
		this->removeCBTEnd();//비어있는 상태로 만듦
	else
	{
		index_p = CBT_ROOT;
		this->t_GA[CBT_ROOT] = this->t_GA[this->end];//마지막에 있던 값 루트노드로 이동
		this->end--;
	
	//다운 힙버블링

		while (this->hasLeftChild(index_p))//왼쪽자식 노드가 있는경우
		{
			index_c = this->leftChildIndex(index_p);//왼쪽자식 노드 설정
			index_rc = this->rightChildIndex(index_p);//오른쪽 자식 설정
			if (this->hasRightChild(index_p) && (this->t_GA[index_c] > this->t_GA[index_rc]))//우선순위가 오른쪽이 더클경우
				index_c = index_rc;
			t_p = this->t_GA[index_p];//부모 노드 
			t_c = this->t_GA[index_c];//자식 노드
			if (t_p > t_c)//부모의 우선순위가 자식보다 낮다면
			{
				temp = this->t_GA[index_p];
				this->t_GA[index_p] = this->t_GA[index_c];
				this->t_GA[index_c] = temp;
				index_p = index_c;//부모인덱스 재설정
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

	if (size() <= 0)//크키가 0보다 작을경우
		return NULL;
	pMinElem = (T_Entry<K, V>*)new T_Entry<K, V>;
	*pMinElem = this->getRootElement();//루트 노드 값(우선순위가 가장높은 값)

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