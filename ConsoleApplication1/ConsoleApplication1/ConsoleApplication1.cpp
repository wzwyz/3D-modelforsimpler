// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

// ChooseFiles.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
#include <string>
#include <windows.h>
#include <tchar.h>
#include<stdio.h>
#include <ShlObj.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <io.h>
#include "shlobj.h"


using namespace std;

/*
TCHAR*转char*
*/
 
char* LPWSTR2LPSTR(LPWSTR lpwszStrIn)
{
    LPSTR pszOut = NULL;
    if (lpwszStrIn != NULL) {
        int nInputStrLen = wcslen(lpwszStrIn);
        int nOutputStrLen = WideCharToMultiByte(CP_ACP, 0, lpwszStrIn, nInputStrLen, NULL, 0, 0, 0) + 2;
        pszOut = new char[nOutputStrLen];
        if (pszOut != NULL) {
            memset(pszOut, 0x00, nOutputStrLen);
            WideCharToMultiByte(CP_ACP, 0, lpwszStrIn, nInputStrLen, pszOut, nOutputStrLen, 0, 0);
        }
    }
    return  pszOut;
}

char* chooseFiles() {

    OPENFILENAME ofn;
    TCHAR szOpenFileNames[80 * MAX_PATH] = { 0 };
    TCHAR szPath[MAX_PATH];
    TCHAR szFileName[80 * MAX_PATH];

    int nLen = 0;
    TCHAR* p = NULL;
    ZeroMemory(&ofn, sizeof(ofn));

    // 结构体大小
    ofn.lStructSize = sizeof(ofn);

    // 拥有着窗口句柄
    ofn.hwndOwner = NULL;

    // 接收返回的文件名，注意第一个字符需要为NULL
    ofn.lpstrFile = szOpenFileNames;

    // 缓冲区长度
    ofn.nMaxFile = sizeof(szOpenFileNames);

    // _T可替换为TEXT，使用_T需要引tchar.h
    ofn.lpstrFile[0] = _T('\0');

    // 设置过滤
    ofn.lpstrFilter = _T(".ply\0*.ply\0.txt\0*.txt\0\0");

    // 过滤器索引
    ofn.nFilterIndex = 1;

    // 窗口标题
    ofn.lpstrTitle = _T("请选择文件");

    // 文件必须存在、允许多选、隐藏只读选项、对话框使用资源管理器风格的用户界面
    // 官方文档：https://docs.microsoft.com/en-us/windows/win32/api/commdlg/ns-commdlg-openfilenamea
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_ALLOWMULTISELECT | OFN_HIDEREADONLY | OFN_EXPLORER;

    // 如果打开文件失败，则不操作
    if (!::GetOpenFileName(&ofn)) {
        return new char[0];
    }

    // 把第一个文件名前的复制到szPath,即:  
    // 如果只选了一个文件,就复制到最后一个'/'  
    // 如果选了多个文件,就复制到第一个NULL字符  
    lstrcpyn(szPath, szOpenFileNames, ofn.nFileOffset);

    // 当只选了一个文件时,下面这个NULL字符是必需的.  
    // 这里不区别对待选了一个和多个文件的情况
    szPath[ofn.nFileOffset] = '\0';
    nLen = lstrlen(szPath);

    // 如果选了多个文件,则必须加上'//'  
    if (szPath[nLen - 1] != '\\') {
        lstrcat(szPath, _T("\\"));
    }

    // 把指针移到第一个文件  
    p = szOpenFileNames + ofn.nFileOffset;

    // 对szFileName进行清零
    ZeroMemory(szFileName, sizeof(szFileName));

    // 定义字符串，用于拼接所选的所有文件的完整路径
    string str = "";

    while (*p) {
        // 读取文件名
        string fileName = LPWSTR2LPSTR(p);

        // 读取文件所在文件夹路径
        string filePath = LPWSTR2LPSTR(szPath);

        // 拼接文件完整路径
        string completePath = filePath + fileName;

        // 拼接字符串
        str += completePath + "***";

        //移至下一个文件
        p += lstrlen(p) + 1;
    }

    // 将string转为char*
    char* strc = new char[strlen(str.c_str()) + 1];
    const char* cc = str.c_str();
    strcpy_s(strc, str.size() + 1, cc);

    return strc;
}
int main() {
    FILE* stream1;
    freopen_s(&stream1,"ghfile.homo", "w", stdout);
    cout << chooseFiles();
    fclose(stdout);
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
