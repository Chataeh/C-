#ifndef CD_H
#define CD_H
#include<Windows.h>

HANDLE initConsoleHandler();
void cls(HANDLE hConsole);//화면 지우기
void colseConsoleHandler(HANDLE hndlr);
int gotoxy(HANDLE consoleHandler, int x, int y);//x,y좌표로 이동

#endif