#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int answer = 0;
	int A[50], B[50];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
	}
	sort(A, A + N);
	sort(B, B + N, greater<>());
	for(int i = 0; i < N; i++)
	{
		answer += A[i] * B[i];
	}
	cout << answer << '\n';
}
