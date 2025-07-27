// C++ Program to count possible binary trees
// using dynamic programming
#include <bits/stdc++.h>
using namespace std;

int countTrees(int n)
{
	// Array to store number of Binary tree
	// for every count of nodes
	int BT[n + 1];
	memset(BT, 0, sizeof(BT));

	BT[0] = BT[1] = 1;

	// Start finding from 2 nodes, since
	// already know for 1 node.
	for (int i = 2; i <= n; ++i)
		for (int j = 0; j < i; j++)
			BT[i] += BT[j] * BT[i - j - 1];

	return BT[n];
}

// Driver code
int main()
{
	int n = 5;
	cout << "Total Possible Binary Trees are : "
		<< countTrees(n) << endl;
	return 0;
}
