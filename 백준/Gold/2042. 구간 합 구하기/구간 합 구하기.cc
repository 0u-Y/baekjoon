#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


long long init(vector<long long> &arr, vector<long long> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}


long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}


void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(tree, node * 2, start, mid, index, diff);
        update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h + 1));
    vector<long long> tree(tree_size);

    init(v, tree, 1, 0, n - 1);

    for (int i = 0; i < m + k; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;

        if (a == 1) {
            b--;
            long long diff = c - v[b];
            v[b] = c;
            update(tree, 1, 0, n - 1, b, diff);
        } else if (a == 2) {
            cout << sum(tree, 1, 0, n - 1, b - 1, c - 1) << '\n';
        }
    }

}
