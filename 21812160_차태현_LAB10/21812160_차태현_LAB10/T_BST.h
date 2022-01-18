#ifndef TBS_H
#define TBS_H

#include"T_Entry.h"
#include"T_BSTN.h"
#include"T_array.h"

template<typename K,typename V>
class T_BST
{
public:
	T_BST(string nm):_root(NULL),num_entry(0),name(nm){}//생성자
	string getName() { return name; }//이름 반환
	int size() const { return num_entry; }//크기 반환
	bool empty() const { return num_entry == 0; }//비어있는지 판별
	void clear();//전체 제거
	T_BSTN<K, V>* getRoot() { return _root; }//root 값 반환
	T_BSTN<K, V>** getRootAddr() { return &_root; }//root 주소 
	T_Entry<K, V>& getRootEntry() { return _root->getEntry(); }//root의 원소 
	T_BSTN<K, V>* eraseBSTN(T_BSTN<K, V>** pp);//노드 삭제
	void insertOrder(const T_Entry<K, V> entry);//순서에 맞춰 삽입
	void insertAndRebalance(T_Entry<K, V> e);//삽입후 재배치
	void traversal_inOrder(T_BSTN<K, V>* p, T_Array<V>& array_value);//데이터 크기에 따른 순차 순회
	void traversal_preOrder(T_BSTN<K, V>* p, T_Array<V>& array_value);//p먼저 처리후 왼쪽처리 마지막 오른쪽 처리
	void traversal_postOrder(T_BSTN<K, V>* p, T_Array<V>& array_value);//왼쪽처리 오른쪽처리 p처리
	T_BSTN<K, V>* searchBSTN(K k);//k값 탐색
	T_Entry<K, V>& minEntry();//원소 최소값
	T_Entry<K, V>& maxEntry();//원소 최대값
	void fprint_with_Depth(ostream& fout);//깊이를 고려해 출력
	void fprint_inOrder(ostream& fout);//크기순으로 출력
protected:
	T_BSTN<K, V>* _maxBSTN(T_BSTN<K, V>* subRoot);//최대값 노드
	T_BSTN<K, V>* _minBSTN(T_BSTN<K, V>* subRoot);//최소값 노드
	T_BSTN<K, V>* _insertInOrder(T_BSTN<K, V>** pp, T_BSTN<K, V>* parenPos, const T_Entry<K, V> e);//순서에 맞춰 삽입
	T_BSTN<K, V>* _insertAndRebalance(T_BSTN<K, V>** ppTN, T_BSTN<K, V>* pPr, T_Entry<K, V>e);//삽입후 재배치
	T_BSTN<K, V>* _rotate_LL(T_BSTN<K, V>* pCurSubRoot);//왼쪽편중 재정렬
	T_BSTN<K, V>* _rotate_RR(T_BSTN<K, V>* pCurSubRoot);//오른쪽편중 재정렬
	T_BSTN<K, V>* _rotate_RL(T_BSTN<K, V>* pCurSubRoot);//오른쪽편중 내부는 왼쪽평중
	T_BSTN<K, V>* _rotate_LR(T_BSTN<K, V>* pCurSubRoot);//왼쪽편중 내부는 오른쪽편중
	int _getHeight(T_BSTN<K, V>* pTN);//높이구하기
	int _getHeightDiff(T_BSTN<K, V>* pTN);//높이 차 계산
	T_BSTN<K, V>* _reBalance(T_BSTN<K, V>** ppTN);//재배치
	T_BSTN<K, V>* _searchBSTN(T_BSTN<K, V>* pos, K k);//탐색
	void _fprint_with_Depth(T_BSTN<K, V>* pTN, ostream& fout, int depth);//깊이를 고려해 출력
	void _fprint_inOrder(T_BSTN<K, V>* pTN, ostream& fout);//크기순으로 출력
private:
	T_BSTN<K, V>* _root;//루트노드
	int num_entry;//원소 수
	string name;//이름
};
template<typename K, typename V>
T_BSTN<K, V>* T_BST<K, V>::_maxBSTN(T_BSTN<K, V>* subRoot)//최대 값 찾기
{
	T_BSTN<K, V>* pos;
	if ((subRoot == NULL) || (NULL == subRoot->getpRc()))//서브 트리의 루트노드가 0이거나 오른쪽자식이 NULL일경우
		return subRoot;//루트노드가 가장 큰값
	pos = subRoot;
	while (pos->getpRc() != NULL)//오른쪽 자식이 없을때 까지
	{
		pos = pos->getpRc();//오른쪽 자식을 계속찾기위해 
	}
	return pos;//최대값 노드 반환
}


