#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR ios::sync_with_stdio(0); cin.tie(0);
 
void dfs(ll u, ll p, vector<pair<ll, ll>> adj[], map<ll, ll>& m, ll mx, ll mn) {
    if (mx >= mn) return;
    m[mx] = u;
    ll last = LLONG_MAX;
    for (pair<ll,ll> v : adj[u]) {
        if (v.second == p) continue;
        dfs(v.second, u, adj, m, max(mx, v.first ), min(mn, last));
        last = v.first ;
    }
}
 
int main() {
    AMR
    ll t;
    cin >> t;
    while (t--) {
        ll n, q;
        cin >> n >> q;
        
        vector<pair<ll, ll>> adj[n + 1];
        for (ll i = 0; i < n - 1; ++i) {
            ll u, v, w;
            cin >> u >> v >> w;
            adj[u].emplace_back(w, v);
            adj[v].emplace_back(w, u); 
        }
 
        for (int i = 1; i <= n; ++i) {
            sort(all(adj[i]), [&](pair<ll, ll > a , pair<ll,ll> b ){
                return a.first > b.first ; 
            });
        }
 
        map<ll, ll> m;
        dfs(1, -1, adj , m, 0, LLONG_MAX);
        m[-1] = 1; 
 
        ll ans = 0;
        while (q--) {
            ll x;
            cin >> x;
            auto it = m.lower_bound(x);
            if (it == m.begin()) {
                ans += 1;
            } else {
                --it;
                ans += it->second;
            }
        }
        cout << ans << endl;
    }
    return 0;
}