#pragma once
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