template<typename K,typename V>
T_BSTN<K, V>* T_BST<K, V>::_minBSTN(T_BSTN<K, V>* subRoot)//최소 값 찾기
{
	T_BSTN<K, V>* pos, * pLc;

	if ((subRoot == NULL) || (NULL == subRoot->getpLc()))//서브 트리의 루트노드가 0이거나 왼쪽자식이 NULL일경우
		return subRoot;//루트노드가 가장 작은값
	pos = subRoot;
	while ((pos->getpLc()) != NULL)//왼쪽자식이 없을때까지
	{
		pos = pos->getpLc();//왼쪽자식의 왼쪽자식을 계속 찾기위해
	}
	return pos;//최소값 노드 반환
}

template<typename K, typename V>
T_Entry<K, V>& T_BST<K, V>::maxEntry()
{
	T_BSTN<K, V>* pMax;
	pMax = _minBSTN(_root);//최대값을 가지는 노드 반환

	return pMax->getEntry();//원소 반환
}

template<typename K, typename V>
T_Entry<K, V>& T_BST<K, V>::minEntry()
{
	T_BSTN<K, V>* pMin;
	pMin = _minBSTN(_root);//최소값을 가지는 노드 반환

	return pMin->getEntry();//원소 반환
}

template<typename K, typename V>
T_BSTN<K, V>* T_BST<K, V>::_insertInOrder(T_BSTN<K, V>** pp, T_BSTN<K, V>* parenPos, const T_Entry<K, V> e)
{
	T_BSTN<K, V>* newPos, ** pChildPos;
	T_BSTN<K, V>* pos;
	T_Entry<K, V> ent;

	if (pp == NULL)//삽입할 위치가 NULL일경우
	{
		cout << "Error in creation of BinarySearchTree:";
		exit;
	}
	pos = *pp;
	if (pos == NULL)//이진트리가 비어있거나 마지막노드의 한쪽자식일경우
	{
		pos = new T_BSTN<K, V>(e);//노드생성
		if (parenPos == NULL)//부모노드가 없는경우
		{
			_root = pos;//루트노드자체가 pos
		}
		pos->setpPr(parenPos);//삽입할 위치의 부모노드 설정
		*pp = pos;
		num_entry++;//원소 수 증가
		
		return pos;//노드가 추가된 위치 반환
	}
	ent = pos->getEntry();//원소 저장
	if (e < ent)//삽입할 노드가 더 작은경우
	{
		pChildPos = pos->getppLc();//왼쪽자식 노드의 주소
		newPos = _insertInOrder(pChildPos, pos, e);//삽입된 주소 설정
		if (newPos != NULL)
			pos->setpLc(newPos);//왼쪽 자식노드로 설정
		return NULL;
	}
	else if (e >= ent)//삽입할 노드가 같거나 큰경우
	{
		pChildPos = pos->getppRc();//오른쪽 노드의 자식주소
		newPos = _insertInOrder(pChildPos, pos, e);//삽인된 주소 설정
		if (newPos != NULL)
			pos->setpRc(newPos);//오른쪽 자식 설정
		return NULL;
	}
}

template<typename K, typename V>
void T_BST<K, V>::insertOrder(const T_Entry<K, V> entry)
{
	_insertInOrder(&_root, NULL, entry);//root의 노드부터 탐색하여 삽입
}

