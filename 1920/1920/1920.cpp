#include <iostream>
#include <algorithm>
using namespace std;
int A[100001];

bool binary_search(int left, int right, int target)
{
	bool result = false;
	int middle;
	while(left <= right)
	{
		middle = (left + right) / 2;
		if(target == A[middle])
		{
			result = true;
			break;
		}
		else if(target < A[middle])
		{
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}
	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, target;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	sort(A, A + N);
	cin >> M;
	for(int i = 0; i < M; i++)
	{
		cin >> target;
		if (binary_search(0, N - 1, target))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}