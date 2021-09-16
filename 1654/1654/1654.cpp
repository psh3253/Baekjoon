#include <iostream>
using namespace std;
long long line[10001];

int main(void)
{
	int K, N;
	int line_count = 0, max_line = 0;
	long long left = 1, middle = 1, right = 1;
	cin >> K >> N;
	for(int i = 0; i < K; i++)
	{
		cin >> line[i];
		if (right < line[i])
			right = line[i];
	}
	while (left <= right)
	{
		line_count = 0;
		middle = (left + right) / 2;
		for(int i = 0; i < K; i++)
		{
			line_count += line[i] / middle;
		}
		if (line_count >= N)
		{
			if (middle > max_line)
				max_line = middle;
			left = middle + 1;
		}
		else
		{
			right = middle - 1;
		}
	}
	cout << max_line << '\n';
}