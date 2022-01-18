#ifndef TBS_H
#define TBS_H

#include"T_Entry.h"
#include"T_BSTN.h"
#include"T_array.h"

template<typename K,typename V>
class T_BST
{
public:
	T_BST(string nm):_root(NULL),num_entry(0),name(nm){}//������
	string getName() { return name; }//�̸� ��ȯ
	int size() const { return num_entry; }//ũ�� ��ȯ
	bool empty() const { return num_entry == 0; }//����ִ��� �Ǻ�
	void clear();//��ü ����
	T_BSTN<K, V>* getRoot() { return _root; }//root �� ��ȯ
	T_BSTN<K, V>** getRootAddr() { return &_root; }//root �ּ� 
	T_Entry<K, V>& getRootEntry() { return _root->getEntry(); }//root�� ���� 
	T_BSTN<K, V>* eraseBSTN(T_BSTN<K, V>** pp);//��� ����
	void insertOrder(const T_Entry<K, V> entry);//������ ���� ����
	void insertAndRebalance(T_Entry<K, V> e);//������ ���ġ
	void traversal_inOrder(T_BSTN<K, V>* p, T_Array<V>& array_value);//������ ũ�⿡ ���� ���� ��ȸ
	void traversal_preOrder(T_BSTN<K, V>* p, T_Array<V>& array_value);//p���� ó���� ����ó�� ������ ������ ó��
	void traversal_postOrder(T_BSTN<K, V>* p, T_Array<V>& array_value);//����ó�� ������ó�� pó��
	T_BSTN<K, V>* searchBSTN(K k);//k�� Ž��
	T_Entry<K, V>& minEntry();//���� �ּҰ�
	T_Entry<K, V>& maxEntry();//���� �ִ밪
	void fprint_with_Depth(ostream& fout);//���̸� ����� ���
	void fprint_inOrder(ostream& fout);//ũ������� ���
protected:
	T_BSTN<K, V>* _maxBSTN(T_BSTN<K, V>* subRoot);//�ִ밪 ���
	T_BSTN<K, V>* _minBSTN(T_BSTN<K, V>* subRoot);//�ּҰ� ���
	T_BSTN<K, V>* _insertInOrder(T_BSTN<K, V>** pp, T_BSTN<K, V>* parenPos, const T_Entry<K, V> e);//������ ���� ����
	T_BSTN<K, V>* _insertAndRebalance(T_BSTN<K, V>** ppTN, T_BSTN<K, V>* pPr, T_Entry<K, V>e);//������ ���ġ
	T_BSTN<K, V>* _rotate_LL(T_BSTN<K, V>* pCurSubRoot);//�������� ������
	T_BSTN<K, V>* _rotate_RR(T_BSTN<K, V>* pCurSubRoot);//���������� ������
	T_BSTN<K, V>* _rotate_RL(T_BSTN<K, V>* pCurSubRoot);//���������� ���δ� ��������
	T_BSTN<K, V>* _rotate_LR(T_BSTN<K, V>* pCurSubRoot);//�������� ���δ� ����������
	int _getHeight(T_BSTN<K, V>* pTN);//���̱��ϱ�
	int _getHeightDiff(T_BSTN<K, V>* pTN);//���� �� ���
	T_BSTN<K, V>* _reBalance(T_BSTN<K, V>** ppTN);//���ġ
	T_BSTN<K, V>* _searchBSTN(T_BSTN<K, V>* pos, K k);//Ž��
	void _fprint_with_Depth(T_BSTN<K, V>* pTN, ostream& fout, int depth);//���̸� ����� ���
	void _fprint_inOrder(T_BSTN<K, V>* pTN, ostream& fout);//ũ������� ���
private:
	T_BSTN<K, V>* _root;//��Ʈ���
	int num_entry;//���� ��
	string name;//�̸�
};
template<typename K, typename V>
T_BSTN<K, V>* T_BST<K, V>::_maxBSTN(T_BSTN<K, V>* subRoot)//�ִ� �� ã��
{
	T_BSTN<K, V>* pos;
	if ((subRoot == NULL) || (NULL == subRoot->getpRc()))//���� Ʈ���� ��Ʈ��尡 0�̰ų� �������ڽ��� NULL�ϰ��
		return subRoot;//��Ʈ��尡 ���� ū��
	pos = subRoot;
	while (pos->getpRc() != NULL)//������ �ڽ��� ������ ����
	{
		pos = pos->getpRc();//������ �ڽ��� ���ã������ 
	}
	return pos;//�ִ밪 ��� ��ȯ
}


