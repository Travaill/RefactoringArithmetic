# 2017《面向对象程序设计》课程作业五

github连接：https://github.com/Travaill/RefactoringArithmetic.git

###一、一个有待修改的类图

![未命名文件](C:\Users\Administrator\Desktop\未命名文件.png)

### 二、程序功能

> - 能对0--10之间的整数进行四则运算(加减乘除)
> - 能实现选择中文,英文,德语法语,日语五种语言
> - 程序能接收用户输入的整数答案，并判断对错
> - 程序结束时，统计出答对、答错的题目数量

### 三、代码规范

- 函数的命名必须使用英文单词,不使用拼音缩写
- 函数的命名如果一个单词的必须首字母大写,如果多个单词的用下划线隔开
- 程序结构清析，简单易懂，单个函数的程序行数不得超过100行。
- 要随意定义全局变量，尽量使用局部变量。
- 函数的旁边必须注释上本函数的功能
- 禁止GOTO语句。
- 源文件头部应进行注释，列出：生成日期、作者、模块目的/功能等。

> 示例：  
>
> 示例：  
>
> 示例：  
> 下面这段源文件的头注释比较标准，可以不局限于此格式，但上述信息要包含在内。    
>
> 示例：  
>
> 示例：  
> 下面这段源文件的头注释比较标准，可以不局限于此格式，但上述信息要包含在内。    
>
> 示例：  
> 下面这段源文件的头注释比较标准，可以不局限于此格式，但上述信息要包含在内。    
> 说明：Description一项描述本文件的内容、功能、内部各部分之间的关系及本文件与其它文件关系等。
>
>   /************************************************************   
>
> FileName: test.cpp    
>
> Author:        
>
> Version :          
>
> Date:   
>
> Description:     // 模块描述         
>
> Version:         // 版本信息    
>
> Function List:   // 主要函数及其功能     
>
> 1. -------    
>
> History:         // 历史修改记录        
>
> < author >  < time >   < version >   < desc >        
>
> ​ David      96/10/12     1.0     build this moudle   ***********************************************************/
>
>     History是修改历史记录列表，每条修改记录应包括修改日期、修改者及修改内容简述。

- 函数头部应进行注释，列出：函数的目的/功能、输入参数、输出参数、返回值等

> 示例:
>
> /*************************************************   
>
> Description:    // 函数功能、性能等的描述    
>
> Input:          // 输入参数说明，包括每个参数的作                  用、取值说明及参数间关系。   
>
> Output:         // 对输出参数的说明。   
>
> Return:         // 函数返回值的说明   
>
> Other          // 其它说明  
>
> *************************************************/

- 函数名以大写字母开头，采用谓宾结构（动名），且应反映函数执行什么

操作以及返回什么内容。

- 类、结构、联合、枚举的命名须分别以C、S、U、E开头，其他部分遵从一般变量命名规范。

### 四、代码展示

> 类Expression

~~~ c++
#include<string>
using namespace std;
class CExpression
{
public:
	void InitExpression();
	void GetExpression(string &str);
	friend bool JudgeExpression(string str);
	friend bool JudgeResult(double res);
private:
	string exp;
	double res;
	int RandomNumber(int low, int high);
	char RandomOperation();
	double CalculateResult(string str);
	void CalculatePolynomial();
	int OpeRank(char x);
};
~~~

> 类Control

~~~c++
#include<string>
using namespace std;
class CControl
{
public:
	bool JudgeExpression(string str);
	bool JudgeResult(double res);
	bool GetKeyAndExit();
	void StatisticalResult();
private:
	int wrong;
	int right;
};
~~~

> 类File

~~~ c++
#include<string>
using namespace std;
class CFile
{
public:
	int  ReadFile();
	bool JudgeIfGet();
	void OutputFile();
private:
	string inputFilePath;
	string outputFilePath;
};
~~~

> 类File的派生类 Resouce

~~~c++
class CResource:public CFile
{
public:
	
private:
	string resouceFilePath;
	string recouce[8];
};

~~~



## 已经实现了生成表达式的功能

~~~c++
#include<string>
using namespace std;
class CExpression
{
public:
	void InitExpression();
	void GetExpression(string &str);
	friend bool JudgeExpression(string str);
	friend bool JudgeResult(double res);
private:
	string exp;
	double res;
	int RandomNumber(int low, int high);
	char RandomOperation();
~~~

~~~c++
#include"Expression.h"
#include<sstream>

void CExpression::GetExpression(string &str)
{
	str = exp;
}
int CExpression::RandomNumber(int low, int high)  //生成[low,high]随机数 
{
	return (rand() % (high - low + 1) + low);
}

char CExpression::RandomOperation()     //生成四则运算符 
{
	char ope;
	switch (RandomNumber(1,4))
	{
	case 1:ope = '+'; break;
	case 2:ope = '-'; break;
	case 3:ope = '*'; break;
	case 4:ope = '/'; break;
	}
	return ope;
}

void CExpression::InitExpression()
{
	stringstream ss;
	string str[2] = { "" };
	for (int i = 0; i < 2; i++)
	{
		int mode = RandomNumber(1, 3);
		if (mode == 1)
		{
			ss << '(' << RandomNumber(1,10) << RandomOperation() <<RandomNumber(1,10) << ')';
		}
		if (mode == 2)
		{
			ss << RandomNumber(1, 10) << RandomOperation() << RandomNumber(1, 10);
		}
		if (mode == 3)
		{
			ss << RandomNumber(1, 10);
		}
		str[i] = ss.str();
		ss.str("");
	}
	ss << str[0] << RandomOperation() << str[1];
	string str1 = ss.str();
	ss.str("");
	exp = str1;
}
~~~

~~~c++
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<string>
#include"Expression.h"
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	CExpression obj;
	obj.InitExpression();
	string exp;
	obj.GetExpression(exp);
	cout << exp<<endl;
	system("pause");
	return 0;
}
~~~



### 五、提交日志证明

![QQ截图20170522233421](C:\Users\Administrator\Desktop\QQ截图20170522233421.png)

### 六、程序测试

![QQ截图20170522173116](C:\Users\Administrator\Desktop\QQ截图20170522173116.png)

### 七、个人感受

本次作业进行完全的代码重构，暂时只重构了一个生成表达式的部分，想先请教一下老师和YC学长，这样重构是否符合面对对象的思想。后续会逐渐完成其他部分的重构。

### 八、对栈知识的探索

要使用标准库的栈和队列，首先得添加头文件

\#include < stack >

定义栈：

stack< int >  curStack;

栈的操作：

curStack.empty()　　　　　　如果栈为空返回true，否则返回false；

curStack.size()　　　　　　　 返回栈内元素的大小；

curStack.pop()　　　　　　　从栈顶弹出一个成员；

curStack.push()　　　　　　 向栈内压入一个成员；

curStack.top()　　　　　　   返回栈顶，但不删除成员；

