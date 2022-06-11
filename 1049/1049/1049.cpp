#include <iostream>
using namespace std;

int main(void)
{
	int min_package = 987654321;
	int min_piece = 987654321;
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		int package, piece;
		cin >> package >> piece;
		min_package = min(min_package, package);
		min_piece = min(min_piece, piece);
	}
	int answer = N / 6 * min_package + N % 6 * min_piece;
	answer = min(answer, (N / 6 + 1) * min_package);
	answer = min(answer, N * min_piece);
	cout << answer << '\n';
}