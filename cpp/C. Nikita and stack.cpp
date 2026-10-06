#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree, lazy;

    void update(int node, int start, int end,
                int left, int right, int value) {

        if (right < start || end < left)
            return;

        if (left <= start && end <= right) {
            tree[node] += value;
            lazy[node] += value;
            return;
        }

        pushDown(node);

        int mid = start + (end - start) / 2;

        update(node * 2, start, mid, left, right, value);
        update(node * 2 + 1, mid + 1, end, left, right, value);

        tree[node] = max(tree[node * 2],
                         tree[node * 2 + 1]);
    }

    void pushDown(int node) {

        if (lazy[node] != 0) {

            tree[node * 2] += lazy[node];
            lazy[node * 2] += lazy[node];

            tree[node * 2 + 1] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];

            lazy[node] = 0;
        }
    }

    int findRightmost(int node, int start, int end) {

        if (start == end)
            return start;

        pushDown(node);

        int mid = start + (end - start) / 2;

        // Search right side first
        if (tree[node * 2 + 1] > 0) {
            return findRightmost(
                node * 2 + 1,
                mid + 1,
                end
            );
        }

        return findRightmost(
            node * 2,
            start,
            mid
        );
    }

public:

    SegmentTree(int size) {

        n = size;

        tree.resize(4 * n + 5, 0);
        lazy.resize(4 * n + 5, 0);
    }

    void update(int left, int right, int value) {

        update(
            1,
            1,
            n,
            left,
            right,
            value
        );
    }

    int getRightmost() {

        if (tree[1] <= 0)
            return -1;

        return findRightmost(1, 1, n);
    }
};


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;

    SegmentTree segTree(m);

    vector<int> value(m + 1);

    for (int i = 0; i < m; i++) {

        int p, type;

        cin >> p >> type;

        if (type == 1) {

            int x;
            cin >> x;

            value[p] = x;

            // push = +1
            segTree.update(1, p, 1);

        } else {
            segTree.update(1, p, -1);
        }

        int position = segTree.getRightmost();

        if (position == -1) {
            cout << -1 << '\n';
        } else {
            cout << value[position] << '\n';
        }
    }

    return 0;
}