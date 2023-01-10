#include <cstdio>
#include <windows.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
int main()
{
    
	HANDLE hInput = GetStdHandle( STD_INPUT_HANDLE );
    DWORD mode;
    GetConsoleMode( hInput, &mode );
    mode &= ~ENABLE_QUICK_EDIT_MODE;
    mode |= ENABLE_MOUSE_INPUT;
    SetConsoleMode( hInput, mode|ENABLE_MOUSE_INPUT );
    INPUT_RECORD record;
    DWORD n;
    for( COORD pos={}; ReadConsoleInput(hInput,&record,1,&n) && n==1; )
    {
        if( record.EventType != MOUSE_EVENT )
            continue;

        COORD pos_new = record.Event.MouseEvent.dwMousePosition;
        //if( pos_new.X== pos.X && pos_new.Y== pos.Y )
            //continue;
        pos = pos_new;
        if(KEY_DOWN(VK_LBUTTON)) {
			printf( "鼠标 与 起始行 的相对位置 (%hd,%hd)字符\n", pos.X, pos.Y );	
			//鼠标左键按下
		}
        
    }
}
