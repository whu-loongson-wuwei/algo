/*************************************************************************************
  命名规范：
  文件名用小写下划线分隔
  类型名每个首字母大写
  函数名每个首字母大写但是取值和设置值得函数需要小写以下划线分割（与变量对应）
  变量命名用小写中间以下划线连接类成员变量后面加上下划线结构体不用
  命名空间用小写

  Say you have an array for which the ith element is the price of a given stock on day i.
  If you were only permitted to complete at most one transaction (ie, buy one and sell on
  e share of the stock), design an algorithm to find the maximum profit.

  f[i] denote the maximum profit until day i
then:   f[i] = max{f[i] - minValue[i],f[i-1]}
minValue[i] = min{minValue[i-1],value[i]}


 **************************************************************************************/
#include<iostream>
#include<vector>
class StockTransaction
{
	public:
		StockTransaction(std::vector<float> data,int transaction_times):
		data_(data),transaction_times_(transaction_times)
		{}
		~StockTransaction()
		{}
		void Slove()
		{
			std::vector<float> max_profit,min_value;
			std::vector<int> sail_day,min_value_day;
			int j = 0;
			while(j++ < data_.size())
			{
				max_profit.push_back(0);
				min_value.push_back(data_[0]);
				sail_day.push_back(0);
				min_value_day.push_back(0);
			}
			for(int i=1;i<data_.size();++i)
			{
				if(data_[i]<min_value[i-1])
				{
					min_value[i] = data_[i];
					min_value_day[i] = i;
				}
				else
				{
					min_value[i] = min_value[i-1];
					min_value_day[i] = min_value_day[i-1];
				}
				if( max_profit[i-1]>(data_[i]-min_value[i]))
				{
					max_profit[i] = max_profit[i-1];
					sail_day[i] = sail_day[i-1];
				}
				else
				{
					max_profit[i] = data_[i]-min_value[i];
					sail_day[i] = i;
				}
			}
			int k = data_.size() - 1;
			std::cout<<"maxmium profit:"<<max_profit[k]<<std::endl;
			for(int sail = sail_day[k];sail!=k;k=sail);
			std::cout<<"sail day:"<<k<<std::endl;
			for(int buy = min_value_day[k];buy!=k;k=buy);
			std::cout<<"buy day:"<<k<<std::endl;
		}

	private:
		std::vector<float> data_;
		int transaction_times_;

};
int main()
{
	std::vector<float> d = {3,4,5,6,2,4,9,10,15};
	(new StockTransaction(d,1))->Slove();
	return 0;
}
