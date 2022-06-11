#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string A, B;
	string min_A, min_B;
	string max_A, max_B;
	cin >> A >> B;
	min_A = A;
	max_A = A;
	min_B = B;
	max_B = B;
	for (int i = 0; i < A.length(); i++)
	{
		if (A[i] == '5')
		{
			max_A[i] = '6';
		}
		else if (A[i] == '6')
		{
			min_A[i] = '5';
		}
		if (B[i] == '5')
		{
			max_B[i] = '6';
		}
		else if (B[i] == '6')
		{
			min_B[i] = '5';
		}
	}
	cout << stoi(min_A) + stoi(min_B) << " " << stoi(max_A) + stoi(max_B) << '\n';
}