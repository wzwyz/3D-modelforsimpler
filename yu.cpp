#include<bits/stdc++.h> 
#include<windows.h>
#define MAXN 260
using namespace std;
int main(){
	freopen("ghfile.homo","r",stdin);
	freopen("deft.homo","w",stdout);
	string b;
	cin>>b;
	int num=0;
	for(int i=0;i<=b.size()-1;i++){
		if(b[i]=='*'){
			num++;
		}
	}
	cout<<num/3<<endl;
	for(int i=0;i<=b.size()-1;i++){
		if(b[i]=='*'){
			cout<<endl;
			i=i+2;
		}
		else cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
