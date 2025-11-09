#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n + 1), rank(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }
    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if (rank[u] == rank[v]) rank[v]++;
        return true;
    }
    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, u, v};
    }
    sort(edges.begin(), edges.end());
    int res = INT_MAX;
    for (int i = 0; i < m; ++i) {
        DSU dsu(n);
        int min_w = get<0>(edges[i]);
        int max_w = min_w;
        dsu.unite(get<1>(edges[i]), get<2>(edges[i]));
        if (dsu.connected(1, n)) {
            res = min(res, min_w + max_w);
            continue;
        }
        for (int j = i + 1; j < m; ++j) {
            int w = get<0>(edges[j]);
            int u = get<1>(edges[j]);
            int v = get<2>(edges[j]);
            dsu.unite(u, v);
            max_w = w;
            if (dsu.connected(1, n)) {
                res = min(res, min_w + max_w);
                break;
            }
            if (min_w + max_w >= res) break;
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}