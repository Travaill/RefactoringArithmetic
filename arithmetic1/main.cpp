#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<string>
#include"Expression.h"
#include"File.h"
#include"Resource.h"
using namespace std;
int main(int argc, char *argv[])
{
	srand((unsigned)time(NULL));
	CFile file(argv[1], argv[2]);
	CResource resource;
	string language;
	do
	{		
		cin >> language;
	} while (!resource.JudgeIfGet());
	resource.SetPath(language);
	resource.SetResource();
	int counts = 0;
	file.ReadFile(counts);
	CExpression exp;
	for (int i = 0; i < counts; i++)
	{
		exp.InitExpression();
		cout << exp.GetExpression() << "=" << exp.GetResult() << endl;
	}
	system("pause");
	return 0;
}