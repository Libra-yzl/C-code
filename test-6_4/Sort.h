#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>


void AdjustDown(int* a, int n, int child);

void Print(int* a, int size);

//≤Â»Î≈≈–Ú
void InsertSort(int* a, int size);
void ShellSort(int* a, int size);

//—°‘Ò≈≈–Ú
void SelectSort(int* a, int size);
void HeapSort(int* a, int size);

//Ωªªª≈≈–Ú
void BubbleSort(int* a, int size);
void QuickSort(int* a, int begin, int end);

//πÈ≤¢≈≈–Ú
void MergeSort(int* a, int size);