template<typename K, typename V>
void T_BST<K, V>::traversal_inOrder(T_BSTN<K, V>* p, T_Array<V>& array_value)
{
	T_BSTN<K, V>* pLc, * pRc;
	T_Entry<K, V> entry;
	V value;
	if (p == NULL)
		return;
	pLc = p->getpLc();//왼쪽자식 설정
	pRc = p->getpRc();//오른쪽자식 설정
	//p 기준 왼쪽 서브트리 처리
	traversal_inOrder(pLc, array_value);//왼쪽자식 먼저 처리
	//p 자기자신 처리
	entry = p->getEntry();//자신의 원소 받아옴
	value = entry.getValue();//원소의 값받아옴
	array_value.insert(value);
	//p기준 오른쪽 서브트리 처리
	traversal_inOrder(pRc, array_value);
}

template<typename K, typename V>
void T_BST<K, V>::traversal_preOrder(T_BSTN<K, V>* p, T_Array<V>& array_value)
{
	T_BSTN<K, V>* pLc, * pRc;
	T_Entry<K, V> entry;
	V value;
	if (p == NULL)
		return;
	pLc = p->getpLc();//왼쪽자식 설정
	pRc = p->getpRc();//오른쪽자식 설정
	//p 자신 먼저 처리
	entry = p->getEntry();//자신의 원소 받아옴
	value = entry.getValue();//원소의 값받아옴
	array_value.insert(value);
	//왼쪽 서브트리에 대해 처리
	traversal_preOrder(pLc, array_value);
	//오른쪽 서브트리에 대해 처리
	traversal_preOrder(pRc, array_value);
}

template<typename K, typename V>
void T_BST<K, V>::traversal_postOrder(T_BSTN<K, V>* p, T_Array<V>& array_value)
{
	T_BSTN<K, V>* pLc, * pRc;
	T_Entry<K, V> entry;
	V value;
	if (p == NULL)
		return;
	pLc = p->getpLc();//왼쪽자식 설정
	pRc = p->getpRc();//오른쪽자식 설정
	//왼쪽 서브트리 처리
	traversal_postOrder(pLc, array_value);
	//오른쪽 서브트리 처리
	traversal_postOrder(pRc, array_value);
	//p 자신마지막 처리
	entry = p->getEntry();//자신의 원소 받아옴
	value = entry.getValue();//원소의 값받아옴
	array_value.insert(value);
}

template<typename K, typename V>
T_BSTN<K, V>* T_BST<K, V>::_searchBSTN(T_BSTN<K, V>* pos, K k)
{
	K ent_k;
	T_BSTN<K, V>* pos_result = NULL;

	if (pos == NULL)
		return NULL;
	ent_k = pos->getKey();//key값 받아옴
	//key값 비교
	if (ent_k == k)//일치할 경우 
	{
		pos_result = pos;
	}
	else if (ent_k > k)//찾으려는 값이 더 작으면
		pos_result = _searchBSTN(pos->getpLc(), k);//왼쪽서브트리에 대해 탐색
	else if (ent_k < k)//찾으려는 값이 더 클경우
		pos_result = _searchBSTN(pos->getpRc(), k);//오른쪽 서브트리에 대해 탐색

	return pos_result;
}
template<typename K, typename V>
T_BSTN<K, V>* T_BST<K, V>::searchBSTN(K k)
{
	T_BSTN<K, V>* pEntry;
	pEntry = _searchBSTN(_root, k);//루트노드부터 k값 탐색

	return pEntry;
}

template<typename K, typename V>
void T_BST<K, V>::_fprint_inOrder(T_BSTN<K, V>* pTN, ostream& fout)
{
	T_BSTN<K, V>* pRc, * pLc;
	if ((pLc = pTN->getpLc()) != NULL)
		_fprint_inOrder(pLc, fout);//왼쪽자식  출력 작은값
	fout << pTN->getEntry() << endl;//서브루트 출력
	if ((pRc = pTN->getpRc()) != NULL)//오른쪽자식 출력 큰값
		_fprint_inOrder(pRc, fout);
}

template<typename K, typename V>
void T_BST<K, V>::fprint_inOrder(ostream& fout)
{
	T_BSTN<K, V>* root = getRoot();//root 값 받아오기
	if (num_entry == 0)
	{
		fout << "EMPTY";
		return;
	}
	_fprint_inOrder(root, fout);//루트부터 전체 출력
}

