#ifndef TR_H
#define TR_H

#include"TrieNode.h"
#include"MyVoca.h"

typedef list<MyVoca*>List_pVoca;
typedef list<MyVoca*>::iterator List_pVoca_Iter;

enum SearchMode { FULL_MATCH, PREFIX_MATCH };

template <typename E>
class Trie
{
public:
	Trie(string name);//������
	int size() { return num_keys; }//ũ�� ��ȯ
	void insert(string keyStr, E value);//����
	void insertExternalTN(TrieNode<E>* pTN, string keyStr, E value);//External��� ����
	TrieNode<E>* find(string keyStr);//Ű���� Ž��
	void findPrefixMatch(string prefix, List_pVoca& predictVocas);//������ ���ξ� ���� �ܾ����
	void deleteKeyStr(string keyStr);//Ű���带 ������� ����
	void eraseTrie();//��ü ����
	void fprintTrie(ostream& fout);//���
protected:
	TrieNode<E>* _find(string keyStr, SearchMode sm = FULL_MATCH);//Ű������ġ�� ��� ��ȯ ��ġ��忡 ���� 
	void _traverse(TrieNode<E>* pTN, List_pVoca& list_keywords);//Ű���� ����Ʈ�� �����
private:
	TrieNode<E>* _root;//��Ʈ���
	int num_keys;//Ű�� ��
	string trie_name;//�̸�
};

template<typename E>
Trie<E>::Trie(string name)
{
	trie_name = name;//�̸�����
	_root = new TrieNode<E>(' ', NULL);//��Ʈ��� ����
	_root->setKey(' ');//Ű ����
	_root->setPrev(NULL);//���� �ʱ�ȭ
	_root->setNext(NULL);//���� �ʱ�ȭ
	_root->setParent(NULL);//�θ� �ʱ�ȭ
	_root->setChild(NULL);//�ڽ� �ʱ�ȭ
	num_keys = 0;
}


template<typename E>
void Trie<E>::insertExternalTN(TrieNode<E>* pTN, string keyStr, E value)
{
	TrieNode<E>* pTN_New = NULL;

	pTN_New = new TrieNode<E>('\0', value);//external��� ����
	pTN->setChild(pTN_New);//pTN�� �ڽ����� ����
	(pTN->getChild())->setParent(pTN);//pTN_New �θ�� pTN
	pTN_New->setValue(value);//�� ����
}

