#include <algorithm>
#include <iostream>
using namespace std;

int number[100];

int gcd(int number1, int number2)
{
	int result = number1 % number2;
	if (result == 0)
		return number2;
	else
		return gcd(number2, result);
}

void printM(int N)
{
	int temp = number[1] - number[0];
	for (int i = 2; i < N; i++)
	{
		temp = gcd(temp, number[i] - number[i - 1]);
	}
	for (int i = 2; i <= temp / 2; i++)
	{
		if (temp % i == 0)
			printf("%d ", i);
	}
	printf("%d ", temp);
}

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &number[i]);
	}
	sort(number, number + N);
	printM(N);
}