template<typename K, typename V>
void T_BST<K, V>::_fprint_with_Depth(T_BSTN<K, V>* pTN, ostream& fout, int depth)
{
	T_BSTN<K, V>* pRc, * pLc;
	T_Entry<K, V>* pEntry;
	//처음 출력되는 부분이 큰쪽 트리의 오른쪽 이므로 오른쪽먼저 출력
	if ((pRc = pTN->getpRc()) != NULL)//오른쪽자식 출력 큰값
		_fprint_with_Depth(pRc, fout, depth + 1);//깊이는 증가됨
	for (int i = 0; i < depth; i++)
	{
		fout << "      ";//들여쓰기
	}
	fout << pTN->getEntry() << endl;//자기자신 출력
	if ((pLc = pTN->getpLc()) != NULL)//왼쪽 출력 작은값들
		_fprint_with_Depth(pLc, fout, depth + 1);//깊이는 증가됨
}

template<typename K, typename V>
void T_BST<K, V>::fprint_with_Depth(ostream& fout)
{
	T_BSTN<K, V>* root = getRoot();//root 값 받아오기
	if (num_entry == 0)
	{
		fout << "EMPTY";
		return;
	}
	_fprint_with_Depth(root, fout, 0);//들여쓰기를 포함하여 루트부터 출력
}


template<typename K, typename V>
T_BSTN<K, V>* T_BST<K, V>::eraseBSTN(T_BSTN<K, V>** pp)
{
	T_BSTN<K, V>* newSubRoot;
	T_BSTN<K, V>* toBeErased;

	toBeErased = *pp;//삭제대상
	if (toBeErased == NULL)//삭제대상이 없음
		return NULL;
	if ((toBeErased->getpLc() == NULL) && (toBeErased->getpRc() == NULL))//자식이 존재하지 않음
	{
		newSubRoot=NULL;
	}
	else if ((toBeErased->getpLc() != NULL) && (toBeErased->getpRc() == NULL))//왼쪽자식만 존재
	{
		newSubRoot=toBeErased->getpLc();//왼쪽 자식으로설정
		newSubRoot->setpPr(toBeErased->getpPr());//삭제대상 부모노드를 newSubRoot의 부모노드로 설정
	}
	else if ((toBeErased->getpLc() == NULL) && (toBeErased->getpRc() != NULL))//오른쪽자식만 존재
	{
		newSubRoot = toBeErased->getpRc();//오른쪽 자식으로설정
		newSubRoot->setpPr(toBeErased->getpPr());//삭제대상 부모노드를 newSubRoot의 부모노드로 설정
	}
	else// 두개의 자식이 다 존재
	{
		int heightDiff= _getHeightDiff(toBeErased);//높이 차 계산
		T_BSTN<K, V>* parDel = toBeErased->getpPr();//삭제대상노드의 부모노드
		T_BSTN<K, V>* lChild = toBeErased->getpLc();//삭제대상노드의 왼쪽자식
		T_BSTN<K, V>* rChild = toBeErased->getpRc();//삭제대상노드의 오른쪽자식
		T_BSTN<K, V>* ioSs = NULL, * rcIoSs, * parIoSs;
		T_BSTN<K, V>* ioPd = NULL, * lcIoPd, * parIoPd;

		if (heightDiff > 0)//왼쪽서브트리가 더 높다
		{
			ioPd = _maxBSTN(lChild);//lChild기준 가장큰 노드 찾기 서브트리중 가장 오른쪽
			lcIoPd = ioPd->getpLc();//가장큰 노드의 왼쪽자식
			parIoPd = ioPd->getpPr();//가장큰 노드의 부모노드
			newSubRoot = ioPd;//새로운 서브루트는 가장큰 노드
			if (ioPd->getpPr() != toBeErased)//삭제할 값이 새로운 서브루트노드의 부모노드가 아닌경우
			{
				newSubRoot->setpLc(lChild);//삭제대상의 왼쪽자식노드를 서브루트노드의 왼쪽자식으로 설정
				parIoPd->setpRc(lcIoPd);//서브루트노드의 부모노드의 오른쪽 자식을 서브루트노드의  왼쪽자식으로 설정
				if (lcIoPd != NULL)//서브루트 노드의 왼쪽자식이 있으면
					lcIoPd->setpPr(parIoPd);//서브루트노드의 부모노드를 자신의 부모노드로 설정
			}
			newSubRoot->setpRc(rChild);//오른쪽자식은 삭제대상 오른쪽자식으로 설정
			newSubRoot->setpPr(parDel);//부모노드는 삭제대상 부모노드로 설정
		}
		else//오른쪽 서브트리의 높이가 더 높을경우
		{
			ioSs = _minBSTN(rChild);//오른쪽 서브트리중 가장 작은 노드찾기
			rcIoSs = ioSs->getpRc();//오른쪽 자식노드 설정
			parIoSs = ioSs->getpPr();//부모노드설정
			newSubRoot = ioSs;//새로운 서브루트노드는 가장작은 노드
			if (ioSs->getpPr() != toBeErased)//가장작은노드의 부모노드값이 삭제할 대상이 아닌경우
			{
				newSubRoot->setpRc(rChild);//오른쪽 자식은 삭제대상의 오른쪽 자식
				parIoSs->setpLc(rcIoSs);//서브루트노드의 오른쪽자식은 서브루트노드의 부모노드의 왼쪽자식이 됨
				if (rcIoSs != NULL)
					rcIoSs->setpPr(parIoSs);//부모노드로 설정해서 연결
			}
			newSubRoot->setpLc(lChild);//서브루트의 왼쪽자식은 삭제대상 왼쪽노드
			newSubRoot->setpPr(parDel);//서브루트의 부모 삭제대상 부모
		}
		if (lChild != ioPd)
			lChild->setpPr(newSubRoot);//부모노드로 설정해서 연결
		if (rChild != ioSs)
			rChild->setpPr(newSubRoot);//부모노드로 설정해서 연결
	}
	if (toBeErased == _root)//삭제대상이 루트일경우
		_root = newSubRoot;//루트 값은 서브루트 값

	num_entry--;//원소수 감소
	free(toBeErased);
	*pp = newSubRoot;

	return newSubRoot;
}