template<typename K,typename V>
T_BSTN<K, V>* T_BST<K, V>::_minBSTN(T_BSTN<K, V>* subRoot)//�ּ� �� ã��
{
	T_BSTN<K, V>* pos, * pLc;

	if ((subRoot == NULL) || (NULL == subRoot->getpLc()))//���� Ʈ���� ��Ʈ��尡 0�̰ų� �����ڽ��� NULL�ϰ��
		return subRoot;//��Ʈ��尡 ���� ������
	pos = subRoot;
	while ((pos->getpLc()) != NULL)//�����ڽ��� ����������
	{
		pos = pos->getpLc();//�����ڽ��� �����ڽ��� ��� ã������
	}
	return pos;//�ּҰ� ��� ��ȯ
}

template<typename K, typename V>
T_Entry<K, V>& T_BST<K, V>::maxEntry()
{
	T_BSTN<K, V>* pMax;
	pMax = _minBSTN(_root);//�ִ밪�� ������ ��� ��ȯ

	return pMax->getEntry();//���� ��ȯ
}

template<typename K, typename V>
T_Entry<K, V>& T_BST<K, V>::minEntry()
{
	T_BSTN<K, V>* pMin;
	pMin = _minBSTN(_root);//�ּҰ��� ������ ��� ��ȯ

	return pMin->getEntry();//���� ��ȯ
}

template<typename K, typename V>
T_BSTN<K, V>* T_BST<K, V>::_insertInOrder(T_BSTN<K, V>** pp, T_BSTN<K, V>* parenPos, const T_Entry<K, V> e)
{
	T_BSTN<K, V>* newPos, ** pChildPos;
	T_BSTN<K, V>* pos;
	T_Entry<K, V> ent;

	if (pp == NULL)//������ ��ġ�� NULL�ϰ��
	{
		cout << "Error in creation of BinarySearchTree:";
		exit;
	}
	pos = *pp;
	if (pos == NULL)//����Ʈ���� ����ְų� ����������� �����ڽ��ϰ��
	{
		pos = new T_BSTN<K, V>(e);//������
		if (parenPos == NULL)//�θ��尡 ���°��
		{
			_root = pos;//��Ʈ�����ü�� pos
		}
		pos->setpPr(parenPos);//������ ��ġ�� �θ��� ����
		*pp = pos;
		num_entry++;//���� �� ����
		
		return pos;//��尡 �߰��� ��ġ ��ȯ
	}
	ent = pos->getEntry();//���� ����
	if (e < ent)//������ ��尡 �� �������
	{
		pChildPos = pos->getppLc();//�����ڽ� ����� �ּ�
		newPos = _insertInOrder(pChildPos, pos, e);//���Ե� �ּ� ����
		if (newPos != NULL)
			pos->setpLc(newPos);//���� �ڽĳ��� ����
		return NULL;
	}
	else if (e >= ent)//������ ��尡 ���ų� ū���
	{
		pChildPos = pos->getppRc();//������ ����� �ڽ��ּ�
		newPos = _insertInOrder(pChildPos, pos, e);//���ε� �ּ� ����
		if (newPos != NULL)
			pos->setpRc(newPos);//������ �ڽ� ����
		return NULL;
	}
}

template<typename K, typename V>
void T_BST<K, V>::insertOrder(const T_Entry<K, V> entry)
{
	_insertInOrder(&_root, NULL, entry);//root�� ������ Ž���Ͽ� ����
}

