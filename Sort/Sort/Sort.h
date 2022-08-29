#pragma

#include<stdio.h>

void PrintArray(int* a, int n);

//²åÈëÅÅĞò
void InsertSort(int* a, int n);

//Ï£¶ûÅÅĞò
void ShellSort(int* a, int n);

//Ñ¡ÔñÅÅĞò
void SelectSort(int* a, int n);
//¶ÑÅÅĞò
void AdjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);

//½»»»ÅÅĞò¡ª¡ªÃ°ÅİÅÅĞò
void BubbleSort(int* a, int n);
//¿ìÅÅ
void QuickSort(int* a, int begin, int end);
int PartSort1(int* a, int left, int right);
int PartSort2(int* a, int left, int right);
int PartSort3(int* a, int left, int right);
//·Çµİ¹é¿ìÅÅ
void QuickSortNonR(int* a, int left, int right);