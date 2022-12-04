#include<bits/stdc++.h> 
#include<string>
#include<windows.h>
#define MAXN 30 
using namespace std;
int jl[100][100][100],jk[100][100],maxr=1,minr=100,t;
string to_string(int n){
	ostringstream stream;
	stream<<n; 
	return stream.str();
}
int equasd(int sdi,double c1,double c2,double c3,int sdf,int sdp){
	double f[]={0,cos(2*3.14159*sdi/MAXN),0,sin(2*3.14159*sdi/MAXN),0,1,0,-sin(2*3.14159*sdi/MAXN),0,cos(2*3.14159*sdi/MAXN)};
	double d[]={0,cos(2*3.14159*sdf/MAXN),sin(2*3.14159*sdf/MAXN),0,-sin(2*3.14159*sdf/MAXN),cos(2*3.14159*sdf/MAXN),0,0,0,1};
	double b[]={0,1,0,0,0,cos(2*3.14159*sdp/MAXN),sin(2*3.14159*sdp/MAXN),0,-sin(2*3.14159*sdp/MAXN),cos(2*3.14159*sdp/MAXN)};
	double u[]={0,c1,c2,c3};
	double c[3];
    c[1]=u[1]*f[1]+u[2]*f[2]+u[3]*f[3];
    c[2]=u[1]*f[4]+u[2]*f[5]+u[3]*f[6];
    c[3]=u[1]*f[7]+u[2]*f[8]+u[3]*f[9];
	double o[3];
	o[1]=c[1]*d[1]+c[2]*d[2]+c[3]*d[3];
    o[2]=c[1]*d[4]+c[2]*d[5]+c[3]*d[6];
    o[3]=c[1]*d[7]+c[2]*d[8]+c[3]*d[9];
    double e[3];
	e[1]=o[1]*b[1]+o[2]*b[2]+o[3]*b[3];
    e[2]=o[1]*b[4]+o[2]*b[5]+o[3]*b[6];
    e[3]=o[1]*b[7]+o[2]*b[8]+o[3]*b[9];
	jl[(int)e[1]+50][(int)e[2]+50][-(int)e[3]+50]=1;
	//cout<<f[1]<<" "<<f[3]<<" "<<f[7]<<" "<<f[9]<<" "<<u[1]<<" "<<u[2]<<" ";
	//cout<<c[1]<<" "<<c[2]<<" "<<c[3]<<" "<<endl;
}
using namespace std;

//绝对值符号个数的奇偶性
enum ABS_ODEVITY {
	ABS_ODD = 1,
	ABS_EVEN = 2,
};

//算术符号优先权等级
enum PRIO_LV {
	PRIO_LV0 = 0,
	PRIO_LV1 = 1,
	PRIO_LV2 = 2,
	PRIO_LV3 = 3,
	PRIO_LV4 = 4,
};

//计算器类
class Calculator
{
public:
	Calculator();
	void getFormat();					//表达式自定义标准格式化
	int getPrior(char c);				//获取算术符号优先级
	void getPostfix();					//后缀表达式转换
	void calResult();					//计算结果
	void calculate();					//计算方法
	double getResult();					//获取结果

	string operatorSym;					//运算符号
	string infix;						//表达式缓存

private:
	vector<string> postfix;				//后缀表达式向量
	stack<char> symStack;				//符号栈
	stack<double> figStack;				//数字栈
	string stdInfix;					//自定义标准格式化表达式
	double result;						//最终计算结果
};


Calculator::Calculator() {				//构造函数，初始化成员变量

	operatorSym = "支持运算符：+, - , *, /, %（百分号）, ^（幂次方）, | |（绝对值），！（阶乘）,c,s,t。其他符号：( ) [ ] { }";
	result = 0.0;
}


//表达式自定义标准格式化
void Calculator::getFormat() {

	stdInfix = infix;

	//实现正负数
	//for (int i = 0; i < stdInfix.length(); i++) {					//string下标调用运算符时可能会导致类型溢出
	for (size_t i = 0; i < stdInfix.size(); i++) {					//string.size()返回size_type类型，避免下标运算时的类型溢出
		if (stdInfix[i] == '-' || stdInfix[i] == '+') {				//-x转换为0-x，+x转化为0+x
			if (i == 0) {
				stdInfix.insert(0, 1, '0');
			}
			else if (stdInfix[i - 1] == '(') {
				stdInfix.insert(i, 1, '0');
			}
		}
	}
}

//获取算术符号优先级
int Calculator::getPrior(char c) {

	if (c == '+' || c == '-') {
		return PRIO_LV1;
	}
	else if (c == '*' || c == '/') {
		return PRIO_LV2;
	}
	else if (c == '%' || c == '^') {
		return PRIO_LV3;
	}
	else if (c == '!'||c=='T'||c=='C'||c=='S') {
		return PRIO_LV4;
	}
	else {
		return PRIO_LV0;
	}
	//else { cout << c << 非法符号！ << endl; }
}

