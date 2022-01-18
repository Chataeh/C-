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
		QuadNode* up;//위쪽
		QuadNode* down;//아래쪽
		QuadNode* prev;//이전
		QuadNode* next;//다음
		int level;//층

	public:
		QuadNode(Key k = Key(), Element e = Element())//생성자
			:_key(k), _elem(e)
		{
			up = down = prev = next = NULL;//초기 값 NULL
			level = -1;
		}
		Key& key() { return _key; }//키 반환
		Element& element() { return _elem; }//element 반환
		void setKey(Key& k) { _key = k; }//키 설정
		void setElement(Element& e) { _elem = e; }//element 설정
		friend class Position;
	};
public:
	//Position
	class Position
	{
	protected:
		QuadNode* pQN;
	public:
		Position(QuadNode* pSLN) { pQN = pSLN; }//생성자
		Position() {}//default 생성자
		Key& key() { return pQN->key(); }//노드의 키 반환
		Element& element() { return pQN->element(); }//노드의 element 반환
		Position below() { return Position(pQN->down); }//아래 노드위치
		Position above() { return Position(pQN->up); }//위 노드 위치
		Position after() { return Position(pQN->next); }//다음 노드 위치
		Position before() { return Position(pQN->prev); }//이전 노드 위치
		void setBelow(Position& p) { pQN->down = p.pQN; }//아래노드로 설정
		void setAbove(Position& p) { pQN->up = p.pQN; }//위쪽노드로 설정
		void setAfter(Position& p) { pQN->next = p.pQN; }//다음노드로 설정
		void setBefore(Position& p) { pQN->prev = p.pQN; }//이전노드로 설정
		bool operator==(Position& q) { return pQN == q.pQN; }//노드가 같은지 판별
		bool operator!=(Position& q) { return pQN != q.pQN; }//노드가 다른지 판별
		Element& operator*() { return pQN->element(); }

		friend class SkipList;
	};
	//SkipList
private:
	Position start;//스킵리스트의 시작
	Position end;//스킵리스트의 끝
	int height;//가장높은 위치
	int num_elements;//전체 element 수
