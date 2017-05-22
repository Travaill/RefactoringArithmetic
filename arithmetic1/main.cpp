#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<string>
#include"Expression.h"
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	CExpression obj;
	obj.InitExpression();
	string exp;
	obj.GetExpression(exp);
	cout << exp<<endl;
	system("pause");
	return 0;
}