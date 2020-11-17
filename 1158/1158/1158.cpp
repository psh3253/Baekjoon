#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;
	int n, i, j, k;
	
	// n �� k �Է�
	cin >> n >> k;

	// ť�� ��ȣ ä���ֱ�
	for (i = 0; i < n; i++)
	{
		q.push(i + 1);
	}

	cout << "<";
	// k��° ��� ť���� ���� ���
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