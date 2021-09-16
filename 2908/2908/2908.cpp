#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
	string A, B;
	cin >> A >> B;
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	if (stoi(A) > stoi(B))
		cout << A;
	else
		cout << B;
}