template<typename K, typename V>
void T_BST<K, V>::traversal_inOrder(T_BSTN<K, V>* p, T_Array<V>& array_value)
{
	T_BSTN<K, V>* pLc, * pRc;
	T_Entry<K, V> entry;
	V value;
	if (p == NULL)
		return;
	pLc = p->getpLc();//�����ڽ� ����
	pRc = p->getpRc();//�������ڽ� ����
	//p ���� ���� ����Ʈ�� ó��
	traversal_inOrder(pLc, array_value);//�����ڽ� ���� ó��
	//p �ڱ��ڽ� ó��
	entry = p->getEntry();//�ڽ��� ���� �޾ƿ�
	value = entry.getValue();//������ ���޾ƿ�
	array_value.insert(value);
	//p���� ������ ����Ʈ�� ó��
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
	pLc = p->getpLc();//�����ڽ� ����
	pRc = p->getpRc();//�������ڽ� ����
	//p �ڽ� ���� ó��
	entry = p->getEntry();//�ڽ��� ���� �޾ƿ�
	value = entry.getValue();//������ ���޾ƿ�
	array_value.insert(value);
	//���� ����Ʈ���� ���� ó��
	traversal_preOrder(pLc, array_value);
	//������ ����Ʈ���� ���� ó��
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
	pLc = p->getpLc();//�����ڽ� ����
	pRc = p->getpRc();//�������ڽ� ����
	//���� ����Ʈ�� ó��
	traversal_postOrder(pLc, array_value);
	//������ ����Ʈ�� ó��
	traversal_postOrder(pRc, array_value);
	//p �ڽŸ����� ó��
	entry = p->getEntry();//�ڽ��� ���� �޾ƿ�
	value = entry.getValue();//������ ���޾ƿ�
	array_value.insert(value);
}

template<typename K, typename V>
T_BSTN<K, V>* T_BST<K, V>::_searchBSTN(T_BSTN<K, V>* pos, K k)
{
	K ent_k;
	T_BSTN<K, V>* pos_result = NULL;

	if (pos == NULL)
		return NULL;
	ent_k = pos->getKey();//key�� �޾ƿ�
	//key�� ��
	if (ent_k == k)//��ġ�� ��� 
	{
		pos_result = pos;
	}
	else if (ent_k > k)//ã������ ���� �� ������
		pos_result = _searchBSTN(pos->getpLc(), k);//���ʼ���Ʈ���� ���� Ž��
	else if (ent_k < k)//ã������ ���� �� Ŭ���
		pos_result = _searchBSTN(pos->getpRc(), k);//������ ����Ʈ���� ���� Ž��

	return pos_result;
}
template<typename K, typename V>
T_BSTN<K, V>* T_BST<K, V>::searchBSTN(K k)
{
	T_BSTN<K, V>* pEntry;
	pEntry = _searchBSTN(_root, k);//��Ʈ������ k�� Ž��

	return pEntry;
}

template<typename K, typename V>
void T_BST<K, V>::_fprint_inOrder(T_BSTN<K, V>* pTN, ostream& fout)
{
	T_BSTN<K, V>* pRc, * pLc;
	if ((pLc = pTN->getpLc()) != NULL)
		_fprint_inOrder(pLc, fout);//�����ڽ�  ��� ������
	fout << pTN->getEntry() << endl;//�����Ʈ ���
	if ((pRc = pTN->getpRc()) != NULL)//�������ڽ� ��� ū��
		_fprint_inOrder(pRc, fout);
}

template<typename K, typename V>
void T_BST<K, V>::fprint_inOrder(ostream& fout)
{
	T_BSTN<K, V>* root = getRoot();//root �� �޾ƿ���
	if (num_entry == 0)
	{
		fout << "EMPTY";
		return;
	}
	_fprint_inOrder(root, fout);//��Ʈ���� ��ü ���
}

