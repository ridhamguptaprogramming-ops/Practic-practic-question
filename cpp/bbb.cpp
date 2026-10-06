#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> cnt(m + 1, 0);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            cnt[a]++;
        }
        int ans = 0;
        for (int x = 1; x <= m; x++) {
            int cur = cnt[x];
            if (2 * x <= m) {
                cur += 2 * cnt[2 * x];
            }
            ans = max(ans, cur);
        }
        cout << ans << '\n';
    }
    return 0;
}