#include"File.h"
#include<fstream>
#include<sstream>
template <class T>
T CFile::ReadFile(T x)
{
	fstream file;
	file.open(inputFilePath, ios::in);
	file >> x;
	file.close();
	return x;
}

bool CFile::JudgeIfGet()
{
	fstream file;
	stringstream ss;
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

template<class T>
void CFile::OutputFile(T x)
{
	fstream fout;
	fout.open(outputFilePath, ios::app);
	fout << x;
	fout.close();
}