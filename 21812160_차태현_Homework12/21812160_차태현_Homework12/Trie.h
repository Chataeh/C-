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
	Trie(string name);//생성자
	int size() { return num_keys; }//크기 반환
	void insert(string keyStr, E value);//삽입
	void insertExternalTN(TrieNode<E>* pTN, string keyStr, E value);//External노드 삽입
	TrieNode<E>* find(string keyStr);//키워드 탐색
	void findPrefixMatch(string prefix, List_pVoca& predictVocas);//동일한 접두어 가진 단어출력
	void deleteKeyStr(string keyStr);//키워드를 가진노드 삭제
	void eraseTrie();//전체 삭제
	void fprintTrie(ostream& fout);//출력
protected:
	TrieNode<E>* _find(string keyStr, SearchMode sm = FULL_MATCH);//키워드위치에 노드 반환 서치모드에 따라서 
	void _traverse(TrieNode<E>* pTN, List_pVoca& list_keywords);//키워드 리스트에 담아줌
private:
	TrieNode<E>* _root;//루트노드
	int num_keys;//키의 수
	string trie_name;//이름
};

template<typename E>
Trie<E>::Trie(string name)
{
	trie_name = name;//이름설정
	_root = new TrieNode<E>(' ', NULL);//루트노드 생성
	_root->setKey(' ');//키 설정
	_root->setPrev(NULL);//이전 초기화
	_root->setNext(NULL);//다음 초기화
	_root->setParent(NULL);//부모 초기화
	_root->setChild(NULL);//자식 초기화
	num_keys = 0;
}


template<typename E>
void Trie<E>::insertExternalTN(TrieNode<E>* pTN, string keyStr, E value)
{
	TrieNode<E>* pTN_New = NULL;

	pTN_New = new TrieNode<E>('\0', value);//external노드 생성
	pTN->setChild(pTN_New);//pTN의 자식으로 설정
	(pTN->getChild())->setParent(pTN);//pTN_New 부모는 pTN
	pTN_New->setValue(value);//값 정의
}

