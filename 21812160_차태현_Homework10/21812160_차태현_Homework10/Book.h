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
		title(bk_title), author(bk_author), pubDate(dt) {}//생성자
	string& getTitle() { return title; }//제목 반환
	string getAuthor() { return author; }//작가 반환
	Date getPubDate() { return pubDate; }//출판일 반환
	void setTitle(string bk_title) { title = bk_title; }//제목설정
	void setAuthor(string bk_author) { author = bk_author; }//작가설정
private:
	string title;//제목
	string author;//작가
	Date pubDate;//출판일
};

#endif 