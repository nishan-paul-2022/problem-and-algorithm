#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void moveZeroes(vector<int> &nums) {
            int n = nums.size();
            vector<int> ans;

            for(int i=0; i<n; i++) {
                if(nums[i] != 0)
                    ans.push_back(nums[i]);
            }

            for(int i=0; i<n; i++) {
                if(nums[i] == 0)
                    ans.push_back(nums[i]);
            }

            nums = ans;
        }
};


int main() {
    Solution ob1;
    vector<int> nums = {1, 2, 0, 3, 4, 0, 5, 6, 0, 7};
    cout << ob1.rotate(nums) << endl;
    return 0;
}

//https://leetcode.com/problems/move-zeroes/