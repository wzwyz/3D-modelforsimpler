#include<bits/stdc++.h> 
#include<windows.h>
#define MAXN 260
using namespace std;
template<typename T>	//T表示任何可以被cout输出的类型
void ColorCout_256(T t, const int ForeColor = 7, const int BackColor = 0)
{
	//ForeColor和BackColor的取值区间为[0,255]
	cout << "\033[" << "38;5;" << ForeColor << "m";
	cout << "\033[" << "48;5;" << BackColor << "m";
	cout << t << "\033[m";
}
int main(){
	ColorCout_256("+------+.      +------+       +------+       +------+      .+------+", 177, 0);cout<<endl;
	ColorCout_256("|`.    | `.    |\\     |\\      |      |      /|     /|    .' |    .'|", 177, 0);cout<<endl;
	ColorCout_256("|  `+--+---+   | +----+-+     +------+     +-+----+ |   +---+--+'  |", 177, 0);cout<<endl;
	ColorCout_256("|   |  |   |   | |    | |     |      |     | |    | |   |   |  |   |", 177, 0);cout<<endl;
	ColorCout_256("+---+--+.  |   +-+----+ |     +------+     | +----+-+   |  .+--+---+", 177, 0);cout<<endl;
	ColorCout_256(" `. |    `.|    \\|     \\|     |      |     |/     |/    |.'    | .'", 177, 0);cout<<endl;
	ColorCout_256("   `+------+     +------+     +------+     +------+     +------+'", 177, 0);cout<<endl;
	ColorCout_256("                             Simpler_3D", 30, 0);cout<<endl;
	ColorCout_256("   .+------+     +------+     +------+     +------+     +------+.", 190, 0);cout<<endl;
	ColorCout_256(" .' |    .'|    /|     /|     |      |     |\\     |\\    |`.    | `.", 190, 0);cout<<endl;
	ColorCout_256("+---+--+'  |   +-+----+ |     +------+     | +----+-+   |  `+--+---+", 190, 0);cout<<endl;
	ColorCout_256("|   |  |   |   | |    | |     |      |     | |    | |   |   |  |   |", 190, 0);cout<<endl;
	ColorCout_256("|  ,+--+---+   | +----+-+     +------+     +-+----+ |   +---+--+   |", 190, 0);cout<<endl;
	ColorCout_256("|.'    | .'    |/     |/      |      |      \\|     \\|    `. |   `. |", 190, 0);cout<<endl;
	ColorCout_256("+------+'      +------+       +------+       +------+      `+------+", 190, 0);cout<<endl;
	cout<<"What do you want to do?"<<endl;
	cout<<"you can tyre in path and name of ";
	ColorCout_256("tar.gz(Standfor origine type);ply(Standfor type);txt(Personal type)",214,0);
	cout<<"to launch your models in the dock"<<endl;
	cout<<"or you can just luanch the done ones (type in \"launch\")";
	string ans;
	cin>>ans;
	if(ans=="tar.gz")system("tar.gzreader.exe");
	else if(ans=="ply")system("plyreader.exe");
	else if(ans=="txt")system("txtreader.exe");
	else if(ans=="launch")system("Simpler3Dviewer.exe");
	
	return 0;
}
