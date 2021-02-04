#include <iostream>
#include <string>
using namespace std;

int getDigits(int num)
{
	int digit = 0;
	if (num == 0)
		return 1;
	while (num > 0)
	{
		num /= 10;
		digit++;
	}
	return digit;
}

int main(void)
{
	int N, M;
	int button[10];
	bool isWrong = true;
	cin >> N;
	int buttonCount = abs(N - 100);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> button[i];
	}
	for (int i = 0; i <= 1000000; i++)
	{
		isWrong = false;
		for (int j = 0; j < M; j++)
		{
			if (to_string(i).find(to_string(button[j])) != string::npos)
			{
				isWrong = true;
				break;
			}
		}
		if (isWrong == false)
		{
			if (abs(i - N) + getDigits(i) < buttonCount)
			{
				buttonCount = abs(i - N) + getDigits(i);
			}
		}
	}
	cout << buttonCount << endl;
}