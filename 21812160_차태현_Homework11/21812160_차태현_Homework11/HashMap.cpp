#include<iostream>
#include"HashMap.h"
#include"Entry.h"
#include"MyVoca.h"
using namespace std;


template <typename K, typename V>
HashMap<K, V>::HashMap(int capacity)//������
	:n(0), B(capacity)//�뷮����(�ؽ� ���̺�)
{

}
template <typename K, typename V>
typename HashMap<K, V>::Iterator HashMap<K, V>::begin()//ù��° �׸�ã��
{
	if (empty())//����ִ°��
		return end();
	BItor bkt = B.begin();
	while (bkt->empty())//������� ���� ��Ŷã��
		++bkt;
	return Iterator(B, bkt, bkt->begin());//������� ���� ��Ŷ�� ù��°
}

template <typename K, typename V>
typename HashMap<K, V>::Iterator HashMap<K, V>::end()
{
	return Iterator(B, B.end());
}

template <typename K, typename V>
bool HashMap<K, V>::Iterator::operator==(const Iterator& p)const//������ �Ǻ�
{
	if (ba != p.ba || bkt != p.bkt)//���� �ʴٸ�
		return false;
	else if (bkt == ba->end())//����ִ� ���
		return true;
	else
		return (ent == p.ent);//��Ŷ�迭�� ��Ŷ�� ���Ұ� �� �������

}

template <typename K, typename V>
bool HashMap<K, V>::Iterator::operator!=(const Iterator& p)const
{
	if (ba != p.ba || bkt != p.bkt)//���� �ʴٸ�
		return true;
	else if (bkt == ba->end())//����ִ� ���
		return false;
	else
		return (ent != p.ent);//���Ұ� �ٸ���

}

template <typename K, typename V>
typename HashMap<K, V>::Iterator& HashMap<K, V> ::Iterator::operator++()//���� ��ġ ����Ű��
{
	++ent;//EItor ����

	if (_endOfBkt(*this))//������ Iterator�� ��Ŷ�� ���������� �Ǻ�
	{
		++bkt;//�������̶�� ���� ��Ŷ����
		while (bkt != ba->end() && bkt->empty())//��Ŷ�� ����ִٸ� 
		{
			++bkt;//���� ��Ŷ���� �Ѿ
		}
		if (bkt == ba->end())//��Ŷ�迭�� �������̶��
			return *this;
		ent = bkt->begin();//������� ���� ��Ŷ�� ù��° ����
	}
	return *this;
}

template <typename K, typename V>
typename HashMap<K, V>::Iterator HashMap<K, V>::_find(const K& k)//ã��
{
	CyclicShiftHashCode hash;//�ؽ��ڵ�
	int i = hash(k) % B.size();//�ؽ��ڵ� ����
	BItor bkt = B.begin() + i;//Ű ���� ������ ��Ŷ
	Iterator p(B, bkt, bkt->begin());//��Ŷ�� ù��°�� ����Ŵ
	while (!_endOfBkt(p) && (*p).getKey() != k)//��Ŷ�� ���̾ƴϰ� ã�� Ű���� �ƴѰ�� 
		++p.ent;//�������� �Ѿ�鼭 ã�µ���
	return p;//ã�� ��ġ ��ȯ
}

template <typename K, typename V>
typename HashMap<K, V>::Iterator HashMap<K, V>::find(const K& k)
{
	Iterator p = _find(k);//ã�� ����
	if (_endOfBkt(p))//��Ŷ�� ���̶��
		return end();//������ ��ȯ
	else
		return p;//�������� ���
}

template <typename K, typename V>
typename HashMap<K, V>::Iterator HashMap<K, V>::_insert(const Iterator& p, const Entry& e)
{
	EItor ins = p.bkt->insert(p.ent, e);//����Ʈ�� ������ ��ġ
	n++;//���Ҽ� ����
	return Iterator(B, p.bkt, ins);
}

template <typename K, typename V>
typename HashMap<K, V>::Iterator HashMap<K, V>::insert(const K& k, const V& v)
{
	Iterator p = _find(k);//��ġ ã��
	if (_endOfBkt(p))//��Ŷ�� ���̶��
		return _insert(p, Entry(k, v));//������ �κп� �߰�
	else
	{
		p.ent->setValue(v);
		return p;
	}
}

template <typename K, typename V>
void HashMap<K, V>::_erase(const Iterator& p)
{
	p.bkt->erase(p.ent);//����
	n--;//���� �� ����
}

template <typename K, typename V>
void HashMap<K, V>::erase(const Iterator& p)
{
	_erase(p);
}
template <typename K, typename V>
void HashMap<K, V>::erase(const K& k)
{
	Iterator p = _find(k);//Ű ��ġ ã�� ��
	if (_endOfBkt(p))
	{//throw NonexistentElement("Erase of nonexistent");
		cout << "Erase of nonexistent";
		exit;
	}
	_erase(p);//����
}
template <typename K, typename V>
void HashMap<K, V>::fprintBucket(ostream& fout, BItor bkt)//��Ŷ ���� ���
{

	Iterator p(B, bkt, bkt->begin());//��Ŷ�� ù��°�׸�
	MyVoca* pVoca;
	while (p.ent != bkt->end())
	{
		pVoca = p.getValue();
		fout << *pVoca << endl;
		++p.ent;
	}
}
template <typename K, typename V>
void HashMap<K, V>::fprintBucketSizes(ostream& fout)//��Ŷ ũ�����
{
	int bkt_size;
	int max_ent, min_ent, total;
	int num_bkts, max_bkt = 0;
	double avg = 0.0;
	max_ent = min_ent = B[0].size();//�ʱⰪ ����
	total = 0;

	num_bkts = B.size();//��� ��Ŷ Ž��
	for (int bkt = 0; bkt < num_bkts; bkt++)
	{
		bkt_size = B[bkt].size();//��Ŷ ������ ���
		fout << "Bucket[" << setw(3) << bkt << "]:" << bkt_size << "entries" << endl;
		if (bkt_size > max_ent)//�ִ� ũ�� ����
		{
			max_ent = bkt_size;
			max_bkt = bkt;

		}
		if (bkt_size < min_ent)//�ּ� ũ�� ����
		{
			min_ent = bkt_size;
		}
		total += bkt_size;//��ü ��Ŷ ũ��
	}
	avg = total / num_bkts;//��� ��Ŷũ��

	fout.precision(2);
	fout << endl << "Max_ent(" << setw(2) << max_ent << "), min_ent(" << setw(2) << min_ent << "), avg(" << setw(5) << avg << ")" << endl;
	fout << "Bucket with maximum(" << max_ent << ") entries :" << endl;
	BItor bkt = B.begin() + max_bkt;

	fprintBucket(fout, bkt);
}