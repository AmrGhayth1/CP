#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;

void cycle(ll u, vector<ll>& to, vector<ll>& vis, vector<ll>& cy) {
    vis[u] = 1;
    ll v = to[u];
    if (vis[v] == 0) {
        cycle(v, to, vis, cy);
    } else if (vis[v] == 1) {
        ll cur = v;
        while (true) {
            cy[cur] = 1;
            cur = to[cur];
            if (cur == v) break;
        }
    }
    vis[u] = 2;
}

ll dfs(ll u, vector<ll>& to, vector<ll>& cy, vector<ll>& dp) {
    if (cy[u]) return 0;
    if (dp[u] != -1) return dp[u];
    dp[u] = 1 + dfs(to[u], to, cy, dp);
    return dp[u];
}

int main() {
    AMR
    ll t = 1 ;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> to(n + 1);
        for (ll i = 1; i <= n; i++) {
            cin >> to[i];
        }

        vector<ll> vis(n + 1, 0);
        vector<ll> cy(n + 1, 0);

        for (ll i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                cycle(i, to, vis, cy);
            }
        }

        vector<ll> dp(n + 1, -1);
        ll mx = 0;
        for (ll i = 1; i <= n; i++) {
            if (!cy[i]) {
                mx = max( mx , dfs(i, to, cy, dp));
            }
        }

        cout << mx +2  << endl ;
    }
    return 0;
}
