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
int equasd(int c1,int c2,int c3,int sdf,int sdp){
	double d[]={0,cos(2*3.14159*sdf/MAXN),sin(2*3.14159*sdf/MAXN),0,-sin(2*3.14159*sdf/MAXN),cos(2*3.14159*sdf/MAXN),0,0,0,1};
	double b[]={0,1,0,0,0,cos(2*3.14159*sdp/MAXN),sin(2*3.14159*sdp/MAXN),0,-sin(2*3.14159*sdp/MAXN),cos(2*3.14159*sdp/MAXN)};
	double u[]={0,c1,c2,c3};
	double o[3];
	o[1]=u[1]*d[1]+u[2]*d[2]+u[3]*d[3];
    o[2]=u[1]*d[4]+u[2]*d[5]+u[3]*d[6];
    o[3]=u[1]*d[7]+u[2]*d[8]+u[3]*d[9];
    double e[3];
	e[1]=o[1]*b[1]+o[2]*b[2]+o[3]*b[3];
    e[2]=o[1]*b[4]+o[2]*b[5]+o[3]*b[6];
    e[3]=o[1]*b[7]+o[2]*b[8]+o[3]*b[9];
	jk[(int)e[1]][(int)e[2]][(int)e[3]][1]=1;
	jk[(int)e[1]][(int)e[2]][(int)e[3]][2]=jl[c1][c2][c3][2];
	jk[(int)e[1]][(int)e[2]][(int)e[3]][3]=jl[c1][c2][c3][3];
	jk[(int)e[1]][(int)e[2]][(int)e[3]][4]=jl[c1][c2][c3][4];
	//cout<<f[1]<<" "<<f[3]<<" "<<f[7]<<" "<<f[9]<<" "<<u[1]<<" "<<u[2]<<" ";
	cout<<e[1]<<" "<<e[2]<<" "<<e[3]<<" "<<endl;
}
int main() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)return GetLastError();
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))return GetLastError();
    dwMode |= 0x0004;
    if (!SetConsoleMode(hOut, dwMode))return GetLastError();
    int r,g,b;
    
    freopen("1.txt","r",stdin);
    cin>>nub;
    cout<<"fuck";
    for(int i=1;i<=nub;i++){
    	cin>>nu[i][1]>>nu[i][2]>>nu[i][3];
    	jl[nu[i][1]][nu[i][2]][nu[i][3]][1]=1;
    	cin>>jl[nu[i][1]][nu[i][2]][nu[i][3]][2]>>jl[nu[i][1]][nu[i][2]][nu[i][3]][3]>>jl[nu[i][1]][nu[i][2]][nu[i][3]][4];
    	wprintf(L"\x1b[38;2;%d;%d;%dm&&",123,15,217);
	}
	cout<<"fuck";
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
					fvector(aq,aw,ae,bq,bw,be,cq,cw,ce);
					RowVector3d T,L;
					T<<AX,BY,CZ;
					L<<i,j,100-v;
					double gl=T.dot(L);
					gl=gl/10000*0.5+0.5;
					jl[i][j][v][2]=(int)(jl[i][j][v][2]*gl);jl[i][j][v][3]=(int)(jl[i][j][v][3]*gl);jl[i][j][v][4]=(int)(jl[i][j][v][4]*gl);
				}
				else{
					jl[i][j][v][2]=0;jl[i][j][v][3]=0;jl[i][j][v][4]=0;
				}
			}
		}
	}
	//system("cls");
	cout << "\033c";
	cout<<"fuck1";
	/*for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			int g=0;
			for(int v=1;v<=100;v++){
				if(jl[i][v][j][1]==1){
					g=v;
					break;
				}
			}
			if(g==0)cout<<"  ";
			else cout<<g;
		}
		cout<<endl;
	}
	Sleep(30000);*/
	//while(1){
		POINT p;
		GetCursorPos(&p);
		memset(jk,0,sizeof(jk));
		cout <<"\033c";
		for(int i=1;i<=100;i++){
			for(int j=1;j<=100;j++){
				for(int v=1;v<=100;v++){
					if(jl[i][j][v][1]==1){
						equasd(i,j,v,MAXN*p.x/1679,MAXN*p.y/1119);
					}
				}
				cout <<"\033c";
				for(int l=1;l<=i;l++)cout<<"¨€";
				double s=i*100+j;
				cout<<fixed<<setprecision(2)<<s/100;
				cout<<"%";
			}
		}
		cout << "\033c";
		cout<<"fuck2";
		for(int i=1;i<=100;i++){
			for(int j=1;j<=100;j++){
				int y=0;
				for(int v=1;v<=100;v++){
					if(jk[i][j][v][1]==1){
						wprintf(L"\x1b[38;2;%d;%d;%dm&&",jk[i][j][v][2],jk[i][j][v][3],jk[i][j][v][4]);
						//cout<<jk[i][j][v][2]<<jk[i][j][v][3]<<jk[i][j][v][4]<<endl;
						y=1;
						break;
					}
				}
				if(y==0)cout<<"  ";
			}
			cout<<endl;
		}
	//}
	return 0; 
}