template<typename K, typename V>
void T_BST<K, V>::_fprint_with_Depth(T_BSTN<K, V>* pTN, ostream& fout, int depth)
{
	T_BSTN<K, V>* pRc, * pLc;
	T_Entry<K, V>* pEntry;
	//ó�� ��µǴ� �κ��� ū�� Ʈ���� ������ �̹Ƿ� �����ʸ��� ���
	if ((pRc = pTN->getpRc()) != NULL)//�������ڽ� ��� ū��
		_fprint_with_Depth(pRc, fout, depth + 1);//���̴� ������
	for (int i = 0; i < depth; i++)
	{
		fout << "      ";//�鿩����
	}
	fout << pTN->getEntry() << endl;//�ڱ��ڽ� ���
	if ((pLc = pTN->getpLc()) != NULL)//���� ��� ��������
		_fprint_with_Depth(pLc, fout, depth + 1);//���̴� ������
}

template<typename K, typename V>
void T_BST<K, V>::fprint_with_Depth(ostream& fout)
{
	T_BSTN<K, V>* root = getRoot();//root �� �޾ƿ���
	if (num_entry == 0)
	{
		fout << "EMPTY";
		return;
	}
	_fprint_with_Depth(root, fout, 0);//�鿩���⸦ �����Ͽ� ��Ʈ���� ���
}


template<typename K, typename V>
T_BSTN<K, V>* T_BST<K, V>::eraseBSTN(T_BSTN<K, V>** pp)
{
	T_BSTN<K, V>* newSubRoot;
	T_BSTN<K, V>* toBeErased;

	toBeErased = *pp;//�������
	if (toBeErased == NULL)//��������� ����
		return NULL;
	if ((toBeErased->getpLc() == NULL) && (toBeErased->getpRc() == NULL))//�ڽ��� �������� ����
	{
		newSubRoot=NULL;
	}
	else if ((toBeErased->getpLc() != NULL) && (toBeErased->getpRc() == NULL))//�����ڽĸ� ����
	{
		newSubRoot=toBeErased->getpLc();//���� �ڽ����μ���
		newSubRoot->setpPr(toBeErased->getpPr());//������� �θ��带 newSubRoot�� �θ���� ����
	}
	else if ((toBeErased->getpLc() == NULL) && (toBeErased->getpRc() != NULL))//�������ڽĸ� ����
	{
		newSubRoot = toBeErased->getpRc();//������ �ڽ����μ���
		newSubRoot->setpPr(toBeErased->getpPr());//������� �θ��带 newSubRoot�� �θ���� ����
	}
	else// �ΰ��� �ڽ��� �� ����
	{
		int heightDiff= _getHeightDiff(toBeErased);//���� �� ���
		T_BSTN<K, V>* parDel = toBeErased->getpPr();//����������� �θ���
		T_BSTN<K, V>* lChild = toBeErased->getpLc();//����������� �����ڽ�
		T_BSTN<K, V>* rChild = toBeErased->getpRc();//����������� �������ڽ�
		T_BSTN<K, V>* ioSs = NULL, * rcIoSs, * parIoSs;
		T_BSTN<K, V>* ioPd = NULL, * lcIoPd, * parIoPd;

		if (heightDiff > 0)//���ʼ���Ʈ���� �� ����
		{
			ioPd = _maxBSTN(lChild);//lChild���� ����ū ��� ã�� ����Ʈ���� ���� ������
			lcIoPd = ioPd->getpLc();//����ū ����� �����ڽ�
			parIoPd = ioPd->getpPr();//����ū ����� �θ���
			newSubRoot = ioPd;//���ο� �����Ʈ�� ����ū ���
			if (ioPd->getpPr() != toBeErased)//������ ���� ���ο� �����Ʈ����� �θ��尡 �ƴѰ��
			{
				newSubRoot->setpLc(lChild);//��������� �����ڽĳ�带 �����Ʈ����� �����ڽ����� ����
				parIoPd->setpRc(lcIoPd);//�����Ʈ����� �θ����� ������ �ڽ��� �����Ʈ�����  �����ڽ����� ����
				if (lcIoPd != NULL)//�����Ʈ ����� �����ڽ��� ������
					lcIoPd->setpPr(parIoPd);//�����Ʈ����� �θ��带 �ڽ��� �θ���� ����
			}
			newSubRoot->setpRc(rChild);//�������ڽ��� ������� �������ڽ����� ����
			newSubRoot->setpPr(parDel);//�θ���� ������� �θ���� ����
		}
		else//������ ����Ʈ���� ���̰� �� �������
		{
			ioSs = _minBSTN(rChild);//������ ����Ʈ���� ���� ���� ���ã��
			rcIoSs = ioSs->getpRc();//������ �ڽĳ�� ����
			parIoSs = ioSs->getpPr();//�θ��弳��
			newSubRoot = ioSs;//���ο� �����Ʈ���� �������� ���
			if (ioSs->getpPr() != toBeErased)//������������� �θ��尪�� ������ ����� �ƴѰ��
			{
				newSubRoot->setpRc(rChild);//������ �ڽ��� ��������� ������ �ڽ�
				parIoSs->setpLc(rcIoSs);//�����Ʈ����� �������ڽ��� �����Ʈ����� �θ����� �����ڽ��� ��
				if (rcIoSs != NULL)
					rcIoSs->setpPr(parIoSs);//�θ���� �����ؼ� ����
			}
			newSubRoot->setpLc(lChild);//�����Ʈ�� �����ڽ��� ������� ���ʳ��
			newSubRoot->setpPr(parDel);//�����Ʈ�� �θ� ������� �θ�
		}
		if (lChild != ioPd)
			lChild->setpPr(newSubRoot);//�θ���� �����ؼ� ����
		if (rChild != ioSs)
			rChild->setpPr(newSubRoot);//�θ���� �����ؼ� ����
	}
	if (toBeErased == _root)//��������� ��Ʈ�ϰ��
		_root = newSubRoot;//��Ʈ ���� �����Ʈ ��

	num_entry--;//���Ҽ� ����
	free(toBeErased);
	*pp = newSubRoot;

	return newSubRoot;
}

