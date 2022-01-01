#include <iostream>
#include <cmath>
using namespace std;
int number = 0;
int N, R, C;

void set_z(int r, int c, int N)
{
	if (N == 0)
	{
		if (r == R && c == C)
		{
			cout << number << '\n';
			exit(0);
		}
		return;
	}
	int temp = pow(2, N - 1);
	int temp1 = pow(temp, 2);
	if (R >= r && R < r + temp && C >= c && C < c + temp)
	{
		set_z(r, c, N - 1);
	}
	else
	{
		number += temp1;
	}
	
	if (R >= r && R < r + temp && C >= c + temp && C < c + 2 * temp)
	{
		set_z(r, c + temp, N - 1);
	}
	else
	{
		number += temp1;
	}
	
	if (R >= r + temp && R < r + 2 * temp && C >= c && C < c + temp)
	{
		set_z(r + temp, c, N - 1);
	}
	else
	{
		number += temp1;
	}
	
	if (R >= r + temp && R < r + 2 * temp && C >= c + temp && C < c + 2 * temp)
	{
		set_z(r + temp, c + temp, N - 1);
	}
	else
	{
		number += temp1;
	}
}

int main(void)
{
	cin >> N >> R >> C;
	set_z(0, 0, N);
}