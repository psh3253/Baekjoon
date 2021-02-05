#include <iostream>
using namespace std;
int numberCount[10001];

int main(void)
{
	int N;
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		numberCount[temp] += 1;
	}
	for (int i = 1; i <= 10000; i++)
	{
		while (numberCount[i] > 0)
		{
			printf("%d\n", i);
			numberCount[i]--;
		}
	}
}