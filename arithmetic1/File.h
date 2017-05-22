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
	
private:
	string resouceFilePath;
	string recouce[8];
};

