#include <iostream>
using namespace std;

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int N;
		long long g = 0;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			g += (long long)(N / i) * i;
		}
		printf("%lld\n", g);
	}
}