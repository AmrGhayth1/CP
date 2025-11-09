#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<int>> adjF, adjG, both;
vector<int> visF, visG, visBoth;

void dfs(int u, vector<vector<int>> &adj, vector<int> &vis, vector<int> &comp, int c) {
    vis[u] = 1;
    comp[u] = c;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v, adj, vis, comp, c);
    }
}

void dfsBoth(int u, vector<vector<int>> &adj, vector<int> &vis) {
    vis[u] = 1;
    for (int v : adj[u])
        if (!vis[v]) dfsBoth(v, adj, vis);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m1, m2;
        cin >> n >> m1 >> m2;

        adjF.assign(n + 1, {});
        adjG.assign(n + 1, {});
        both.assign(n + 1, {});

        for (int i = 0; i < m1; i++) {
            int u, v;
            cin >> u >> v;
            adjF[u].push_back(v);
            adjF[v].push_back(u);
        }

        for (int i = 0; i < m2; i++) {
            int u, v;
            cin >> u >> v;
            adjG[u].push_back(v);
            adjG[v].push_back(u);
        }

        vector<int> compF(n + 1), compG(n + 1);
        visF.assign(n + 1, 0);
        visG.assign(n + 1, 0);

        int cF = 0, cG = 0;

        for (int i = 1; i <= n; i++) {
            if (!visF[i]) dfs(i, adjF, visF, compF, ++cF);
            if (!visG[i]) dfs(i, adjG, visG, compG, ++cG);
        }

        // Build combined graph (connect if same F or same G component)
        for (int i = 1; i <= n; i++) {
            for (int j : adjF[i])
                both[i].push_back(j);
            for (int j : adjG[i])
                both[i].push_back(j);
        }

        visBoth.assign(n + 1, 0);
        int combinedComponents = 0;
        for (int i = 1; i <= n; i++) {
            if (!visBoth[i]) {
                dfsBoth(i, both, visBoth);
                combinedComponents++;
            }
        }

        cout << (n - combinedComponents) << "\n";
    }
    return 0;
}
