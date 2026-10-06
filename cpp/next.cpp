#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

const int64 MOD = 998244353;

int64 mod_pow(int64 a, int64 e) {
    int64 r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

struct Item {
    int v;
    int64 cnt;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    vector<int64> k(m);

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 0; i < m; ++i)
        cin >> k[i];

    /*
        Base:
        sum over all subarrays of sum(1 / a[i]).

        a[i] occurs in exactly:
            i * (n - i + 1)
        subarrays.
    */
    int64 base = 0;

    for (int i = 1; i <= n; ++i) {
        int64 inv = mod_pow(a[i], MOD - 2);

        int64 ways = 1LL * i * (n - i + 1) % MOD;

        base = (base + inv * ways) % MOD;
    }

    /*
        Count subarrays for which position i is the chosen minimum.

        Left boundary:
            previous element <= a[i]

        Right boundary:
            next element < a[i]

        This makes equal values assigned consistently.
    */
    vector<int> L(n + 1), R(n + 1);
    vector<int> st;
    st.reserve(n);

    // Previous <= a[i].
    for (int i = 1; i <= n; ++i) {
        while (!st.empty() && a[st.back()] > a[i])
            st.pop_back();

        L[i] = st.empty() ? 0 : st.back();

        st.push_back(i);
    }

    st.clear();

    // Next < a[i].
    for (int i = n; i >= 1; --i) {
        while (!st.empty() && a[st.back()] >= a[i])
            st.pop_back();

        R[i] = st.empty() ? n + 1 : st.back();

        st.push_back(i);
    }

    /*
        For each value v, cnt[v] = number of subarrays
        whose selected minimum has value v.
    */
    vector<Item> items;
    items.reserve(n);

    for (int i = 1; i <= n; ++i) {
        int64 cnt = 1LL * (i - L[i]) * (R[i] - i) % MOD;
        items.push_back({a[i], cnt});
    }

    sort(items.begin(), items.end(),
         [](const Item &x, const Item &y) {
             return x.v < y.v;
         });

    // Merge equal values.
    vector<int> val;
    vector<int64> cnt;

    for (auto &it : items) {
        if (val.empty() || val.back() != it.v) {
            val.push_back(it.v);
            cnt.push_back(it.cnt);
        } else {
            cnt.back() += it.cnt;
            if (cnt.back() >= MOD)
                cnt.back() -= MOD;
        }
    }

    int sz = val.size();

    /*
        For a minimum value v:

        if k < v:
            extra = k / v

        if k >= v:
            extra = k + 2 - v - 1/v

        Define:

        A[v] = cnt[v] / v
        B[v] = cnt[v]
        D[v] = cnt[v] * (2 - v - 1/v)

        Then:

        extra_sum =
            k * sum(A[v]) for v > k
            +
            k * sum(B[v]) for v <= k
            +
            sum(D[v]) for v <= k
    */

    vector<int64> prefA(sz + 1, 0);
    vector<int64> prefB(sz + 1, 0);
    vector<int64> prefD(sz + 1, 0);

    for (int i = 0; i < sz; ++i) {
        int64 inv = mod_pow(val[i], MOD - 2);

        int64 A = cnt[i] * inv % MOD;
        int64 B = cnt[i];

        int64 D = cnt[i] *
                  ((2LL - val[i] - inv) % MOD + MOD) % MOD;

        prefA[i + 1] = (prefA[i] + A) % MOD;
        prefB[i + 1] = (prefB[i] + B) % MOD;
        prefD[i + 1] = (prefD[i] + D) % MOD;
    }

    /*
        Queries are sorted, but binary search is simple and robust.

        p = first index with val[p] > k.

        Therefore:
            val[0 ... p-1] <= k
            val[p ... sz-1] > k
    */
    for (int i = 0; i < m; ++i) {
        int64 x = k[i];

        int p = upper_bound(val.begin(), val.end(), x) - val.begin();

        // sum A[v] for v > k
        int64 sumA = (prefA[sz] - prefA[p] + MOD) % MOD;

        // sum B[v] for v <= k
        int64 sumB = prefB[p];

        // sum D[v] for v <= k
        int64 sumD = prefD[p];

        int64 extra = 0;

        extra = (extra + (x % MOD) * sumA) % MOD;
        extra = (extra + (x % MOD) * sumB) % MOD;
        extra = (extra + sumD) % MOD;

        int64 ans = (base + extra) % MOD;

        cout << ans << '\n';
    }

    return 0;
}