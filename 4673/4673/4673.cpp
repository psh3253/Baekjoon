#include <iostream>
#include <string>
using namespace std;
bool visit[10001];

int main(void)
{
	for (int i = 1; i < 10000; i++)
	{
		int temp = i;
		int idx = i;
		while(temp > 0)
		{
			idx += temp % 10;
			temp /= 10;
		}
		visit[idx] = true;
	}
	for (int i = 1; i <= 10000; i++)
	{
		if (!visit[i])
			cout << i << '\n';
	}
}