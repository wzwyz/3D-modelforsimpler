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
using namespace std;
using namespace Eigen;
int nub,nu[500005][7],jl[101][101][101][4],jk[101][101][101][4];
int AX,BY,CZ;
int kx[6]={-1,0,1,0,0,0},ky[6]={0,1,0,-1,0,0},kz[6]={0,0,0,0,1,-1};
int main() {
	//_____________________________________________________
	typedef int (*H1)(int,int,int,int,int,int,int,int,int);
	typedef int (*H2)(int,int,int,int,int);
	HMODULE hMod=LoadLibrary("fdll.dll");
	H1 fvectorx=(H1)GetProcAddress(hMod,"_Z8fvectorxiiiiiiiii"),fvectory=(H1)GetProcAddress(hMod,"_Z8fvectoryiiiiiiiii"),fvectorz=(H1)GetProcAddress(hMod,"_Z8fvectorziiiiiiiii");
	H2 equasdx=(H2)GetProcAddress(hMod,"_Z7equasdxiiiii"),equasdy=(H2)GetProcAddress(hMod,"_Z7equasdyiiiii"),equasdz=(H2)GetProcAddress(hMod,"_Z7equasdziiiii");
	//_____________________________________________________
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)return GetLastError();
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))return GetLastError();
    dwMode |= 0x0004;
    if (!SetConsoleMode(hOut, dwMode))return GetLastError();
    int r,g,b;
    //_____________________________________________________
    system("mode con: cols=120 lines=40");
	char zhiling[1000];
	cout<<"Please enter in the file you want to open:";
	string namer;
	cin>>namer;
	const char *nmae2=namer.c_str(); 
	sprintf(zhiling,"copy .\\files\\%s.txt .\\1.txt",nmae2);
	system(zhiling);
	freopen("1.txt","r",stdin);
    cin>>nub;
    for(int i=1;i<=nub;i++){
    	cin>>nu[i][1]>>nu[i][2]>>nu[i][3];
    	jl[nu[i][1]][nu[i][2]][nu[i][3]][1]=1;
    	cin>>jl[nu[i][1]][nu[i][2]][nu[i][3]][2]>>jl[nu[i][1]][nu[i][2]][nu[i][3]][3]>>jl[nu[i][1]][nu[i][2]][nu[i][3]][4];
    	wprintf(L"\x1b[38;2;%d;%d;%dm&&",jl[nu[i][1]][nu[i][2]][nu[i][3]][2],jl[nu[i][1]][nu[i][2]][nu[i][3]][3],jl[nu[i][1]][nu[i][2]][nu[i][3]][4]);
    	cout<<endl;
	}
	fclose(stdin); 
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
	cout << "\033c";
	cout<<"fuck1";
	while(1){
		POINT p;
		GetCursorPos(&p);
		memset(jk,0,sizeof(jk));
		cout <<"\033c";
		for(int i=1;i<=nub;i++){
			int Ex=equasdx(nu[i][1],nu[i][2],nu[i][3],MAXN*p.x/1679,MAXN*p.y/1119),Ey=equasdy(nu[i][1],nu[i][2],nu[i][3],MAXN*p.x/1679,MAXN*p.y/1119),Ez=equasdz(nu[i][1],nu[i][2],nu[i][3],MAXN*p.x/1679,MAXN*p.y/111);
			jk[Ex][Ey][Ez][1]=1;
			jk[Ex][Ey][Ez][2]=jl[nu[i][1]][nu[i][2]][nu[i][3]][2];
			jk[Ex][Ey][Ez][3]=jl[nu[i][1]][nu[i][2]][nu[i][3]][3];
			jk[Ex][Ey][Ez][4]=jl[nu[i][1]][nu[i][2]][nu[i][3]][4];
		}
		cout << "\033c";
		cout<<"fuck2";
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
	}
	return 0; 
}
