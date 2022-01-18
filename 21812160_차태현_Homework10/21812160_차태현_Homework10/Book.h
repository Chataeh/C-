#ifndef B_H
#define B_H

#include<iostream>
#include<iomanip>
#include<string>
#include"Date.h"

using namespace std;

class Book
{
	friend ostream& operator<<(ostream& fout, Book& bk)
	{
		fout.setf(ios::left);
		fout << "[" << setw(8) << bk.title << "," << setw(8) << bk.author << "," << bk.pubDate << "]";
		return fout;
	}
public:
	Book(string bk_title, string bk_author, Date dt) :
		title(bk_title), author(bk_author), pubDate(dt) {}//������
	string& getTitle() { return title; }//���� ��ȯ
	string getAuthor() { return author; }//�۰� ��ȯ
	Date getPubDate() { return pubDate; }//������ ��ȯ
	void setTitle(string bk_title) { title = bk_title; }//������
	void setAuthor(string bk_author) { author = bk_author; }//�۰�����
private:
	string title;//����
	string author;//�۰�
	Date pubDate;//������
};

#endif 