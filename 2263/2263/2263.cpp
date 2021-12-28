#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
int n;
vector<int> inorder_tree;
vector<int> postorder_tree;
map<int, pair<int, int>> tree;

int makeTree(int start, int end, int parent, int post_order_pointer)
{
	int parentIndex = lower_bound(inorder_tree + start, inorder_tree + end, parent) - inorder_tree.begin();
	int currentIndex = lower_bound(start, end, postorder_tree[post_order_pointer]);
	if(currentIndex < parentIndex)
}

int main(void)
{
	int temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		inorder_tree.push_back(temp);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		postorder_tree.push_back(temp);
	}
	makeTree(0, n - 1, postorder_tree[n - 1], n- 2);
}