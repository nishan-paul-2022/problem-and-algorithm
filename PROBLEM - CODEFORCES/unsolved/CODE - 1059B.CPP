#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
char in[1005][1005];
char pr[1005][1005];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", in[i] + 1);
        for (int j = 1; j <= m; ++j) {
            pr[i][j] = '.';
        }
    }
    for (int i = 2; i < n; ++i) {
        for (int j = 2; j < m; ++j) {
            bool b = 1;
            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    if (x == 0 && y == 0) continue;
                    if (in[i + x][j + y] != '#') {
                        b = 0;
                        break;
                    }
                }
                if (!b) break;
            }
            if (b) {
                for (int x = -1; x <= 1; ++x) {
                    for (int y = -1; y <= 1; ++y) {
                        if (x == 0 && y == 0) continue;
                        pr[i + x][j + y] = '#';
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (in[i][j] != pr[i][j]) {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
	return 0;
}
