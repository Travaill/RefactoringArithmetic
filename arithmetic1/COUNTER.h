#pragma once
#include<string>
#include"File.h"
#include"Expression.h"
using namespace std;
class CCounter
{
public:
	bool GetKeyAndExit();
	void StaResult(double number, double answer);
private:
	int wrong;
	int right;
};
