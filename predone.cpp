#include<bits/stdc++.h> 
#include<windows.h>
#define MAXN 260
using namespace std;
struct tyu{
	string gh;
}df[100];
int jl[101][101][101],jk[100][100],maxr=1,minr=100;
int main(){
	freopen("deft.homo","r",stdin);
	int nub;cin>>nub;
	for(int l=1;l<=nub;l++){
		cin>>df[l].gh;
	}
	fclose(stdin);
	for(int i=1;i<=nub;i++){
		int start=df[i].gh.find_last_of('\\'); 
		int end=df[i].gh.find_first_of('.');
		string pathr=df[i].gh.substr(0,start+1);
		string namer=df[i].gh.substr(start+1,end-start-1);
		string exten=df[i].gh.substr(end,df[i].gh.length()-end);
		char zhiling[10000];
		if(exten==".txt"){
			string usder=pathr+namer;
			const char *nmae2=usder.c_str(); 
			const char *nmae3=namer.c_str(); 
			sprintf(zhiling,"copy %s.txt .\\midt.txt",nmae2);
			system(zhiling);
			freopen("midt.txt","r",stdin);
			freopen("midr.txt","w",stdout);
			int nub;
			cin>>nub;
			for(int j=1;j<=nub;j++){
				double xx,yy,zz;
				cin>>xx>>yy>>zz;
				xx=xx*100+50;yy=yy*100+50;zz=zz*100+50;
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
			sprintf(zhiling,"move .\\midr.txt .\\files\\%s.txt",nmae3);
			system(zhiling);
			system("del .\\midt.txt");
			freopen("CON", "w", stdout);
			cout<<"\033c";
			//cout<<"Here is the file called "<<nmae3<<endl;
		}
		if(exten==".ply"){
			string usder=pathr+namer;
			const char *nmae2=usder.c_str(); 
			const char *nmae3=namer.c_str(); 
			sprintf(zhiling,"copy %s.ply .\\midt.txt",nmae2);
			system(zhiling);
			freopen("midt.txt","r",stdin);
			freopen("midr.txt","w",stdout);
			for(int i=1;i<=42;i++){
				string q;cin>>q;
 			}
			int nub;
			cin>>nub;
			for(int i=1;i<=18;i++){
			string q;cin>>q;
			}
			for(int j=1;j<=nub;j++){
				double xx,yy,zz;
				cin>>xx>>yy>>zz;
				xx=xx*100+50;yy=yy*100+50;zz=zz*100+50;
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
			sprintf(zhiling,"move .\\midr.txt .\\files\\%s.txt",nmae3);
			system(zhiling);
			system("del .\\midt.txt");
			freopen("CON", "w", stdout);
			cout<<"\033c";
		}
		else {
			MessageBox(NULL,"文件类型不支持","错误",MB_OK);
			return 0;
		} 
	}
	cout<<"open up files:"<<endl;
	for(int l=1;l<=nub;l++){
		cout<<df[l].gh<<endl;
	}
	Sleep(1000);
	return 0;
}

