#pragma

#include<stdio.h>

void PrintArray(int* a, int n);

//��������
void InsertSort(int* a, int n);

//ϣ������
void ShellSort(int* a, int n);

//ѡ������
void SelectSort(int* a, int n);
//������
void AdjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);

//�������򡪡�ð������
void BubbleSort(int* a, int n);
//����
void QuickSort(int* a, int begin, int end);
int PartSort1(int* a, int left, int right);
int PartSort2(int* a, int left, int right);
int PartSort3(int* a, int left, int right);
//�ǵݹ����
void QuickSortNonR(int* a, int left, int right);