template<typename K, typename V>
void T_BST<K, V>::clear()//��ü����
{
	while (size() != 0)//����� 0�ƴҶ� �ݺ�
	{
		eraseBSTN(&_root);//��Ʈ������ ����
	}
}

template<typename K, typename V>
T_BSTN<K, V>* T_BST<K, V>::_rotate_LL(T_BSTN<K, V>* pCurSubRoot)//�������� ������
{
	T_BSTN<K, V>* pNewSubRoot, * pBR, * pCurParent;

	pCurParent = pCurSubRoot->getpPr();//���缭���Ʈ����� �θ� ��� ����
	pNewSubRoot = pCurSubRoot->getpLc();//���ο� �����Ʈ���� ���������Ʈ�� �����ڽ�
	pBR = pNewSubRoot->getpRc();//���ο� �����Ʈ����� �������ڽ�
	pCurSubRoot->setpLc(pBR);//������ �����Ʈ����� �����ڽ��� ���ο���Ʈ����� �������ڽ�
	if (pBR != NULL)
		pBR->setpPr(pCurSubRoot);//�θ��� �����ؼ� ����
	pNewSubRoot->setpRc(pCurSubRoot);//���ο� �����Ʈ����� �������ڽ��� ���� �����Ʈ���
	pNewSubRoot->setpPr(pCurParent);//�θ���� ���������Ʈ ��尪 �޾ƿ�
	pCurSubRoot->setpPr(pNewSubRoot);//���ο���Ʈ��尡 ���� �����Ʈ����� �θ��尡 ��

	return pNewSubRoot;//���ο� �����Ʈ��� ��ȯ
}

