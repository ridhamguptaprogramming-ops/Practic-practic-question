// #include <iostream>
// #include <vector>

// using namespace std;

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> p(n + 1);
//     for (int i = 1; i <= n; ++i) {
//         cin >> p[i];
//     }

//     bool possible = true;
//     for (int i = 1; i <= n; ++i) {
//         if (p[p[i]] != i) {
//             possible = false;
//             break;
//         }
//     }

//     if (possible) {
//         cout << "YES\n";
//     } else {
//         cout << "NO\n";
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }
    
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while (t--) {
//         int n, m;
//         cin >> n >> m;
//         vector<ll> a(n);
//         for (ll &x : a) {
//             cin >> x;
//         }
//         if (m == 1) {
//             cout << *max_element(a.begin(), a.end()) << '\n';
//             continue;
//         }
//         priority_queue<ll> pq;
//         ll sum = 0;
//         for (int i = 0; i < m - 1; i++) {
//             pq.push(a[i]);
//             sum += a[i];
//         }
//         ll answer = LLONG_MIN;
//         for (int i = m - 1; i < n; i++) {
//             answer = max(answer, 1LL * m * a[i] - sum);
//             pq.push(a[i]);
//             sum += a[i];
//             if ((int)pq.size() > m - 1) {
//                 sum -= pq.top();
//                 pq.pop();
//             }
//         }

//         cout << answer << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;
// const ll MOD = 998244353;
// ll modPow(ll a, ll b) {
//     ll result = 1;
//     while (b) {
//         if (b & 1)
//             result = result * a % MOD;

//         a = a * a % MOD;
//         b >>= 1;
//     }
//     return result;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<ll> a(n);
//         for (ll &x : a)
//             cin >> x;

//         if (n == 1) {
//             cout << 0 << '\n';
//             continue;
//         }
//         sort(a.begin(), a.end());
//         ll totalWays = 1;

//         for (int i = 1; i <= n - 1; i++) {
//             totalWays = totalWays * i % MOD;
//         }
//         vector<ll> suffix(n + 1, 0);

//         for (int i = n - 1; i >= 0; i--) {
//             suffix[i] = (suffix[i + 1] + a[i]) % MOD;
//         }
//         ll answer = 0;
//         for (int i = 0; i < n - 1; i++) {
//             ll choices = n - i - 1;
//             ll sumHigher = suffix[i + 1];

//             ll sumDifference =
//                 (sumHigher - choices * (a[i] % MOD) % MOD + MOD) % MOD;
//             ll otherWays =
//                 totalWays * modPow(choices, MOD - 2) % MOD;

//             answer =
//                 (answer + sumDifference * otherWays) % MOD;
//         }

//         cout << answer << '\n';
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll cost(ll x) {
    return x * (x + 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "1\n";
            continue;
        }

        if (n == 2) {
            cout << "11\n";
            continue;
        }
        if (n % 6 == 2) {
            int k = (n - 2) / 6;

            cout << "1";
            cout << string(2 * k, '0');
            cout << "1";
            cout << string(2 * k - 1, '0');
            cout << "1";
            cout << string(2 * k, '0');
            cout << '\n';

            continue;
        }
        int zeros = n - 2;

        ll best = LLONG_MAX;
        int bestX = 0, bestY = 0, bestZ = 0;
        int center = zeros / 3;

        for (int y = max(1, center - 5);
             y <= min(zeros, center + 5);
             y++) {
            if (y % 2 == 0)
                continue;

            int remaining = zeros - y;

            int x = remaining / 2;
            int z = remaining - x;

            ll current = cost(x) + cost(y) + cost(z);

            if (current < best) {
                best = current;
                bestX = x;
                bestY = y;
                bestZ = z;
            }
        }

        cout << string(bestX, '0');
        cout << "1";
        cout << string(bestY, '0');
        cout << "1";
        cout << string(bestZ, '0');
        cout << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            if (p[i] != i) {
                v.push_back(p[i]);
            }
        }
        bool ok = true;

        for (int i = 1; i < (int)v.size(); i++) {
            if (v[i - 1] <= v[i]) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}