//后缀表达式转换
void Calculator::getPostfix() {

	int absNumeber = ABS_ODD;				//绝对值符号个数的奇偶性
	string tmp;

	//for (int i = 0; i < stdInfix.length(); i++) {
	for (size_t i = 0; i < stdInfix.size(); i++) {					//string.size()返回size_type类型，避免下标运算时的类型溢出
		tmp = "";
		switch (stdInfix[i]) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '^':
		case '!':
			if (symStack.empty() || symStack.top() == '(' || symStack.top() == '[' || symStack.top() == '{' || (symStack.top() == '|' && absNumeber == ABS_ODD)) {
				symStack.push(stdInfix[i]);
			}
			else {
				while (!symStack.empty() && (getPrior(symStack.top()) >= getPrior(stdInfix[i]))) {
					tmp += symStack.top();
					postfix.push_back(tmp);
					symStack.pop();
					tmp = "";
				}
				symStack.push(stdInfix[i]);
			}
			break;
		case 'T':
			if (symStack.empty() || symStack.top() == '(' || symStack.top() == '[' || symStack.top() == '{' || (symStack.top() == '|' && absNumeber == ABS_ODD)) {
				symStack.push(stdInfix[i]);
			}
			else {
				while (!symStack.empty() && (getPrior(symStack.top()) >= getPrior(stdInfix[i]))) {
					tmp += symStack.top();
					postfix.push_back(tmp);
					symStack.pop();
					tmp = "";
				}
				symStack.push(stdInfix[i]);
			}
			break;
		case 'S':
			if (symStack.empty() || symStack.top() == '(' || symStack.top() == '[' || symStack.top() == '{' || (symStack.top() == '|' && absNumeber == ABS_ODD)) {
				symStack.push(stdInfix[i]);
			}
			else {
				while (!symStack.empty() && (getPrior(symStack.top()) >= getPrior(stdInfix[i]))) {
					tmp += symStack.top();
					postfix.push_back(tmp);
					symStack.pop();
					tmp = "";
				}
				symStack.push(stdInfix[i]);
			}
			break;
		case 'C':
			if (symStack.empty() || symStack.top() == '(' || symStack.top() == '[' || symStack.top() == '{' || (symStack.top() == '|' && absNumeber == ABS_ODD)) {
				symStack.push(stdInfix[i]);
			}
			else {
				while (!symStack.empty() && (getPrior(symStack.top()) >= getPrior(stdInfix[i]))) {
					tmp += symStack.top();
					postfix.push_back(tmp);
					symStack.pop();
					tmp = "";
				}
				symStack.push(stdInfix[i]);
			}
			break;
		case '|':
			if (absNumeber == ABS_ODD) {
				symStack.push(stdInfix[i]);
				absNumeber = ABS_EVEN;
			}
			else{
				while (!symStack.empty() && symStack.top() != '|') {
					tmp += symStack.top();
					postfix.push_back(tmp);
					symStack.pop();
					tmp = "";
				}
				if (!symStack.empty() && symStack.top() == '|') {
					tmp += symStack.top();
					postfix.push_back(tmp);						//左绝对值符号'|'加入后缀表达式，用于绝对值的检测计算
					symStack.pop();
					absNumeber = ABS_ODD;
				}
			}
			break;
		case '(':
		case '[':
		case '{':
			symStack.push(stdInfix[i]);
			break;
		case ')':
			while (!symStack.empty() && symStack.top() != '(') {
				tmp += symStack.top();
				postfix.push_back(tmp);
				symStack.pop();
				tmp = "";
			}
			if (!symStack.empty() && symStack.top() == '(') {
				symStack.pop();							//将左括号出栈丢弃
			}
			break;
		case ']':
			while (!symStack.empty() && symStack.top() != '[') {
				tmp += symStack.top();
				postfix.push_back(tmp);
				symStack.pop();
				tmp = "";
			}
			if (!symStack.empty() && symStack.top() == '[') {
				symStack.pop();							//将左括号出栈丢弃
			}
			break;
		case '}':
			while (!symStack.empty() && symStack.top() != '{') {
				tmp += symStack.top();
				postfix.push_back(tmp);
				symStack.pop();
				tmp = "";
			}
			if (!symStack.empty() && symStack.top() == '{') {
				symStack.pop();							//将左括号出栈丢弃
			}
			break;
		default:
			if ((stdInfix[i] >= '0' && stdInfix[i] <= '9')) {
				tmp += stdInfix[i];
				while (i + 1 < stdInfix.length() && (stdInfix[i + 1] >= '0' && stdInfix[i + 1] <= '9' || stdInfix[i + 1] == '.')) {		//小数处理

					tmp += stdInfix[i + 1];			//是连续的数字，则追加
					i++;
				}
				if (tmp[tmp.length() - 1] == '.') {
					tmp += '0';						//将x.做x.0处理
				}
				postfix.push_back(tmp);
			}
			break;
		}//end switch
	}//end for

	//if(!symStack.empty()) {
	while (!symStack.empty()) {						//将栈中剩余符号加入后缀表达式
		tmp = "";
		tmp += symStack.top();
		postfix.push_back(tmp);
		symStack.pop();
	}
}

