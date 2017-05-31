#pragma once
#include<string>
#include"File.h"
using namespace std;
class CControl
{
public:
	bool JudgeExpression(string str);
	bool JudgeResult(double res);
	bool GetKeyAndExit();
	void StatisticalResult(int &number, CExpression& , CResource & );
private:
	int wrong;
	int right;
};
