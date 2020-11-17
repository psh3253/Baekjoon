#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, i, count = 0, arr[1000];
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (i = 0; i < n; i++)
	{
		count += arr[i] * (n - i);
	}
	cout << count << endl;
}