template<typename E>
void Trie<E>::insert(string keyStr, E value)
{
	TrieNode<E>* pTN = NULL, * pTN_New = NULL;
	char* keyPtr = (char*)keyStr.c_str();//�ܾ ���縵 �ϳ��ϳ��� ����

	if (keyStr == "")
		return;
	if (_find(keyStr, FULL_MATCH) != NULL)
	{
		cout << "The given key string (" << keyStr << ") is already existing; just return !!" << endl;//Ű���尡 �̹� ������ ���
		return;
	}

	pTN = this->_root;//��Ʈ���� ����

	while ((pTN != NULL) && (*keyPtr != '\0'))//pTN�� NULL�� �ƴϰ� �����Ϸ��� Ű�� ������ ���
	{
		if ((pTN->getKey() < *keyPtr) && (pTN->getNext() == NULL) && (*keyPtr != '\0'))//������ġ�� Ű���� ���� Ű������ ũ�� �ٷ� ������ġ�� NULL�ϰ�� 
			break;//�ٷ� ������ �����ϸ� �Ǳ⶧���� �극��ũ
		while ((pTN->getKey() < *keyPtr) && (pTN->getNext() != NULL))//pTN ���� ��ġ�� ��尡 �̹� ������ ���
		{
			pTN = pTN->getNext();//�������� �Ѿ�� ������ NULL�� �ɶ����� ����
		}
		while ((pTN != NULL) && (pTN->getKey() == *keyPtr) && (*keyPtr != '\0'))//Ű�� ������ ���
		{
			pTN = pTN->getChild();//�ڽĳ��� �̵�
			keyPtr++;
		}
		if ((pTN->getKey() > *keyPtr) && (*keyPtr != '\0'))//pTN�տ� ��ġ�� �����ϴ� ���
			break;
	}

	//�����ҷ��� Ű���尡 ����Ű���忡 ���ԵǾ��ִ°��
	if ((pTN->getKey() != '\0') && (*keyPtr == '\0'))//���� ����� Ű�� �� ����Ű���带 �����ϸ鼭 ���縵�� �����ְ� �����ҷ��� �ܾ��� ���縵�� �������ΰ��
	{
		//���� �����ҷ��¹��ڸ� �����ϴ� �� �乮�� ����
		pTN_New = new TrieNode<E>('\0', value);//��� ����
		pTN_New->setParent(pTN->getParent());//��������� �θ� �θ���� ����
		(pTN->getParent())->setChild(pTN_New);//���� �θ����� �ڽĳ�带 ���Ӱ� ������ ���μ���
		pTN_New->setNext(pTN);//�����ҷ��� Ű�� ����������� �������� ������ ������������ ����
		pTN->setPrev(pTN_New);//�������� �����ؼ� ����
		this->num_keys++;//Ű�� ����

		return;
	}
	else if ((pTN->getKey() < *keyPtr) && (pTN->getNext() == NULL) && (*keyPtr != '\0'))//�ٷ� �����ʿ� ���԰����Ͽ� �ܾ ����
	{

		pTN_New = new TrieNode<E>(*keyPtr, VALUE_INTERNAL_NODE);//Ű���带 ���� ������
		pTN_New->setParent(pTN->getParent());//�θ���� ����
		pTN_New->setPrev(pTN);//������ pTN
		pTN->setNext(pTN_New);//���ĸ� pTN_New ���� ����
		pTN = pTN_New;//�������� �̵�
		keyPtr++;
		while (*keyPtr != '\0')//���ڰ� �����Ұ��
		{
			pTN_New = new TrieNode<E>(*keyPtr, VALUE_INTERNAL_NODE);//��� ����
			pTN->setChild(pTN_New);//�ڽ����� ����
			(pTN->getChild())->setParent(pTN);//�θ�� ���� ���� ����
			pTN = pTN->getChild();//�Ʒ���ġ�� ������
			keyPtr++;
		}
		if (*keyPtr == '\0')//���ڰ� ������
		{
			insertExternalTN(pTN, keyStr, value);//������ ��� �߰�
			this->num_keys++;
			return;
		}
	}

	else if ((pTN->getKey() > *keyPtr) && (*keyPtr != '\0'))//pTN��ġ���� �տ� ���ԵǴ°��
	{

		pTN_New = new TrieNode<E>(*keyPtr, VALUE_INTERNAL_NODE);//��� ����
		pTN_New->setNext(pTN);//pTN���� �������� ����
		pTN_New->setParent(pTN->getParent());//�θ���� ����
		if (pTN->getPrev() == NULL)//������ NULL�̾��ٸ� �������� ù��° �����
		{
			if (pTN->getParent() != NULL)//�θ� �ִٸ�
				(pTN->getParent())->setChild(pTN_New);//�θ� �ڽ� ����
		}
		else
		{
			(pTN->getPrev())->setNext(pTN_New);//pTN�� ��������� �������� ����
		}
		pTN_New->setPrev(pTN->getPrev());//���λ����� ����� ������ ��������� ����
		pTN->setPrev(pTN_New);//pTN������ ���� ������ ���
		pTN = pTN_New;//�������� �̵�
		keyPtr++;//���� ����ó���� ����
		while (*keyPtr != '\0')//���ڰ� �������
		{
			pTN_New = new TrieNode<E>(*keyPtr, VALUE_INTERNAL_NODE);//��� ����
			pTN->setChild(pTN_New);//�ڽ� ����
			(pTN->getChild())->setParent(pTN);//�θ��ڽ� ����
			pTN = pTN->getChild();//�Ʒ��� �̵�
			keyPtr++;//���� ����ó���� ����
		}
		if (*keyPtr == '\0')//���ڸ� ��ó���������
		{
			insertExternalTN(pTN, keyStr, value);//External��� �߰�
			this->num_keys++;
			return;
		}
	}
}


template<typename E>
TrieNode<E>* Trie<E>::find(string keyStr)
{
	TrieNode<E>* pTN = NULL;//��� ����
	pTN = _find(keyStr, FULL_MATCH);//Ű����� ������ ��ġ�ϴ� ���
	return pTN;
}

