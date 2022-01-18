#ifndef MV_H
#define MV_H

#include<iostream>
#include<string>
#include<list>

using namespace std;

enum Word_Type { NOUN, VERB, ADJ, ADV, PREPOS };
typedef list<string> List_Str;
typedef list<string>::iterator Lst_Str_Itr;

class MyVoca
{
	friend ostream& operator<<(ostream& fout, MyVoca& mv)
	{
		const string wd_ty[] = { "n","v","adj","adv","prepos" };
		list<string>::iterator itr;//�ݺ��� ����
		fout << mv.keyWord << "(" << wd_ty[mv.type] << "):" << endl;//ǰ�� ���
		fout << " - thesaurus(";
		for (itr = mv.thesaurus.begin(); itr != mv.thesaurus.end(); ++itr)
		{
			fout << *itr << ",";//���Ǿ� ���
		}
		fout << ")" << endl;
		fout << " - example usage(";
		for (itr = mv.usages.begin(); itr != mv.usages.end(); ++itr)
		{
			fout << *itr << "";//�������
		}
		fout << ")";

		return fout;
	}
public:
	MyVoca(string kw, Word_Type wt, List_Str thes, List_Str ex_usg)
		:keyWord(kw), type(wt), thesaurus(thes), usages(ex_usg) {}
	MyVoca() {}
	string getKeyWord() { return keyWord; }
private:
	string keyWord;//Ű����
	Word_Type type;//ǰ��
	List_Str thesaurus;//���Ǿ�
	List_Str usages;//����
};



#endif 