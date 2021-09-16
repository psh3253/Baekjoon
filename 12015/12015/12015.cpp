#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[1000001];
vector<int> lis;

int main(void)
{
	int N;
	int lis_length = 0;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	lis.push_back(arr[0]);
	lis_length++;
	for(int i = 1; i < N; i++)
	{
		if(arr[i] > lis.back())
		{
			lis.push_back(arr[i]);
			lis_length++;
		}
		else
		{
			int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
			lis[idx] = arr[i];
		}
	}
	cout << lis_length << '\n';
}