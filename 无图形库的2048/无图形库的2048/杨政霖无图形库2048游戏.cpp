#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<stdbool.h>
#include<graphics.h>

#define ROW 4

void GetNum(int arr[ROW][ROW])
{
	int n = 2;
	if (rand() % 5 == 0)
		n = 4;

	int row = rand() % ROW;
	int col = rand() % ROW;

	while (arr[row][col] != 0)//坐标冲突则找"下一个"
	{
		col = col + 1;
		if (col == ROW)//需要转到"下一行"的第一个
		{
			row = row + 1;//error
			if (row == ROW)//已经是最后一行,则变为第一行
				row = 0;
			col = 0;
		}
	}
	arr[row][col] = n;
}




//输出二维数组的值
void Show(int arr[ROW][ROW])
{
	system("cls");
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			printf("%-5d", arr[i][j]);
			//修改此项为画图
		}
		printf("\n");
	}
}


//开始游戏
void Start(int arr[ROW][ROW])
{
	for (int i = 0; i < 2; i++)//产生两个数字
	{
		GetNum(arr);
	}
	Show(arr);
}

//获取方向.左->1,上->2,右->3,下->4
int GetButton()
{
	int ch;
	while (1)
	{
		if (_kbhit())//有按键
		{
			ch = _getch();
			if (ch == 224)
			{
				ch = _getch();
				if (ch == 75)//左
					return 1;
				else if (ch == 72)//上
					return 2;
				else if (ch == 77)//右
					return 3;
				else if (ch == 80)//下
					return 4;
			}
		}
	}
	return -1;
}

//向左合并和移动数据
bool MergeLeft(int arr[ROW][ROW])
{
	//合并数据
	int index1;//第一个数字的下标
	int index2;//第二个数字的下标
	for (int i = 0; i < ROW; i++)
	{
		index1 = -1;//无效下标
		index2 = -1;//无效下标
		for (int j = 0; j < ROW; j++)
		{
			if (index1 == -1 && arr[i][j] != 0)//找到第一个需要的值
				index1 = j;
			else if (index2 == -1 && arr[i][j] != 0)//找到第二个需要的值
			{
				index2 = j;
				if (arr[i][index1] == arr[i][index2])//合并
				{
					arr[i][index1] *= 2;
					arr[i][index2] = 0;
				}
				else//第一个值和第二个值不同
				{
					index1 = index2;
					index2 = -1;
				}
			}
		}
	}
	//移动数据
	for (int i = 0; i < ROW; i++)
	{
		index1 = -1;
		for (int j = 0; j < ROW; j++)
		{
			if (index1 == -1 && arr[i][j] == 0)
				index1 = j;
			else if (index1 != -1 && arr[i][j] != 0)
			{
				arr[i][index1] = arr[i][j];
				arr[i][j] = 0;
				index1++;
			}
		}
	}

	return true;
}

//右
bool MergeRight(int arr[ROW][ROW])
{
	//合并数据
	int index1;//第一个数字的下标
	int index2;//第二个数字的下标
	for (int i = ROW - 1; i >= 0; i--)
	{
		index1 = -1;//无效下标
		index2 = -1;//无效下标
		for (int j = ROW - 1; j >= 0; j--)
		{
			if (index1 == -1 && arr[i][j] != 0)//找到第一个需要的值
				index1 = j;
			else if (index2 == -1 && arr[i][j] != 0)//找到第二个需要的值
			{
				index2 = j;
				if (arr[i][index1] == arr[i][index2])//合并
				{
					arr[i][index1] *= 2;
					arr[i][index2] = 0;
				}
				else//第一个值和第二个值不同
				{
					index1 = index2;
					index2 = -1;
				}
			}
		}
	}
	//移动数据
	for (int i = ROW - 1; i >= 0; i--)
	{
		index1 = -1;
		for (int j = ROW - 1; j >= 0; j--)
		{
			if (index1 == -1 && arr[i][j] == 0)
				index1 = j;
			else if (index1 != -1 && arr[i][j] != 0)
			{
				arr[i][index1] = arr[i][j];
				arr[i][j] = 0;
				index1--;
			}
		}
	}

	return true;
}

bool MergeUp(int arr[ROW][ROW])
{
	int indey1;//第一个数字的下标
	int indey2;//第二个数字的下标
	for (int j = 0; j < ROW; j++)
	{
		indey1 = -1;//无效下标
		indey2 = -1;//无效下标
		for (int i = 0; i < ROW; i++)
		{
			if (indey1 == -1 && arr[i][j] != 0)//找到第一个需要的值
				indey1 = i;
			else if (indey2 == -1 && arr[i][j] != 0)//找到第二个需要的值
			{
				indey2 = i;
				if (arr[indey1][j] == arr[indey2][j])//合并
				{
					arr[indey1][j] *= 2;
					arr[indey2][j] = 0;
				}
				else//第一个值和第二个值不同
				{
					indey1 = indey2;
					indey2 = -1;
				}
			}
		}
	}
	//移动数据
	for (int j = 0; j < ROW; j++)
	{
		indey1 = -1;
		for (int i = 0; i < ROW; i++)
		{
			if (indey1 == -1 && arr[i][j] == 0)
				indey1 = i;
			else if (indey1 != -1 && arr[i][j] != 0)
			{
				arr[indey1][j] = arr[i][j];
				arr[i][j] = 0;
				indey1++;
			}
		}
	}

	return true;
}

bool MergeDown(int arr[ROW][ROW])
{
	int indey1;//第一个数字的下标
	int indey2;//第二个数字的下标
	for (int j = ROW - 1; j >= 0; j--)
	{
		indey1 = -1;//无效下标
		indey2 = -1;//无效下标
		for (int i = ROW - 1; i >= 0; i--)
		{
			if (indey1 == -1 && arr[i][j] != 0)//找到第一个需要的值
				indey1 = i;
			else if (indey2 == -1 && arr[i][j] != 0)//找到第二个需要的值
			{
				indey2 = i;
				if (arr[indey1][j] == arr[indey2][j])//合并
				{
					arr[indey1][j] *= 2;
					arr[indey2][j] = 0;
				}
				else//第一个值和第二个值不同
				{
					indey1 = indey2;
					indey2 = -1;
				}
			}
		}
	}
	//移动数据
	for (int j = ROW - 1; j >= 0; j--)
	{
		indey1 = -1;
		for (int i = ROW - 1; i >= 0; i--)
		{
			if (indey1 == -1 && arr[i][j] == 0)
				indey1 = i;
			else if (indey1 != -1 && arr[i][j] != 0)
			{
				arr[indey1][j] = arr[i][j];
				arr[i][j] = 0;
				indey1--;
			}
		}
	}

	return true;
}

//游戏是否结束
bool IsOver(int arr[ROW][ROW])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			if (arr[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}





void Run(int arr[ROW][ROW])
{
	while (!IsOver(arr))
	{
		int n = GetButton();
		switch (n)
		{
		case 1:
			MergeLeft(arr);
			GetNum(arr);
			break;
		case 2:
			MergeUp(arr);
			GetNum(arr);
			break;
		case 3:
			MergeRight(arr);
			GetNum(arr);
			break;
		case 4:
			MergeDown(arr);
			GetNum(arr);
			break;
		default:
			break;
		}
		Show(arr);
	}
}


int main()
{

	int arr[ROW][ROW] = { 0 };
	Start(arr);
	Run(arr);


	_getch();
	closegraph();



	return 0;
}