template<typename K, typename V>
T_BSTN<K, V>* T_BST<K, V>::_rotate_RR(T_BSTN<K, V>* pCurSubRoot)//������ ���� ������
{
	T_BSTN<K, V>* pNewSubRoot, * pBL, * pCurParent;

	pCurParent = pCurSubRoot->getpPr();//���缭���Ʈ����� �θ� ��� ����
	pNewSubRoot = pCurSubRoot->getpRc();//���ο� �����Ʈ���� ���������Ʈ�� �������ڽ�
	pBL = pNewSubRoot->getpLc();//���ο� �����Ʈ����� �����ڽ�
	pCurSubRoot->setpRc(pBL);//������ �����Ʈ����� �������ڽ��� ���ο���Ʈ����� �����ڽ�
	if (pBL != NULL)
		pBL->setpPr(pCurSubRoot);//�θ��� �����ؼ� ����
	pNewSubRoot->setpLc(pCurSubRoot);//���ο� �����Ʈ����� �����ڽ��� ���� �����Ʈ���
	pNewSubRoot->setpPr(pCurParent);//�θ���� ���������Ʈ ��尪 �޾ƿ�
	pCurSubRoot->setpPr(pNewSubRoot);//���ο���Ʈ��尡 ���� �����Ʈ����� �θ��尡 ��

	return pNewSubRoot;//���ο� �����Ʈ��� ��ȯ
}

template<typename K, typename V>
T_BSTN<K, V>* T_BST<K, V>::_rotate_LR(T_BSTN<K, V>* pCurSubRoot)
{
	T_BSTN<K, V>* pSubRoot, * pNewSubRoot, * pCurParent;
	T_BSTN<K, V>* pA, * pB, * pC, * pBL, * pBR;

	pC = pCurSubRoot;// �����Ʈ���
	pCurParent = pCurSubRoot->getpPr();//�����Ʈ����� �θ���
	pA = pC->getpLc();// �����Ʈ����� �����ڽ�
	pB = pA->getpRc();// �����Ʈ����� �����ڽ��� �������ڽ�
	pBL = pB->getpLc();//�����Ʈ����� �����ڽ��� �������ڽ��� �����ڽ�
	pBR = pB->getpRc();//�����Ʈ�����  �����ڽ��� �������ڽ��� �������ڽ�
	pSubRoot = _rotate_RR(pA);//���������� �����ִ� �κ� ���ġ
	pCurSubRoot->setpLc(pSubRoot);//���ġ �Ѱ��� �����ڽ����� ����
	pNewSubRoot = _rotate_LL(pC);//���������̹Ƿ� LL����
	pNewSubRoot->setpPr(pCurParent);//�θ���� ���޹��� �μ��� �θ���� ����
	pA->setpPr(pNewSubRoot);//���ο� ��Ʈ��带 �θ���� ����
	pC->setpPr(pNewSubRoot);//���ο� ��Ʈ��带 �θ���� ����

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

	pA = pCurSubRoot;// �����Ʈ���
	pCurParent = pCurSubRoot->getpPr();//�����Ʈ����� �θ���
	pC = pA->getpRc();// �����Ʈ����� �������ڽ�
	pB = pC->getpLc();//�����Ʈ����� �������ڽ��� �����ڽ�
	pBL = pB->getpLc();//�����Ʈ����� �������ڽ��� �����ڽ��� �����ڽ�
	pBR = pB->getpRc();//�����Ʈ����� �������ڽ��� �����ڽ��� �������ڽ�
	pSubRoot = _rotate_LL(pC);//���ο� �������� �����ִ� �κ� ���ġ
	pCurSubRoot->setpRc(pSubRoot);//���ġ �Ѱ��� �������ڽ����� ����
	pNewSubRoot = _rotate_RR(pA);//�����������̹Ƿ� RR����
	
	pNewSubRoot->setpPr(pCurParent);//�θ���� ���޹��� �μ��� �θ���� ����
	pA->setpPr(pNewSubRoot);//���ο� ��Ʈ��带 �θ���� ����
	pC->setpPr(pNewSubRoot);//���ο� ��Ʈ��带 �θ���� ����

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
		height_Lc = _getHeight(pTN->getpLc());//���� ���̰��
		height_Rc = _getHeight(pTN->getpRc());//������ ���̰��

		if (height_Lc > height_Rc)//������ �� �������
		{
			height = 1 + height_Lc;//��ü ���̴� ���ʳ���+1
		}
		else//�������� �� �������
			height = 1 + height_Rc;//��ü ���̴� �����ʳ���+1
	}
	return height;//���� ��ȯ
}