template<typename K, typename V>
void T_BST<K, V>::clear()//전체제거
{
	while (size() != 0)//사이즈가 0아닐때 반복
	{
		eraseBSTN(&_root);//루트노드부터 제거
	}
}

template<typename K, typename V>
T_BSTN<K, V>* T_BST<K, V>::_rotate_LL(T_BSTN<K, V>* pCurSubRoot)//왼쪽편중 재정렬
{
	T_BSTN<K, V>* pNewSubRoot, * pBR, * pCurParent;

	pCurParent = pCurSubRoot->getpPr();//현재서브루트노드의 부모 노드 설정
	pNewSubRoot = pCurSubRoot->getpLc();//새로운 서브루트노드는 기존서브루트의 왼쪽자식
	pBR = pNewSubRoot->getpRc();//새로운 서브루트노드의 오른쪽자식
	pCurSubRoot->setpLc(pBR);//이전의 서브루트노드의 왼쪽자식은 새로운서브루트노드의 오른쪽자식
	if (pBR != NULL)
		pBR->setpPr(pCurSubRoot);//부모노드 설정해서 연결
	pNewSubRoot->setpRc(pCurSubRoot);//새로운 서브루트노드의 오른쪽자식은 기존 서브루트노드
	pNewSubRoot->setpPr(pCurParent);//부모노드는 기존서브루트 노드값 받아옴
	pCurSubRoot->setpPr(pNewSubRoot);//새로운서브루트노드가 기존 서브루트노드의 부모노드가 됨

	return pNewSubRoot;//새로운 서브루트노드 반환
}

template<typename K, typename V>
T_BSTN<K, V>* T_BST<K, V>::_rotate_RR(T_BSTN<K, V>* pCurSubRoot)//오른쪽 편중 재정렬
{
	T_BSTN<K, V>* pNewSubRoot, * pBL, * pCurParent;

	pCurParent = pCurSubRoot->getpPr();//현재서브루트노드의 부모 노드 설정
	pNewSubRoot = pCurSubRoot->getpRc();//새로운 서브루트노드는 기존서브루트의 오른쪽자식
	pBL = pNewSubRoot->getpLc();//새로운 서브루트노드의 왼쪽자식
	pCurSubRoot->setpRc(pBL);//이전의 서브루트노드의 오른쪽자식은 새로운서브루트노드의 왼쪽자식
	if (pBL != NULL)
		pBL->setpPr(pCurSubRoot);//부모노드 설정해서 연결
	pNewSubRoot->setpLc(pCurSubRoot);//새로운 서브루트노드의 왼쪽자식은 기존 서브루트노드
	pNewSubRoot->setpPr(pCurParent);//부모노드는 기존서브루트 노드값 받아옴
	pCurSubRoot->setpPr(pNewSubRoot);//새로운서브루트노드가 기존 서브루트노드의 부모노드가 됨

	return pNewSubRoot;//새로운 서브루트노드 반환
}

