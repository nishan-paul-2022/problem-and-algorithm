// C++ program to implement wildcard
// pattern matching algorithm
#include <bits/stdc++.h>
using namespace std;

// Function that matches input text
// with given wildcard pattern
bool strmatch(char txt[], char pat[],
			int n, int m)
{
	// empty pattern can only
	// match with empty string.
	// Base Case :
	if (m == 0)
		return (n == 0);

	// step-1 :
	// initailze markers :
	int i = 0, j = 0, index_txt = -1,
		index_pat = -1;

	while (i < n) {

		// For step - (2, 5)
		if (txt[i] == pat[j]) {
			i++;
			j++;
		}

		// For step - (3)
		else if (j < m && pat[j] == '?') {
			i++;
			j++;
		}

		// For step - (4)
		else if (j < m && pat[j] == '*') {
			index_txt = i;
			index_pat = j;
			j++;
		}

		// For step - (5)
		else if (index_pat != -1) {
			j = index_pat + 1;
			i = index_txt + 1;
			index_txt++;
		}

		// For step - (6)
		else {
			return false;
		}
	}

	// For step - (7)
	while (j < m && pat[j] == '*') {
		j++;
	}

	// Final Check
	if (j == m) {
		return true;
	}

	return false;
}

// Driver code
int main()
{
	char str[] = "baaabab";
	char pattern[] = "*****ba*****ab";
	// char pattern[] = "ba*****ab";
	// char pattern[] = "ba*ab";
	// char pattern[] = "a*ab";

	if (strmatch(str, pattern,
				strlen(str), strlen(pattern)))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	char pattern2[] = "a*****ab";
	if (strmatch(str, pattern2,
				strlen(str), strlen(pattern2)))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}