//获取运算结果
void Calculator::calResult() {

	string tmp;
	double number = 0;
	double op1 = 0, op2 = 0;

	for (int i = 0; i < postfix.size(); i++) {
		tmp = postfix[i];
		if (tmp[0] >= '0' && tmp[0] <= '9') {
			number = atof(tmp.c_str());
			figStack.push(number);
		}
		else if (postfix[i] == "+") {
			if (!figStack.empty()) {
				op2 = figStack.top();
				figStack.pop();
			}
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			figStack.push(op1 + op2);
		}
		else if (postfix[i] == "-") {
			if (!figStack.empty()) {
				op2 = figStack.top();
				figStack.pop();
			}
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			figStack.push(op1 - op2);
		}
		else if (postfix[i] == "*") {
			if (!figStack.empty()) {
				op2 = figStack.top();
				figStack.pop();
			}
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			figStack.push(op1* op2);
		}
		else if (postfix[i] == "/") {
			if (!figStack.empty()) {
				op2 = figStack.top();
				figStack.pop();
			}
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop(); 
			}
			if (op2 != 0) {
				///除数不为0，未做处理，默认
			}
			figStack.push(op1 / op2);
		}
		else if (postfix[i] == "%") {
			if (!figStack.empty()) {
				op2 = figStack.top();
				figStack.pop();
			}
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			figStack.push(fmod(op1, op2));			//可进行小数求余
		}
		else if (postfix[i] == "^") {
			if (!figStack.empty()) {
				op2 = figStack.top();
				figStack.pop();
			}
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			figStack.push(pow(op1, op2));
		}
		else if (postfix[i] == "|") {
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			figStack.push(abs(op1));
		}
		else if (postfix[i] == "!") {
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			if (op1 > 0) {
				//阶乘数应大于；为小数时(转化为整数求阶)
				double factorial = 1;
				for (int i = 1; i <= op1; ++i)
				{
					factorial *= i;
				}
				op1 = factorial;
			}
			figStack.push(op1);
		}
		else if (postfix[i] == "C") {
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			figStack.push(cos(2*3.14159*op1/MAXN));
		}
		else if (postfix[i] == "S") {
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			figStack.push(sin(2*3.14159*op1/MAXN));
		}
		else if (postfix[i] == "T") {
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			figStack.push(tan(2*3.14159*op1/MAXN));
		}
	}//end for
	if (!figStack.empty()) {
		result = figStack.top();
	}
}

//计算方法
void Calculator::calculate() {

	getFormat();				//表达式自定义标准格式化
	getPostfix();				//后缀表达式转换
	calResult();				//获取算术结果
}

//获取结果
double Calculator::getResult() {
	return result;
}

int main(){
	POINT p;
	Calculator cal;
	string xx,yy,zz;
	int al,bl,cl;
	cin>>xx>>al>>yy>>bl>>zz>>cl;
	while(1){
	GetCursorPos(&p);
	memset(jl,0,sizeof(jl));
	cout<<"fuct"; 
	for(int i=1;i<=MAXN;i++){
		for(int j=1;j<=MAXN;j++){
			string gx=xx;cal.infix.assign(gx.insert(al,to_string(j)));cal.calculate();double cc1=cal.getResult();
			string gy=yy;cal.infix.assign(gy.insert(bl,to_string(j)));cal.calculate();double cc2=cal.getResult();
			string gz=zz;cal.infix.assign(gz.insert(cl,to_string(j)));cal.calculate();double cc3=cal.getResult();
			equasd(i,cc1,cc2,cc3,MAXN*p.x/1679,MAXN*p.y/1119);
			//cout<<gx<<" "<<gy<<" "<<gz<<" ";
			//cout<<cc1<<" "<<cc2<<" "<<cc3<<" "<<endl;
		}
	}
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			int g=0;
			for(int v=1;v<=100;v++){
				if(jl[i][v][j]==1){
					g=v;
					break;
				}
			}
			jk[i][j]=g;
			if(maxr<g&&j<=99&&i<=99)maxr=g;
			if(minr>g&&g!=0)minr=g;
		}
	}
	system("cls");
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			if(jk[i][j]==0)cout<<"  ";
			else if(jk[i][j]>minr+(maxr-minr)*3/5&&jk[i][j]<=maxr)cout<<"口";
			else if(jk[i][j]>minr+(maxr-minr)*2/10&&jk[i][j]<=minr+(maxr-minr)*3/5)cout<<"回";
			else if(jk[i][j]>minr+(maxr-minr)/10&&jk[i][j]<=minr+(maxr-minr)*3/10)cout<<"荄";
			else if(jk[i][j]<=minr+(maxr-minr)/10)cout<<"鑻";
			//else cout<<"**";
			//else cout<<jk[i][j];
		}
		cout<<endl;
	}
	Sleep(10);
	
}
	
	return 0;
}
