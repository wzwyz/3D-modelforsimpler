#include<bits/stdc++.h> 
#include<windows.h>
#define MAXN 260
using namespace std;
struct tyu{
	string gh;
}sdf[100];
int jl[101][101][101],jk[100][100],maxr=1,minr=100;
int main(){
	char zhiling[10000];
	system("title Ply reader");
	freopen("C:\\Users\\wyz\\Documents\\ghfile.txt","r",stdin);
	//cout<<"Please enter in the file you want to open:"<<endl;
	string dir,pathr,namer;
	cin>>dir>>pathr>>namer; 
	fclose(stdin);
	string usder=pathr+namer;
	const char *nmae1=dir.c_str();
	const char *nmae2=usder.c_str(); 
	const char *nmae3=namer.c_str(); 
	sprintf(zhiling,"tar -xzvf %s.tar.gz -C C:\\Users\\wyz\\Documents\\",nmae2);
	system(zhiling);
	sprintf(zhiling,"copy %s.txt C:\\Users\\wyz\\Documents\\midt.txt",nmae2);
	system(zhiling);
	freopen("C:\\Users\\wyz\\Documents\\midt.txt","r",stdin);
	freopen("C:\\Users\\wyz\\Documents\\midr.txt","w",stdout);
	int nub;
	cin>>nub;
	for(int j=1;j<=nub;j++){
		double xx,yy,zz;
		cin>>xx>>yy>>zz;
		xx=xx*250+50;yy=yy*250+50;zz=zz*250+50;
		jl[(int)xx][(int)yy][(int)zz]=1;
	} 
	int sum=0;
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			for(int k=1;k<=100;k++){
				if(jl[i][j][k]==1){
					sum++;
				} 
			}
		} 
	}
	cout<<sum<<endl;
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			for(int k=1;k<=100;k++){
				if(jl[i][j][k]==1){
					cout<<i<<' '<<j<<' '<<k<<' ';
					int r=i*255/100,g=j*255/100,b=k*255/100;//该点的rgb值 
					cout<<r<<' '<<g<<' '<<b<<endl; 
				} 
			}
		} 
	}
	fclose(stdin);
	fclose(stdout);
	sprintf(zhiling,"move C:\\Users\\wyz\\Documents\\midr.txt %s\\files\\%s.txt",nmae1,nmae3);
	system(zhiling);
	system("del C:\\Users\\wyz\\Documents\\midt.txt");
	//system("del .\\*.ply");
	freopen("CON", "w", stdout);
	cout<<"\033c";
	cout<<"Here is the file called "<<nmae3<<endl;
	//system("type .\\trf.txt");
	cout<<nmae3;
	
	//dir /b | find ".ply" >trf.txt
	return 0;
}
