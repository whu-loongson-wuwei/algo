#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<string>  func(int k){
        vector<string> result;
	if(k == 1){
	  result.emplace_back("0");
	  result.emplace_back("1");
	  return result;
	}
        vector<string> s = func(k - 1);
	string prefix = "0";
        auto f = [&](const string &str){
		result.emplace_back(prefix + str);
	};
	for_each(s.begin(),s.end(),f);
	prefix = "1";
	for_each(s.rbegin(),s.rend(),f);
	return result;
}

int main(){
  vector<string> r = func(3);
  for(const auto &s : r)
	  cout << s << endl;
}
