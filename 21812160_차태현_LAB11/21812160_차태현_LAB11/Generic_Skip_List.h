#ifndef GSL_H
#define GSL_H


#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<time.h>
#include<limits>
#include<string>

#define PROBABILITY_OF_ABOVE_LEVEL 2
#define PLUS_INF INT_MAX
#define MINUS_INF INT_MIN

using namespace std;

template <typename Key, typename Element>
class SkipList
{
protected:
	//QuadNode
	class QuadNode
	{
	private:
		Key _key;//key
		Element _elem;//element
	protected:
		QuadNode* up;//����
		QuadNode* down;//�Ʒ���
		QuadNode* prev;//����
		QuadNode* next;//����
		int level;//��

	public:
		QuadNode(Key k = Key(), Element e = Element())//������
			:_key(k), _elem(e)
		{
			up = down = prev = next = NULL;//�ʱ� �� NULL
			level = -1;
		}
		Key& key() { return _key; }//Ű ��ȯ
		Element& element() { return _elem; }//element ��ȯ
		void setKey(Key& k) { _key = k; }//Ű ����
		void setElement(Element& e) { _elem = e; }//element ����
		friend class Position;
	};
public:
	//Position
	class Position
	{
	protected:
		QuadNode* pQN;
	public:
		Position(QuadNode* pSLN) { pQN = pSLN; }//������
		Position() {}//default ������
		Key& key() { return pQN->key(); }//����� Ű ��ȯ
		Element& element() { return pQN->element(); }//����� element ��ȯ
		Position below() { return Position(pQN->down); }//�Ʒ� �����ġ
		Position above() { return Position(pQN->up); }//�� ��� ��ġ
		Position after() { return Position(pQN->next); }//���� ��� ��ġ
		Position before() { return Position(pQN->prev); }//���� ��� ��ġ
		void setBelow(Position& p) { pQN->down = p.pQN; }//�Ʒ����� ����
		void setAbove(Position& p) { pQN->up = p.pQN; }//���ʳ��� ����
		void setAfter(Position& p) { pQN->next = p.pQN; }//�������� ����
		void setBefore(Position& p) { pQN->prev = p.pQN; }//�������� ����
		bool operator==(Position& q) { return pQN == q.pQN; }//��尡 ������ �Ǻ�
		bool operator!=(Position& q) { return pQN != q.pQN; }//��尡 �ٸ��� �Ǻ�
		Element& operator*() { return pQN->element(); }

		friend class SkipList;
	};
	//SkipList
private:
	Position start;//��ŵ����Ʈ�� ����
	Position end;//��ŵ����Ʈ�� ��
	int height;//������� ��ġ
	int num_elements;//��ü element ��
public:
	SkipList()//������
	{
		height = 0;//���� �ʱ�ȭ

		QuadNode* pQNode = new QuadNode(Key(MINUS_INF), Element());
		start = Position(pQNode);//���� ��ġ

		pQNode = new QuadNode(Key(PLUS_INF), Element());
		end = Position(pQNode);//������ ��ġ

		start.setAfter(end);//���� ������ �� ���� ����
		start.setBefore(Position(NULL));
		start.setAbove(Position(NULL));
		start.setBelow(Position(NULL));

		end.setBefore(start);//���� ������ ���� ���� ����
		end.setAfter(Position(NULL));
		end.setBelow(Position(NULL));
		end.setAbove(Position(NULL));

		srand(time(NULL));
	}

	Position SkipListSearch(Key& k)//k �� ã��
	{
		Position pos = start;//�ʱ� ��ġ
		while (pos.below() != Position(NULL))//�Ʒ��� NULL�� �ƴҶ�����
		{
			pos = pos.below();//�Ʒ��� �̵�
			while (k >= ((pos.after()).key()))//k���� ��ũ�ٸ�
			{
				pos = pos.after();//�������� �̵�
				if (pos.after() == Position(NULL))//�̵��� ��尡 NULL�ΰ�� �� ������ ��
					break;//break
			}
		}
		return pos;//ã�� ��ġ ��ȯ
	}

