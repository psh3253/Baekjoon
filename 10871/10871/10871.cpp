#include <iostream>
using namespace std;
int arr[10000];

int main(void)
{
	int N, X;
	cin >> N >> X;
	for(int i = 0; i< N; i++)
	{
		cin >> arr[i];
	}
	for(int i = 0; i < N; i++)
	{
		if (arr[i] < X)
			cout << arr[i] << " ";
	}
	cout << '\n';
}