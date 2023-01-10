#include <windows.h>                			//GetAsyncKeyState所需头文件
#include <iostream>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)  //用来检测按键的点击事件

int main() {
	
	//----------移除快速编辑模式(对于win10用户)----------
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD modet;
	GetConsoleMode(hStdin, &modet);
	modet &= ~ENABLE_QUICK_EDIT_MODE;
	SetConsoleMode(hStdin, modet);
	
	//----------循环检测----------
	while(1) {                      			//循环检测
		if(KEY_DOWN(VK_LBUTTON)) {  			//鼠标左键按下
			printf("key down!\n");
		}
		Sleep(20);                  			//等待20毫秒，减少CPU占用
	}
	
	return 0;
}