template<typename K, typename V>
T_BSTN<K, V>* T_BST<K, V>::_rotate_LR(T_BSTN<K, V>* pCurSubRoot)
{
	T_BSTN<K, V>* pSubRoot, * pNewSubRoot, * pCurParent;
	T_BSTN<K, V>* pA, * pB, * pC, * pBL, * pBR;

	pC = pCurSubRoot;// 서브루트노드
	pCurParent = pCurSubRoot->getpPr();//서브루트노드의 부모노드
	pA = pC->getpLc();// 서브루트노드의 왼쪽자식
	pB = pA->getpRc();// 서브루트노드의 왼쪽자식의 오른쪽자식
	pBL = pB->getpLc();//서브루트노드의 왼쪽자식의 오른쪽자식의 왼쪽자식
	pBR = pB->getpRc();//서브루트노드의  왼쪽자식의 오른쪽자식의 오른쪽자식
	pSubRoot = _rotate_RR(pA);//오른쪽으로 꺽여있는 부분 재배치
	pCurSubRoot->setpLc(pSubRoot);//재배치 한것을 왼쪽자식으로 설정
	pNewSubRoot = _rotate_LL(pC);//왼쪽편중이므로 LL실행
	pNewSubRoot->setpPr(pCurParent);//부모노드는 전달받은 인수의 부모노드와 같음
	pA->setpPr(pNewSubRoot);//새로운 루트노드를 부모노드로 설정
	pC->setpPr(pNewSubRoot);//새로운 루트노드를 부모노드로 설정

	if (pBL != NULL)
		pBL->setpPr(pA);
	if (pBR != NULL)
		pBR->setpPr(pC);

	return pNewSubRoot;
}

template<typename K, typename V>
T_BSTN<K, V>* T_BST<K, V>::_rotate_RL(T_BSTN<K, V>* pCurSubRoot)
{
	T_BSTN<K, V>* pSubRoot, * pNewSubRoot, * pCurParent;
	T_BSTN<K, V>* pA, * pB, * pC, * pBL, * pBR;

	pA = pCurSubRoot;// 서브루트노드
	pCurParent = pCurSubRoot->getpPr();//서브루트노드의 부모노드
	pC = pA->getpRc();// 서브루트노드의 오른쪽자식
	pB = pC->getpLc();//서브루트노드의 오른쪽자식의 왼쪽자식
	pBL = pB->getpLc();//서브루트노드의 오른쪽자식의 왼쪽자식의 왼쪽자식
	pBR = pB->getpRc();//서브루트노드의 오른쪽자식의 왼쪽자식의 오른쪽자식
	pSubRoot = _rotate_LL(pC);//내부에 왼쪽으로 꺽여있는 부분 재배치
	pCurSubRoot->setpRc(pSubRoot);//재배치 한것을 오른쪽자식으로 설정
	pNewSubRoot = _rotate_RR(pA);//오른쪽편중이므로 RR실행
	
	pNewSubRoot->setpPr(pCurParent);//부모노드는 전달받은 인수의 부모노드와 같음
	pA->setpPr(pNewSubRoot);//새로운 루트노드를 부모노드로 설정
	pC->setpPr(pNewSubRoot);//새로운 루트노드를 부모노드로 설정

	if (pBL != NULL)
		pBL->setpPr(pA);
	if (pBR != NULL)
		pBR->setpPr(pC);


	return pNewSubRoot;
}



