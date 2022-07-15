#include<stdio.h>
#include<stdio.h>

int main()
{
	//时间复杂度
//int missNum(int* nums, int numSize)
//{
//	//直接运用数字进行计算 O(1)
//	int n = numSize + 1;
//	int ret1 = 0;
//	int i = 0;
//	for (i = 0; i < n; ++i)
//	{
//		ret1 += i;
//	}
//
//	//对未知数组中的各数进行运算 O(n)
//	int ret2 = 0;
//	int j = 0;
//	for (j = 0; j < numSize; ++j)
//	{
//		ret2 += nums[j];
//	}
//
//	return ret1 - ret2;//所以时间复杂度是O（n）
//}
//
//
//int missNum2(int* nums, int numSize)
//{
//	int x = 0;
//	int i = 0;
//	for (i = 0; i < numSize + 1; ++i)
//	{
//		x ^= i;//与有序的数值异或
//	}
//	for (i = 0; i < numSize; ++i)
//	{
//		x ^= nums[i];//再与缺少一个数的数组进行异或
//	}
//	return x;
//}

	//从低到高去找ret里面一个为1的位 j
	int ret = 0;
	int j = 0;
	for (j = 0; j < 32; ++j)
	{
		if (ret & (1 << j))//如果成立则是找到ret中从左往右第一个为 1 的位：j 
			break;
	}


	return 0;

}



