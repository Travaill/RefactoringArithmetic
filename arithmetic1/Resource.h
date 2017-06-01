#include<string>
#include<fstream>
using namespace std;
#define N 8
class CResource
{
public:
	void SetResource();
	void SetPath(string&);
	bool JudgeIfGet();
private:
	string resourcePath;
	string resource[N];
};