template<typename K, typename V>
int T_BST<K, V>::_getHeight(T_BSTN<K, V>* pTN)
{
	int height = 0;
	int height_Lc, height_Rc;

	if (pTN != NULL)
	{
		height_Lc = _getHeight(pTN->getpLc());//왼쪽 높이계산
		height_Rc = _getHeight(pTN->getpRc());//오른쪽 높이계산

		if (height_Lc > height_Rc)//왼쪽이 더 높을경우
		{
			height = 1 + height_Lc;//전체 높이는 왼쪽높이+1
		}
		else//오른쪽이 더 높을경우
			height = 1 + height_Rc;//전체 높이는 오른쪽높이+1
	}
	return height;//높이 반환
}

template<typename K, typename V>
int T_BST<K, V>::_getHeightDiff(T_BSTN<K, V>* pTN)
{
	int heightDiff = 0;

	if (pTN == NULL)
		return 0;

	heightDiff = _getHeight(pTN->getpLc()) - _getHeight(pTN->getpRc());//왼쪽높이-오른쪽 높이

	return heightDiff;
}

template<typename K, typename V>
T_BSTN<K, V>* T_BST<K, V>::_reBalance(T_BSTN<K, V>** ppTN)
{
	int heightDiff = 0;

	heightDiff = _getHeightDiff(*ppTN);
	if (heightDiff > 1)//왼쪽 서브트리가 더 높이가 높음
	{
		if (_getHeightDiff((*ppTN)->getpLc()) > 0)//자식의 높이차 계산
			*ppTN = _rotate_LL(*ppTN);//왼쪽편중 해결
		else
			*ppTN = _rotate_LR(*ppTN);//왼쪽편중 내부 오른쪽편중해결
	}
	else if (heightDiff < -1)//오른쪽 서브트리 높이가 더 높음
	{
		if (_getHeightDiff((*ppTN)->getpRc()) < 0)
			*ppTN = _rotate_RR(*ppTN);//오른쪽편중해결
		else
			*ppTN = _rotate_RL(*ppTN);//오른쪽편중 내부 왼쪽편중해결
	}

	return *ppTN;
}




template<typename K, typename V>
T_BSTN<K, V>* T_BST<K, V>::_insertAndRebalance(T_BSTN<K, V>** ppTN, T_BSTN<K, V>* pPr, T_Entry<K, V> entry)
{
	T_BSTN<K, V>* pTN, ** ppLc, ** ppRc;

	if (*ppTN == NULL)//NULL포인터라면
	{
		pTN = new T_BSTN<K, V>(entry);//새로운 노드 생성
		*ppTN = pTN;
		if (pPr != NULL)//루트노드가 아니라면
			pTN->setpPr(pPr);//부모노드를 pPr로 설정
		(*ppTN)->setpLc(NULL);//새로생성된 자식노드는 NULL
		(*ppTN)->setpRc(NULL);

		num_entry++;//원소 추가

		return *ppTN;//노드추가된 주소
	}
	T_Entry<K, V> bstn_entry;
	bstn_entry = (*ppTN)->getEntry();
	//원소값에 따라 삽입하기 위함
	if (entry < bstn_entry)//삽입할 원소가 더 작을경우
	{
		ppLc = (*ppTN)->getppLc();//왼쪽노드주소로 설정
		pTN = _insertAndRebalance(ppLc, *ppTN, entry);//삽입될 주소
		if (ppTN != NULL)
		{
			(*ppTN)->setpLc(pTN);//기준의 왼쪽 자식으로 설정
			*ppTN = _reBalance(ppTN);//재배치
		}
	}
	else//삽입할 원소가 더 크거나 같을경우
	{
		ppRc = (*ppTN)->getppRc();//오른쪽 노드주소로 설정
		pTN = _insertAndRebalance(ppRc, *ppTN, entry);//삽입될 주소 
		if (ppTN != NULL)
		{
			(*ppTN)->setpRc(pTN);//기준의 오른쪽 자식으로 설정
			*ppTN = _reBalance(ppTN);//재배치
		}
	}
	
	return *ppTN;
}

template<typename K, typename V>
void T_BST<K, V>::insertAndRebalance(T_Entry<K, V> entry)
{
	_insertAndRebalance(&_root, NULL, entry);
}

#endif // !TBS_H