template<typename E>
TrieNode<E>* Trie<E>::_find(string keyStr, SearchMode sm)
{
	const char* keyPtr = (char*)keyStr.c_str();
	TrieNode<E>* pTN = NULL;//��� ����
	TrieNode<E>* found = NULL;//ã�� ���
	if (keyPtr == NULL)//ã��Ű�� ������
		return NULL;

	pTN = this->_root;//��Ʈ���� ����
	while ((pTN != NULL) && (*keyPtr != '\0'))//��尡 �����ϰ� ���ڰ� �����ϸ�
	{
		while ((pTN != NULL) && (pTN->getKey() < *keyPtr))//ã������ ������ Ű���� ��ū���
		{
			if (pTN->getNext() == NULL)//������ NULL�̸�
				return NULL;//���ڰ� �������� ����
			pTN = pTN->getNext();//�������� �̵�
		}
		if ((pTN != NULL) && (pTN->getKey() > *keyPtr))//ã������ ������ Ű�� ��ū���(�̹� �������� �̵��߱⿡)
		{
			return NULL;//ã������
		}
		else if ((pTN == NULL) && (*keyPtr != '\0'))//���ڴ� �����ϳ� �̵��� ��尡����
		{
			return NULL;//ã������
		}
		else if ((pTN->getKey() == *keyPtr) && (*keyPtr != '\0'))//���ڰ� �����ϸ� ���ڰ� �����ִ°��
		{
			pTN = pTN->getChild();//�Ʒ��� ����
			keyPtr++;
			if (*keyPtr == '\0')//�� ã�����
			{

				if (sm == FULL_MATCH)
				{
					if (pTN->getKey() == '\0')//Ű���尡 ������ ���
					{
						return pTN;
					}
					else //Ű�� �� ����(Ǯ ��ġ�� ������)
					{
						return NULL;//ã�� ����
					}
				}
				else if (sm == PREFIX_MATCH)//���ξ� ��ġ
				{
					return pTN;
				}
			}
			else if ((pTN->getKey() == '\0') && (*keyPtr != '\0'))//Ű�� �������
			{
				if (pTN->getNext() != NULL)
				{
					pTN = pTN->getNext();//������ġ���� ã�� �� �ִٸ� ã��
					continue;
				}
				else
					return NULL;//ã�� �� ����
			}
			else
			{
				continue;
			}
		}
	}
}

template<typename E>
void Trie<E>::_traverse(TrieNode<E>* pTN, List_pVoca& list_keywords)
{
	if (pTN == NULL)
		return;
	if (pTN->getChild() == NULL)//������ ����ϰ��
	{
		list_keywords.push_back(pTN->getValue());//value �޾ƿ�
	}
	else
	{
		_traverse(pTN->getChild(), list_keywords);//�Ʒ��� ��ӳ�����
	}
	if (pTN->getNext() != NULL)//������ �����Ѵٸ�
	{
		_traverse(pTN->getNext(), list_keywords);//��� �������� �̵�
	}
}

template<typename E>
void Trie<E>::findPrefixMatch(string prefix, List_pVoca& predictWords)
{
	TrieNode<E>* pPtr = NULL;
	const char* keyPtr = (char*)prefix.c_str();
	TrieNode<E>* pTN = NULL;
	TrieNode<E>* found = NULL;
	keyPtr;
	if (keyPtr == NULL)//���ڰ� �������
		return;
	pTN = this->_root;//��Ʈ���� ����
	pTN = _find(prefix, PREFIX_MATCH);//���ξ� ��ġ�� ��ġ ã��

	_traverse(pTN, predictWords);//�ܾ�� ����Ʈ�� ����

}

