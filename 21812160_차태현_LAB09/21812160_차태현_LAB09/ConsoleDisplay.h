#ifndef CD_H
#define CD_H
#include<Windows.h>

HANDLE initConsoleHandler();
void cls(HANDLE hConsole);//ȭ�� �����
void colseConsoleHandler(HANDLE hndlr);
int gotoxy(HANDLE consoleHandler, int x, int y);//x,y��ǥ�� �̵�

#endif