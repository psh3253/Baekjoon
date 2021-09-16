#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> matrix(5, vector<int>(5, 0));
int N;

vector<vector<int>> multiply(vector<vector<int>> a, vector<vector<int>> b)
{
	vector<vector<int>> result(5, vector<int>(5, 0));
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			for(int k = 0; k < N; k++)
			{
				result[i][j] += a[i][k] * b[k][j];
			}
			result[i][j] = result[i][j] % 1000;
		}
	}
	return result;
}

vector<vector<int>> divisional_conquest(long long n)
{
	vector<vector<int>> result(5, vector<int>(5, 0));
	vector<vector<int>> temp(5, vector<int>(5, 0));
	if (n == 1)
		result = matrix;
	else if (n == 2)
		result = multiply(matrix, matrix);
	else if (n % 2 == 0)
	{
		temp = divisional_conquest(n / 2);
		result = multiply(temp, temp);
	}
	else
	{
		result = multiply(divisional_conquest(n - 1), matrix);
	}
	return result;
}

int main(void)
{
	vector<vector<int>> result(5, vector<int>(5, 0));
	int temp;
	long long B;
	cin >> N >> B;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> matrix[i][j];
			matrix[i][j] %= 1000;
		}
	}
	result = divisional_conquest(B);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}
}