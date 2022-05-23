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

	while (arr[row][col] != 0)//�����ͻ����"��һ��"
	{
		col = col + 1;
		if (col == ROW)//��Ҫת��"��һ��"�ĵ�һ��
		{
			row = row + 1;//error
			if (row == ROW)//�Ѿ������һ��,���Ϊ��һ��
				row = 0;
			col = 0;
		}
	}
	arr[row][col] = n;
}




//�����ά�����ֵ
void Show(int arr[ROW][ROW])
{
	system("cls");
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			printf("%-5d", arr[i][j]);
			//�޸Ĵ���Ϊ��ͼ
		}
		printf("\n");
	}
}


//��ʼ��Ϸ
void Start(int arr[ROW][ROW])
{
	for (int i = 0; i < 2; i++)//������������
	{
		GetNum(arr);
	}
	Show(arr);
}

//��ȡ����.��->1,��->2,��->3,��->4
int GetButton()
{
	int ch;
	while (1)
	{
		if (_kbhit())//�а���
		{
			ch = _getch();
			if (ch == 224)
			{
				ch = _getch();
				if (ch == 75)//��
					return 1;
				else if (ch == 72)//��
					return 2;
				else if (ch == 77)//��
					return 3;
				else if (ch == 80)//��
					return 4;
			}
		}
	}
	return -1;
}

//����ϲ����ƶ�����
bool MergeLeft(int arr[ROW][ROW])
{
	//�ϲ�����
	int index1;//��һ�����ֵ��±�
	int index2;//�ڶ������ֵ��±�
	for (int i = 0; i < ROW; i++)
	{
		index1 = -1;//��Ч�±�
		index2 = -1;//��Ч�±�
		for (int j = 0; j < ROW; j++)
		{
			if (index1 == -1 && arr[i][j] != 0)//�ҵ���һ����Ҫ��ֵ
				index1 = j;
			else if (index2 == -1 && arr[i][j] != 0)//�ҵ��ڶ�����Ҫ��ֵ
			{
				index2 = j;
				if (arr[i][index1] == arr[i][index2])//�ϲ�
				{
					arr[i][index1] *= 2;
					arr[i][index2] = 0;
				}
				else//��һ��ֵ�͵ڶ���ֵ��ͬ
				{
					index1 = index2;
					index2 = -1;
				}
			}
		}
	}
	//�ƶ�����
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

//��
bool MergeRight(int arr[ROW][ROW])
{
	//�ϲ�����
	int index1;//��һ�����ֵ��±�
	int index2;//�ڶ������ֵ��±�
	for (int i = ROW - 1; i >= 0; i--)
	{
		index1 = -1;//��Ч�±�
		index2 = -1;//��Ч�±�
		for (int j = ROW - 1; j >= 0; j--)
		{
			if (index1 == -1 && arr[i][j] != 0)//�ҵ���һ����Ҫ��ֵ
				index1 = j;
			else if (index2 == -1 && arr[i][j] != 0)//�ҵ��ڶ�����Ҫ��ֵ
			{
				index2 = j;
				if (arr[i][index1] == arr[i][index2])//�ϲ�
				{
					arr[i][index1] *= 2;
					arr[i][index2] = 0;
				}
				else//��һ��ֵ�͵ڶ���ֵ��ͬ
				{
					index1 = index2;
					index2 = -1;
				}
			}
		}
	}
	//�ƶ�����
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
	int indey1;//��һ�����ֵ��±�
	int indey2;//�ڶ������ֵ��±�
	for (int j = 0; j < ROW; j++)
	{
		indey1 = -1;//��Ч�±�
		indey2 = -1;//��Ч�±�
		for (int i = 0; i < ROW; i++)
		{
			if (indey1 == -1 && arr[i][j] != 0)//�ҵ���һ����Ҫ��ֵ
				indey1 = i;
			else if (indey2 == -1 && arr[i][j] != 0)//�ҵ��ڶ�����Ҫ��ֵ
			{
				indey2 = i;
				if (arr[indey1][j] == arr[indey2][j])//�ϲ�
				{
					arr[indey1][j] *= 2;
					arr[indey2][j] = 0;
				}
				else//��һ��ֵ�͵ڶ���ֵ��ͬ
				{
					indey1 = indey2;
					indey2 = -1;
				}
			}
		}
	}
	//�ƶ�����
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
	int indey1;//��һ�����ֵ��±�
	int indey2;//�ڶ������ֵ��±�
	for (int j = ROW - 1; j >= 0; j--)
	{
		indey1 = -1;//��Ч�±�
		indey2 = -1;//��Ч�±�
		for (int i = ROW - 1; i >= 0; i--)
		{
			if (indey1 == -1 && arr[i][j] != 0)//�ҵ���һ����Ҫ��ֵ
				indey1 = i;
			else if (indey2 == -1 && arr[i][j] != 0)//�ҵ��ڶ�����Ҫ��ֵ
			{
				indey2 = i;
				if (arr[indey1][j] == arr[indey2][j])//�ϲ�
				{
					arr[indey1][j] *= 2;
					arr[indey2][j] = 0;
				}
				else//��һ��ֵ�͵ڶ���ֵ��ͬ
				{
					indey1 = indey2;
					indey2 = -1;
				}
			}
		}
	}
	//�ƶ�����
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

//��Ϸ�Ƿ����
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