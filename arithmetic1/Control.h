#pragma once
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
