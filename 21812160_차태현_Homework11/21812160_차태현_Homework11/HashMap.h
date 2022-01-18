#ifndef HM_H
#define HM_H

#include<list>
#include<vector>
#include"Entry.h"
#include"CyclicShiftHashCode.h"
#include"Generic_Skip_List.h"
//#include"Exceptions.h"

template<typename K, typename V>
class HashMap
{
public:
	typedef Entry<const K, V>Entry;//키와 밸류
	class Iterator;
protected:
	typedef std::list<Entry> Bucket;//버킷
	typedef std::vector<Bucket> BktArray;//버킷배열

	Iterator _find(const K& k);//찾기
	Iterator _insert(const Iterator& p, const Entry& e);//삽입
	void _erase(const Iterator& p);//삭제
	typedef typename BktArray::iterator BItor;//버킷배열 반복자(벡터)
	typedef typename Bucket::iterator EItor;//버킷 반복자(리스트)

	static void _next(Iterator& p)
	{
		++p.ent;
	}
	static bool _endOfBkt(const Iterator& p)
	{
		return p.ent == p.bkt->end();//마지막인지 확인
	}
public:
	HashMap(int capacity = 101);//생성자
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
		Entry& operator*() const { return *ent; }
		V getValue() { Entry& e = *ent; return e.getValue(); }
		bool operator==(const Iterator& p)const;//같은지 판별
		bool operator!=(const Iterator& p)const;//다른지 판별
		Iterator& operator++();//다음위치의 entry 가르킴
		Iterator& advanceEItor()
		{
			++ent;
			return *this;
		}
		friend class HashMap;
	};
};


#endif	
