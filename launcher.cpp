#include<bits/stdc++.h>
#include<ctime>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<cstdio>
#include<time.h>
#include <Eigen/Dense>
#include <Eigen/Core>
#define MAXN 260
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;
void clearp(HANDLE hConsole)
{
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   SMALL_RECT scrollRect;
   COORD scrollTarget;
   CHAR_INFO fill;
   if (!GetConsoleScreenBufferInfo(hConsole, &csbi))return;
   scrollRect.Left=0;
   scrollRect.Top=0;
   scrollRect.Right=csbi.dwSize.X;
   scrollRect.Bottom=csbi.dwSize.Y;
   scrollTarget.X=0;
   scrollTarget.Y=(SHORT)(0-csbi.dwSize.Y);
   fill.Char.UnicodeChar=TEXT(' ');
   fill.Attributes=csbi.wAttributes;
   ScrollConsoleScreenBuffer(hConsole,&scrollRect,NULL,scrollTarget,&fill);
   csbi.dwCursorPosition.X=0;
   csbi.dwCursorPosition.Y=0;
   SetConsoleCursorPosition(hConsole,csbi.dwCursorPosition);
}
int main(){
	//_______________________________________________________________RGB¾ä±ú 
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)return GetLastError();
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))return GetLastError();
    dwMode |= 0x0004;
    if (!SetConsoleMode(hOut, dwMode))return GetLastError();
    int r,g,b;
    
	//cout<<"\033c"; 
	while(1){
	//_______________________________________________________________¼üÊó½»»¥¾ä±ú 
	HANDLE hInput = GetStdHandle( STD_INPUT_HANDLE );
    DWORD mode;
    GetConsoleMode( hInput, &mode );
    mode &= ~ENABLE_QUICK_EDIT_MODE;
    mode |= ENABLE_MOUSE_INPUT;
    SetConsoleMode( hInput, mode|ENABLE_MOUSE_INPUT );
    INPUT_RECORD record;
    DWORD n;
    //_______________________________________________________________¼üÊó½»»¥¾ä±ú
	wprintf(L"\x1b[38;2;%d;%d;%dm+------+.      +------+       +------+       +------+      .+------+", 255, 255,18);cout<<endl;
	wprintf(L"\x1b[38;2;%d;%d;%dm|`.    | `.    |\\     |\\      |      |      /|     /|    .' |    .'|", 255, 255,18);cout<<endl;
	wprintf(L"\x1b[38;2;%d;%d;%dm|  `+--+---+   | +----+-+     +------+     +-+----+ |   +---+--+'  |", 255, 255,18);cout<<endl;
	wprintf(L"\x1b[38;2;%d;%d;%dm|   |  |   |   | |    | |     |      |     | |    | |   |   |  |   |", 255, 255,18);cout<<endl;
	wprintf(L"\x1b[38;2;%d;%d;%dm+---+--+.  |   +-+----+ |     +------+     | +----+-+   |  .+--+---+", 255, 255,18);cout<<endl;
	wprintf(L"\x1b[38;2;%d;%d;%dm `. |    `.|    \\|     \\|     |      |     |/     |/    |.'    | .'", 255, 255,18);cout<<endl;
	wprintf(L"\x1b[38;2;%d;%d;%dm   `+------+     +------+     +------+     +------+     +------+'", 255, 255,18);cout<<endl;
	wprintf(L"\x1b[38;2;%d;%d;%dm                             Simpler_3D",106,90,205);cout<<endl;
	wprintf(L"\x1b[38;2;%d;%d;%dm   .+------+     +------+     +------+     +------+     +------+.",  0,250,170);cout<<endl;
	wprintf(L"\x1b[38;2;%d;%d;%dm .' |    .'|    /|     /|     |      |     |\\     |\\    |`.    | `.",  0,250,170);cout<<endl;
	wprintf(L"\x1b[38;2;%d;%d;%dm+---+--+'  |   +-+----+ |     +------+     | +----+-+   |  `+--+---+",  0,250,170);cout<<endl;
	wprintf(L"\x1b[38;2;%d;%d;%dm|   |  |   |   | |    | |     |      |     | |    | |   |   |  |   |",  0,250,170);cout<<endl;
	wprintf(L"\x1b[38;2;%d;%d;%dm|  ,+--+---+   | +----+-+     +------+     +-+----+ |   +---+--+   |",  0,250,170);cout<<endl;
	wprintf(L"\x1b[38;2;%d;%d;%dm|.'    | .'    |/     |/      |      |      \\|     \\|    `. |   `. |", 0,250,170);cout<<endl;
	wprintf(L"\x1b[38;2;%d;%d;%dm+------+'      +------+       +------+       +------+      `+------+", 0,250,170);cout<<endl;
	wprintf(L"\x1b[38;2;%d;%d;%dmWhat do you want to do?",255,255,255);cout<<endl;
	wprintf(L"\x1b[38;2;%d;%d;%dmyou can click ",255,255,255);
	wprintf(L"\x1b[38;2;%d;%d;%dmadd ",30,255,254);
	wprintf(L"\x1b[38;2;%d;%d;%dmto launch your models in the dock",255,255,255);cout<<endl;
	wprintf(L"\x1b[38;2;%d;%d;%dmor you can click",255,255,255);
	wprintf(L"\x1b[38;2;%d;%d;%dm launch ",30,255,254);
	wprintf(L"\x1b[38;2;%d;%d;%dmto luanch the done ones",255,255,255);
	cout<<endl;wprintf(L"\x1b[38;2;%d;%d;%dm",30,255,254);
	for( COORD pos={}; ReadConsoleInput(hInput,&record,1,&n) && n==1; ){
        if(record.EventType!=MOUSE_EVENT)continue;
		COORD pos_new = record.Event.MouseEvent.dwMousePosition;
        pos = pos_new;
        if(pos.X>=14&&pos.X<=18&&pos.Y==16){
        	HANDLE outputHandle=GetStdHandle(STD_OUTPUT_HANDLE);
			DWORD getWrittenCount = 0;
			COORD writtenPos={14,16};
			FillConsoleOutputAttribute(outputHandle, 0xB0, 4, writtenPos, &getWrittenCount);
        	if(KEY_DOWN(VK_LBUTTON)) { 
				system("ConsoleApplication1.exe");
				system("yu.exe");
				system("predone.exe");
				system("pause");
				HANDLE hStdoutw;hStdoutw=GetStdHandle(STD_OUTPUT_HANDLE);clearp(hStdoutw);
				break;
			}
		}
		else if(pos.X>=17&&pos.X<=24&&pos.Y==17){
        	HANDLE outputHandle=GetStdHandle(STD_OUTPUT_HANDLE);
			DWORD getWrittenCount = 0;
			COORD writtenPos={17,17};
			FillConsoleOutputAttribute(outputHandle, 0xB0, 7, writtenPos, &getWrittenCount);
        	if(KEY_DOWN(VK_LBUTTON)) { 
				HANDLE hStdoutw;hStdoutw=GetStdHandle(STD_OUTPUT_HANDLE);clearp(hStdoutw);
				system("main.exe");
				system("pause"); 
				hStdoutw=GetStdHandle(STD_OUTPUT_HANDLE);clearp(hStdoutw);
				break;
			}
		}
		else{
			HANDLE outputHandle=GetStdHandle(STD_OUTPUT_HANDLE);
			DWORD getWrittenCount = 0;
			COORD writtenPos={14,16};
			FillConsoleOutputAttribute(outputHandle, 0x0B, 4, writtenPos, &getWrittenCount);
			writtenPos={17,17};
			FillConsoleOutputAttribute(outputHandle, 0x0B, 7, writtenPos, &getWrittenCount);
		} 
        
    }
}
	return 0;
}
