#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);

vector<ll> adj[100001];
pair<ll, ll> p[100001];
ll n;
ll dp[100001][2];
ll dfs(ll v, ll u, bool left)
{
    if (dp[v][left] != -1)
        return dp[v][left];
    if (adj[v].empty())
        return 0;
    ll x = left ? p[v].first : p[v].second;
    ll res = 0;
    for (ll ch : adj[v])
    {
        if (ch != u)
        {
            ll op1 = dfs(ch, v, 1) + abs(x - p[ch].first);
            ll op2 = dfs(ch, v, 0) + abs(x - p[ch].second);
            res += max(op1, op2);
        }
    }
    return dp[v][left] = res;
}
int main()
{
    // بسم الله
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (ll i = 1; i <= n; i++)
        {
            adj[i].clear();
            dp[i][0] = -1;
            dp[i][1] = -1;
            cin >> p[i].first >> p[i].second;
        }

        for (ll i = 1; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        ll ans = 0;
        ans = max(dfs(1, -1, 0), dfs(1, -1, 1));

        cout << ans << endl;
    }
    return 0;
}
