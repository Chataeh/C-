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
	typedef Entry<const K, V>Entry;//Ű�� ���
	class Iterator;
protected:
	//typedef std::list<Entry> Bucket;//��Ŷ
	typedef::SkipList<K, V> Bucket;//��ŵ����Ʈ ��Ŷ
	typedef std::vector<Bucket> BktArray;//��Ŷ�迭

	Iterator _find(const K& k);//ã��
	Iterator _insert(const Iterator& p, const Entry& e);//����
	void _erase(const Iterator& p);//����
	typedef typename BktArray::iterator BItor;//��Ŷ�迭 �ݺ���(����)
	//typedef typename Bucket::iterator EItor;//��Ŷ �ݺ���(����Ʈ)
	typedef typename Bucket::Position EItor;//��Ŷ �ݺ���(��ŵ����Ʈ ������)

	static void _next(Iterator& p)
	{
		++p.ent;
	}
	static bool _endOfBkt(const Iterator& p)
	{
		return p.ent == p.bkt->last();//���������� Ȯ��
	}
public:
	HashMap(int capacity = HASH_TABLE_SIZE);//������
	int size() const { return n; }//���� �� ��ȯ
	bool empty() const { return (n == 0); }//����ִ��� �Ǻ�
	Iterator find(const K& k);//ã��
	Iterator insert(const K& k, const V& v);//����
	void erase(const K& k);//�����
	void erase(const Iterator& p);//�����
	Iterator begin();//ù��° ������ġ  
	Iterator end();//������ ���� ��ġ
	void fprintBucketSizes(ostream& fout); //��Ŷ ũ�� ���
	void fprintBucket(ostream& fout, BItor bkt);

private:
	int n;//entry�� ��
	BktArray B;//�ؽ� ���̺�

public:
	class Iterator {
	protected:
		const BktArray* ba;//��Ŷ �迭 
		BItor bkt;//��Ŷ 
		EItor ent;//��Ʈ�� 
	public:
		Iterator() {}//default ������
		Iterator(const BktArray& a, const BItor& b, const EItor& q = EItor())//������
			:ent(q), bkt(b), ba(&a) {}
		Entry& operator*() const
		{
			V  vo = *ent;
			K nKey = vo->MyVoca::getKeyWord();
			Entry vla(nKey, vo);

			return vla;
		}
		V getValue() { V& e = *ent; return e; }
		bool operator==(const Iterator& p)const;//������ �Ǻ�
		bool operator!=(const Iterator& p)const;//�ٸ��� �Ǻ�
		Iterator& operator++();//������ġ�� entry ����Ŵ
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