public:
	SkipList()//생성자
	{
		height = 0;//높이 초기화

		QuadNode* pQNode = new QuadNode(Key(MINUS_INF), Element());
		start = Position(pQNode);//시작 위치

		pQNode = new QuadNode(Key(PLUS_INF), Element());
		end = Position(pQNode);//마지막 위치

		start.setAfter(end);//시작 다음은 끝 서로 연결
		start.setBefore(Position(NULL));
		start.setAbove(Position(NULL));
		start.setBelow(Position(NULL));

		end.setBefore(start);//끝의 이전은 시작 서로 연결
		end.setAfter(Position(NULL));
		end.setBelow(Position(NULL));
		end.setAbove(Position(NULL));

		srand(time(NULL));
	}

	Position SkipListSearch(Key& k)//k 값 찾기
	{
		Position pos = start;//초기 위치
		while (pos.below() != Position(NULL))//아래가 NULL이 아닐때까지
		{
			pos = pos.below();//아래로 이동
			while (k >= ((pos.after()).key()))//k값이 더크다면
			{
				pos = pos.after();//다음으로 이동
				if (pos.after() == Position(NULL))//이동한 노드가 NULL인경우 즉 오른쪽 끝
					break;//break
			}
		}
		return pos;//찾은 위치 반환
	}

	Position SkipListInsert(ostream& fout, Key k, const Element e)//삽입
	{
		Position p, q, t;

		p = SkipListSearch(k);//삽입될 위치 
		q = Position(NULL);//초기 below 위치 
		int i = -1;

		do {
			i = i + 1;
			if (i >= height)//스킵리스트의 높이 보다 같거나 크다면
			{
				height = height + 1;//높이 증가  (+무한대 -무한대 두개만 있는 층 만들기위해)
				t = start.after();
				start = insertAfterAbove(fout, Position(NULL), start, MINUS_INF, Element());//새로운 start노드 
				insertAfterAbove(fout, start, t, PLUS_INF, Element());//새로운 end노드 맨오른쪽
			}
			q = insertAfterAbove(fout, p, q, k, e);//level 0부터 쌓아나감
			while (p.above() == (Position)NULL)//p의 위쪽 위치가 NULL이면
			{
				p = p.before();//p의 이전으로 이동
			}
			p = p.above();//NULL이 아닌경우와 연결

		} while (rand() % 2 == 0);//동전 던지기와 같이

		++num_elements;//전체 element 증가

		return q;//새로운 타워의 맨 위층 반환
	}

	void SkipListNodeDelete(Position p)//노드 삭제
	{
		Position pprev, pnext;

		if (p != Position(NULL))//위치가 존재한다면
		{
			//p의 prev와 p의 next를 연결
			pprev = p.before();
			pnext = p.after();
			if (pprev != Position(NULL))
				pprev.setAfter(pnext);
			if (pnext != Position(NULL))
				pnext.setBefore(pprev);

			delete p.pQN;//노드삭제
		}
	}

	void SkipListRemove(ostream& fout, Key k)//k를 가진 타워삭제
	{
		Position p, pprev, pnext, p00, px0;
		Position p0y, pxy, old_p;
		int h_max, h;

		p = SkipListSearch(k);//k위치 탐색
		if ((p.key() != k) || (p.key() == MINUS_INF))//k값이 없다면
		{
			fout << "Key (" << k << ") is not found" << "in SkipList!!" << endl;

			return;
		}
		//k위치가 존재 하는경우
		while (p != Position(NULL))//key 타워 전체 삭제
		{
			old_p = p;
			p = p.above();//p의 위쪽을 새로운p로 설정
			SkipListNodeDelete(old_p);//이전 p위치 삭제
		}
		fout << "deleted skip list node (Key:" << k << ")" << endl;

		//-무한대 +무한대 층을 하나만 남기기 위하여
		p00 = start;
		for (int i = height; i > 0; i--)
		{
			p00 = p00.below();//맨 아래위치
		}

		px0 = p00.after();
		pxy = start;
		h_max = 0;

		while (px0.key() != PLUS_INF)//무한대외에 다른 노드들이 있음
		{
			pxy = px0;
			h = 0;
			while (pxy != Position(NULL))
			{
				++h;//타워 높이 찾아냄
				pxy = pxy.above();
			}
			if (h_max < h)
				h_max = h;//최대 타워높이 
			px0 = px0.after();
		}
		if (h_max < height)//최대 타워높이가 삭제 이전 높이보다 작을경우
		{
			fout << "Current height is less than the new h_max (" << h_max << ") ==> need adjustment!!" << endl;
		}

		for (int i = 0; i < (height - h_max); i++)
		{
			//-무한대 +무한대 층을 하나만 남기기위한 삭제
			p0y = start;
			pxy = start.after();
			start = start.below();
			SkipListNodeDelete(pxy);
			SkipListNodeDelete(p0y);
		}
		height = h_max;//높이는 삭제된 이후 가장높은 타워의 높이
	}

	void PrintSkipList(ostream& fout)//스킵리스트 출력
	{
		Position p, p00, px0, p0y, pxy, q, q0, qx;
		int level;

		fout << "Print Skip List Inside: current height(" << height << ")" << endl;

		p00 = start;
		level = height;
		for (int i = height; i > 0; i--)
		{
			p00 = p00.below();//level 0에 맨왼쪽위치
		}

		p0y = start;
		pxy = start;
		for (level = height; level >= 0; level--)
		{
			fout << "level" << setw(2) << level << " ";
			if (pxy.key() == MINUS_INF)//마이너스 무한대 출력
				fout << "-oo";
			else
				fout << setw(5) << pxy.key();

			px0 = p00.after;//level 0의 데이터를 포함하는 첫번째 위치
			for (pxy = p0y.after();; pxy = pxy.after())
			{
				while ((px0.key() != pxy.key()))//스킵인 경우
				{
					fout << "------";
					px0 = px0.after();//다음위치로 이동
				}
				if (pxy.key() == PLUS_INF)//맨오른쪽 위치인경우
					break;
				else
				{
					fout << "-" << setw(5) << pxy.key();
				}
				px0 = px0.after();//다음위치로 이동
			}
			if (pxy.key() == PLUS_INF)//맨오른쪽 인경우
				fout << "\ +oo";//무한대 출력
			else
				fout << setw(5) << pxy.key();
			fout << endl;
			p0y = p0y.below();//아래위치로 이동
			pxy = p0y;
		}
		fout << endl;
	}

	Position insertAfterAbove(ostream& fout, Position p, Position q, const Key k, const Element e)//p다음q위에 삽입
	{
		QuadNode* pNewNode = new QuadNode(k, e);
		Position n(pNewNode); //새로운 노드 생성
		//초기에 NULL과 연결
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
			else//q값은 있고 p가 NULL인경우
			{
				q.setAbove(n);//q위에 n설정
				n.setBelow(q);//n아래는 q로 설정해서 연결
				n.setAbove(Position(NULL));
				n.setAfter(Position(NULL));

				return n;
			}
		}
		else
		{
			if (q == Position(NULL))//p값은 있고 q가 NULL인경우
			{
				//level 0에 새로운 값추가
				Position nx, ny;
				fout << "insert a node(" << n.key() << ") at level 0" << endl;
				nx = p.after();//기존 p의 다음 nx
				p.setAfter(n);//p다음은 n
				n.setBefore(p);//n이전은 p 서로연결
				n.setAfter(nx);//n이후는 기존의 p의 다음이던 nx
				nx.setBefor(n);//nx의 이전 n
				n.setBleow(Position(NULL));
				n.setAbove(Position(NULL));
				return n;
			}
			else//p와q 모두 값이 NULL이 아닌경우
			{
				Position nx, ny;
				nx = p.after();//p의 다음 nx
				n.setAfter(nx);//n은 p와 nx사이에 삽입이므로 n다음을 nx로 재설정
				if (nx != Position(NULL))//nx값이 있다면
					nx.setBefore(n);//nx이전을 n으로 연결
				p.setAfter(n);//p다음은 n
				n.setBefore(p);//n의 이전은 p로 연결
				ny = q.above();//q의 위는 ny
				q.setAbove(n);//n은q와 ny의 사이에 삽입이므로 q의 위는 n으로 재설정
				n.setBelow(q);//n의 아래는 q로  연결
				n.setAbove(ny);//n의 위는 ny
				if (ny != Position(NULL))//ny값이 있다면
					ny.setBelow(n);//ny의 아래는 n으로 연결
			}
		}
		return n;
	}
};

#endif