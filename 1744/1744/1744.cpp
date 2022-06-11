#include <iostream>
#include <algorithm>
using namespace std;
int arr[50];
bool visit[50];

int main(void)
{
	int answer = 0;
	int N;
	cin >> N;
	for(int i = 0 ;i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int i = N - 2;
	int j = N - 1;
	bool go_left = true;
	while(true)
	{
		if(go_left)
		{
			if (j < 0)
				break;
			if(i < 0)
			{
				answer += arr[j];
				break;
			}
			if (arr[i] * arr[j] > arr[i] + arr[j] && arr[i] >= 0)
			{
				answer += arr[i] * arr[j];
				visit[i] = true;
				visit[j] = true;
				i -= 2;
				j -= 2;
			}
			else
			{
				i = 0;
				j = 1;
				go_left = false;
			}
		}
		else
		{
			if (i > N - 1)
				break;
			if(j > N - 1 || visit[j])
			{
				if(!visit[i])
					answer += arr[i];
				break;
			}
			if(arr[i] * arr[j] > arr[i] + arr[j])
			{
				answer += arr[i] * arr[j];
				visit[i] = true;
				visit[j] = true;
				i += 2;
				j += 2;
			}
			else
			{
				answer += arr[i] + arr[j];
				visit[i] = true;
				visit[j] = true;
				i += 2;
				j += 2;
			}
		}
	}
	cout << answer << '\n';
}