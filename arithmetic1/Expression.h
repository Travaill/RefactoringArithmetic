#pragma once
#include<string>
#include <stack>
using namespace std;
class CExpression
{
public:
	void InitExpression();
	string GetExpression();
	int GetResult();
private:
	string exp;
	double res;
	stack<double> num_stk;
	stack<char> ope_stk;
	int RandomNumber(int low, int high);
	char RandomOperation();
	void RandomExpression();
	void CalculateResult();
	void CalculatePolynomial();
	int OpeRank(char x);
	bool JudgeExpression();
	bool JudgeResult();
};

