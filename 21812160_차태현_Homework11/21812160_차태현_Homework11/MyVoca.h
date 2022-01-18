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
		list<string>::iterator itr;//반복자 선언
		fout << mv.keyWord << "(" << wd_ty[mv.type] << "):" << endl;//품사 출력
		fout << " - thesaurus(";
		for (itr = mv.thesaurus.begin(); itr != mv.thesaurus.end(); ++itr)
		{
			fout << *itr << ",";//동의어 출력
		}
		fout << ")" << endl;
		fout << " - example usage(";
		for (itr = mv.usages.begin(); itr != mv.usages.end(); ++itr)
		{
			fout << *itr << "";//예문출력
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
	string keyWord;//키워드
	Word_Type type;//품사
	List_Str thesaurus;//유의어
	List_Str usages;//예문
};



#endif 