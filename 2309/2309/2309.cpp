#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int height[9];
	vector<int> height2;
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> height[i];
		sum += height[i];
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i != j && sum - height[i] - height[j] == 100)
			{
				for (int k = 0; k < 9; k++)
				{
					if (k != i && k != j)
					{
						height2.push_back(height[k]);
					}
				}
				sort(height2.begin(), height2.end());
				for (int k = 0; k < 7; k++)
				{
					cout << height2[k] << endl;
				}
				return 0;
			}
		}
	}
}