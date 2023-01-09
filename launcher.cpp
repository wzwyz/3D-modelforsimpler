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
using namespace std;	//T表示任何可以被cout输出的类型
int main(){
	//_______________________________________________________________ 
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)return GetLastError();
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))return GetLastError();
    dwMode |= 0x0004;
    if (!SetConsoleMode(hOut, dwMode))return GetLastError();
    int r,g,b;
    //_______________________________________________________________ 
	while(1){
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
	wprintf(L"\x1b[38;2;%d;%d;%dmyou can type in ",255,255,255);
	wprintf(L"\x1b[38;2;%d;%d;%dmadd ",30,255,254);
	wprintf(L"\x1b[38;2;%d;%d;%dmto launch your models in the dock",255,255,255);cout<<endl;
	wprintf(L"\x1b[38;2;%d;%d;%dmor you can type in",255,255,255);
	wprintf(L"\x1b[38;2;%d;%d;%dm launch ",30,255,254);
	wprintf(L"\x1b[38;2;%d;%d;%dmto luanch the done ones",255,255,255);
	cout<<endl;wprintf(L"\x1b[38;2;%d;%d;%dm",30,255,254);
	string ans;
	cin>>ans;
	if(ans=="add"){
		system("ConsoleApplication1");
		system("yu.exe");
		system("predone.exe");
		system("pause");
		cout<<"\033c";
	}
	else if(ans=="launch")system("main.exe");
}
	return 0;
}
