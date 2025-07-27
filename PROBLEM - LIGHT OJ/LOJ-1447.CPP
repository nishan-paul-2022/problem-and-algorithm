#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int no = 0; no < T; ++no) {
        int num;
        cin >> num;

        vector<int> elements(num);
        for (int i = 0; i < num; ++i) {
            cin >> elements[i];
        }

        unordered_map<int, int> check;
        int sum = 0;

        for (int i : elements) {
            check[abs(i)] = (i < 0) ? -1 : 1;
        }

        for (auto const& [key, val] : check) {
            sum += key * val;
        }

        cout << "Case " << no + 1 << ": " << sum << endl;
    }

    return 0;
}
