#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int target, int left, int right)
{
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (target < arr[mid])
			right = mid - 1;
		else if (target == arr[mid])
			return 1;
		else
			left = mid + 1;
	}
	return 0;
}

int compare(const void* a, const void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 > num2)
		return 1;
	else if (num1 == num2)
		return 0;
	else
		return -1;
}

int main(void)
{
	int n, i, m, result;
	int* arr;
	int* target;
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	qsort(arr, n, sizeof(int), compare);

	scanf("%d", &m);
	target = (int*)malloc(sizeof(int) * m);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &target[i]);
	}
	for (i = 0; i < m; i++)
	{
		int result = binarySearch(arr, target[i], 0, n - 1);
		printf("%d\n", result);
	}
	return 0;
}