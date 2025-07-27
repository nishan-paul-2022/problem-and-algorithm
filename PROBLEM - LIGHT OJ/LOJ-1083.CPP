#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int max_area = 0;
    int tp;
    int area_with_top;

    int i = 0;
    while (i < heights.size()) {
        if (s.empty() || heights[i] >= heights[s.top()]) {
            s.push(i++);
        } else {
            tp = s.top();
            s.pop();

            area_with_top = heights[tp] * (s.empty() ? i : i - s.top() - 1);

            if (max_area < area_with_top) {
                max_area = area_with_top;
            }
        }
    }

    while (!s.empty()) {
        tp = s.top();
        s.pop();
        area_with_top = heights[tp] * (s.empty() ? i : i - s.top() - 1);

        if (max_area < area_with_top) {
            max_area = area_with_top;
        }
    }

    return max_area;
}

int main() {
    int t;
    cin >> t;
    for (int case_num = 1; case_num <= t; ++case_num) {
        int n;
        cin >> n;
        vector<int> heights(n);
        for (int i = 0; i < n; ++i) {
            cin >> heights[i];
        }
        cout << "Case " << case_num << ": " << largestRectangleArea(heights) << endl;
    }
    return 0;
}
