#include<iostream>
#include"HashMap.h"
#include"Entry.h"
#include"MyVoca.h"
using namespace std;


template <typename K, typename V>
HashMap<K, V>::HashMap(int capacity)//생성자
	:n(0), B(capacity)//용량설정(해쉬 테이블)
{

}
template <typename K, typename V>
typename HashMap<K, V>::Iterator HashMap<K, V>::begin()//첫번째 항목찾기
{
	if (empty())//비어있는경우
		return end();
	BItor bkt = B.begin();
	while (bkt->empty())//비어있지 않은 버킷찾기
		++bkt;
	return Iterator(B, bkt, bkt->begin());//비어있지 않은 버킷의 첫번째
}

template <typename K, typename V>
typename HashMap<K, V>::Iterator HashMap<K, V>::end()
{
	return Iterator(B, B.end());
}

template <typename K, typename V>
bool HashMap<K, V>::Iterator::operator==(const Iterator& p)const//같은지 판별
{
	if (ba != p.ba || bkt != p.bkt)//같지 않다면
		return false;
	else if (bkt == ba->end())//비어있는 경우
		return true;
	else
		return (ent == p.ent);//버킷배열과 버킷과 원소가 다 같은경우

}

template <typename K, typename V>
bool HashMap<K, V>::Iterator::operator!=(const Iterator& p)const
{
	if (ba != p.ba || bkt != p.bkt)//같지 않다면
		return true;
	else if (bkt == ba->end())//비어있는 경우
		return false;
	else
		return (ent != p.ent);//원소가 다른가

}

template <typename K, typename V>
typename HashMap<K, V>::Iterator& HashMap<K, V> ::Iterator::operator++()//다음 위치 가르키기
{
	++ent;//EItor 증가

	if (_endOfBkt(*this))//증가한 Iterator가 버킷의 마지막인지 판별
	{
		++bkt;//마지막이라면 다음 버킷으로
		while (bkt != ba->end() && bkt->empty())//버킷이 비어있다면 
		{
			++bkt;//다음 버킷으로 넘어감
		}
		if (bkt == ba->end())//버킷배열의 마지막이라면
			return *this;
		ent = bkt->begin();//비어있지 않은 버킷의 첫번째 원소
	}
	return *this;
}

template <typename K, typename V>
typename HashMap<K, V>::Iterator HashMap<K, V>::_find(const K& k)//찾기
{
	CyclicShiftHashCode hash;//해시코드
	int i = hash(k) % B.size();//해시코드 압축
	BItor bkt = B.begin() + i;//키 값을 가지는 버킷
	Iterator p(B, bkt, bkt->begin());//버킷의 첫번째를 가르킴
	while (!_endOfBkt(p) && (*p).getKey() != k)//버킷이 끝이아니고 찾는 키값이 아닌경우 
		++p.ent;//다음으로 넘어가면서 찾는동작
	return p;//찾은 위치 반환
}

template <typename K, typename V>
typename HashMap<K, V>::Iterator HashMap<K, V>::find(const K& k)
{
	Iterator p = _find(k);//찾기 실행
	if (_endOfBkt(p))//버킷의 끝이라면
		return end();//마지막 반환
	else
		return p;//정상적인 경우
}

template <typename K, typename V>
typename HashMap<K, V>::Iterator HashMap<K, V>::_insert(const Iterator& p, const Entry& e)
{
	EItor ins = p.bkt->insert(p.ent, e);//리스트에 삽입한 위치
	n++;//원소수 증가
	return Iterator(B, p.bkt, ins);
}

template <typename K, typename V>
typename HashMap<K, V>::Iterator HashMap<K, V>::insert(const K& k, const V& v)
{
	Iterator p = _find(k);//위치 찾기
	if (_endOfBkt(p))//버킷의 끝이라면
		return _insert(p, Entry(k, v));//마지막 부분에 추가
	else
	{
		p.ent->setValue(v);
		return p;
	}
}

template <typename K, typename V>
void HashMap<K, V>::_erase(const Iterator& p)
{
	p.bkt->erase(p.ent);//삭제
	n--;//원소 수 감소
}

template <typename K, typename V>
void HashMap<K, V>::erase(const Iterator& p)
{
	_erase(p);
}
template <typename K, typename V>
void HashMap<K, V>::erase(const K& k)
{
	Iterator p = _find(k);//키 위치 찾은 후
	if (_endOfBkt(p))
	{//throw NonexistentElement("Erase of nonexistent");
		cout << "Erase of nonexistent";
		exit;
	}
	_erase(p);//삭제
}
template <typename K, typename V>
void HashMap<K, V>::fprintBucket(ostream& fout, BItor bkt)//버킷 내부 출력
{

	Iterator p(B, bkt, bkt->begin());//버킷의 첫번째항목
	MyVoca* pVoca;
	while (p.ent != bkt->end())
	{
		pVoca = p.getValue();
		fout << *pVoca << endl;
		++p.ent;
	}
}
template <typename K, typename V>
void HashMap<K, V>::fprintBucketSizes(ostream& fout)//버킷 크기출력
{
	int bkt_size;
	int max_ent, min_ent, total;
	int num_bkts, max_bkt = 0;
	double avg = 0.0;
	max_ent = min_ent = B[0].size();//초기값 설정
	total = 0;

	num_bkts = B.size();//모든 버킷 탐색
	for (int bkt = 0; bkt < num_bkts; bkt++)
	{
		bkt_size = B[bkt].size();//버킷 사이즈 출력
		fout << "Bucket[" << setw(3) << bkt << "]:" << bkt_size << "entries" << endl;
		if (bkt_size > max_ent)//최대 크기 설정
		{
			max_ent = bkt_size;
			max_bkt = bkt;

		}
		if (bkt_size < min_ent)//최소 크기 설정
		{
			min_ent = bkt_size;
		}
		total += bkt_size;//전체 버킷 크기
	}
	avg = total / num_bkts;//평균 버킷크기

	fout.precision(2);
	fout << endl << "Max_ent(" << setw(2) << max_ent << "), min_ent(" << setw(2) << min_ent << "), avg(" << setw(5) << avg << ")" << endl;
	fout << "Bucket with maximum(" << max_ent << ") entries :" << endl;
	BItor bkt = B.begin() + max_bkt;

	fprintBucket(fout, bkt);
}