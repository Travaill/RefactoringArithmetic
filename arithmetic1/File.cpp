#include"File.h"
#include<fstream>
#include<sstream>
int CFile::ReadFile()
{
	int counts;
	fstream file;
	file.open(inputFilePath, ios::in);
	file >> counts;
	file.close();
	return counts;
}

bool CFile::JudgeIfGet()
{
	fstream file;
	stringstream ss;
	char filepath[200] = "";
	file.open(inputFilePath,ios::in);
	if (file.is_open())
	{
		file.close();
		return true;
	}
	else
	{
		return false;
	}
}
