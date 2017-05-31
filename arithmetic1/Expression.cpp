#include "Expression.h"
#include <sstream>
#include <stack>
using namespace std;

void CExpression::InitExpression()   //��ʼ��
{
	RandomExpression();
	CalculateResult();
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

int CExpression::RandomNumber(int low, int high)  //����[low,high]����� 
{
	return (rand() % (high - low + 1) + low);
}

char CExpression::RandomOperation()     //������������� 
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