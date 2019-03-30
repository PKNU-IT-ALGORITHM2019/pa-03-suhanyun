// sort.c.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) 
#define MAX 1000000   
int original[MAX];    
int list[MAX];     
int sorted[MAX]; 

int n;
clock_t start, finish, used_time = 0;    
										 
void bubble_sort(int list[], int n)
{
	int i, j, tmp;
	printf("버블 정렬 ");
	for (i = n - 1; i>0; i--)
	{
		for (j = 0; j<i; j++)
			if (list[j]>list[j + 1])
				SWAP(list[j], list[j + 1], tmp);
	}
	
}


										 
void selection_sort(int list[], int n)
{
	int i, j, least, tmp;

	printf("선택 정렬 중... ");
	for (i = 0; i<n - 1; i++)
	{
		least = i;
		for (j = i + 1; j<n; j++)
			if (list[j]<list[least]) least = j;
		SWAP(list[i], list[least], tmp);
	}
}


void insertion_sort(int list[], int n)
{
	int i, j, key;
	printf("삽입 정렬 중... ");
	for (i = 1; i<n; i++)
	{
		key = list[i];
		for (j = i - 1; j >= 0 && list[j]>key; j--)
			list[j + 1] = list[j];
		list[j + 1] = key;
	}
}

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left, j = mid + 1; k = left;

	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	if (i>mid)
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (l = i; l <= right; l++)
			sorted[k++] = list[l];

	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}
void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left<right)
	{
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}

int partition(int list[], int left, int right)
{
	int pivot = list[left], tmp, low = left, high = right + 1;

	do {
		do
			low++;
		while (low <= right && list[low]<pivot);

		do
			high--;
		while (high >= left && list[high]>pivot);
		if (low<high) SWAP(list[low], list[high], tmp);
	} while (low<high);

	SWAP(list[left], list[high], tmp);
	return high;
}
void quick_sort(int list[], int left, int right)
{
	if (left<right)
	{
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}


void CopyArr(void)
{
	int i;
	for (i = 0; i<n; i++)
		list[i] = original[i];
}

void CalcTime(void)
{
	used_time = finish - start;
	printf("완료!\n소요 시간 : %f sec\n\n", (float)used_time / CLOCKS_PER_SEC);
}

void print()
{
	printf("\t\tRandom1000\tReverse1000\tRandom10000\tReverse10000\tRandom100000\tReverse100000\n\n\n");
	printf("Bubble    \t ");
	printf("%lf \t%lf\t%lf\t%lf\t%lf\t%lf ", bubble_sort(list[],MAX));
	printf("\nSelection    \t");
	printf("%lf \t%lf \t%lf \t%lf \t%lf \t%lf\n", selectionsort(ran, 1000), selectionsort(rev, 1000), selectionsort(ran, 10000), selectionsort(rev, 10000), selectionsort(ran, 100000), selectionsort(rev, 100000));
	printf("Insertion    \t ");
	printf("%lf \t%lf \t%lf \t%lf \t%lf \t%lf\n", Insertionsort(ran, 1000), Insertionsort(rev, 1000), Insertionsort(ran, 10000), Insertionsort(rev, 10000), Insertionsort(ran, 100000), Insertionsort(rev, 100000));
	printf("Merge    \t ");
	printf("%lf \t%lf \t%lf \t%lf \t%lf \t%lf\n", merge_sort(ran, 0, 1000), merge_sort(rev, 0, 1000), merge_sort(ran, 0, 10000), merge_sort(rev, 0, 10000), merge_sort(ran, 0, 100000), merge_sort(rev, 0, 100000));
	printf("Quick1    \t ");
	printf("%lf \t%lf \t%lf \t%lf \t%lf \t%lf\n", quickSort1(ran, 0, 1000), quickSort1(rev, 0, 1000), quickSort1(ran, 0, 10000), quickSort1(rev, 0, 10000), quickSort1(ran, 0, 100000), quickSort1(rev, 0, 100000));
	printf("Quick2    \t ");
	printf("%lf \t%lf \t%lf \t%lf \t%lf \t%lf\n", quickSort2(ran, 0, 1000), quickSort2(rev, 0, 1000), quickSort2(ran, 0, 10000), quickSort2(rev, 0, 10000), quickSort2(ran, 0, 100000), quickSort2(rev, 0, 100000));
	printf("Quick3    \t ");
	printf("%lf \t%lf \t%lf \t%lf \t%lf \t%lf\n", quickSort3(ran, 0, 1000), quickSort3(rev, 0, 1000), quickSort3(ran, 0, 10000), quickSort3(rev, 0, 10000), quickSort3(ran, 0, 100000), quickSort3(rev, 0, 100000));
}
void main()
{
	int i;

	n = MAX;
	for (i = 0; i<n; i++)
		original[i] = rand();

	print();

	CopyArr();
	start = clock();
	selection_sort(list, n);
	finish = clock();
	CalcTime();

	CopyArr();
	start = clock();
	insertion_sort(list, n);
	finish = clock();
	CalcTime();

	CopyArr();
	start = clock();
	bubble_sort(list, n);
	finish = clock();
	CalcTime();

	CopyArr();
	start = clock();
	finish = clock();
	CalcTime();

	CopyArr();
	start = clock();
	printf("합병 정렬 중... ");
	merge_sort(list, 0, n);
	finish = clock();
	CalcTime();

	CopyArr();
	start = clock();
	printf("퀵 정렬 중... ");
	quick_sort(list, 0, n);
	finish = clock();
	CalcTime();
}

