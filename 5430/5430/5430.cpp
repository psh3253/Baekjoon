#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(void)
{
	deque<int> dq;
	int dq_size;
	bool reverse, is_error;
	int T, n;
	string command, arr, temp;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		dq.clear();
		temp = "";
		reverse = false;
		is_error = false;
		cin >> command;
		cin >> n;
		cin >> arr;
		for (int j = 0; j < arr.size(); j++)
		{
			if (arr.at(j) == '[')
				continue;
			else if (arr.at(j) >= '0' && arr.at(j) <= '9')
				temp += arr.at(j);
			else if (arr.at(j) == ']' || arr.at(j) == ',')
			{
				if (arr.at(j - 1) == '[')
				{
					break;
				}
				dq.push_back(stoi(temp));
				temp = "";
			}
		}
		for (int j = 0; j < command.size(); j++)
		{
			if (command.at(j) == 'R')
			{
				reverse = !reverse;
			}
			else if (command.at(j) == 'D')
			{
				if (reverse)
				{
					if (dq.empty())
					{
						is_error = true;
						break;
					}
					else {
						dq.pop_back();
					}
				}
				else
				{
					if (dq.empty())
					{
						is_error = true;
						break;
					}
					else
					{
						dq.pop_front();
					}
				}
			}
		}
		if (is_error)
		{
			cout << "error" << '\n';
		}
		else {
			dq_size = dq.size();
			cout << '[';
			if (dq.size() == 0)
				cout << ']' << '\n';
			for (int j = 0; j < dq_size; j++)
			{
				if (reverse)
				{
					cout << dq.back();
					dq.pop_back();
				}
				else
				{
					cout << dq.front();
					dq.pop_front();
				}
				if (j == dq_size - 1)
				{
					cout << ']' << '\n';
				}
				else
				{
					cout << ',';
				}
			}
		}
	}
}