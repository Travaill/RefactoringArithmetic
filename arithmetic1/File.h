#pragma once
#include<string>
using namespace std;
class CFile
{
public:
	template<class T>
	T  ReadFile(T x);
	template<class T>
	void OutputFile(T x);
	bool JudgeIfGet();
	CFile(char *input,char* output)
	{
		inputFilePath = input;
		outputFilePath = output;
	}
private:
	char* inputFilePath; 
	char* outputFilePath;
};
 


