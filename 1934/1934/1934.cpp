#include <iostream>
using namespace std;

int gcd(int A, int B)
{
	int result = A % B;
	if (result == 0)
		return B;
	else
		return gcd(B, result);
}

int main(void)
{
	int T;
	int A, B;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> A >> B;
		cout << A * B / gcd(A, B) << endl;
	}
}