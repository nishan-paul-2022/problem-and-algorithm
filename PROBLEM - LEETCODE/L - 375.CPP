#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
       int cost(int low, int high, vector < vector <int> >& dp){
          if(low >= high)
            return 0;

          if(dp[low][high] != -1)
            return dp[low][high];

          int ans = INT_MAX;

          for(int i = low; i <= high; i++) {
            int lowercost = cost(low, i - 1, dp);
            int uppercost = cost(i + 1, high, dp);
            int currentcost = i + max(lowercost, uppercost);
            ans = min(ans, currentcost);
          }

          dp[low][high] = ans;
          return ans;
       }

       int getMoneyAmount(int n) {
          vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
          int mincost = cost(1, n, dp);
          return mincost;
       }
};

int main() {
    int n;
    cin >> n;
    Solution ob1;
    cout << ob1.getMoneyAmount(n) << endl;
    return 0;
}

# https://leetcode.com/problems/guess-number-higher-or-lower-ii/
