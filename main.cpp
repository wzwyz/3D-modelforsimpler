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
#define MAXN 120 
using namespace std;
using namespace Eigen;
int nub,nu[500005][7],jl[101][101][101][4],jk[101][101][101][4];
int AX,BY,CZ;
int kx[6]={-1,0,1,0,0,0},ky[6]={0,1,0,-1,0,0},kz[6]={0,0,0,0,1,-1};
void fvector(int a1,int b1,int c1,int a2,int b2,int c2,int a3,int b3,int c3){
	int a, b, c, d, e, f;
	a = a1 - a2;
	b = b1 - b2;
	c = c1 - c2;
	d = a1 - a3;
	e = b1 - b3;
	f = c1 - c3;
	int A, B, C;
	A = b * f - c * e;
	B = c * d - a * f;
	C = a * e - b * d;
	AX=A;BY=B;CZ=C;
}
int equasd(int sdi,int c1,int c2,int c3,int sdf,int sdp){
	double f[]={0,cos(2*3.14159*sdi/MAXN),0,sin(2*3.14159*sdi/MAXN),0,1,0,-sin(2*3.14159*sdi/MAXN),0,cos(2*3.14159*sdi/MAXN)};
	double d[]={0,cos(2*3.14159*sdf/MAXN),sin(2*3.14159*sdf/MAXN),0,-sin(2*3.14159*sdf/MAXN),cos(2*3.14159*sdf/MAXN),0,0,0,1};
	double b[]={0,1,0,0,0,cos(2*3.14159*sdp/MAXN),sin(2*3.14159*sdp/MAXN),0,-sin(2*3.14159*sdp/MAXN),cos(2*3.14159*sdp/MAXN)};
	double u[]={0,c1,c2,c3};
	double c[3];
    c[1]=u[1]*f[1]+u[2]*f[2]+u[3]*f[3];
    c[2]=u[1]*f[4]+u[2]*f[5]+u[3]*f[6];
    c[3]=u[1]*f[7]+u[2]*f[8]+u[3]*f[9];
	double o[3];
	o[1]=c[1]*d[1]+c[2]*d[2]+c[3]*d[3];
    o[2]=c[1]*d[4]+c[2]*d[5]+c[3]*d[6];
    o[3]=c[1]*d[7]+c[2]*d[8]+c[3]*d[9];
    double e[3];
	e[1]=o[1]*b[1]+o[2]*b[2]+o[3]*b[3];
    e[2]=o[1]*b[4]+o[2]*b[5]+o[3]*b[6];
    e[3]=o[1]*b[7]+o[2]*b[8]+o[3]*b[9];
	jk[(int)e[1]][(int)e[2]][(int)e[3]][1]=1;
	jk[(int)e[1]][(int)e[2]][(int)e[3]][2]=jl[c1][c2][c3][2];
	jk[(int)e[1]][(int)e[2]][(int)e[3]][3]=jl[c1][c2][c3][3];
	jk[(int)e[1]][(int)e[2]][(int)e[3]][4]=jl[c1][c2][c3][4];
	//cout<<f[1]<<" "<<f[3]<<" "<<f[7]<<" "<<f[9]<<" "<<u[1]<<" "<<u[2]<<" ";
	//cout<<c[1]<<" "<<c[2]<<" "<<c[3]<<" "<<endl;
}
int main() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)return GetLastError();
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))return GetLastError();
    dwMode |= 0x0004;
    if (!SetConsoleMode(hOut, dwMode))return GetLastError();
    int r,g,b;
    cin>>nub;
    for(int i=1;i<=nub;i++){
    	cin>>nu[i][1]>>nu[i][2]>>nu[i][3];
    	jl[nu[i][1]][nu[i][2]][nu[i][3]][1]=1;
	}
    for(int i=1;i<=100;i++){
    	for(int j=1;j<=100;j++){
    		for(int v=1;v<=100;v++){
    			if(jl[i][j][v][1]==0)continue;
    			queue<int> qx,qy,qz;
				for(int z=1;z<=6;z++){
    				if(jl[i+kz[z]][j+ky[z]][v+kz[z]][1]==1){
    					if(qx.size()==3)break;
    					else {
    						qx.push(i+kx[i]);
    						qy.push(j+ky[i]);
    						qz.push(v+kz[i]);
						}
					}
				}
				if(qx.size()==3){
					int aq=qx.front();qx.pop();int bq=qy.front();qy.pop();int cq=qz.front();qz.pop();
					int aw=qx.front();qx.pop();int bw=qy.front();qy.pop();int cw=qz.front();qz.pop();
					int ae=qx.front();qx.pop();int be=qy.front();qy.pop();int ce=qz.front();qz.pop();
					fvector(aq,bq,cq,aw,bw,cw,ae,be,ce);
					RowVector3f T,L;
					T<<AX/100,BY/100,CZ/100;
					L<<i/100,j/100,1-v/100;
					int gl=0.5*T.dot(L)+0.5;
					jl[i][j][v][2]=jl[i][j][v][2]*gl;jl[i][j][v][3]=jl[i][j][v][3]*gl;jl[i][j][v][4]=jl[i][j][v][4]*gl;
				}
				else{
					jl[i][j][v][2]=0;jl[i][j][v][3]=0;jl[i][j][v][4]=0;
				}
			}
		}
	}
	while(1){
		POINT p;
		GetCursorPos(&p);
		memset(jk,0,sizeof(jk));
		for(int i=1;i<=100;i++){
			for(int j=1;j<=100;j++){
				for(int v=1;v=100;v++){
					if(jl[i][j][v][1]==1)equasd(MAXN,i,j,v,MAXN*p.x/1679,MAXN*p.y/1119);
				}
			}
		}
		for(int i=1;i<=100;i++){
			for(int j=1;j<=100;j++){
				for(int v=1;v=100;v++){
					if(jk[i][j][v][1]==1)wprintf(L"\x1b[38;2;%d;%d;%dm&&",jk[i][j][v][2],jk[i][j][v][3],jk[i][j][v][4]);
					else cout<<"  ";
				}
			}
		}
	}
	return 0; 
}
