
//时间复杂度

#include<stdio.h>
int missNum(int* nums, int numSize)
{
	//直接运用数字进行计算 O(1)
	int n = numSize + 1;
	int ret1 = 0;
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		ret1 += i;
	}

	//对未知数组中的各数进行运算 O(n)
	int ret2 = 0;
	int j = 0;
	for (j = 0; j < numSize; ++j)
	{
		ret2 += nums[j];
	}

	return ret1 - ret2;//所以时间复杂度是O（n）
}
int main()
{
	
	int i = 0;


	return 0;
}