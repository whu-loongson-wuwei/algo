#include<iostream>
#include<vector>
#include<string>
void
mergeSort(std::vector<int>& nums,int first,int end){
	if(end - first <= 1)
		return;
	int mid = (first+end)/2;
	mergeSort(nums,first,mid);
	mergeSort(nums,mid,end);
	std::vector<int> tmp;
	int i = first;
	int j = mid;
	while(i < mid && j < end){
		if(nums[i] < nums[j])
			tmp.push_back(nums[i++]);
		else
			tmp.push_back(nums[j++]);
	}
	if(i == mid)
		while(j < end)
			tmp.push_back(nums[j++]);
	if(j == end)
		while(i < mid)
			tmp.push_back(nums[i++]);
	for(int k = first,t= 0;k<end;++k)
	nums[k] = tmp[t++];
}

int main()
{
	std::vector<int> a;
	int m;
	while(std::cin >> m)
		a.push_back(m);
	mergeSort(a,0,a.size());
	for(int n : a){
		std::cout<< n <<std::endl;
	}
	return 0;

}

