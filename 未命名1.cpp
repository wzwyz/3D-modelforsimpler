#undef UNICODE
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <string> 
#include "windows.h"
#include<bits/stdc++.h>

using namespace std;
struct tyu{
	string gh;
}sdf[100];
int jl[101][101][101],jk[100][100],maxr=1,minr=100;
int main(){
	char zhiling[10000];
	char dir[100];
	GetCurrentDirectory(100,dir);
	const char *nmae2=dir;
	TCHAR szBuffer[MAX_PATH] = { 0 };
	OPENFILENAME file = { 0 };
	file.hwndOwner = NULL;
	file.lStructSize = sizeof(file);
	file.lpstrFilter = "所有文件(*.*)\0*.*\0Exe文件(*.exe)\0*.exe\0";//要选择的文件后缀 
	file.lpstrInitialDir = "";//默认的文件路径 
	file.lpstrFile = szBuffer;//存放文件的缓冲区 
	file.nMaxFile = sizeof(szBuffer) / sizeof(*szBuffer);
	file.nFilterIndex = 0;
	file.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER|OFN_ALLOWMULTISELECT;//标志如果是多选要加上OFN_ALLOWMULTISELECT
	BOOL bSel = GetOpenFileName(&file);
	//cout<< file.lpstrFile;
	string filePath = file.lpstrFile; //控制台需要用string，需要包含<string>头文件，并使用using namespace std;
	int start = filePath.find_last_of('\\'); //获取最后一个\\的索引
	int end = filePath.find_first_of('.'); //获取最后一个.的索引
	string filepath = filePath.substr(0, start+1);
	string fileName = filePath.substr(start + 1, end - start - 1);
	string exten = filePath.substr(end, filePath.length() - end);
	system("del C:\\Users\\wyz\\Documents\\ghfile.txt");
	//freopen("C:\\Users\\wyz\\Documents\\ghfile.txt","w",stdout);
	
	cout<<nmae2<<endl;
	cout<<filepath<<endl;
	cout<<fileName<<endl;
	fclose(stdout);
	//sprintf(zhiling,"%s\\plyreader.exe",nmae2);
	//system(zhiling);
	return 0; 
}
