#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<int> depth;

void dfs(int u, int p, int d) {
    parent[u] = p;
    depth[u] = d;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

int getLCA(int u, int v) {
    while (u != v) {
        if (depth[u] > depth[v]) {
            u = parent[u];
        } else {
            v = parent[v];
        }
    }
    return u;
}

int getLCAOfSet(const vector<int>& nodes) {
    if (nodes.empty()) return -1;
    int currentLCA = nodes[0];
    for (size_t i = 1; i < nodes.size(); ++i) {
        currentLCA = getLCA(currentLCA, nodes[i]);
    }
    return currentLCA;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        adj.assign(n + 1, vector<int>());
        parent.assign(n + 1, -1);
        depth.assign(n + 1, 0);
        
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        dfs(1, -1, 0);
        
        while (q--) {
            int k, m;
            cin >> k >> m;
            vector<int> nodes(m);
            for (int i = 0; i < m; ++i) {
                cin >> nodes[i];
            }
            
            vector<int> lcas;
            vector<int> subset(k);
            
            // Generate all combinations of size k
            vector<bool> mask(m, false);
            fill(mask.end() - k, mask.end(), true);
            
            do {
                subset.clear();
                for (int i = 0; i < m; ++i) {
                    if (mask[i]) {
                        subset.push_back(nodes[i]);
                    }
                }
                int lca = getLCAOfSet(subset);
                lcas.push_back(lca);
            } while (next_permutation(mask.begin(), mask.end()));
            
            if (lcas.empty()) {
                cout << 0 << endl;
                continue;
            }
            
            map<int, int> depthCount;
            int maxDepth = -1;
            for (int lca : lcas) {
                int d = depth[lca];
                if (d > maxDepth) {
                    maxDepth = d;
                }
            }
            
            set<int> deepestLCAs;
            for (int lca : lcas) {
                if (depth[lca] == maxDepth) {
                    deepestLCAs.insert(lca);
                }
            }
            
            cout << deepestLCAs.size() << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}