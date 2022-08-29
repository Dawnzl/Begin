#include"Sort.h"

void TestInsertSort()
{
	int a[] = { 4,3,7,1,9,8,4,3,5 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestShellSort()
{
	int a[] = { 4,3,7,1,9,8,4,3,5 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestQuickSort()
{
	int a[] = { 4,3,7,1,9,8,4,3,5 };
	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
	TestQuickSort();
	return 0;

}

