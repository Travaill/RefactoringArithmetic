#pragma once
#include<string>
using namespace std;
class CFile
{
public:
	int  ReadFile();
	bool JudgeIfGet();
	void OutputFile();
private:
	string inputFilePath; 
	string outputFilePath;
};
 
class CResource:public CFile
{
public:
	string resouceFilePath;
	string resource[8];
private:

};

