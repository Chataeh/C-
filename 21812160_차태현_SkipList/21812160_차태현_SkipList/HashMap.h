#ifndef HM_H
#define HM_H

#include<list>
#include<vector>
#include"Entry.h"
#include"CyclicShiftHashCode.h"
#include"Generic_Skip_List.h"
//#include"Exceptions.h"
#define HASH_TABLE_SIZE 2

template<typename K, typename V>
class HashMap
{
public:
	typedef Entry<const K, V>Entry;//키와 밸류
	class Iterator;
protected:
	//typedef std::list<Entry> Bucket;//버킷
	typedef::SkipList<K, V> Bucket;//스킵리스트 버킷
	typedef std::vector<Bucket> BktArray;//버킷배열

	Iterator _find(const K& k);//찾기
	Iterator _insert(const Iterator& p, const Entry& e);//삽입
	void _erase(const Iterator& p);//삭제
	typedef typename BktArray::iterator BItor;//버킷배열 반복자(벡터)
	//typedef typename Bucket::iterator EItor;//버킷 반복자(리스트)
	typedef typename Bucket::Position EItor;//버킷 반복자(스킵리스트 포지션)

	static void _next(Iterator& p)
	{
		++p.ent;
	}
	static bool _endOfBkt(const Iterator& p)
	{
		return p.ent == p.bkt->last();//마지막인지 확인
	}
public:
	HashMap(int capacity = HASH_TABLE_SIZE);//생성자
	int size() const { return n; }//원소 수 반환
	bool empty() const { return (n == 0); }//비어있는지 판별
	Iterator find(const K& k);//찾기
	Iterator insert(const K& k, const V& v);//삽입
	void erase(const K& k);//지우기
	void erase(const Iterator& p);//지우기
	Iterator begin();//첫번째 원소위치  
	Iterator end();//마지막 다음 위치
	void fprintBucketSizes(ostream& fout); //버킷 크기 출력
	void fprintBucket(ostream& fout, BItor bkt);

private:
	int n;//entry의 수
	BktArray B;//해쉬 테이블

public:
	class Iterator {
	protected:
		const BktArray* ba;//버킷 배열 
		BItor bkt;//버킷 
		EItor ent;//엔트리 
	public:
		Iterator() {}//default 생성자
		Iterator(const BktArray& a, const BItor& b, const EItor& q = EItor())//생성자
			:ent(q), bkt(b), ba(&a) {}
		Entry& operator*() const
		{
			V  vo = *ent;
			K nKey = vo->MyVoca::getKeyWord();
			Entry vla(nKey, vo);

			return vla;
		}
		V getValue() { V& e = *ent; return e; }
		bool operator==(const Iterator& p)const;//같은지 판별
		bool operator!=(const Iterator& p)const;//다른지 판별
		Iterator& operator++();//다음위치의 entry 가르킴
		BItor& getBKT() { return bkt; }
		EItor& getEnt() { return ent; }
		Iterator& advanceEItor()
		{
			++ent;
			return *this;
		}
		friend class HashMap;
	};
};


#endif	
