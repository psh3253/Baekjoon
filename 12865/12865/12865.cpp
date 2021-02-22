#include <iostream>
#include <utility>
using namespace std;

pair<int, int> object[100];

int main(void)
{
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> object[i].first >> object[i].second;
	}
}