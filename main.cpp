#include<bits/stdc++.h> 
#include<windows.h>
#define MAXN 260
using namespace std;
int jl[100][100][100],jk[100][100],maxr=1,minr=100;
int equasd(int sdi,int sdj,int sdf,int sdp){
	double f[]={0,cos(2*3.14159*sdi/MAXN),0,sin(2*3.14159*sdi/MAXN),0,1,0,-sin(2*3.14159*sdi/MAXN),0,cos(2*3.14159*sdi/MAXN)};
	double d[]={0,cos(2*3.14159*sdf/MAXN),sin(2*3.14159*sdf/MAXN),0,-sin(2*3.14159*sdf/MAXN),cos(2*3.14159*sdf/MAXN),0,0,0,1};
	double b[]={0,1,0,0,0,cos(2*3.14159*sdp/MAXN),sin(2*3.14159*sdp/MAXN),0,-sin(2*3.14159*sdp/MAXN),cos(2*3.14159*sdp/MAXN)};
	double u[]={0,20+10*cos(2*3.14159*sdj/MAXN),10*sin(2*3.14159*sdj/MAXN),0};
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
	jl[(int)e[1]+50][(int)e[2]+50][-(int)e[3]+50]=1;
	//cout<<f[1]<<" "<<f[3]<<" "<<f[7]<<" "<<f[9]<<" "<<u[1]<<" "<<u[2]<<" ";
	//cout<<c[1]<<" "<<c[2]<<" "<<c[3]<<" "<<endl;
}

int main(){
	POINT p;
	while(1){
		GetCursorPos(&p);
		for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			for(int v=1;v<=100;v++){
				jl[i][j][v]=0;
			}
		}
	}
	for(int i=1;i<=MAXN;i++){
		for(int j=1;j<=MAXN;j++){
			equasd(i,j,100*p.x/1679,100*p.y/1119);
		}
	}
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			int g=0;
			for(int v=1;v<=100;v++){
				if(jl[i][v][j]==1){
					g=v;
					break;
				}
			}
			jk[i][j]=g;
			if(maxr<g&&j<=99&&i<=99)maxr=g;
			if(minr>g&&g!=0)minr=g;
		}
	}
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			if(jk[i][j]==0)cout<<"  ";
			else if(jk[i][j]>minr+(maxr-minr)*3/5&&jk[i][j]<=maxr)cout<<"¿Ú";
			else if(jk[i][j]>minr+(maxr-minr)*2/10&&jk[i][j]<=minr+(maxr-minr)*3/5)cout<<"»Ø";
			else if(jk[i][j]>minr+(maxr-minr)/10&&jk[i][j]<=minr+(maxr-minr)*3/10)cout<<"ÇD";
			else if(jk[i][j]<=minr+(maxr-minr)/10)cout<<"è‹";
			//else cout<<"**";
			//else cout<<jk[i][j];
		}
		cout<<endl;
	}
	Sleep(10);
	system("cls");
	}
	
	return 0;
}
