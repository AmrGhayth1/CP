#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bll;
const ll INF = 1e18;

int main()
{ // بسم الله
    AMR
    ll t = 1;
    // cin >> t;
next:
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> adj(n + 1);
        for (ll i = 0; i < m; i++)
        {
            ll u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string s;
        cin >> s;

        vector<ll> dis1(n + 1, INF), dis2(n + 1, INF), vis(n + 1, -1);
        queue<ll> q;
        for (ll i = 1; i <= n; i++)
        {
            if (s[i - 1] == 'S')
            {
                dis1[i] = 0;
                vis[i] = i;
                q.push(i);
            }
        }

        while (!q.empty())
        {
            ll u = q.front();
            q.pop();
            for (auto v : adj[u])
            {
                ll d = dis1[u] + 1;
                if (d < dis1[v])
                {
                    if (vis[v] != vis[u])
                        dis2[v] = dis1[v];
                    dis1[v] = d;
                    vis[v] = vis[u];
                    q.push(v);
                }
                else if (vis[v] != vis[u] && d < dis2[v])
                {
                    dis2[v] = d;
                    q.push(v);
                }
            }
        }

        vector<ll> dp(n + 1, -1);
        auto dfs = [&](ll i) -> ll 
        {
            if (dp[i] != -1) return dp[i];
            ll res = 1e18;
            if (dis2[i] != 1e18) res = min(res, dis1[i] + dis2[i]);
            for (auto v : adj[i])
            {
                if (dis2[v] != 1e18)
                    res = min(res, 2 + dis1[v] + dis2[v]);
            }
            return dp[i] = res;
        };

        for (ll i = 1; i <= n; i++)
        {
            if (s[i - 1] == 'D')
                cout << dfs(i) << endl;
        }
    }
    return 0;
}

