#include <windows.h>                			//GetAsyncKeyState����ͷ�ļ�
#include <iostream>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)  //������ⰴ���ĵ���¼�

int main() {
	
	//----------�Ƴ����ٱ༭ģʽ(����win10�û�)----------
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD modet;
	GetConsoleMode(hStdin, &modet);
	modet &= ~ENABLE_QUICK_EDIT_MODE;
	SetConsoleMode(hStdin, modet);
	
	//----------ѭ�����----------
	while(1) {                      			//ѭ�����
		if(KEY_DOWN(VK_LBUTTON)) {  			//����������
			printf("key down!\n");
		}
		Sleep(20);                  			//�ȴ�20���룬����CPUռ��
	}
	
	return 0;
}