template<typename E>
void Trie<E>::insert(string keyStr, E value)
{
	TrieNode<E>* pTN = NULL, * pTN_New = NULL;
	char* keyPtr = (char*)keyStr.c_str();//단어를 스펠링 하나하나로 관리

	if (keyStr == "")
		return;
	if (_find(keyStr, FULL_MATCH) != NULL)
	{
		cout << "The given key string (" << keyStr << ") is already existing; just return !!" << endl;//키워드가 이미 존재할 경우
		return;
	}

	pTN = this->_root;//루트노드로 설정

	while ((pTN != NULL) && (*keyPtr != '\0'))//pTN이 NULL이 아니고 삽입하려는 키가 존재할 경우
	{
		if ((pTN->getKey() < *keyPtr) && (pTN->getNext() == NULL) && (*keyPtr != '\0'))//삽입위치의 키값이 기존 키값보다 크고 바로 다음위치가 NULL일경우 
			break;//바로 다음에 삽입하면 되기때문에 브레이크
		while ((pTN->getKey() < *keyPtr) && (pTN->getNext() != NULL))//pTN 다음 위치에 노드가 이미 존재할 경우
		{
			pTN = pTN->getNext();//다음으로 넘어가서 다음이 NULL이 될때까지 실행
		}
		while ((pTN != NULL) && (pTN->getKey() == *keyPtr) && (*keyPtr != '\0'))//키가 동일한 경우
		{
			pTN = pTN->getChild();//자식노드로 이동
			keyPtr++;
		}
		if ((pTN->getKey() > *keyPtr) && (*keyPtr != '\0'))//pTN앞에 위치에 삽입하는 경우
			break;
	}

	//삽입할려는 키워드가 기존키워드에 포함되어있는경우
	if ((pTN->getKey() != '\0') && (*keyPtr == '\0'))//현재 노드의 키는 더 삽입키워드를 포함하면서 스펠링이 남아있고 삽입할려는 단어의 스펠링의 마지막인경우
	{
		//내가 삽입할려는문자를 포함하는 더 긴문자 존재
		pTN_New = new TrieNode<E>('\0', value);//노드 생성
		pTN_New->setParent(pTN->getParent());//기존노드의 부모를 부모노드로 설정
		(pTN->getParent())->setChild(pTN_New);//기존 부모노드의 자식노드를 새롭게 생성한 노드로설정
		pTN_New->setNext(pTN);//삽입할려는 키의 마지막노드의 다음으로 문자의 나머지값들을 설정
		pTN->setPrev(pTN_New);//이전노드로 설정해서 연결
		this->num_keys++;//키를 증가

		return;
	}
	else if ((pTN->getKey() < *keyPtr) && (pTN->getNext() == NULL) && (*keyPtr != '\0'))//바로 오른쪽에 삽입가능하여 단어가 존재
	{

		pTN_New = new TrieNode<E>(*keyPtr, VALUE_INTERNAL_NODE);//키워드를 갖는 노드생성
		pTN_New->setParent(pTN->getParent());//부모노드는 같음
		pTN_New->setPrev(pTN);//이전을 pTN
		pTN->setNext(pTN_New);//이후를 pTN_New 서로 연결
		pTN = pTN_New;//다음으로 이동
		keyPtr++;
		while (*keyPtr != '\0')//문자가 존재할경우
		{
			pTN_New = new TrieNode<E>(*keyPtr, VALUE_INTERNAL_NODE);//노드 생성
			pTN->setChild(pTN_New);//자식으로 설정
			(pTN->getChild())->setParent(pTN);//부모로 설정 서로 연결
			pTN = pTN->getChild();//아래위치로 내려감
			keyPtr++;
		}
		if (*keyPtr == '\0')//문자가 끝났음
		{
			insertExternalTN(pTN, keyStr, value);//마지막 노드 추가
			this->num_keys++;
			return;
		}
	}

	else if ((pTN->getKey() > *keyPtr) && (*keyPtr != '\0'))//pTN위치보다 앞에 삽입되는경우
	{

		pTN_New = new TrieNode<E>(*keyPtr, VALUE_INTERNAL_NODE);//노드 생성
		pTN_New->setNext(pTN);//pTN보다 이전으로 설정
		pTN_New->setParent(pTN->getParent());//부모노드는 같음
		if (pTN->getPrev() == NULL)//이전이 NULL이었다면 레벨에서 첫번째 노드임
		{
			if (pTN->getParent() != NULL)//부모가 있다면
				(pTN->getParent())->setChild(pTN_New);//부모 자식 연결
		}
		else
		{
			(pTN->getPrev())->setNext(pTN_New);//pTN의 이전노드의 다음으로 설정
		}
		pTN_New->setPrev(pTN->getPrev());//새로생성된 노드의 이전은 기존노드의 이전
		pTN->setPrev(pTN_New);//pTN이전은 새로 생성된 노드
		pTN = pTN_New;//이전으로 이동
		keyPtr++;//다음 글자처리를 위함
		while (*keyPtr != '\0')//문자가 있을경우
		{
			pTN_New = new TrieNode<E>(*keyPtr, VALUE_INTERNAL_NODE);//노드 생성
			pTN->setChild(pTN_New);//자식 설정
			(pTN->getChild())->setParent(pTN);//부모자식 연결
			pTN = pTN->getChild();//아래로 이동
			keyPtr++;//다음 문자처리를 위해
		}
		if (*keyPtr == '\0')//문자를 다처리했을경우
		{
			insertExternalTN(pTN, keyStr, value);//External노드 추가
			this->num_keys++;
			return;
		}
	}
}


template<typename E>
TrieNode<E>* Trie<E>::find(string keyStr)
{
	TrieNode<E>* pTN = NULL;//노드 생성
	pTN = _find(keyStr, FULL_MATCH);//키워드와 완전히 일치하는 노드
	return pTN;
}

