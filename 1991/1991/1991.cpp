#include <iostream>
#include <map>
#include <utility>
using namespace std;
map<char, pair<char, char>> tree;

void preorder(char node)
{
	cout << node;
	if (tree[node].first != '.')
		preorder(tree[node].first);
	if (tree[node].second != '.')
		preorder(tree[node].second);
}

void inorder(char node)
{
	if (tree[node].first != '.')
		inorder(tree[node].first);
	cout << node;
	if (tree[node].second != '.')
		inorder(tree[node].second);
}

void postorder(char node)
{
	if (tree[node].first != '.')
		postorder(tree[node].first);
	if (tree[node].second != '.')
		postorder(tree[node].second);
	cout << node;
}

int main(void)
{
	int N;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		char node, left_child_node, right_child_node;
		cin >> node >> left_child_node >> right_child_node;
		tree[node] = make_pair(left_child_node, right_child_node);
	}
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	cout << '\n';
}