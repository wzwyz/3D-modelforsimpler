#include<bits/stdc++.h>
#include<ctime>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <io.h>
#include<iostream>
#include<cstdio>
#include<time.h>
#include <Eigen/Dense>
#include <Eigen/Core>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#define MAXN 260
using namespace std;
using namespace Eigen;
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
struct tyu{
	string gh;
}df[10000];
int nub,nu[500005][7],jl[101][101][101][4],jk[101][101][101][4];
int AX,BY,CZ;
int kx[6]={-1,0,1,0,0,0},ky[6]={0,1,0,-1,0,0},kz[6]={0,0,0,0,1,-1};
int main() {
	ifstream infile;
	ofstream outfile; 
	//_____________________________________________________fdll调用 
	typedef int (*H1)(int,int,int,int,int,int,int,int,int);
	typedef int (*H2)(int,int,int,int,int);
	HMODULE hMod=LoadLibrary("fdll.dll");
	H1 fvectorx=(H1)GetProcAddress(hMod,"_Z8fvectorxiiiiiiiii"),fvectory=(H1)GetProcAddress(hMod,"_Z8fvectoryiiiiiiiii"),fvectorz=(H1)GetProcAddress(hMod,"_Z8fvectorziiiiiiiii");
	H2 equasdx=(H2)GetProcAddress(hMod,"_Z7equasdxiiiii"),equasdy=(H2)GetProcAddress(hMod,"_Z7equasdyiiiii"),equasdz=(H2)GetProcAddress(hMod,"_Z7equasdziiiii");
	//_____________________________________________________RGB句柄 
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)return GetLastError();
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))return GetLastError();
    dwMode |= 0x0004;
    if (!SetConsoleMode(hOut, dwMode))return GetLastError();
    int r,g,b;
    //_______________________________________________________________键鼠交互句柄 
	HANDLE hInput = GetStdHandle( STD_INPUT_HANDLE );
    DWORD mode;
    GetConsoleMode( hInput, &mode );
    mode &= ~ENABLE_QUICK_EDIT_MODE;
    mode |= ENABLE_MOUSE_INPUT;
    SetConsoleMode( hInput, mode|ENABLE_MOUSE_INPUT );
    INPUT_RECORD record;
    DWORD n;
    //_______________________________________________________________选择 
	char zhiling[1000];
	cout<<"Please Choose the file you want to open:"<<endl;
	string namer;
	const char *to_search=".\\files\\*.txt";
	long handlet;                                                //查找句柄
    struct _finddata_t fileinfo;                          //文件信息
    handlet=_findfirst(to_search,&fileinfo);         //第一次查找
    if(-1==handlet)return -1;
    printf("%s\n",fileinfo.name); 
	df[1].gh=fileinfo.name;
	int num=2;                      
    while(!_findnext(handlet,&fileinfo)){printf("%s\n",fileinfo.name);df[num].gh=fileinfo.name;num++;}
    _findclose(handlet);   
	for( COORD pos={}; ReadConsoleInput(hInput,&record,1,&n) && n==1; ){
        if(record.EventType!=MOUSE_EVENT)continue;
		COORD pos_new = record.Event.MouseEvent.dwMousePosition;
        pos = pos_new;
        HANDLE outputHandle=GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD getWrittenCount = 0;
		COORD writtenPos={16,16};
		for(int i=1;i<=num;i++){
			writtenPos={0,i};
			FillConsoleOutputAttribute(outputHandle, 0x0f, 100, writtenPos, &getWrittenCount);
		}
		if(pos.Y>=1&&pos.Y<=num){
			getWrittenCount = 0;
			writtenPos={0,pos.Y};
			FillConsoleOutputAttribute(outputHandle, 0xf0, 100, writtenPos, &getWrittenCount);
        	if(KEY_DOWN(VK_LBUTTON)) { 
				HANDLE hStdoutw;hStdoutw=GetStdHandle(STD_OUTPUT_HANDLE);clearp(hStdoutw);
				namer=df[pos.Y].gh;
				break;
			}
		}
        
    }
    //_______________________________________________________________加速输入输出 
    /*ios::sync_with_studio(false);
    cin.tie(0);cout.tie(0);*/
    //_______________________________________________________________运算 
	const char *nmae2=namer.c_str(); 
	sprintf(zhiling,"copy .\\files\\%s .\\1.txt",nmae2);
	system(zhiling);
	infile.open("1.txt");
	//freopen("1.txt","r",stdin);
    infile>>nub;
    for(int i=1;i<=nub;i++){
    	infile>>nu[i][1]>>nu[i][2]>>nu[i][3];
    	jl[nu[i][1]][nu[i][2]][nu[i][3]][1]=1;
    	infile>>jl[nu[i][1]][nu[i][2]][nu[i][3]][2]>>jl[nu[i][1]][nu[i][2]][nu[i][3]][3]>>jl[nu[i][1]][nu[i][2]][nu[i][3]][4];
    	wprintf(L"\x1b[38;2;%d;%d;%dm&&",jl[nu[i][1]][nu[i][2]][nu[i][3]][2],jl[nu[i][1]][nu[i][2]][nu[i][3]][3],jl[nu[i][1]][nu[i][2]][nu[i][3]][4]);
    	cout<<endl;
	}
	infile.close(); 
	system("del 1.txt");
    for(int i=1;i<=100;i++){
    	for(int j=1;j<=100;j++){
    		for(int v=1;v<=100;v++){
    			if(jl[i][j][v][1]==0)continue;
    			queue<int> qx,qy,qz;
				for(int z=0;z<=5;z++){
    				if(jl[i+kz[z]][j+ky[z]][v+kz[z]][1]==1){
    					if(qx.size()==3)break;
    					else {
    						qx.push(i+kx[z]);
    						qy.push(j+ky[z]);
    					qz.push(v+kz[z]);
						}
					}
				}
				if(qx.size()==3){
					int aq=qx.front();qx.pop();int bq=qy.front();qy.pop();int cq=qz.front();qz.pop();
					int aw=qx.front();qx.pop();int bw=qy.front();qy.pop();int cw=qz.front();qz.pop();
					int ae=qx.front();qx.pop();int be=qy.front();qy.pop();int ce=qz.front();qz.pop();
					RowVector3d T,L;
					T<<fvectorx(aq,aw,ae,bq,bw,be,cq,cw,ce),fvectory(aq,aw,ae,bq,bw,be,cq,cw,ce),fvectorz(aq,aw,ae,bq,bw,be,cq,cw,ce);
					L<<i,j,100-v;
					double gl=T.dot(L)*5;
					gl=gl/10000*0.5+0.7;
					jl[i][j][v][2]=(int)(jl[i][j][v][2]*gl);jl[i][j][v][3]=(int)(jl[i][j][v][3]*gl);jl[i][j][v][4]=(int)(jl[i][j][v][4]*gl);
				}
			}
		}
	}
	HANDLE hStdoutwr;hStdoutwr=GetStdHandle(STD_OUTPUT_HANDLE);clearp(hStdoutwr);
	//_______________________________________________________________输出 
	COORD tpos={0,0};
	COORD cpos={0,0},spos={0,0};
	while(1){
		memset(jk,0,sizeof(jk));
		HANDLE outputHandleu = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO inofo;
		GetConsoleScreenBufferInfo(outputHandleu, &inofo);
		for(int i=1;i<=nub;i++){
			int Ex=equasdx(nu[i][1]-50,nu[i][2]-50,50-nu[i][3],MAXN*(tpos.X+spos.X-cpos.X)/inofo.dwSize.X,MAXN*(tpos.Y+spos.Y-cpos.Y)/120)+50,Ey=equasdy(nu[i][1]-50,nu[i][2]-50,50-nu[i][3],MAXN*(tpos.X+spos.X-cpos.X)/inofo.dwSize.X,MAXN*(tpos.Y+spos.Y-cpos.Y)/120)+50,Ez=50-equasdz(nu[i][1]-50,nu[i][2]-50,50-nu[i][3],MAXN*(tpos.X+spos.X-cpos.X)/inofo.dwSize.X,MAXN*(tpos.Y+spos.Y-cpos.Y)/120);
			jk[Ex][Ey][Ez][1]=1;
			jk[Ex][Ey][Ez][2]=jl[nu[i][1]][nu[i][2]][nu[i][3]][2];
			jk[Ex][Ey][Ez][3]=jl[nu[i][1]][nu[i][2]][nu[i][3]][3];
			jk[Ex][Ey][Ez][4]=jl[nu[i][1]][nu[i][2]][nu[i][3]][4];
		}
		
		HANDLE hStdoutwl;hStdoutwl=GetStdHandle(STD_OUTPUT_HANDLE);clearp(hStdoutwl);
		for(int i=1;i<=100;i++){
			for(int j=1;j<=100;j++){
				int y=0;
				for(int v=1;v<=100;v++){
					if(jk[i][j][v][1]==1){
						wprintf(L"\x1b[38;2;%d;%d;%dm&&",jk[i][j][v][2],jk[i][j][v][3],jk[i][j][v][4]);
						y=1;
						break;
					}
				}
				if(y==0)cout<<"  ";
			}
			cout<<endl;
		}
		HANDLE hInputd = GetStdHandle( STD_INPUT_HANDLE );
    	DWORD modee;
    	GetConsoleMode( hInputd, &modee );
    	modee &= ~ENABLE_QUICK_EDIT_MODE;
    	modee |= ENABLE_MOUSE_INPUT;
    	SetConsoleMode( hInputd, modee|ENABLE_MOUSE_INPUT );
    	INPUT_RECORD records;
    	DWORD nl;
    	bool k=1;
        for( COORD pos={}; ReadConsoleInput(hInputd,&records,1,&nl) && nl==1; )
        {
		    if(records.EventType!=MOUSE_EVENT)continue;
		    COORD pos_new = records.Event.MouseEvent.dwMousePosition;
            pos = pos_new;
            if(KEY_DOWN(VK_LBUTTON)&&k==1){cpos=pos;k=0;}
		    else if(!KEY_DOWN(VK_LBUTTON)&&k==0){
		    	spos=pos;break;
		    }
        }
		tpos=spos;
	}
	return 0; 
}
