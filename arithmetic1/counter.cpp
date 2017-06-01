#include"Control.h"
#include"Expression.h"
#include"File.h"
#include"COUNTER.h"
#include<string>
#include<iostream>
using namespace std;


bool CCounter::GetKeyAndExit()
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

void CCounter::StaResult(double number,double answer)
{
	if (number == answer)
	{
		right++;
	}
	else
	{
		wrong++;
	}
}