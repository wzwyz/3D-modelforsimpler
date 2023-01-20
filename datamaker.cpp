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
#include <graphics.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#define MAXN 260
using namespace std;
using namespace Eigen;
//_____________________________________________________fdll调用
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
//_____________________________________________________文件名 
struct tyu{
	string gh;
}df[10000];
//_____________________________________________________判断直线 
int nub,nu[500005][7],jl[101][101][101][4],jk[101][101][101][4];

bool noobstacle(int x1,int y1,int z1,int x2,int y2,int z2){
	int cx=x1,cy=y1,cz=z1; 
	int Le=ceil(sqrt(pow(abs(x1-x2),2)+pow(abs(y1-y2),2)+pow(abs(z1-z2),2)));
	for(int i=1;i<=Le;i++){
		if(jk[(int)(x1*i/Le+x2*(Le-i)/Le)][(int)(x1*i/Le+x2*(Le-i)/Le)][(int)(x1*i/Le+x2*(Le-i)/Le)][1]==1)return false;
		if((int)(x1*i/Le+x2*(Le-i)/Le)>=100||(int)(x1*i/Le+x2*(Le-i)/Le)<=0||(int)(y1*i/Le+y2*(Le-i)/Le)>=100||(int)(y1*i/Le+y2*(Le-i)/Le)<=0||(int)(z1*i/Le+z2*(Le-i)/Le)>=100||(int)(z1*i/Le+z2*(Le-i)/Le)<=0)return true;
	}
	return true;
} 
double lengh(int i,int j){
	return sqrt(pow(nu[i][1]-nu[j][1],2)+pow(nu[i][2]-nu[j][2],2)+pow(nu[i][3]-nu[j][3],2));
}
int AX,BY,CZ;
int kx[6]={-1,0,1,0,0,0},ky[6]={0,1,0,-1,0,0},kz[6]={0,0,0,0,1,-1};
struct contina{
	double num;
	int x,y,z;
}con[4];
struct len{
			double len;int num;
	}as[8000];
bool cmp(len a,len b){
	return a.len<b.len;
}
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
    	//wprintf(L"\x1b[38;2;%d;%d;%dm&&",jl[nu[i][1]][nu[i][2]][nu[i][3]][2],jl[nu[i][1]][nu[i][2]][nu[i][3]][3],jl[nu[i][1]][nu[i][2]][nu[i][3]][4]);
	}
	infile.close(); 
	system("del 1.txt");
    freopen("data.txt","w",stdout);
	for(int i=1;i<=nub;i++){
		for(int j=1;j<=nub;j++){
			as[j].num=j;as[j].len=lengh(i,j);
		}
		sort(as+1,as+nub,cmp);
		cout<<nu[i][1]<<' '<<nu[i][2]<<' '<<nu[i][3]<<' '<<nu[as[4].num][1]<<' '<<nu[as[4].num][2]<<' '<<nu[as[4].num][3]<<' '<<nu[as[5].num][1]<<' '<<nu[as[5].num][2]<<' '<<nu[as[5].num][3]<<' ';
		cout<<jl[nu[i][1]][nu[i][2]][nu[i][3]][2]<<' '<<jl[nu[i][1]][nu[i][2]][nu[i][3]][3]<<' '<<jl[nu[i][1]][nu[i][2]][nu[i][3]][4]<<endl;
		cout<<nu[i][1]<<' '<<nu[i][2]<<' '<<nu[i][3]<<' '<<nu[as[6].num][1]<<' '<<nu[as[6].num][2]<<' '<<nu[as[6].num][3]<<' '<<nu[as[7].num][1]<<' '<<nu[as[7].num][2]<<' '<<nu[as[7].num][3]<<' ';
		cout<<jl[nu[i][1]][nu[i][2]][nu[i][3]][2]<<' '<<jl[nu[i][1]][nu[i][2]][nu[i][3]][3]<<' '<<jl[nu[i][1]][nu[i][2]][nu[i][3]][4]<<endl;
	}
	//HANDLE hStdoutwr;hStdoutwr=GetStdHandle(STD_OUTPUT_HANDLE);clearp(hStdoutwr);
	//_______________________________________________________________输出 
	/*COORD tpos={0,0};
	COORD cpos={0,0},spos={0,0};*/
    return 0;
}
