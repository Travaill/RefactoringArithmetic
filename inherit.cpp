#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
class Random 
{
private: 
public:
    virtual ~Random() {}
    virtual void random() = 0;   //´¿Ðéº¯Êý 

};

class RandomNum : public Random
{
private:
    int num;
public:
    virtual void random();
    int GetNum() 
	{ 
	  return num; 
	}	
};

void RandomNum::random()
{
    num = rand() % 11;
}

class RandomOperation: public Random
{
private:
    char ope;
public:
    RandomOperation(){ope='+';}
    virtual void random();
    char GetOpe() 
	{ 
	  return ope; 
	}
};

void RandomOperation::random()
{
    switch (rand() % 4)
    {
    case 0:ope = '+'; break;
    case 1:ope = '-'; break;
    case 2:ope = '*'; break;
    case 3:ope = '/'; break;
    default:
    break;
    }
}

int main()
{
	RandomNum number;
	number.random();
	cout << number.GetNum() << endl;
	RandomOperation ope;
	ope.random();
	cout << ope.GetOpe() << endl;	
    return 0;
}