	Position SkipListInsert(ostream& fout, Key k, const Element e)//����
	{
		Position p, q, t;

		p = SkipListSearch(k);//���Ե� ��ġ 
		q = Position(NULL);//�ʱ� below ��ġ 
		int i = -1;

		do {
			i = i + 1;
			if (i >= height)//��ŵ����Ʈ�� ���� ���� ���ų� ũ�ٸ�
			{
				height = height + 1;//���� ����  (+���Ѵ� -���Ѵ� �ΰ��� �ִ� �� ���������)
				t = start.after();
				start = insertAfterAbove(fout, Position(NULL), start, MINUS_INF, Element());//���ο� start��� 
				insertAfterAbove(fout, start, t, PLUS_INF, Element());//���ο� end��� �ǿ�����
			}
			q = insertAfterAbove(fout, p, q, k, e);//level 0���� �׾Ƴ���
			while (p.above() == (Position)NULL)//p�� ���� ��ġ�� NULL�̸�
			{
				p = p.before();//p�� �������� �̵�
			}
			p = p.above();//NULL�� �ƴѰ��� ����

		} while (rand() % 2 == 0);//���� ������� ����

		++num_elements;//��ü element ����

		return q;//���ο� Ÿ���� �� ���� ��ȯ
	}

	void SkipListNodeDelete(Position p)//��� ����
	{
		Position pprev, pnext;

		if (p != Position(NULL))//��ġ�� �����Ѵٸ�
		{
			//p�� prev�� p�� next�� ����
			pprev = p.before();
			pnext = p.after();
			if (pprev != Position(NULL))
				pprev.setAfter(pnext);
			if (pnext != Position(NULL))
				pnext.setBefore(pprev);

			delete p.pQN;//������
		}
	}

	void SkipListRemove(ostream& fout, Key k)//k�� ���� Ÿ������
	{
		Position p, pprev, pnext, p00, px0;
		Position p0y, pxy, old_p;
		int h_max, h;

		p = SkipListSearch(k);//k��ġ Ž��
		if ((p.key() != k) || (p.key() == MINUS_INF))//k���� ���ٸ�
		{
			fout << "Key (" << k << ") is not found" << "in SkipList!!" << endl;

			return;
		}
		//k��ġ�� ���� �ϴ°��
		while (p != Position(NULL))//key Ÿ�� ��ü ����
		{
			old_p = p;
			p = p.above();//p�� ������ ���ο�p�� ����
			SkipListNodeDelete(old_p);//���� p��ġ ����
		}
		fout << "deleted skip list node (Key:" << k << ")" << endl;

		//-���Ѵ� +���Ѵ� ���� �ϳ��� ����� ���Ͽ�
		p00 = start;
		for (int i = height; i > 0; i--)
		{
			p00 = p00.below();//�� �Ʒ���ġ
		}

		px0 = p00.after();
		pxy = start;
		h_max = 0;

		while (px0.key() != PLUS_INF)//���Ѵ�ܿ� �ٸ� ������ ����
		{
			pxy = px0;
			h = 0;
			while (pxy != Position(NULL))
			{
				++h;//Ÿ�� ���� ã�Ƴ�
				pxy = pxy.above();
			}
			if (h_max < h)
				h_max = h;//�ִ� Ÿ������ 
			px0 = px0.after();
		}
		if (h_max < height)//�ִ� Ÿ�����̰� ���� ���� ���̺��� �������
		{
			fout << "Current height is less than the new h_max (" << h_max << ") ==> need adjustment!!" << endl;
		}

		for (int i = 0; i < (height - h_max); i++)
		{
			//-���Ѵ� +���Ѵ� ���� �ϳ��� ��������� ����
			p0y = start;
			pxy = start.after();
			start = start.below();
			SkipListNodeDelete(pxy);
			SkipListNodeDelete(p0y);
		}
		height = h_max;//���̴� ������ ���� ������� Ÿ���� ����
	}

