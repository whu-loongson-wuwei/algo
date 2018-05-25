#include<vector>
#include<list>
#include<iostream>
int main(){
  std::vector<int> a{1,2};
  std::cout<<sizeof a <<a.size()<<a.capacity()<<std::endl;
  return 0;
}
