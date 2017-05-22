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