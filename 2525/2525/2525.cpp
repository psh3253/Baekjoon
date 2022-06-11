#include <iostream>
using namespace std;

int main(void)
{
	int A, B, C;
	cin >> A >> B;
	cin >> C;
	if(B + C >= 60)
	{
		A += (B + C) / 60;
	}
	if (A >= 24)
		A -= 24;
	cout << A << " " << (B + C) % 60 << '\n';
}