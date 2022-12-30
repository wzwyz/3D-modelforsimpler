#include<bits/stdc++.h> 
#include<windows.h>
#define MAXN 260
using namespace std;
int jl[101][101][101],jk[100][100],maxr=1,minr=100;
int equasd(int sdi,int sdj){
	double f[]={0,cos(2*3.14159*sdi/MAXN),0,sin(2*3.14159*sdi/MAXN),0,1,0,-sin(2*3.14159*sdi/MAXN),0,cos(2*3.14159*sdi/MAXN)};
	double u[]={0,20+10*cos(2*3.14159*sdj/MAXN),10*sin(2*3.14159*sdj/MAXN),0};
	double c[3];
    c[1]=u[1]*f[1]+u[2]*f[2]+u[3]*f[3];
    c[2]=u[1]*f[4]+u[2]*f[5]+u[3]*f[6];
    c[3]=u[1]*f[7]+u[2]*f[8]+u[3]*f[9];
	jl[(int)c[1]+50][(int)c[2]+50][-(int)c[3]+50]=1;
	//cout<<f[1]<<" "<<f[3]<<" "<<f[7]<<" "<<f[9]<<" "<<u[1]<<" "<<u[2]<<" ";
	//cout<<(int)c[1]+50<<" "<<(int)c[2]+50<<" "<<-(int)c[3]+50<<" ";
}

int main(){
	for(int i=1;i<=MAXN;i++){
		for(int j=1;j<=MAXN;j++){
			equasd(i,j);
		}
	}
	freopen("1.txt","w",stdout);
	int sum=0;
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			for(int k=1;k<=100;k++){
				if(jl[i][j][k]==1){
					cout<<i<<' '<<j<<' '<<k<<' '<<123<<' '<<15<<' '<<217<<endl;
					sum++; 
				} 
			}
		} 
	}
	cout<<sum;
	return 0;
}