	void PrintSkipList(ostream& fout)//��ŵ����Ʈ ���
	{
		Position p, p00, px0, p0y, pxy, q, q0, qx;
		int level;

		fout << "Print Skip List Inside: current height(" << height << ")" << endl;

		p00 = start;
		level = height;
		for (int i = height; i > 0; i--)
		{
			p00 = p00.below();//level 0�� �ǿ�����ġ
		}

		p0y = start;
		pxy = start;
		for (level = height; level >= 0; level--)
		{
			fout << "level" << setw(2) << level << " ";
			if (pxy.key() == MINUS_INF)//���̳ʽ� ���Ѵ� ���
				fout << "-oo";
			else
				fout << setw(5) << pxy.key();

			px0 = p00.after;//level 0�� �����͸� �����ϴ� ù��° ��ġ
			for (pxy = p0y.after();; pxy = pxy.after())
			{
				while ((px0.key() != pxy.key()))//��ŵ�� ���
				{
					fout << "------";
					px0 = px0.after();//������ġ�� �̵�
				}
				if (pxy.key() == PLUS_INF)//�ǿ����� ��ġ�ΰ��
					break;
				else
				{
					fout << "-" << setw(5) << pxy.key();
				}
				px0 = px0.after();//������ġ�� �̵�
			}
			if (pxy.key() == PLUS_INF)//�ǿ����� �ΰ��
				fout << "\ +oo";//���Ѵ� ���
			else
				fout << setw(5) << pxy.key();
			fout << endl;
			p0y = p0y.below();//�Ʒ���ġ�� �̵�
			pxy = p0y;
		}
		fout << endl;
	}

	Position insertAfterAbove(ostream& fout, Position p, Position q, const Key k, const Element e)//p����q���� ����
	{
		QuadNode* pNewNode = new QuadNode(k, e);
		Position n(pNewNode); //���ο� ��� ����
		//�ʱ⿡ NULL�� ����
		n.setAbove(Position(NULL));
		n.setBelow(Position(NULL));
		n.setBefore(Position(NULL));
		n.setAfter(Position(NULL));

		if (p == Position(NULL))
		{
			if (q == Position(NULL))
			{
				fout << "Trying to insert at (NULL,NULL) position" << endl;;
				return Position(NULL);
			}
			else//q���� �ְ� p�� NULL�ΰ��
			{
				q.setAbove(n);//q���� n����
				n.setBelow(q);//n�Ʒ��� q�� �����ؼ� ����
				n.setAbove(Position(NULL));
				n.setAfter(Position(NULL));

				return n;
			}
		}
		else
		{
			if (q == Position(NULL))//p���� �ְ� q�� NULL�ΰ��
			{
				//level 0�� ���ο� ���߰�
				Position nx, ny;
				fout << "insert a node(" << n.key() << ") at level 0" << endl;
				nx = p.after();//���� p�� ���� nx
				p.setAfter(n);//p������ n
				n.setBefore(p);//n������ p ���ο���
				n.setAfter(nx);//n���Ĵ� ������ p�� �����̴� nx
				nx.setBefor(n);//nx�� ���� n
				n.setBleow(Position(NULL));
				n.setAbove(Position(NULL));
				return n;
			}
			else//p��q ��� ���� NULL�� �ƴѰ��
			{
				Position nx, ny;
				nx = p.after();//p�� ���� nx
				n.setAfter(nx);//n�� p�� nx���̿� �����̹Ƿ� n������ nx�� �缳��
				if (nx != Position(NULL))//nx���� �ִٸ�
					nx.setBefore(n);//nx������ n���� ����
				p.setAfter(n);//p������ n
				n.setBefore(p);//n�� ������ p�� ����
				ny = q.above();//q�� ���� ny
				q.setAbove(n);//n��q�� ny�� ���̿� �����̹Ƿ� q�� ���� n���� �缳��
				n.setBelow(q);//n�� �Ʒ��� q��  ����
				n.setAbove(ny);//n�� ���� ny
				if (ny != Position(NULL))//ny���� �ִٸ�
					ny.setBelow(n);//ny�� �Ʒ��� n���� ����
			}
		}
		return n;
	}
};

#endif