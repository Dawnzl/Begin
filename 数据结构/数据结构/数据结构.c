#include<stdio.h>
#include<stdio.h>

int main()
{
	//ʱ�临�Ӷ�
//int missNum(int* nums, int numSize)
//{
//	//ֱ���������ֽ��м��� O(1)
//	int n = numSize + 1;
//	int ret1 = 0;
//	int i = 0;
//	for (i = 0; i < n; ++i)
//	{
//		ret1 += i;
//	}
//
//	//��δ֪�����еĸ����������� O(n)
//	int ret2 = 0;
//	int j = 0;
//	for (j = 0; j < numSize; ++j)
//	{
//		ret2 += nums[j];
//	}
//
//	return ret1 - ret2;//����ʱ�临�Ӷ���O��n��
//}
//
//
//int missNum2(int* nums, int numSize)
//{
//	int x = 0;
//	int i = 0;
//	for (i = 0; i < numSize + 1; ++i)
//	{
//		x ^= i;//���������ֵ���
//	}
//	for (i = 0; i < numSize; ++i)
//	{
//		x ^= nums[i];//����ȱ��һ����������������
//	}
//	return x;
//}

	//�ӵ͵���ȥ��ret����һ��Ϊ1��λ j
	int ret = 0;
	int j = 0;
	for (j = 0; j < 32; ++j)
	{
		if (ret & (1 << j))//������������ҵ�ret�д������ҵ�һ��Ϊ 1 ��λ��j 
			break;
	}


	return 0;

}



