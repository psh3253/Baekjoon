#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<long long>> vv;
vv matrix = { {1, 1}, {1, 0} };

vv multiply(vv matrix1, vv matrix2)
{
	vv result(2, vector<long long>(2, 0));
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				result[i][j] += matrix1[k][i] * matrix2[j][k];
			}
			result[i][j] %= 1000000007;
		}
	}
	return result;
}

vv square(long long n)
{
	if (n == 1)
		return matrix;
	else if (n % 2)
	{
		return multiply(matrix, square(n - 1));
	}
	else
	{
		vv temp = square(n / 2);
		return multiply(temp, temp);
	}
}

int main(void)
{
	long long n;
	cin >> n;
	vv result = square(n);
	cout << result[1][0] << '\n';
}