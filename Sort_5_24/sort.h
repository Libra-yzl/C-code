#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>



void sortPrint(int* a, int size);


//��������
void InsertSort(int* a, int size);
void ShellSort(int* a, int size);

//ѡ������
void SelectSort(int* a, int size);
void HeapSort(int* a, int size);

//��������
void bubbleSort(int* a, int size);
void QuickSort(int* a, int begin, int end);