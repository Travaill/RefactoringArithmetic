#include "Expression.h"
#include <sstream>
#include <stack>
using namespace std;

void CExpression::InitExpression()   //初始化
{
	do
	{
		RandomExpression();
		CalculateResult();
	} while (JudgeExpression() || JudgeResult());

}

string CExpression::GetExpression()
{
	string str = exp;
	return exp;
}

int CExpression::GetResult()
{
	int num = res;
	return num;
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

void CExpression::RandomExpression()
{
	stringstream ss;
	string str[2] = { "" };
	for (int i = 0; i < 2; i++)
	{
		int mode = RandomNumber(1, 3);
		if (mode == 1)
		{
			ss << '(' << RandomNumber(1, 10) << RandomOperation() << RandomNumber(1, 10) << ')';
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

void CExpression::CalculateResult()
{
	int x = 0;
	int  num_flag = 0;
	for (int i = 0; i<exp.size(); i++)
	{
		if ((exp[i] >= '0') && (exp[i] <= '9'))
		{
			x = x * 10 + exp[i] - '0';
			num_flag = 1;
			if (i == exp.size() - 1)
				num_stk.push(x);
		}
		else {
			if (x)
			{
				num_stk.push(x);
				x = 0;
				num_flag = 0;
			}
			if (ope_stk.empty())
				ope_stk.push(exp[i]);
			else if (exp[i] == '(')
				ope_stk.push(exp[i]);
			else if (exp[i] == ')')
			{
				while (ope_stk.top() != '(')
					CalculatePolynomial();
				ope_stk.pop();
			}
			else if ((OpeRank(exp[i])) <= OpeRank(ope_stk.top()))
			{
				CalculatePolynomial();
				ope_stk.push(exp[i]);
			}
			else
			{
				ope_stk.push(exp[i]);
			}
		}
	}
	while (!ope_stk.empty())
		CalculatePolynomial();
	res = num_stk.top();
}

void CExpression::CalculatePolynomial()
{
	char ope = ope_stk.top();
	double a, b, res;
	b = num_stk.top();
	num_stk.pop();
	a = num_stk.top();
	num_stk.pop();
	switch (ope)
	{
	case '+':res = a + b; break;
	case '-':res = a - b; break;
	case '*':res = a*b; break;
	case '/':res = a / b; break;
	default: break;
	}
	num_stk.push(res);
	ope_stk.pop();
}

int CExpression::OpeRank(char x)
{
	switch (x)
	{
	case '*':
	case '/': return 3;
	case '-':
	case '+': return 2;
	case '(': return 1;
	case ')': return -2;
	default:return -1;
	}
}

bool CExpression::JudgeExpression()
{
	char ptr[35];
	strcpy_s(ptr,exp.c_str());
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
		return false;
	}
	else
	{
		return true;
	}
}

bool CExpression::JudgeResult()
{
	if ((int)res == res&&abs(res) <= 100)
	{
		return false;
	}
	else
	{
		return true;
	}
}