template<typename E>
void Trie<E>::deleteKeyStr(string KeyStr)
{

	TrieNode<E>* pTN = NULL, * _root;
	TrieNode<E>* tmp = NULL;
	int trie_val;

	_root = this->_root;//��Ʈ��� ����
	if (NULL == _root || "" == KeyStr)//����� ����
		return;

	pTN = _find(KeyStr, FULL_MATCH);//��ġ ã��

	if (pTN == NULL)
	{
		cout << "Key [" << KeyStr << "] not found in trie" << endl;
		return;
	}

	while (true)
	{
		if (pTN == NULL)
			break;
		if (pTN->getPrev() && pTN->getNext())//������� ��� ������ ������ ���� �߰�������
		{
			tmp = pTN;
			//������ ������ ��������
			(pTN->getNext())->setPrev(pTN->getPrev());
			(pTN->getPrev())->setNext(pTN->getNext());
			free(tmp);//��ȯ
			break;
		}
		else if (pTN->getPrev() && !(pTN->getNext()))//������ ������� ��尡 ����
		{
			tmp = pTN;
			(pTN->getPrev())->setNext(NULL);//��������� ������ NULL�μ���
			free(tmp);//��ȯ
			break;
		}
		else if (!(pTN->getPrev()) && pTN->getNext())//������ ��������尡 ����
		{
			tmp = pTN;
			(pTN->getParent())->setChild(pTN->getNext());//�θ��ڽİ��踦 �ٲ��� ������尡 �ڽ��̵Ǵ� ��
			pTN = pTN->getNext();//������ġ�� �Ű���
			pTN->setPrev(NULL);//���ο� ��ġ�� ���� �� ������������� NULL�μ���
			free(tmp);//��ȯ
			break;
		}
		else
		{
			tmp = pTN;
			pTN = pTN->getParent();//�θ���� �̵�
			if (pTN != NULL)
				pTN->setChild(NULL);//�ڽ��� NULL�� ����
			free(tmp);//��ȯ
			if ((pTN == _root) && (pTN->getNext() == NULL) && (pTN->getPrev() == NULL))//��Ʈ��常 ����
			{
				cout << "Now, the trie is empty !!" << endl;
				break;
			}
		}
	}
	this->num_keys--;//Ű�� ���� �ٿ���
}

template<typename E>
void Trie<E>::eraseTrie()
{
	TrieNode<E>* pTN;
	TrieNode<E>* pTN_to_be_deleted = NULL;
	if (this->_root == NULL)//������� ����
		return;
	pTN = this->_root;
	/* delete the last key word first */
	while (pTN != NULL)//��������� ������ �ݺ�
	{
		while ((pTN != NULL) && (pTN->getNext()))//������尡 �������
			pTN = pTN->getNext();//������ġ�� �������̵�
		while (pTN->getChild())//�ڽ��� �����
		{
			if (pTN->getNext())
				break;
			pTN = pTN->getChild();
		}
		if (pTN->getNext())
			continue;
		if (pTN->getPrev() && pTN->getNext())
		{
			pTN_to_be_deleted = pTN;
			(pTN->getNext())->setPrev(pTN->getPrev());
			(pTN->getPrev())->setNext(pTN->getNext());
			pTN = pTN->getNext();
			free(pTN_to_be_deleted);
		}
		else if (pTN->getPrev() && !(pTN->getNext()))
		{
			pTN_to_be_deleted = pTN;
			(pTN->getPrev())->setNext(NULL);
			pTN = pTN->getPrev();
			free(pTN_to_be_deleted);
		}
		else if (!(pTN->getPrev()) && pTN->getNext())
		{
			pTN_to_be_deleted = pTN;
			(pTN->getParent())->setChild(pTN->getNext());
			(pTN->getNext())->setPrev(NULL);
			pTN = pTN->getNext();
			free(pTN_to_be_deleted);
		}
		else
		{
			pTN_to_be_deleted = pTN;
			if (pTN == this->_root)
			{
				/* _root */
				this->num_keys = 0;
				return;
			}
			if (pTN->getParent() != NULL)
			{
				pTN = pTN->getParent();
				pTN->setChild(NULL);
			}
			else
			{
				pTN = pTN->getPrev();
			}
			free(pTN_to_be_deleted);
		} // end if - else
	} // end while
}

template<typename E>
void Trie<E>::fprintTrie(ostream& fout)
{
	TrieNode<E>* pTN;
	int line = 1, indent = 0;
	fout << "trie ( " << this->trie_name << ") with " << this->num_keys << " trie_nodes\n";
	if (this->num_keys == 0)
	{
		fout << "Empty trie !" << endl;
		return;
	}
	pTN = this->_root;
	pTN->_fprint(fout, pTN, indent);
}
#endif