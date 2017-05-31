#include"Control.h"
#include"Expression.h"
#include"File.h"
#include<string>
#include<iostream>
using namespace std;

bool CControl::JudgeExpression(string str)  //生成的算式是否合法
{
	char ptr[35];
	strcpy_s(ptr, str.c_str());
	const char *substr[] = { "/0" ,"/(1-1)","/(2-2)","/(3-3)","/(4-4)","/(5-5)","/(6-6)","/(7-7)","/(8-8)","/(9-9)","/(10-10)" };
	char *s;
	for (int i = 0; i <= 10; i++)
	{
		s = strstr(ptr, substr[i]);
		if (s != NULL)
		{
			break;
		}
	}
	if (s == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

bool CControl::JudgeResult(double res)  //判断结果是否符合要求以及是否绝对值小于100
{
	if ((int)res == res&&abs(res) <= 100)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

bool CControl::GetKeyAndExit()
{
	char c;
	c = getchar();
	if (c == 'E' || c == 'e')  //当输入y时退出，不区分大小写。
	{
		return false;
 	}
	else
	{
		return true;
	}
}

void CControl::StatisticalResult(int &number,CExpression& e,CResource & r)
{
	if (number == e.GetResult())
	{
		cout << r.resource[3] << endl;
		Printf().FilePrint(filePath, Resource[3]);
		Printf().FilePrint(filePath, "\n");
		right++;
	}
	else
	{
		cout << Resource[4] << res << endl;
		Printf().FilePrint(filePath, Resource[4]);
		Printf().FilePrint(filePath, res);
		Printf().FilePrint(filePath, "\n");
		wrong++;
	}
}