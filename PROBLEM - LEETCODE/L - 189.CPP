#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void rotate(vector<int> &nums, int k) {
            int n = nums.size();
            k = k % n;
            vector<int> ans(n);

            for(int i=n-k, j=0; i<n; i++, j++) {
                ans[j] = nums[i];
            }

            for(int i=0, j=k; i<n-k; i++, j++) {
                ans[j] = nums[i];
            }

            nums = ans;
        }
};


int main() {
    Solution ob1;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    cout << ob1.rotate(nums, 3) << endl;
    return 0;
}

//https://leetcode.com/problems/rotate-array/