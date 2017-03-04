// SortingAlgorithm.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>

void PrintArray(int* arr, int n)
{
	printf("Current array is: ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
};
//=============================================
class SortAbstract
{
protected:
	int* arr;
	int n;
protected:
	void Swap(int& a, int &b)
	{
		a = a + b;
		b = a - b;
		a = a - b;
	};
public:
	SortAbstract(int *arr, int n)
	{
		this->arr = arr;
		this->n = n;
	};
	virtual ~SortAbstract()
	{
		n = 0;
	};
	virtual void DoSort() = 0;
};
//=============================================
class SelectionSort : public SortAbstract
{
private:
	int GetIndexOfMin(int* arr, int i, int n)
	{
		int index = i;
		int min = arr[index];
		for (; i < n; i++)
		{
			if (min > arr[i])
			{
				index = i;
				min = arr[index];
			}
		}
		return index;
	};
public:
	SelectionSort(int *arr, int n) : SortAbstract(arr, n) {}
	void DoSort() override
	{
		printf("===== Doing Selection Sort =====\n");
		for (int i = 0; i < n - 1; i++)
		{
			int indexMin = GetIndexOfMin(arr, i + 1, n);
			if (arr[i] > arr[indexMin])
			{
				Swap(arr[i], arr[indexMin]);
			}
		}
	}
};
//=============================================
class BubbleSort : public SortAbstract
{
public:
	BubbleSort(int *arr, int n) : SortAbstract(arr, n) {}
	void DoSort() override
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int k = n - 1; k > i; k--)
			{
				if (arr[k] < arr[k - 1])
					Swap(arr[k], arr[k - 1]);
			}
		}
	};
};
//=============================================
class InsertionSort : public SortAbstract
{
public:
	InsertionSort(int *arr, int n) : SortAbstract(arr, n) {}
	void DoSort() override
	{
		for (int i = 1; i < n; i++)
		{
			int k = i;
			int temp = arr[k];
			while (k > 0)
			{
				if (temp < arr[k - 1])
				{
					arr[k] = arr[k - 1];
					k--;
				}
				else
					break;
			}
			arr[k] = temp;
		}
	};
};
//=============================================
class QuickSort : public SortAbstract
{
private:
	int tabStop;
public:	
	QuickSort(int *arr, int n) : SortAbstract(arr, n), tabStop(0) {}
	int Partition(int *arr, int i, int k)
	{
		int indexFirst = i;
		int temp = arr[i];
		i++;
		while (true)
		{
			while (arr[i] < temp)
			{
				i++;
			}
			while (arr[k] > temp)
			{
				k--;
			}
			if (i < k)
				Swap(arr[i], arr[k]);
			else if (i > k)
			{
				Swap(arr[indexFirst], arr[k]);
				break;
			}
		}
		return k;
	}
	void QSort(int *arr, int i, int k)
	{
		if (i < k - 1)
		{
			tabStop++;
			int mid = Partition(arr, i, k);
			for (int t = 0; t < tabStop; t++)
				printf(".");
			printf("Left: ");
			PrintArray(arr, n);
			QSort(arr, i, mid - 1);
			for (int t = 0; t < tabStop; t++)
				printf(".");
			printf("Right: ");
			QSort(arr, mid + 1, k);
			PrintArray(arr, n);
		}
		else
			tabStop--;
	}
	void DoSort() override
	{
		QSort(arr, 0, n - 1);
	};
};

int main()
{
	printf("Hello world\n");
	int arr[] = { 23, 6, 44, 22, 8, 5, 11, 40, 34, 18 };
	PrintArray(arr, sizeof(arr) / sizeof(int));
	//SortAbstract* a = new SelectionSort(arr, sizeof(arr) / sizeof(int));
	//SortAbstract* a = new BubbleSort(arr, sizeof(arr) / sizeof(int));
	//SortAbstract* a = new InsertionSort(arr, sizeof(arr) / sizeof(int));
	SortAbstract* a = new QuickSort(arr, sizeof(arr) / sizeof(int));
	a->DoSort();
	PrintArray(arr, sizeof(arr) / sizeof(int));
	delete(a);
	return 0;
}

