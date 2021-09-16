#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
	deque<int> dq;
	int N, M, target, rotation_count, result = 0;
	cin >> N >> M;
	for(int i = 1; i < N + 1; i++)
	{
		dq.push_back(i);
	}
	for(int i = 0; i < M; i++)
	{
		rotation_count = 0;
		cin >> target;
		while(true)
		{
			if(dq.front() == target)
			{
				if (rotation_count > dq.size() / 2)
					rotation_count = dq.size() - rotation_count;
				dq.pop_front();
				result += rotation_count;
				break;
			}
			dq.push_back(dq.front());
			dq.pop_front();
			rotation_count++;
		}
	}
	cout << result << '\n';
}