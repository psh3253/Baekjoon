#include <stdio.h>

typedef struct meeting
{
	int start;
	int end;
}meeting;
meeting time[100000];

int static compare(const void** a, const void** b)
{
	if ((*(meeting*)a).start > (*(meeting*)b).start)
		return 1;
	else if ((*(meeting*)a).start < (*(meeting*)b).start)
		return -1;
	else
	{
		if ((*(meeting*)a).end > (*(meeting*)b).end)
			return 1;
		else if ((*(meeting*)a).end < (*(meeting*)b).end)
			return -1;
		else 0;
	}
}

int main(void)
{
	int n, i, j, min, endtime = 0, count = 0;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &time[i].start, &time[i].end);
	}
	qsort(time, n, sizeof(meeting), compare);

	for (i = 0; i < n; i++)
	{
		printf("%d %d\n", &time[i].start, &time[i].end);
	}

	for (i = 0; i < n-1; i++)
	{
		if (time[i].start < endtime)
			continue;
		if (time[i].end > time[i + 1].end)
			continue;
		endtime = time[i].end;
		count++;
	}
	if (time[n - 1].start >= endtime)
		count++;
	printf("%d\n", count);
	return 0;
}