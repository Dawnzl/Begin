#include"Sort.h"

void TestInsertSort()
{
	int a[] = { 4,3,7,1,9,8,4,3,5 };
	InsertDort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestShellSort()
{
	int a[] = { 4,3,7,1,9,8,4,3,5 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
	TestShellSort();
	return 0;

}

