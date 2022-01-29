/* Dynamic Programming solution to construct
Maximum Sum Increasing Subsequence */
#include <iostream>
#include <vector>
using namespace std;

// Utility function to calculate sum of all
// vector elements
int findSum(vector<int> arr)
{
	int sum = 0;
	for (int i: arr)
		sum += i;
	return sum;
}

// Function to construct Maximum Sum Increasing
// Subsequence
void printMaxSumIS(int arr[], int n)
{
	// L[i] - The Maximum Sum Increasing
	// Subsequence that ends with arr[i]
	vector <vector<int> > L(n);

	// L[0] is equal to arr[0]
	L[0].push_back(arr[0]);

	// start from index 1
	for (int i = 1; i < n; i++)
	{
		// for every j less than i
		for (int j = 0; j < i; j++)
		{
			/* L[i] = {MaxSum(L[j])} + arr[i]
			where j < i and arr[j] < arr[i] */
			if ((arr[i] > arr[j]) &&
				(findSum(L[i]) < findSum(L[j])))
				L[i] = L[j];
		}

		// L[i] ends with arr[i]
		L[i].push_back(arr[i]);

		// L[i] now stores Maximum Sum Increasing
		// Subsequence of arr[0..i] that ends with
		// arr[i]
	}

	vector<int> res = L[0];

	// find max
	for (vector<int> x : L)
		if (findSum(x) > findSum(res))
			res = x;

	// max will contain result
	for (int i : res)
		cout << i << " ";
	cout << endl;
}

// Driver function
int main()
{
	int arr[] = { 3, 2, 6, 4, 5, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// construct and print Max Sum IS of arr
	printMaxSumIS(arr, n);

	return 0;
}

