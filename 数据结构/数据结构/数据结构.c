
//ʱ�临�Ӷ�

#include<stdio.h>
int missNum(int* nums, int numSize)
{
	//ֱ���������ֽ��м��� O(1)
	int n = numSize + 1;
	int ret1 = 0;
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		ret1 += i;
	}

	//��δ֪�����еĸ����������� O(n)
	int ret2 = 0;
	int j = 0;
	for (j = 0; j < numSize; ++j)
	{
		ret2 += nums[j];
	}

	return ret1 - ret2;//����ʱ�临�Ӷ���O��n��
}
int main()
{
	
	int i = 0;


	return 0;
}