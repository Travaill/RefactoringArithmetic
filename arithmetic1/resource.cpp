#include"Resource.h"
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

void CResource::SetPath(string& language)
{
	stringstream ss;
	ss << "Languagerc\\" << language << ".txt";
	resourcePath = ss.str();
	ss.str("");
}

void CResource::SetResource()
{	
	fstream File;
	File.open(resourcePath, ios::in);
	string line;
	for (int i = 0; getline(File, line); i++)
	{
		swap(line, resource[i]);
	}
	File.close();
}

bool CResource::JudgeIfGet()
{
	fstream file;
	stringstream ss;
	file.open(resourcePath, ios::in);
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


