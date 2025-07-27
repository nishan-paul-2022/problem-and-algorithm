#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        int n;
        cin >> n;
        unordered_map<int, vector<int>> g;
        for (int i = 0; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        unordered_map<int, int> color;
        int ans = 0;
        for (auto& node : g) {
            int start = node.first;
            if (color.count(start)) continue;
            int cnt[2] = {0, 0};
            queue<int> q;
            q.push(start);
            color[start] = 0;
            cnt[0]++;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : g[u]) {
                    if (!color.count(v)) {
                        color[v] = 1 - color[u];
                        cnt[color[v]]++;
                        q.push(v);
                    }
                }
            }
            ans += max(cnt[0], cnt[1]);
        }
        cout << "Case " << cs << ": " << ans << endl;
    }
    return 0;
}
