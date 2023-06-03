#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>


void AdjustDown(int* a, int n, int child);

void Print(int* a, int size);

//��������
void InsertSort(int* a, int size);
void ShellSort(int* a, int size);

//ѡ������
void SelectSort(int* a, int size);
void HeapSort(int* a, int size);

//��������
void BubbleSort(int* a, int size);
void QuickSort(int* a, int begin, int end);

//�鲢����
void MergeSort(int* a, int size);