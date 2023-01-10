#include <cstdio>
#include <windows.h>
#include <fstream>
#include<bits/stdc++.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;
int main()
{
    int data;
	//infile>>data;//从文件读入 
	
	ofstream outfile; 
	outfile.open("output.txt");//打开写入的文件
	cout<<"zz"<<endl;
	
	outfile<<data<<endl;
	
	//infile.close();
	outfile.close();//关闭文件
    while(1){
    	HANDLE hInputd = GetStdHandle( STD_INPUT_HANDLE );
    DWORD modee;
    GetConsoleMode( hInputd, &modee );
    modee &= ~ENABLE_QUICK_EDIT_MODE;
    modee |= ENABLE_MOUSE_INPUT;
    SetConsoleMode( hInputd, modee|ENABLE_MOUSE_INPUT );
    INPUT_RECORD records;
    DWORD nl;
    	bool k=1;
        COORD cpos={},spos={};
        for( COORD pos={}; ReadConsoleInput(hInputd,&records,1,&nl) && nl==1; )
        {
		    if(records.EventType!=MOUSE_EVENT)continue;
		    COORD pos_new = records.Event.MouseEvent.dwMousePosition;
            pos = pos_new;
            if(KEY_DOWN(VK_RBUTTON)&&k==1){cpos=pos;k=0;}
		    else if(!KEY_DOWN(VK_RBUTTON)&&k==0){
		    	spos=pos;break;
		    }
        }
        cout<<spos.X-cpos.X<<' '<<spos.Y-cpos.Y<<endl;

	}
	
    return 0;
}
