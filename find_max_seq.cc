#include<iostream>
#include<vector>
using namespace std;
class FindMaxSeq{
	public:
		virtual find(const vector<int>&) = 0;
};
class F1:public FindMaxSeq{
	public:
		virtual find(const vector<int>&){
		}
};
int main()
{
	FindMaxSeq *f = new F1;

	return 0;
}
