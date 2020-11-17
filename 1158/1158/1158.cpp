#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;
	int n, i, j, k;
	
	// n 및 k 입력
	cin >> n >> k;

	// 큐에 번호 채워넣기
	for (i = 0; i < n; i++)
	{
		q.push(i + 1);
	}

	cout << "<";
	// k번째 사람 큐에서 빼고 출력
	for (i = 0; i < n; i++)
	{
		for (j = 1; j < k; j++)
		{
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		if (i < n - 1)
			cout << ", ";
		q.pop();
	}

	cout << ">" << endl;
}