template<typename K, typename V>
int T_BST<K, V>::_getHeightDiff(T_BSTN<K, V>* pTN)
{
	int heightDiff = 0;

	if (pTN == NULL)
		return 0;

	heightDiff = _getHeight(pTN->getpLc()) - _getHeight(pTN->getpRc());//���ʳ���-������ ����

	return heightDiff;
}

template<typename K, typename V>
T_BSTN<K, V>* T_BST<K, V>::_reBalance(T_BSTN<K, V>** ppTN)
{
	int heightDiff = 0;

	heightDiff = _getHeightDiff(*ppTN);
	if (heightDiff > 1)//���� ����Ʈ���� �� ���̰� ����
	{
		if (_getHeightDiff((*ppTN)->getpLc()) > 0)//�ڽ��� ������ ���
			*ppTN = _rotate_LL(*ppTN);//�������� �ذ�
		else
			*ppTN = _rotate_LR(*ppTN);//�������� ���� �����������ذ�
	}
	else if (heightDiff < -1)//������ ����Ʈ�� ���̰� �� ����
	{
		if (_getHeightDiff((*ppTN)->getpRc()) < 0)
			*ppTN = _rotate_RR(*ppTN);//�����������ذ�
		else
			*ppTN = _rotate_RL(*ppTN);//���������� ���� ���������ذ�
	}

	return *ppTN;
}




template<typename K, typename V>
T_BSTN<K, V>* T_BST<K, V>::_insertAndRebalance(T_BSTN<K, V>** ppTN, T_BSTN<K, V>* pPr, T_Entry<K, V> entry)
{
	T_BSTN<K, V>* pTN, ** ppLc, ** ppRc;

	if (*ppTN == NULL)//NULL�����Ͷ��
	{
		pTN = new T_BSTN<K, V>(entry);//���ο� ��� ����
		*ppTN = pTN;
		if (pPr != NULL)//��Ʈ��尡 �ƴ϶��
			pTN->setpPr(pPr);//�θ��带 pPr�� ����
		(*ppTN)->setpLc(NULL);//���λ����� �ڽĳ��� NULL
		(*ppTN)->setpRc(NULL);

		num_entry++;//���� �߰�

		return *ppTN;//����߰��� �ּ�
	}
	T_Entry<K, V> bstn_entry;
	bstn_entry = (*ppTN)->getEntry();
	//���Ұ��� ���� �����ϱ� ����
	if (entry < bstn_entry)//������ ���Ұ� �� �������
	{
		ppLc = (*ppTN)->getppLc();//���ʳ���ּҷ� ����
		pTN = _insertAndRebalance(ppLc, *ppTN, entry);//���Ե� �ּ�
		if (ppTN != NULL)
		{
			(*ppTN)->setpLc(pTN);//������ ���� �ڽ����� ����
			*ppTN = _reBalance(ppTN);//���ġ
		}
	}
	else//������ ���Ұ� �� ũ�ų� �������
	{
		ppRc = (*ppTN)->getppRc();//������ ����ּҷ� ����
		pTN = _insertAndRebalance(ppRc, *ppTN, entry);//���Ե� �ּ� 
		if (ppTN != NULL)
		{
			(*ppTN)->setpRc(pTN);//������ ������ �ڽ����� ����
			*ppTN = _reBalance(ppTN);//���ġ
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
