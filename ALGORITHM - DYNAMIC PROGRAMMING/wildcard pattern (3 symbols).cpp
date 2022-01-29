// C++ program to implement wildcard
// pattern matching algorithm
#include <bits/stdc++.h>
using namespace std;

struct DP {
	bool value;
	char ch;
};

// Function that matches input str with
// given wildcard pattern
bool strmatch(string str, string pattern,
			int n, int m)
{
	// empty pattern can only match with
	// empty string
	if (m == 0)
		return (n == 0);

	// If first character of pattern is '+'
	if (pattern[0] == '+')
		return false;

	// lookup table for storing results of
	// subproblems
	struct DP lookup[m + 1][n + 1];

	// initialize lookup table to false
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= n; j++) {
			lookup[i][j].value = false;
			lookup[i][j].ch = ' ';
		}

	// empty pattern can match with
	// empty string
	lookup[0][0].value = true;

	// Only '*' can match with empty string
	for (int j = 1; j <= n; j++)
		if (pattern[j - 1] == '*')
			lookup[j][0].value =
				lookup[j - 1][0].value;

	// fill the table in bottom-up fashion
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {

			// Two cases if we see a '*'
			// a) We ignore ‘*’ character and move
			// to next character in the pattern,
			// i.e., ‘*’ indicates an empty sequence.
			// b) '*' character matches with ith
			// character in input
			if (pattern[i - 1] == '*') {
				lookup[i][j].value =
					lookup[i][j - 1].value ||
					lookup[i - 1][j].value;
				lookup[i][j].ch = str[j - 1];
			}

			// Current characters are considered as
			// matching in two cases
			// (a) current character of pattern is '?'
			else if (pattern[i - 1] == '?') {
				lookup[i][j].value =
						lookup[i - 1][j - 1].value;
				lookup[i][j].ch = str[j - 1];
			}

			// (b) characters actually match
			else if (str[j - 1] == pattern[i - 1])
				lookup[i][j].value =
					lookup[i - 1][j - 1].value;

			// Current character match
			else if (pattern[i - 1] == '+')

				// case 1: if previous character is
				// not symbol
				if (pattern[i - 2] != '+' ||
					pattern[i - 2] != '*' ||
					pattern[i - 2] != '?')
					if (pattern[i - 2] == str[j - 1]) {
						lookup[i][j].value =
						lookup[i - 1][j - 1].value;
						lookup[i][j].ch = str[j - 1];
					}

					// case 2 : if previous character
					// is symbol (+, *, ? ) then we
					// compare current text character
					// with the character that is used by
					// the symbol at that point. we
					// access it by lookup[i-1][j-1]
					else if (str[j-1] == lookup[i-1][j-1].ch) {
						lookup[i][j].value =
							lookup[i - 1][j - 1].value;
						lookup[i][j].ch =
							lookup[i - 1][j - 1].ch;
					}

					// If characters don't match
					else
						lookup[i][j].value = false;
		}
	}

	return lookup[m][n].value;
}

// Driver code
int main()
{
	string str = "baaabaaa";
	string pattern = "*****+ba***+";

	if (strmatch(str, pattern, str.length(),
					pattern.length()))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}