template<typename E>
TrieNode<E>* Trie<E>::_find(string keyStr, SearchMode sm)
{
	const char* keyPtr = (char*)keyStr.c_str();
	TrieNode<E>* pTN = NULL;//노드 생성
	TrieNode<E>* found = NULL;//찾은 노드
	if (keyPtr == NULL)//찾을키가 없으면
		return NULL;

	pTN = this->_root;//루트노드로 설정
	while ((pTN != NULL) && (*keyPtr != '\0'))//노드가 존재하고 문자가 존재하면
	{
		while ((pTN != NULL) && (pTN->getKey() < *keyPtr))//찾을려는 문자의 키값이 더큰경우
		{
			if (pTN->getNext() == NULL)//다음이 NULL이면
				return NULL;//문자가 존재하지 않음
			pTN = pTN->getNext();//다음노드로 이동
		}
		if ((pTN != NULL) && (pTN->getKey() > *keyPtr))//찾을려는 문자의 키가 더큰경우(이미 다음으로 이동했기에)
		{
			return NULL;//찾지못함
		}
		else if ((pTN == NULL) && (*keyPtr != '\0'))//문자는 존재하나 이동할 노드가없음
		{
			return NULL;//찾지못함
		}
		else if ((pTN->getKey() == *keyPtr) && (*keyPtr != '\0'))//문자가 동일하며 문자가 남아있는경우
		{
			pTN = pTN->getChild();//아래로 설정
			keyPtr++;
			if (*keyPtr == '\0')//다 찾은경우
			{

				if (sm == FULL_MATCH)
				{
					if (pTN->getKey() == '\0')//키워드가 동일한 경우
					{
						return pTN;
					}
					else //키가 더 긴경우(풀 매치기 때문에)
					{
						return NULL;//찾지 못함
					}
				}
				else if (sm == PREFIX_MATCH)//접두어 일치
				{
					return pTN;
				}
			}
			else if ((pTN->getKey() == '\0') && (*keyPtr != '\0'))//키가 남은경우
			{
				if (pTN->getNext() != NULL)
				{
					pTN = pTN->getNext();//다음위치에서 찾을 수 있다면 찾음
					continue;
				}
				else
					return NULL;//찾을 수 없음
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
	if (pTN->getChild() == NULL)//마지막 노드일경우
	{
		list_keywords.push_back(pTN->getValue());//value 받아옴
	}
	else
	{
		_traverse(pTN->getChild(), list_keywords);//아래로 계속내려감
	}
	if (pTN->getNext() != NULL)//다음이 존재한다면
	{
		_traverse(pTN->getNext(), list_keywords);//계속 다음으로 이동
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
	if (keyPtr == NULL)//문자가 없을경우
		return;
	pTN = this->_root;//루트노드로 설정
	pTN = _find(prefix, PREFIX_MATCH);//접두어 일치로 위치 찾음

	_traverse(pTN, predictWords);//단어들 리스트에 저장

}

template<typename E>
void Trie<E>::deleteKeyStr(string KeyStr)
{

	TrieNode<E>* pTN = NULL, * _root;
	TrieNode<E>* tmp = NULL;
	int trie_val;

	_root = this->_root;//루트노드 설정
	if (NULL == _root || "" == KeyStr)//대상이 없음
		return;

	pTN = _find(KeyStr, FULL_MATCH);//위치 찾기

	if (pTN == NULL)
	{
		cout << "Key [" << KeyStr << "] not found in trie" << endl;
		return;
	}

	while (true)
	{
		if (pTN == NULL)
			break;
		if (pTN->getPrev() && pTN->getNext())//삭제대상 노드 이전과 다음이 존재 중간노드삭제
		{
			tmp = pTN;
			//이전과 다음을 직접연결
			(pTN->getNext())->setPrev(pTN->getPrev());
			(pTN->getPrev())->setNext(pTN->getNext());
			free(tmp);//반환
			break;
		}
		else if (pTN->getPrev() && !(pTN->getNext()))//이전에 삭제대상 노드가 존재
		{
			tmp = pTN;
			(pTN->getPrev())->setNext(NULL);//이전노드의 다음을 NULL로설정
			free(tmp);//반환
			break;
		}
		else if (!(pTN->getPrev()) && pTN->getNext())//다음에 삭제대상노드가 존재
		{
			tmp = pTN;
			(pTN->getParent())->setChild(pTN->getNext());//부모자식관계를 바꿔줌 다음노드가 자식이되는 것
			pTN = pTN->getNext();//다음위치로 옮겨줌
			pTN->setPrev(NULL);//새로운 위치의 이전 즉 기존삭제대상노드 NULL로설정
			free(tmp);//반환
			break;
		}
		else
		{
			tmp = pTN;
			pTN = pTN->getParent();//부모노드로 이동
			if (pTN != NULL)
				pTN->setChild(NULL);//자식을 NULL로 설정
			free(tmp);//반환
			if ((pTN == _root) && (pTN->getNext() == NULL) && (pTN->getPrev() == NULL))//루트노드만 존재
			{
				cout << "Now, the trie is empty !!" << endl;
				break;
			}
		}
	}
	this->num_keys--;//키의 수를 줄여줌
}

template<typename E>
void Trie<E>::eraseTrie()
{
	TrieNode<E>* pTN;
	TrieNode<E>* pTN_to_be_deleted = NULL;
	if (this->_root == NULL)//삭제대상 없음
		return;
	pTN = this->_root;
	/* delete the last key word first */
	while (pTN != NULL)//삭제대상이 있을때 반복
	{
		while ((pTN != NULL) && (pTN->getNext()))//다음노드가 있을경우
			pTN = pTN->getNext();//다음위치의 끝으로이동
		while (pTN->getChild())//자식이 존재시
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